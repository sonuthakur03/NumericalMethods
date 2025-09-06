// Equation: x^3 - 2x - 5 = 0
// Initial guess(x0) = 2, Error tolerance(E) = 0.0001, Max Iteration(N) = 20

#include <stdio.h>
#include <math.h>

double f(double x)
{
    return x * x * x - 2 * x - 5;
}

double g(double x)
{
    return 3 * x * x - 2; // derivative f'(x)
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
            printf("Error: Derivative approx. zero!\n");
            return 0;
        }
        x1 = x0 - f(x0) / g(x0);
        x0 = x1;
        I++;
        if (I > N)
        {
            printf("Error: Not convergent!\n");
            return 0;
        }
    }

    printf("After %d iterations, Root = %lf\n", I, x0);
    return 0;
}
