/*
 * Euler Method  (solves dy/dx = f(x, y), y(x0) = y0)
 *   y_(i+1) = y_i + h * f(x_i, y_i)
 *
 * Compile : gcc euler.c -o euler -lm
 * Run     : ./euler
 */

#include <stdio.h>
#include <math.h>

/* Differential equation: dy/dx = x + y */
double f(double x, double y)
{
    return x + y;
}

int main(void)
{
    double x0, y0, xn, h, x, y, slope, ynew;
    int n, i;

    printf("Enter x0: ");
    scanf("%lf", &x0);
    printf("Enter y0: ");
    scanf("%lf", &y0);
    printf("Enter step size h: ");
    scanf("%lf", &h);
    printf("Enter x at which y is required: ");
    scanf("%lf", &xn);

    n = (int)floor((xn - x0) / h + 0.5);
    x = x0;
    y = y0;

    printf("\n===== Euler Method =====\n");
    printf("Number of steps = %d\n\n", n);
    printf("%-4s %-10s %-12s %-12s %-12s\n", "i", "x_i", "y_i", "f(x_i,y_i)", "y_(i+1)");

    for (i = 0; i < n; i++) {
        slope = f(x, y);
        ynew = y + h * slope;
        printf("%-4d %-10.4f %-12.6f %-12.6f %-12.6f\n", i, x, y, slope, ynew);
        y = ynew;
        x = x0 + (i + 1) * h;
    }

    printf("\ny(%.4f) = %.6f\n", x, y);
    return 0;
}