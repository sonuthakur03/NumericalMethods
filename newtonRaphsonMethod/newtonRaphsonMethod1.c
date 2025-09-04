// xsinx+cosx
// Initial guess(x0) = 2, Error tolerance(E) = 0.000005, Max Iteration(N) = 20

#include <stdio.h>
#include <math.h>

double f(double x)
{
    return x * sin(x) + cos(x);
}

double g(double x)
{
    return x * cos(x);
}

int main()
{
    double x0, x1, E;
    int I = 0, N;

    printf("Initial Guess(x0): ");
    scanf("%lf", &x0);

    printf("Error tolerance(E): ");
    scanf("%lf", &E);

    printf("Maximum Iterations(N): ");
    scanf("%d", &N);

    while (fabs(f(x0)) > E)
    {
        if (fabs(g(x0)) < 0.000005)
        {
            printf("Error: First Deviation approx. zero!");
            return 0;
        }
        x1 = x0 - f(x0) / g(x0);
        x0 = x1;
        I++;
        if (I > N)
        {
            printf("Error: Not convergent!");
            return 0;
        }
    }
    printf("After %d iterations, Root = %lf", I, x0);

    return 0;
}