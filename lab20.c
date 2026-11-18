/*
 * Improved Euler Method (Heun's / Modified Euler, predictor-corrector)
 *   Predictor : y* = y_i + h * f(x_i, y_i)
 *   Corrector : y_(i+1) = y_i + (h/2) * [ f(x_i, y_i) + f(x_i + h, y*) ]
 *
 * Compile : gcc improved_euler.c -o improved_euler -lm
 * Run     : ./improved_euler
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
    double x0, y0, xn, h, x, y, s1, s2, ypred, ynew;
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

    printf("\n===== Improved Euler Method =====\n");
    printf("Number of steps = %d\n\n", n);
    printf("%-4s %-9s %-11s %-11s %-11s %-11s %-11s\n",
           "i", "x_i", "y_i", "slope1", "y*(pred)", "slope2", "y_(i+1)");

    for (i = 0; i < n; i++) {
        s1 = f(x, y);
        ypred = y + h * s1;
        s2 = f(x + h, ypred);
        ynew = y + (h / 2) * (s1 + s2);
        printf("%-4d %-9.4f %-11.6f %-11.6f %-11.6f %-11.6f %-11.6f\n",
               i, x, y, s1, ypred, s2, ynew);
        y = ynew;
        x = x0 + (i + 1) * h;
    }

    printf("\ny(%.4f) = %.6f\n", x, y);
    return 0;
}