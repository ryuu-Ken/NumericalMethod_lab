#include <stdio.h>

int main() {
    int n, i, j;
    float x[20], y[20][20], sum, u, fact, p;

    printf("Enter number of data points: ");
    scanf("%d", &n);

    printf("Enter x values:\n");
    for (i = 0; i < n; i++)
        scanf("%f", &x[i]);

    printf("Enter y values:\n");
    for (i = 0; i < n; i++)
        scanf("%f", &y[i][0]);

    // Build backward difference table
    for (j = 1; j < n; j++) {
        for (i = n - 1; i >= j; i--) {
            y[i][j] = y[i][j - 1] - y[i - 1][j - 1];
        }
    }

    // Print difference table
    printf("\nBackward Difference Table:\n");
    for (i = 0; i < n; i++) {
        printf("%.2f\t", x[i]);
        for (j = 0; j <= i; j++)
            printf("%.4f\t", y[i][j]);
        printf("\n");
    }

    float value;
    printf("\nEnter value of x to interpolate: ");
    scanf("%f", &value);

    // h = step size (assumes equally spaced points)
    float h = x[1] - x[0];
    u = (value - x[n - 1]) / h;

    sum = y[n - 1][0];
    fact = 1;
    p = 1;

    for (i = 1; i < n; i++) {
        p = p * (u + (i - 1));
        fact = fact * i;
        sum = sum + (p * y[n - 1][i]) / fact;
    }

    printf("\nInterpolated value at x = %.4f is %.4f\n", value, sum);

    return 0;
}