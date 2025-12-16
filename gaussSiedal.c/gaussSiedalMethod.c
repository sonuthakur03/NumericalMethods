#include <stdio.h>
#include <math.h>
#define f1(x, y, z) (17 - y + 2 * z) / 20
#define f2(x, y, z) (-18 - 3 * x + z) / 20
#define f3(x, y, z) (25 - 2 * x + 3 * y) / 20
int main()
{
    int iteration = 1;
    float x0 = 0, y0 = 0, z0 = 0, x1, y1, z1, e1, e2, e3, e;
    printf("Enter stopping criteria (error) e:");
    scanf("%f", &e);
    printf("\nIteration\tx\t\ty\t\tz\n");
    do
    {
        x1 = f1(x0, y0, z0);
        y1 = f2(x1, y0, z0);
        z1 = f3(x1, y1, z1);
        printf("%d\t\t%0.4f\t\t%0.4f\t\t%0.4f\n", iteration, x1, y1, z1);
        e1 = fabs(x0 - x1);
        e3 = fabs(y0 - y1);
        e3 = fabs(z0 - z1);
        iteration++;
        x0 = x1;
        y0 = y1;
        z0 = z1;
    } while (e1 > e && e3 > e);
    printf("\nSolution: x=%0.4f, y=%0.4f, z=%0.4f\n", x1, y1, z1);
    return 0;
}