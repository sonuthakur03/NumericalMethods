// xsin(x) + cos(x)

#include <stdio.h>
#include <math.h>

double f(double x)
{
    return x * sin(x) + cos(x);
}

int main()
{
    double a, b, E, c;
    printf("Enter initial intervals (a,b): ");
    scanf("%lf %lf", &a, &b);
    printf("Enter error tolerance (E): ");
    scanf("%lf", &E);

    if (f(a) * f(b) > 0)
    {
        printf("Error: No root in the interval!!");
        return 0;
    }

    do
    {
        c = (a + b) / 2;

        if (f(c) < 0)
            a = c;
        else
            b = c;

    } while (fabs(f(c)) > E);

    printf("Root: %f\n", c);
    return 0;
}
