#include <stdio.h>
#include <math.h>

double	iterative_factorial(double nb)
{
	double	result;

	result = 1.0;
	if (nb < 0)
		return (0);
	while (nb > 0)
	{
		result *= nb;
		nb --;
	}
	return (result);
}

double	recursive_factorial(double nb)
{
	if (nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (1);
	return (nb * recursive_factorial(nb - 1));
}

double	iterative_power(double nb, int power)
{
	double	result;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	result = 1.0;
	while (power > 0)
	{
		result *= nb;
		power --;
	}
	return (result);
}

double	recursive_power(double nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	return (nb * recursive_power(nb, power - 1));
}
double sinx(double a, int i)
{
    double result = 0.0;
    int j = 1;
	if(a == 180 * (M_PI / 180) || a == 360 * (M_PI / 180))
		return 0.00;

    while(j <= i)
    {
        if(j % 2 == 0)
            result -= recursive_power(a, (2 * j - 1)) / recursive_factorial(2 * j - 1);
        else if(j % 2 != 0)
            result += recursive_power(a, (2 * j - 1)) / recursive_factorial(2 * j - 1);
        j++;
    }
    return (result);
}
double cosx(double a, int i)
{
    double result = 0;
    int j = 1;

	if(a == 90 * (M_PI / 180) || a == 180 * (M_PI / 180))
		return 0.00;

    while(j <= i)
    {
        if(j % 2 != 0)
            result += recursive_power(a, (2 * j - 2)) / recursive_factorial(2 * j - 2);
        else if(j % 2 == 0)
            result -= recursive_power(a, (2 * j - 2)) / recursive_factorial(2 * j - 2);
        j++;
    }
    return (result);
}

double my_fabs(double a, double b)
{
	if (a == b)
		return 0.0;
	else if(a > b)
		return (a - b);
	else
		return (b - a);
}

int main ()
{
    double a;
	int i;
	printf("give me a number as a degree: ");
    scanf("%lf",&a);
	printf("give me a number for the iteration: ");
	scanf("%d",&i);
    a *= M_PI/180;
	double my_sin = sinx(a, i);
	double my_cos = cosx(a, i);
    printf("sin: %.12lf \n", my_sin);
    printf("cos: %.12lf\n", my_cos);
	double original_sin = sin(a);
	double original_cos = cos(a);
	printf("original sinx: %.12lf\n", original_sin);
	printf("original cosx: %.12lf\n", original_cos);
	double the_error_of_sin = (my_fabs(my_sin, original_sin) / original_sin) * 100;
	printf("the error percentage for sin is: %.12lf\n", the_error_of_sin);
	double the_error_of_cos = (my_fabs(my_cos, original_cos) / original_cos) * 100;
	printf("the error percentage for cos is: %.12lf\n", the_error_of_cos);
    return (0);
}
