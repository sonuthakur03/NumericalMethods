#include <stdio.h>
#include <conio.h>
#include <math.h>

#define M 10

void main()
{
    int n, i, j, k;
    double A[M][M], L[M][M], U[M][M], X[M], Y[M], B[M];

    printf("How Many Unknowns? ");
    scanf("%d", &n);

    printf("\nEnter the augmented co-eff. matrix: \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            scanf("%lf", &A[i][j]);
        scanf("%lf", &B[i]);
    }

    /* Factorize A to L and U */
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (i <= j)
            {
                U[i][j] = A[i][j];
                for (k = 0; k < i; k++)
                    U[i][j] -= L[i][k] * U[k][j];

                L[i][j] = (i == j) ? 1 : 0;
            }
            else
            {
                if (fabs(U[j][j]) < 0.000005)
                {
                    printf("\nError: Pivot = Zero!");
                    getch();
                    return;
                }
                L[i][j] = A[i][j];
                for (k = 0; k < j; k++)
                    L[i][j] -= L[i][k] * U[k][j];

                L[i][j] /= U[j][j];
                U[i][j] = 0;
            }
        }
    }

    // Display L matrix
    printf("\n L =");
    for (i = 0; i < n; i++)
    {
        printf("\n");
        for (j = 0; j < n; j++)
            printf("%10.4f ", L[i][j]);
    }

    // Display U matrix
    printf("\n\n U =");
    for (i = 0; i < n; i++)
    {
        printf("\n");
        for (j = 0; j < n; j++)
            printf("%10.4f ", U[i][j]);
    }

    /* Forward Substitution -> Compute Y from LY = B */
    for (i = 0; i < n; i++)
    {
        Y[i] = B[i];
        for (j = 0; j < i; j++)
            Y[i] = Y[i] - L[i][j] * Y[j];
    }

    printf("\n\nY' = \n");
    for (i = 0; i < n; i++)
        printf("%10.4f ", Y[i]);

    /* Back Substitution -> Compute X from UX = Y */
    for (i = n - 1; i >= 0; i--)
    {
        X[i] = Y[i];
        for (j = i + 1; j < n; j++)
            X[i] = X[i] - U[i][j] * X[j];

        X[i] = X[i] / U[i][i];
    }

    printf("\n\nSolution [X']: \n");
    for (i = 0; i < n; i++)
        printf("%10.4f ", X[i]);

    getch();
}