#include <stdio.h>
#include <math.h>

#define FALSE 0
#define TRUE 1

double g(double x);
double h(double x);
double bisection(double x_left, double x_right, double epsilon, double f(double farg), int *errp);

int main()
{
    double x_left, x_right, epsilon, root;
    int error;
    printf("Enter the left endpoint, right endpoint, and epsilon: ");
    scanf("%lf %lf %lf", &x_left, &x_right, &epsilon);
    printf("\n\nFunction g");
    root = bisection(x_left, x_right, epsilon, g, &error);
    if(!error)
        printf("\n    g(%.7f) = %e\n", root, g(root));
    printf("\n\nFunction h");
    root = bisection(x_left, x_right, epsilon, h, &error);
    if(!error)
        printf("\n    h(%.7f) = %e\n", root, h(root));  
    return 0;
}

double bisection(double x_left, double x_right, double epsilon, double f(double farg), int *errp)
{
    double x_mid, f_left, f_right, f_mid;
    int root_found = FALSE;
    f_left = f(x_left);
    f_right = f(x_right);
    if(f_left * f_right > 0)
    {
        *errp = TRUE;
        printf("\n May be no root in [%.7f, %.7f]\n", x_left, x_right);
    }
    else
    {
        *errp = FALSE;
        while(fabs(x_right - x_left) > epsilon && !root_found)
        {
            x_mid = (x_left + x_right) / 2.0;
            f_mid = f(x_mid);
            if(f_mid == 0.0)
                root_found = TRUE;
            else if(f_mid * f_left < 0)
                x_right = x_mid;
            else
            {
                x_left = x_mid;
                f_left = f_mid;
            }
            if(root_found)
                printf("\n    Root found at x = %.7f, midpoint of [%.7f, %.7f]\n", x_mid, x_left, x_right);
            else
                printf("\n    New interval is [%.7f, %.7f]\n", x_left, x_right);
        }
    }
    return (x_left + x_right) / 2.0;
}

double g(double x)
{
    return (5 * pow(x, 3.0) - 2 * pow(x, 2.0) + 3);
}
double h(double x)
{
    return (pow(x, 4.0) - 3 * pow(x, 2.0) - 8);
}