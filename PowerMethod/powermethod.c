#include <stdio.h>
#include <conio.h>
#include <math.h>

#define M 10

void main()
{
    int n, i, j, k, Count, MAXITR = 100;
    double A[M][M], X[M], Z[M], D[M];
    double E = 0.00005, lambda, Dmax, norm;

    // Input the matrix size and elements
    printf("Enter the size of square matrix: ");
    scanf("%d", &n);

    printf("\nEnter the matrix: \n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%lf", &A[i][j]);
        }
        // Initial guess for the eigenvector (all 1s)
        X[i] = 1;
    }

    Count = 0;
    do
    {
        Count++;

        // Safety check for convergence
        if (Count > MAXITR)
        {
            printf("Error: Not Convergent!");
            getch();
            return;
        }

        // Matrix-vector multiplication: Z = A * X
        for (i = 0; i < n; i++)
        {
            Z[i] = 0;
            for (j = 0; j < n; j++)
            {
                Z[i] += A[i][j] * X[j];
            }
        }

        // Finding the largest element in Z to be the new lambda
        lambda = fabs(Z[0]);
        for (i = 1; i < n; i++)
        {
            if (fabs(Z[i]) > fabs(lambda))
                lambda = Z[i];
        }

        // Normalization and error calculation
        for (i = 0; i < n; i++)
        {
            Z[i] = Z[i] / lambda;
            D[i] = fabs(Z[i] - X[i]);
            X[i] = Z[i];
        }

        // Finding the maximum error (Dmax)
        Dmax = D[0];
        for (i = 1; i < n; i++)
        {
            if (D[i] > Dmax)
                Dmax = D[i];
        }

    } while (Dmax > E);

    // Convert the eigenvector to normal form (Unit Vector)
    norm = 0;
    for (i = 0; i < n; i++)
        norm += X[i] * X[i];

    for (i = 0; i < n; i++)
        X[i] /= sqrt(norm);

    // Output results
    printf("\nDominant Eigen value = %.4f", lambda);
    printf("\nCorresponding Vector [X]:\n");
    for (i = 0; i < n; i++)
        printf("%10.4f ", X[i]);

    getch();
}