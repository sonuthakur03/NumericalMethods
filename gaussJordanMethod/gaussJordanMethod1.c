#include <stdio.h>
#include <math.h>
#include <conio.h>

#define MAX 10

int main()
{
    int n, i, j, k;
    double A[MAX][MAX + 1], X[MAX];
    double ratio;

    printf("How many unknown: ");
    scanf("%d", &n);

    printf("Enter the augmented coefficient matrix\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j <= n; j++)
        {
            scanf("%lf", &A[i][j]);
        }
    }

    // Gaussian Elimination (Forward Elimination)
    for (j = 0; j < n; j++)
    {
        // Check for zero pivot element
        if (fabs(A[j][j]) < 0.00005)
        {
            printf("Error: pivot element approx. zero!");
            getch();
            return 0;
        }

        for (i = 0; i < n; i++)
        {
            if (i != j)
            {
                ratio = A[i][j] / A[j][j];

                for (k = j; k <= n; k++)
                {
                    A[i][k] = A[i][k] - ratio * A[j][k];
                }
            }
        }
    }

    // Back Substitution (Finding the solutions X[i])
    for (i = 0; i < n; i++)
    {
        X[i] = A[i][n] / A[i][i];
    }

    // Output the solutions
    printf("\nSolution:\n");
    for (i = 0; i < n; i++)
    {
        printf("X[%d] = %lf\n", i + 1, X[i]);
    }

    getch();