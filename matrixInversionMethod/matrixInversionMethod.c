#include <stdio.h>
#include <math.h>

#define MAX 10

int main()
{
    int n, i, j, k;
    double A[MAX][MAX], B[MAX][MAX];
    double ratio, diag;

    printf("Enter the size of square matrix: ");
    scanf("%d", &n);

    printf("\nEnter the coefficient matrix:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%lf", &A[i][j]);

    /* Initialize identity matrix */
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            B[i][j] = (i == j) ? 1.0 : 0.0;

    /* Gauss–Jordan elimination */
    for (j = 0; j < n; j++)
    {
        if (fabs(A[j][j]) < 0.0005)
        {
            printf("\nError: Pivot element is approximately zero.");
            return 0;
        }

        for (i = 0; i < n; i++)
        {
            if (i != j)
            {
                ratio = A[i][j] / A[j][j];
                for (k = 0; k < n; k++)
                {
                    A[i][k] -= ratio * A[j][k];
                    B[i][k] -= ratio * B[j][k];
                }
            }
        }
    }

    /* Normalize diagonal elements */
    for (i = 0; i < n; i++)
    {
        diag = A[i][i];
        for (j = 0; j < n; j++)
        {
            A[i][j] /= diag;
            B[i][j] /= diag;
        }
    }

    printf("\nInverse of the matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%10.4f", B[i][j]);
        printf("\n");
    }

    return 0;
}
