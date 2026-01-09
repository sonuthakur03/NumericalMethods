#include <stdio.h>
#include <conio.h>
#include <math.h>

#define M 100

void main()
{
    double x[M], y[M], A[9][10], C[9], r;
    int i, j, k, n, d;

    printf("Enter no. of data pairs   : ");
    scanf("%d", &n);
    printf("Enter degree of polynomial: ");
    scanf("%d", &d);
    printf("Enter the data pairs (x,y): ");
    for (k = 0; k < n; k++)
        scanf("%lf%lf", &x[k], &y[k]);

    /* Construct augmented coeff. matrix of normal equations */
    for (i = 0; i <= d; i++)
    {
        for (j = 0; j <= d; j++)
        {
            A[i][j] = 0;
            for (k = 0; k < n; k++)
                A[i][j] += pow(x[k], i + j);
        }
        A[i][d + 1] = 0;
        for (k = 0; k < n; k++)
            A[i][d + 1] += pow(x[k], i) * y[k];
    }

    /* Gauss Jordan */
    for (j = 0; j <= d; j++)
    {
        for (i = 0; i <= d; i++)
        {
            if (i != j)
            {
                r = A[i][j] / A[j][j];
                for (k = 0; k <= d + 1; k++)
                    A[i][k] -= r * A[j][k];
            }
        }
    }

    for (i = 0; i <= d; i++)
        C[i] = A[i][d + 1] / A[i][i];

    printf("\nSolution:");
    printf("\nIntercept = %12.4f", C[0]);
    printf("\nCoefficients:");
    for (i = 1; i <= d; i++)
        printf("\n\t x^%d => %12.4f", i, C[i]);

    getch();
}