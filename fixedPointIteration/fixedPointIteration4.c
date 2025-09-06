// Equation: x = 1 + 0.5*sin(x)  (x - 1 - 0.5*sin(x) = 0)
// Initial Guess(x0) = 1.0, Error Tolerance(E) = 0.00001, Maximum Iterations(N) = 50

#include <stdio.h>
#include <math.h>

double g(double x)
{
    return 1 + 0.5 * sin(x);
}

int main()
{
    double x0, x1, E, err;
    int I, N;
    printf("Initial guess(x0): ");
    scanf("%lf", &x0);
    printf("Error Tolerance(E): ");
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
            printf("Error: Exceeded maximum iterations\n");
            return 0;
        }
    } while (err > E);

    printf("After %d iterations, Root = %lf\n", I, x0);
    return 0;
}
