#include <stdio.h>

int main() {
    int n, i, j;
    float x[20], y[20], value, result = 0, term;

    printf("Enter number of data points: ");
    scanf("%d", &n);

    printf("Enter x values:\n");
    for (i = 0; i < n; i++)
        scanf("%f", &x[i]);

    printf("Enter y values:\n");
    for (i = 0; i < n; i++)
        scanf("%f", &y[i]);

    printf("Enter value of x to interpolate: ");
    scanf("%f", &value);

    // Lagrange's formula
    for (i = 0; i < n; i++) {
        term = y[i];
        for (j = 0; j < n; j++) {
            if (j != i) {
                term = term * (value - x[j]) / (x[i] - x[j]);
            }
        }
        result += term;
    }

    printf("\nInterpolated value at x = %.4f is %.4f\n", value, result);

    return 0;
}