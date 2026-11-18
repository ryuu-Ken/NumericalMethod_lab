/*
 * Simpson's 1/3 Rule
 *   I = (h/3) * [ y0 + yn + 4*(odd y's) + 2*(even y's) ]
 *   Requires n to be even
 *
 * Compile : gcc simpson_1_3.c -o simpson_1_3 -lm
 * Run     : ./simpson_1_3
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
            printf("Enter number of subintervals n (even, n >= 2): ");
            scanf("%d", &n);
            if (n < 2 || n % 2 != 0)
                printf("Invalid: n must be even.\n");
        } while (n < 2 || n % 2 != 0);

        h = (b - a) / n;
        sum = f(a) + f(b);

        printf("\n===== Simpson's 1/3 Rule =====\n");
        printf("h = %.6f\n", h);
        printf("Initial sum = y0 + yn = %.6f\n\n", sum);
        printf("%-4s %-10s %-12s %-6s %-12s\n", "i", "x_i", "y_i", "coef", "running sum");

        for (i = 1; i < n; i++) {
            double x = a + i * h;
            double y = f(x);
            int coef = (i % 2 == 0) ? 2 : 4;
            sum += coef * y;
            printf("%-4d %-10.4f %-12.6f %-6d %-12.6f\n", i, x, y, coef, sum);
        }

        result = (h / 3) * sum;
        printf("\nIntegral (Simpson's 1/3) = %.6f\n", result);

        printf("\nCalculate again? (y/n): ");
        scanf(" %c", &again);

    } while (again == 'y' || again == 'Y');

    return 0;
}