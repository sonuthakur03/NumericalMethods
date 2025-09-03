// 4x³ - 2x - 6
// Enter initial intervals(a, b) : 1 2 Enter error tolerance(E) : 0.0001

#include <stdio.h>
#include <math.h>

double f(double x)
{
    return 4 * x * x * x - 2 * x - 6;
}

int main()
{
    double a, b, c, E;
    printf("Enter initial intervals (a,b): ");
    scanf("%lf %lf", &a, &b);
    printf("Enter error tolerance (E): ");
    scanf("%lf", &E);

    if (f(a) * f(b) > 0)
    {
        printf("No real root in this interval!");
        return 0;
    }

    do
    {
        c = (a + b) / 2;
        if (f(c) < 0)
        {
            a = c;
        }
        else
        {
            b = c;
        }
    } while (fabs(f(c)) > E);

    printf("Root: %f\n", c);
    return 0;
}
