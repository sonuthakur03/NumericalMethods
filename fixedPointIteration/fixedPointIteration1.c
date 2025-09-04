#include <stdio.h>
#include <math.h>

double g(double x)
{
    return (2 * cos(x)) / 3;
}

int main()
{
    double x0, x1, E, err;
    int I, N;
    printf("initial guess(x0): ");
    scanf("%lf", &x0);
    printf("Error tolerance(E): ");
    scanf("%lf", &E);
    printf("Maximum Iterations(N): ");
    scanf("%d", &N);
    I = 0;
    do
    {
        x1 = g(x0);
        err = fabs(x1 - x0);
        x0 = x1;
        I++;
        if (I > N)
        {
            printf("Error");
            return 0;
        }

    } while (err > E);
    printf("after %d iterations, Root = %lf", I, x0);

    return 0;
}