#include <stdio.h>
#include <conio.h>
#include <math.h>
#define M 100

void main()
{
    double X[M], Y[M], x, y, P;
    int i, j, n;

    printf("How many data pairs? ");
    scanf("%d", &n);

    printf("\nEnter %d data pairs (Xi, Yi):\n", n);
    for (i = 0; i < n; i++)
        scanf("%lf%lf", &X[i], &Y[i]);

    printf("\nEnter the value of interpolant (x): ");
    scanf("%lf", &x);

    y = 0;
    for (i = 0; i < n; i++)
    {
        P = 1;
        for (j = 0; j < n; j++)
        {
            if (i != j)
                P = P * (x - X[j]) / (X[i] - X[j]);
        }
        y = y + P * Y[i];
    }

    printf("\nResult: y(%g) = %g", x, y);
    getch();
}