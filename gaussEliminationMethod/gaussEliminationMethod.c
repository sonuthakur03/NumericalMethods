#include <stdio.h>
#include <math.h>
#include <conio.h>

#define MAX 10

int main()
{
    int n, i, j, k;
    double A[MAX][MAX + 1], X[MAX], sum;
    double ratio;

    printf("How many unknowns: ");
    scanf("%d", &n);

    printf("Enter the augmented coefficient matrix row by row:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j <= n; j++)
        {
            scanf("%lf", &A[i][j]);
        }
    }

    /* 1. Forward Elimination (to Upper Triangular Matrix) */
    for (j = 0; j < n - 1; j++)
    {
        if (fabs(A[j][j]) < 0.00001)
        {
            printf("Error: Pivot element is zero! Row swapping needed.");
            getch();
            return 0;
        }

        for (i = j + 1; i < n; i++)
        {
            ratio = A[i][j] / A[j][j];

            for (k = j; k <= n; k++)
            {
                A[i][k] = A[i][k] - ratio * A[j][k];
            }
        }
    }

    /* 2. Back Substitution */
    X[n - 1] = A[n - 1][n] / A[n - 1][n - 1];

    for (i = n - 2; i >= 0; i--)
    {
        sum = 0;
        for (j = i + 1; j < n; j++)
        {
            sum = sum + A[i][j] * X[j];
        }
        X[i] = (A[i][n] - sum) / A[i][i];
    }

    /* Output the solutions */
    printf("\nSolution:\n");
    for (i = 0; i < n; i++)
    {
        printf("X[%d] = %.3f\n", i + 1, X[i]);
    }

    printf("\nPress any key to exit...");
    getch();
    return 0;
}