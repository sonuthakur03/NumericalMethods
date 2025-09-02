#include <stdio.h>
#include <math.h>

// Define the system of equations
double f(double x, double y) {
    return x*x*x - y - 50.0;
}

double g(double x, double y) {
    return y*y*y - x - 75.0;
}

// Define the partial derivatives for Jacobian matrix
double df_dx(double x, double y) {
    return 3.0*x*x;
}

double df_dy(double x, double y) {
    return -1.0;
}

double dg_dx(double x, double y) {
    return -1.0;
}

double dg_dy(double x, double y) {
    return 3.0*y*y;
}

int main() {
    double x, y;        // Current guess
    double x_new, y_new; // Updated guess
    double h, k;        // Corrections
    double p1, p2, q1, q2; // Jacobian matrix elements
    double r1, r2;      // Right-hand side vector
    double det;         // Determinant of Jacobian
    double f_val, g_val; // Function values
    
    int max_iter = 10;
    double tolerance = 1e-10;
    
    // Initial guess
    x = 4.0;
    y = 10.0;
    
    printf("Newton-Raphson Method for System of Equations\n");
    printf("f(x,y) = x³ - y - 50 = 0\n");
    printf("g(x,y) = y³ - x - 75 = 0\n\n");
    
    printf("Iter |     x_i     |     y_i     |     f(x,y)    |     g(x,y)    |");
    printf("     p1      | q1 |     p2      |     q2      |     r1      |     r2      |");
    printf("       h       |       k       |    x_{i+1}  |    y_{i+1}  \n");
    
    for(int iter = 0; iter < max_iter; iter++) {
        // Evaluate functions
        f_val = f(x, y);
        g_val = g(x, y);
        
        // Calculate Jacobian matrix elements
        p1 = df_dx(x, y);
        q1 = df_dy(x, y);
        p2 = dg_dx(x, y);
        q2 = dg_dy(x, y);
        
        // Calculate right-hand side vector
        r1 = -f_val;
        r2 = -g_val;
        
        // Calculate determinant of Jacobian
        det = p1 * q2 - q1 * p2;
        
        // Solve for h and k using Cramer's rule
        h = (r1 * q2 - q1 * r2) / det;
        k = (p1 * r2 - r1 * p2) / det;
        
        // Calculate new estimates
        x_new = x + h;
        y_new = y + k;
        
        // Print current iteration results
        printf("%3d  | %10.6f | %10.6f | %13.6e | %13.6e |", 
               iter, x, y, f_val, g_val);
        printf(" %10.6f | %2.0f | %10.6f | %10.6f |", p1, q1, p2, q2);
        printf(" %10.6f | %12.6f |", r1, r2);
        printf(" %11.6f | %11.6f |", h, k);
        printf(" %10.6f | %10.6f\n", x_new, y_new);
        
        // Check for convergence
        if(fabs(h) < tolerance && fabs(k) < tolerance) {
            printf("\nConverged after %d iterations!\n", iter + 1);
            printf("Final solution: x = %.10f, y = %.10f\n", x_new, y_new);
            break;
        }
        
        // Update for next iteration
        x = x_new;
        y = y_new;
        
        if(iter == max_iter - 1) {
            printf("\nMaximum iterations reached!\n");
        }
    }
    
    // Verify the final solution
    printf("\nVerification:\n");
    printf("f(%.6f, %.6f) = %.12e\n", x, y, f(x, y));
    printf("g(%.6f, %.6f) = %.12e\n", x, y, g(x, y));
    
    return 0;
}