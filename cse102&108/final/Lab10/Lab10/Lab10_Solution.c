/*
 * CSE108 - Lab #10
 * Structs and Unions
 *
 * Solution file.
 * The main function is unchanged.
 */

#include <stdio.h>

/* Define music_t struct */
typedef struct {
    double monthly_fee;
    double extra_hours;
    double extra_hour_fee;
    double total_cost;
} music_t;

/* Define cloud_t struct */
typedef struct {
    double base_fee;
    double extra_gb;
    double gb_fee;
    double total_cost;
} cloud_t;

/* Define course_t struct */
typedef struct {
    double monthly_fee;
    double number_of_courses;
    double course_fee;
    double total_cost;
} course_t;

/* Define subscription_data_t union */
typedef union {
    music_t music;
    cloud_t cloud;
    course_t course;
} subscription_data_t;

/* Define subscription_t struct */
typedef struct {
    char type;
    subscription_data_t data;
} subscription_t;

/* Function prototypes */
subscription_t get_subscription_info(void);
subscription_t compute_total_cost(subscription_t subscription);

int main(void)
{
    subscription_t one_subscription;

    printf("Digital Subscription Cost Computation Program\n");

    for (one_subscription = get_subscription_info();
         one_subscription.type != 'Q';
         one_subscription = get_subscription_info()) {

        one_subscription = compute_total_cost(one_subscription);
    }

    return 0;
}

subscription_t get_subscription_info(void)
{
    subscription_t subscription;
    char choice;

    printf("\nEnter subscription type ");
    printf("(M for music, C for cloud, O for online course, Q to quit): ");
    scanf(" %c", &choice);

    if (choice == 'M') {
        subscription.type = 'M';

        printf("Enter monthly fee: ");
        scanf("%lf", &subscription.data.music.monthly_fee);

        printf("Enter extra listening hours: ");
        scanf("%lf", &subscription.data.music.extra_hours);

        printf("Enter fee per extra hour: ");
        scanf("%lf", &subscription.data.music.extra_hour_fee);
    }
    else if (choice == 'C') {
        subscription.type = 'C';

        printf("Enter base fee: ");
        scanf("%lf", &subscription.data.cloud.base_fee);

        printf("Enter extra storage in GB: ");
        scanf("%lf", &subscription.data.cloud.extra_gb);

        printf("Enter fee per extra GB: ");
        scanf("%lf", &subscription.data.cloud.gb_fee);
    }
    else if (choice == 'O') {
        subscription.type = 'O';

        printf("Enter monthly fee: ");
        scanf("%lf", &subscription.data.course.monthly_fee);

        printf("Enter number of additional paid courses: ");
        scanf("%lf", &subscription.data.course.number_of_courses);

        printf("Enter fee per additional course: ");
        scanf("%lf", &subscription.data.course.course_fee);
    }
    else {
        subscription.type = 'Q';
    }

    return subscription;
}

subscription_t compute_total_cost(subscription_t subscription)
{
    if (subscription.type == 'M') {
        subscription.data.music.total_cost =
            subscription.data.music.monthly_fee +
            subscription.data.music.extra_hours * subscription.data.music.extra_hour_fee;

        printf("Total cost for music streaming: %.2f\n",
               subscription.data.music.total_cost);
    }
    else if (subscription.type == 'C') {
        subscription.data.cloud.total_cost =
            subscription.data.cloud.base_fee +
            subscription.data.cloud.extra_gb * subscription.data.cloud.gb_fee;

        printf("Total cost for cloud storage: %.2f\n",
               subscription.data.cloud.total_cost);
    }
    else if (subscription.type == 'O') {
        subscription.data.course.total_cost =
            subscription.data.course.monthly_fee +
            subscription.data.course.number_of_courses * subscription.data.course.course_fee;

        printf("Total cost for online course platform: %.2f\n",
               subscription.data.course.total_cost);
    }

    return subscription;
}
