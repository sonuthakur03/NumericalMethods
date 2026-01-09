#include <stdio.h>
#include <conio.h>
#include <math.h>

float f1(float x, float y, float z) { return 3 * x + y - z; }
float f2(float x, float y, float z) { return 2 * x - y + z; }

void main()
{
    double x0, y0, z0, xn, h;
    double k1, k2, k3, k4, k;
    double l1, l2, l3, l4, l;
    double x, y, z;
    int i, n;

    printf("Enter initial condition (x0, y0, z0): ");
    scanf("%lf%lf%lf", &x0, &y0, &z0);

    printf("Enter final x (xn) and number of intervals (n): ");
    scanf("%lf%d", &xn, &n);

    h = (xn - x0) / n;
    x = x0;
    y = y0;
    z = z0;

    printf("\nSolution (x,y,z):");
    printf("\n%f %f %f", x, y, z);

    for (i = 1; i <= n; i++)
    {
        k1 = h * f1(x, y, z);
        l1 = h * f2(x, y, z);

        k2 = h * f1(x + h / 2, y + k1 / 2, z + l1 / 2);
        l2 = h * f2(x + h / 2, y + k1 / 2, z + l1 / 2);

        k3 = h * f1(x + h / 2, y + k2 / 2, z + l2 / 2);
        l3 = h * f2(x + h / 2, y + k2 / 2, z + l2 / 2);

        k4 = h * f1(x + h, y + k3, z + l3);
        l4 = h * f2(x + h, y + k3, z + l3);

        k = (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        l = (l1 + 2 * l2 + 2 * l3 + l4) / 6;

        y = y + k;
        z = z + l;
        x = x + h;

        printf("\n%f %f %f", x, y, z);
    }
    getch();
}