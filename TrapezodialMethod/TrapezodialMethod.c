#include <stdio.h>
#include <conio.h>
#include <math.h>

#define N 100

void main()
{
    double Y[N], a, b, h, sum;
    int i, n;

    printf("Enter the limits of integration (a, b): ");
    scanf("%lf%lf", &a, &b);

    printf("How many sub-intervals? ");
    scanf("%d", &n);

    printf("Enter the %d number of y values:\n", n + 1);
    for (i = 0; i <= n; i++)
        scanf("%lf", &Y[i]);

    h = (b - a) / n;

    sum = Y[0] + Y[n];
    for (i = 1; i < n; i++)
        sum = sum + 2 * Y[i];

    sum = sum * h / 2;

    printf("\nSolution: %f", sum);
    getch();
}