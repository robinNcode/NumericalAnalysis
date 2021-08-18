/**
* CSE 1901016113
* MD Shahin Mia Robin
* 16A2
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

#define EPSILON 0.01
#define E 0.001
#define F(x) (x * x) - (4 * x) - 10
#define F1(x) (2 * x) - 4

double func(double x)
{
    return x * x * x - x * x + 2;
}

/**
* Bisection function starts here
*/
void bisection(double a, double b)
{

    double c = a;
    while ((b - a) >= EPSILON)
    {
        c = (a + b) / 2;

        if (func(c) == 0.0)
            break;

        else if (func(c) * func(a) < 0)
            b = c;
        else
            a = c;
    }

    printf("\n\n In Bisection Method");
    printf("\n\nThe value of root is : %lf", c);
}

/**
* secant function starts here
*/
void secant(double x0)
{
    double x1, fx0, fx1;
    int flag = 1, count = 0;

    while (1)
    {
        fx0 = F(x0);
        fx1 = F(x0);
        x1 = x0 - (fx0 / fx1);
        printf("\nIteration Step %d : %lf", flag, x1);
        flag++;
        count++;

        if (fabs((x1 - x0) <= E))
        {
            printf("\n\n In Section Method");
            printf("\n\n The root is : %lf\n\n", x1);
            printf("\n\nTotal Iteration Steps count : %d\n\n\n", count);
            break;
        }
        else
            x0 = x1;
    }

    getch();
}

int main()
{
    double a = -200, b = 300;

    printf("Enter your initial guess value : ");
    scanf("%ld %lf", &a, &b);

    if (func(a) * func(b) >= 0)
    {
        bisection(a, b);
    }
    else
    {
        secant(a);
    }

    return 0;
}
