/*
 * Trapezoidal Rule
 *   I = (h/2) * [ y0 + yn + 2*(y1 + y2 + ... + y(n-1)) ]
 *   Works for any n >= 1
 *
 * Compile : gcc trapezoidal.c -o trapezoidal -lm
 * Run     : ./trapezoidal
 */

#include <stdio.h>
#include <math.h>

/* Function to integrate: f(x) = 1 / (1 + x^2) */
double f(double x)
{
    return 1.0 / (1.0 + x * x);
}

int main(void)
{
    double a, b, h, sum, result;
    int n, i;
    char again;

    do {
        printf("\nEnter lower limit a : ");
        scanf("%lf", &a);
        printf("Enter upper limit b : ");
        scanf("%lf", &b);

        do {
            printf("Enter number of subintervals n (n >= 1): ");
            scanf("%d", &n);
        } while (n < 1);

        h = (b - a) / n;
        sum = f(a) + f(b);

        printf("\n===== Trapezoidal Rule =====\n");
        printf("h = %.6f\n", h);
        printf("Initial sum = y0 + yn = %.6f\n\n", sum);
        printf("%-4s %-10s %-12s %-6s %-12s\n", "i", "x_i", "y_i", "coef", "running sum");

        for (i = 1; i < n; i++) {
            double x = a + i * h;
            double y = f(x);
            sum += 2 * y;
            printf("%-4d %-10.4f %-12.6f %-6d %-12.6f\n", i, x, y, 2, sum);
        }

        result = (h / 2) * sum;
        printf("\nIntegral (Trapezoidal) = %.6f\n", result);

        printf("\nCalculate again? (y/n): ");
        scanf(" %c", &again);

    } while (again == 'y' || again == 'Y');

    return 0;
}