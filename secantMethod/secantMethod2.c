// cos(x)+2sin(x)+x^2

#include <stdio.h>
#include <math.h>

double f(double x)
{
    return cos(x) + 2 * sin(x) + x * x;
}

int main()
{
    double a, b, c, E;
    int I, N;

    printf("Enter initial intervals (a, b): ");
    scanf("%lf %lf", &a, &b);
    printf("Enter error tolerance (E): ");
    scanf("%lf", &E);
    printf("Enter Maximum Iterations (N): ");
    scanf("%d", &N);

    I = 0;

    do
    {

        if (fabs(f(b) - f(a)) < 0.000005)
        {
            printf("Mathematical Error!\n");
            return 0;
        }

        c = (a * f(b) - b * f(a)) / (f(b) - f(a));

        a = b;
        b = c;

        I++;

        if (I > N)
        {
            printf("Error: Not Convergent!\n");
            return 0;
        }

    } while (fabs(f(c)) > E);

    printf("After %d iterations, root = %f\n", I, c);

    return 0;
}
