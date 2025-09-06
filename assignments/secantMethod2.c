// 2x^3+4x^2-4x-6
// Enter initial intervals(a, b) : 0 2 Enter error tolerance(E) : 0.00001 Enter Maximum Iterations(N) : 50

#include <stdio.h>
#include <math.h>

double f(double x)
{
    return 2 * x * x * x + 4 * x * x - 4 * x - 6;
}

int main()
{
    double a, b, c, E;
    int i = 0, n;

    // inputs
    printf("Enter initial intervals(a,b): \n");
    scanf("%lf %lf", &a, &b);
    printf("Enter Error Tolerance(E): \n");
    scanf("%lf", &E);
    printf("Enter Max-Iterations(n): \n");
    scanf("%d", &n);

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
        i++;

        if (i > n)
        {
            printf("Error : Not Convergent!");
            return 0;
        }

    } while (fabs(f(c)) > E);

    printf("After %d iterations, Root = %lf", i, c);
    return 0;
}