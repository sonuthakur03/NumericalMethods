#include <stdio.h>
#include <math.h>

double f(double x){
    return x*x-4*x-10;
}

int main() {
    double a, b, c, E;
    printf("Enter initial intervals (a,b): ");
    scanf("%lf %lf", &a, &b);
    printf("Enter error tolerance (E): ");
    scanf("%lf", &E);

    if(f(a)*f(b) > 0){
        printf("No real root in this interval!");
        return 0;
    }

    do{
        c = (a + b) / 2;
        if(f(c)*f(a) > 0){
            a = c;
        }else{
            b = c;
        }
    }while(fabs(f(c)) > E);

    printf("Root: %f\n", c);
    return 0;
}
