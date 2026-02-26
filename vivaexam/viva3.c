#include <stdio.h>

int main()
{
    int i, j, k;
    float a[3][4], ratio;
    float x[3];

    printf("Enter augmented matrix (3x4):\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            scanf("%f", &a[i][j]);
        }
    }

    for (i = 0; i < 2; i++)
    {
        for (j = i + 1; j < 3; j++)
        {
            ratio = a[j][i] / a[i][i];
            for (k = 0; k < 4; k++)
            {
                a[j][k] = a[j][k] - ratio * a[i][k];
            }
        }
    }

    x[2] = a[2][3] / a[2][2];

    for (i = 1; i >= 0; i--)
    {
        x[i] = a[i][3];
        for (j = i + 1; j < 3; j++)
        {
            x[i] = x[i] - a[i][j] * x[j];
        }
        x[i] = x[i] / a[i][i];
    }

    printf("Solution:\n");
    printf("x = %f\n", x[0]);
    printf("y = %f\n", x[1]);
    printf("z = %f\n", x[2]);

    return 0;
}