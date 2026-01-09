#include <stdio.h>
#include <conio.h>
#include <math.h>

#define N 1000

double f(double x, double y, double z)
{
    return exp(x) + y - 2 * z;
}

void printValues(double X[], double Y[], double Z[], int n)
{
    int i;
    for (i = 0; i <= n; i++)
        printf("\n%f %f %f", X[i], Y[i], Z[i]);
}

void shoot(double X[], double Y[], double Z[], double xn, int n)
{
    double h = (xn - X[0]) / n;
    double k1, k2, k3, k4, k;
    double l1, l2, l3, l4, l;
    int i;
    for (i = 0; i < n; i++)
    {
        k1 = h * (Z[i]);
        l1 = h * f(X[i], Y[i], Z[i]);
        k2 = h * (Z[i] + l1 / 2);
        l2 = h * f(X[i] + h / 2, Y[i] + k1 / 2, Z[i] + l1 / 2);
        k3 = h * (Z[i] + l2 / 2);
        l3 = h * f(X[i] + h / 2, Y[i] + k2 / 2, Z[i] + l2 / 2);
        k4 = h * (Z[i] + l3);
        l4 = h * f(X[i] + h, Y[i] + k3, Z[i] + l3);

        k = (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        l = (l1 + 2 * l2 + 2 * l3 + l4) / 6;

        Y[i + 1] = Y[i] + k;
        Z[i + 1] = Z[i] + l;
        X[i + 1] = X[i] + h;
    }
}

void main()
{
    double X[N], Y[N], Z[N];
    double a, A, b, B;
    double B1, B2, B3;
    double m1, m2, m3;
    double E = 0.00005;
    int i, n;

    printf("Enter boundary conditions (x0, y0) and (xn, yn):\n");
    scanf("%lf%lf%lf%lf", &a, &A, &b, &B);
    printf("Enter the number of sub-intervals: ");
    scanf("%d", &n);

    X[0] = a;
    Y[0] = A;

    /* First Shot */
    printf("\nEnter initial guess to slope (m1): ");
    scanf("%lf", &m1);
    Z[0] = m1;
    shoot(X, Y, Z, b, n);
    B1 = Y[n];
    printf("\nShot 1: Initial slope = %f, Yn = %f\n", m1, B1);

    if (fabs(B1 - B) < E)
    {
        printf("\nSolution:");
        printValues(X, Y, Z, n);
        getch();
        return;
    }

    /* Second Shot */
    printf("\nEnter second guess to slope (m2): ");
    scanf("%lf", &m2);
    Z[0] = m2;
    shoot(X, Y, Z, b, n);
    B2 = Y[n];
    printf("\nShot 2: Initial slope = %f, Yn = %f\n", m2, B2);

    if (fabs(B2 - B) < E)
    {
        printf("\nSolution (x,y,z):");
        printValues(X, Y, Z, n);
        getch();
        return;
    }

    /* Third and further Shots */
    for (i = 3; i <= 100; i++)
    {
        m3 = m1 + (m2 - m1) / (B2 - B1) * (B - B1);
        Z[0] = m3;
        shoot(X, Y, Z, b, n);
        B3 = Y[n];
        printf("\nShot %d: Initial slope = %f, Yn = %f\n", i, m3, B3);

        if (fabs(B3 - B) < E)
        {
            printf("\nSolution:");
            printValues(X, Y, Z, n);
            getch();
            return;
        }
        m1 = m2;
        m2 = m3;
        B1 = B2;
        B2 = B3;
    }

    printf("\nError! No Solution!");
    getch();
}