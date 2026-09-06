#include <stdio.h>
#include <string.h>

int grade[160] = {85, 92, 78, 88, 95, 82, 90, 77, 89, 93, 81, 87, 94, 79, 86, 91, 84, 96, 80, 88, 92, 75, 89, 97, 83, 87, 90, 78, 85, 93, 82, 89, 91, 76, 88, 94, 81, 86, 92, 79, 87, 95, 84, 90, 98, 77, 89, 93, 80, 85, 91, 82, 88, 96, 78, 87, 92, 74, 89, 94, 83, 86, 90, 81, 85, 93, 79, 88, 95, 77, 91, 92, 84, 87, 89, 82, 90, 94, 80, 86, 93, 75, 89, 97, 81, 88, 91, 78, 85, 92, 83, 90, 96, 79, 87, 94, 84, 89, 91, 82, 85, 93, 80, 88, 95, 76, 92, 97, 81, 86, 90, 83, 89, 94, 77, 85, 91, 84, 88, 92, 79, 87, 96, 82, 90, 93, 75, 89, 98, 81, 86, 92, 78, 85, 94, 80, 88, 91, 83, 90, 95, 77, 89, 97, 82, 87, 93, 79, 86, 90, 84, 91, 94, 81, 85, 92, 88, 80, 87, 89};
char names[160][50] = {"Ali", "Berna", "Cemil", "Deniz", "Esra", "Fatih", "Gul", "Hasan", "Isin", "Jale", "Kamil", "Leyla", "Mehmet", "Nuray", "Okan", "Pelin", "Ramazan", "Selma", "Tugrul", "Ufuk", "Vural", "Windy", "Ahmet", "Bercem", "Can", "Derya", "Elif", "Faruk", "Gizem", "Harun", "Irem", "Jandarma", "Kamera", "Lena", "Meltem", "Nil", "Orhan", "Pinar", "Rahul", "Selim", "Tolga", "Uysal", "Vesile", "Wiktor", "Asim", "Basak", "Ceyda", "Didem", "Emre", "Ferah", "Gamze", "Haluk", "Ibrahim", "Julide", "Kadir", "Luiza", "Meric", "Nalan", "Oguz", "Peride", "Rafet", "Serra", "Tarik", "Ulviye", "Vakif", "Wilma", "Aziz", "Belgin", "Cetin", "Duman", "Emin", "Ferda", "Gokce", "Hatice", "Idris", "Jabu", "Karina", "Lilia", "Mithat", "Natalia", "Olgun", "Petronela", "Rasit", "Serdar", "Tevfik", "Umut", "Valeria", "Wilhelm", "Ayse", "Bahar", "Ceyhun", "Diger", "Engin", "Ferhat", "Gulay", "Huseyin", "Ismail", "Jaime", "Karen", "Lina", "Mirna", "Nazim", "Osman", "Petek", "Rauf", "Sevinc", "Tekin", "Ural", "Vanessa", "Xavier", "Ayhan", "Bekir", "Coskun", "Dogan", "Enver", "Figen", "Gulay", "Huseyin", "Ilhan", "Jasmine", "Karatay", "Lider", "Mines", "Necat", "Orkan", "Pida", "Recep", "Serap", "Teoman", "Ugur", "Vanessa", "Xenophon", "Aydin", "Beril", "Can", "Duygu", "Ercan", "Figen", "Gunes", "Ilknur", "Ilyas", "Javad", "Karim", "Leman", "Millicent", "Necmi", "Osman", "Pina", "Reka", "Sertac", "Tevhid", "Unsu", "Varol", "Xenia", "Yalcin", "Zayim", "Yusuf", "Zeynep", "Zafer", "Zehra"};

#define n 160

typedef struct t_student{
    char name[50];
    int grade;
}student;

int main()
{
    student students[n];
    int i = 0;
    while(i < n)
    {
        strcpy(students[i].name, names[i]);
        students[i].grade = grade[i];
        i++;
    }
    int j = 0, k;
    int low;
    while(j < n)
    {
        k = j + 1;
        while(k < n)
        {
            if(students[k].grade < students[j].grade)
            {
                student temp;
                temp = students[k];
                students[k] = students[j];
                students[j] = temp;
            }
            k++;
        }
        j++;
    }
    int sum = 0;
    for(int i = 0; i < 10; i++)
    {
        printf("%s %d\n", students[i].name, students[i].grade);
        sum += students[i].grade;
    }
    printf("\n%d\n", sum / 10);
    j = 10;
    while(j < n)
    {
        sum += students[j].grade;
        j++;
    }
    printf("\n%d\n", sum / n);
    printf("\n %s %d is the best\n", students[n - 1].name, students[n -1].grade);
    printf("\n %s %d is the worst\n", students[0].name, students[0].grade);
    return 0;
}