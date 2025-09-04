// x^4 - 4x^3 + 4x^2 + x - 4
// Initial guess(x0) = 3, Error tolerance(E) = 0.0001, Max Iteration(N) = 14
#include <stdio.h>
#include <math.h>

double f(double x)
{
    return pow(x, 4) - 4 * pow(x, 3) + 4 * pow(x, 2) + x - 4;
}

double g(double x)
{
    return 4 * pow(x, 3) - 12 * pow(x, 2) + 8 * x + 1;
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