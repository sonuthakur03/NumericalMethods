#include <stdio.h>
#include <math.h>

double f(double x)
{
    return x * x * x - 4 * x - 9;
}

int main()
{
    double a, b, c, error;
    int i = 0;

    printf("Enter initial guesses a and b: ");
    scanf("%lf %lf", &a, &b);

    if (f(a) * f(b) >= 0)
    {
        printf("Root does not exist in this interval.\n");
        return 0;
    }

    do
    {
        c = (a + b) / 2;
        printf("i %d: Root = %lf\n", ++i, c);

        if (f(c) == 0)
            break;
        else if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;

        error = fabs(b - a);

    } while (error >= 0.0001);

    printf("Final Root = %lf\n", c);

    return 0;
}