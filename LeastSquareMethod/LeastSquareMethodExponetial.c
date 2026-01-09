#include <stdio.h>
#include <conio.h>
#include <math.h>

void main()
{
    double x, y;
    double sumX, sumX2, sumY, sumXY;
    double a, b;
    double D1, D2, D3;
    int i, j, n;

    printf("Number of data? ");
    scanf("%d", &n);

    sumX = 0;
    sumX2 = 0;
    sumY = 0;
    sumXY = 0;

    printf("Enter %d data pairs (x,y):\n", n);
    for (i = 0; i < n; i++)
    {
        scanf("%lf%lf", &x, &y);
        sumX += x;
        sumX2 += x * x;
        sumY += log(y);
        sumXY += x * log(y);
    }

    D1 = (sumY * sumX2 - sumXY * sumX);
    D2 = (n * sumXY - sumX * sumY);
    D3 = (n * sumX2 - sumX * sumX);

    a = exp(D1 / D3);
    b = D2 / D3;

    printf("\nRequired equation is:\n");
    printf("y = %.3f e^(%.3f x)", a, b);

    getch();
}