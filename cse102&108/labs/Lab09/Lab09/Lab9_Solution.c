/*
* CSE102 — Lab 9: Structs / Solution
*/

#define CODE_LEN 10
#define EXAM_LEN 20
#define MAX_EXAMS 5
#define STUDENT_NAME_LEN 20
#define MAX_STUDENTS 100
#define MAX_COURSES 10

#include <stdio.h>
#include <string.h>

// Structs
typedef struct {
    char code[CODE_LEN];
    char exams[MAX_EXAMS][EXAM_LEN];
    double weights[MAX_EXAMS];
    int exam_count;
} course_t;

typedef struct {
    double values[MAX_EXAMS];
} grades_t;

typedef struct {
    char name[STUDENT_NAME_LEN];
    grades_t grades[MAX_COURSES];
} student_t;


/* TODO - 5 */
/* Prints a course's details */
void print_course(const course_t *course)
{
    printf("Course %s (%d exam(s))\n", course->code, course->exam_count);
    for (int i = 0; i < course->exam_count; i++)
        printf("  [%d] %-20s  weight: %.2f\n", i + 1, course->exams[i], course->weights[i]);
}


/* TODO - 4 */
/* Calculates weighted average of all exams in a course */
double weighted_average_for_course(const student_t *student, int course_index, const course_t *courses)
{
    double weighted_sum = 0.0;
    double total_weight = 0.0;
    
    for (int i = 0; i < courses[course_index].exam_count; i++)
    {
        weighted_sum += student->grades[course_index].values[i] * courses[course_index].weights[i];
        total_weight += courses[course_index].weights[i];
    }
    
    return weighted_sum / total_weight;
}


/*
* Helper function
* Returns the index of the first occurrence of the target string in the items array;
* if the target is not found, returns -1.
*/
int index_of_string(const char *target, const char *items[], int item_count)
{
    for (int i = 0; i < item_count; i++)
    {
        if (strcmp(items[i], target) == 0)
            return i;
    }
    return -1;
}


/*
* Helper function
* Returns the index of the course with the given course_code in the courses array;
* if no matching course is found, returns -1.
*/
int index_of_course_by_code(const course_t *courses, int course_count, const char *course_code)
{
    const char *course_codes[MAX_COURSES];
    for (int i = 0; i < course_count; i++)
        course_codes[i] = courses[i].code;
    return index_of_string(course_code, course_codes, course_count);
}


/*
* Helper function
* Returns the index of the exam with the given exam_name in the course's exams array;
* if no matching exam is found, returns -1.
*/
int index_of_exam_by_name(const course_t *course, const char *exam_name)
{
    const char *exam_names[MAX_EXAMS];
    for (int i = 0; i < course->exam_count; i++)
        exam_names[i] = course->exams[i];
    return index_of_string(exam_name, exam_names, course->exam_count);
}


/* TODO - 1 */
/* Gets course details from the user */
void get_course_details_from_user(course_t *course)
{
    printf("Enter course code: ");
    scanf("%s", course->code);
    printf("Enter number of exams: ");
    scanf("%d", &course->exam_count);
    
    for (int i = 0; i < course->exam_count; i++)
    {
        printf("Exam %d name: ", i + 1);
        fflush(stdout);
        scanf("%s", course->exams[i]);
        printf("Exam %d weight: ", i + 1);
        fflush(stdout);
        scanf("%lf", &course->weights[i]);
    }
}


/* TODO - 2 */
/* Gets student details from the user */
void get_student_details_from_user(student_t *student, const course_t *courses, int course_count)
{
    printf("Enter student name: ");
    scanf("%s", student->name);
    
    for (int c = 0; c < course_count; c++)
    {
        printf("Enter grades for course %s:\n", courses[c].code);
        for (int j = 0; j < courses[c].exam_count; j++)
        {
            printf("Grade of exam %s: ", courses[c].exams[j]);
            scanf("%lf", &student->grades[c].values[j]);
        }
    }
}


/* TODO - 3 */
/* List students above a threshold for a given course */
void list_students(student_t *students, int student_count, const char *course_code, course_t *courses, int course_count, double grade_threshold)
{
    int course_index = index_of_course_by_code(courses, course_count, course_code);
    
    for (int i = 0; i < student_count; i++)
    {
        double avg = weighted_average_for_course(&students[i], course_index, courses);
        if (avg > grade_threshold)
            printf("%s\n", students[i].name);
    }
}
    
    
int main(void)
{
    course_t courses[MAX_COURSES];
    int course_count = 0;
        
    /* Q1: Get course details from the user */
    printf("========== Q1: get_course_details_from_user ==========\n");
    printf("Enter the number of courses to be defined: ");
    scanf("%d", &course_count);
        
    for (int i = 0; i < course_count; i++)
        get_course_details_from_user(&courses[i]);
        
    /* Print each course details */
    printf("\n========== print_course ==========\n");
    for (int i = 0; i < course_count; i++)
    {
        print_course(&courses[i]);   
        printf("\n");
    }
        
        
    /* Q2: Get student details from the user */
    printf("\n========== Q2: get_student_details_from_user ==========\n");
    int student_count = 0;
    student_t students[MAX_STUDENTS];
        
    printf("Enter number of students: ");
    scanf("%d", &student_count);
        
    for (int s = 0; s < student_count; s++)
        get_student_details_from_user(&students[s], courses, course_count);
        
    /* Q3: List student names above threshold for "CSE102" course */
    printf("\n========== Q3: list_students (threshold %.1f) ==========\n", 50.0);
    if (course_count > 0)
        list_students(students, student_count, "CSE102", courses, course_count, 50.0);
    return 0;
}
    