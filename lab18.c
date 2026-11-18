/*
 * Simpson's 3/8 Rule
 *   I = (3h/8) * [ y0 + yn + 3*(y's not multiple of 3) + 2*(y's multiple of 3) ]
 *   Requires n to be a multiple of 3
 *
 * Compile : gcc simpson_3_8.c -o simpson_3_8 -lm
 * Run     : ./simpson_3_8
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
            printf("Enter number of subintervals n (multiple of 3): ");
            scanf("%d", &n);
            if (n < 3 || n % 3 != 0)
                printf("Invalid: n must be a multiple of 3.\n");
        } while (n < 3 || n % 3 != 0);

        h = (b - a) / n;
        sum = f(a) + f(b);

        printf("\n===== Simpson's 3/8 Rule =====\n");
        printf("h = %.6f\n", h);
        printf("Initial sum = y0 + yn = %.6f\n\n", sum);
        printf("%-4s %-10s %-12s %-6s %-12s\n", "i", "x_i", "y_i", "coef", "running sum");

        for (i = 1; i < n; i++) {
            double x = a + i * h;
            double y = f(x);
            int coef = (i % 3 == 0) ? 2 : 3;
            sum += coef * y;
            printf("%-4d %-10.4f %-12.6f %-6d %-12.6f\n", i, x, y, coef, sum);
        }

        result = (3 * h / 8) * sum;
        printf("\nIntegral (Simpson's 3/8) = %.6f\n", result);

        printf("\nCalculate again? (y/n): ");
        scanf(" %c", &again);

    } while (again == 'y' || again == 'Y');

    return 0;
}