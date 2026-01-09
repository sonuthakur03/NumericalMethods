#include <stdio.h>
#include <conio.h>
#include <math.h>

float f(float x, float y) { return (x * x - y); }

void main()
{
    double x0, y0, xn, h;
    double k1, k2, k3, k4, k;
    double x, y;
    int i, n;

    printf("Enter x0, y0, xn, n: \n");
    scanf("%lf%lf%lf%d", &x0, &y0, &xn, &n);

    h = (xn - x0) / n;
    x = x0;
    y = y0;

    printf("\nSolution:\n x         y");
    printf("\n%f %f", x, y);

    for (i = 1; i <= n; i++)
    {
        k1 = h * f(x, y);
        k2 = h * f(x + h / 2, y + k1 / 2);
        k3 = h * f(x + h / 2, y + k2 / 2);
        k4 = h * f(x + h, y + k3);

        k = (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        y = y + k;
        x = x + h;

        printf("\n %.2f  %.6f", x, y);
    }
}