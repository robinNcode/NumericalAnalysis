#include <bits/stdc++.h>
using namespace std;
#define EPSILON 0.01
#define MAX_ITER 1000000

double func(double x)
{
    return x * x * x - x * x + 2;
}

/**
 * bisection function  starts here
 */
void bisection(double a, double b)
{
    if (func(a) * func(b) >= 0)
    {
        cout << "You have not assumed right a and b\n";
        return;
    }

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
    cout << "The value of root is : " << c;
}

/**
* False position function starts here
*/
void regulaFalsi(double a, double b)
{
    if (func(a) * func(b) >= 0)
    {
        cout << "You have not assumed right a and b\n";
        return;
    }

    double c = a; // Initialize result

    for (int i = 0; i < MAX_ITER; i++)
    {
        c = (a * func(b) - b * func(a)) / (func(b) - func(a));

        if (func(c) == 0)
            break;

        else if (func(c) * func(a) < 0)
            b = c;
        else
            a = c;
    }
    cout << "The value of root is : " << c;
}

int main()
{
    double a, b;

    cout<<"Enter your initial guess value : ";
    cin>>a>>b;

    bisection(a, b);
    cout<<endl<<endl;
    regulaFalsi(a, b);
    return 0;
}
