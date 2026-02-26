#include <stdio.h>
#include <math.h>

double f(double x)
{
    return 3 * x * x - 7 * x + 2;
}

double df(double x)
{
    return 6 * x - 7;
}

int main()
{
    double x0, x1, error;
    int i = 0;

    printf("Enter initial guess: ");
    scanf("%lf", &x0);

    do
    {
        if (df(x0) == 0)
        {
            printf("Division by zero error.\n");
            return 0;
        }

        x1 = x0 - f(x0) / df(x0);
        error = fabs(x1 - x0);

        printf("i %d: Root = %lf\n", ++i, x1);

        x0 = x1;

    } while (error >= 0.0001);

    printf("Final Root = %lf\n", x1);

    return 0;
}