/*
 * Runge-Kutta 4th Order (RK-4) Method
 *   k1 = f(x_i, y_i)
 *   k2 = f(x_i + h/2, y_i + (h/2)*k1)
 *   k3 = f(x_i + h/2, y_i + (h/2)*k2)
 *   k4 = f(x_i + h,   y_i + h*k3)
 *   y_(i+1) = y_i + (h/6) * (k1 + 2*k2 + 2*k3 + k4)
 *
 * Compile : gcc rk4.c -o rk4 -lm
 * Run     : ./rk4
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
    double x0, y0, xn, h, x, y, k1, k2, k3, k4, ynew;
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

    printf("\n===== Runge-Kutta 4th Order Method =====\n");
    printf("Number of steps = %d\n\n", n);
    printf("%-4s %-9s %-11s %-10s %-10s %-10s %-10s %-11s\n",
           "i", "x_i", "y_i", "k1", "k2", "k3", "k4", "y_(i+1)");

    for (i = 0; i < n; i++) {
        k1 = f(x, y);
        k2 = f(x + h / 2, y + (h / 2) * k1);
        k3 = f(x + h / 2, y + (h / 2) * k2);
        k4 = f(x + h, y + h * k3);
        ynew = y + (h / 6) * (k1 + 2 * k2 + 2 * k3 + k4);
        printf("%-4d %-9.4f %-11.6f %-10.6f %-10.6f %-10.6f %-10.6f %-11.6f\n",
               i, x, y, k1, k2, k3, k4, ynew);
        y = ynew;
        x = x0 + (i + 1) * h;
    }

    printf("\ny(%.4f) = %.6f\n", x, y);
    return 0;
}