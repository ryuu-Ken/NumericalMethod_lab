#include <stdio.h>

int main() {
    int n, i;
    float x[50], y[50];
    float sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;
    float a, b;

    printf("Enter number of data points: ");
    scanf("%d", &n);

    printf("Enter x values:\n");
    for (i = 0; i < n; i++)
        scanf("%f", &x[i]);

    printf("Enter y values:\n");
    for (i = 0; i < n; i++)
        scanf("%f", &y[i]);

    // Calculate required sums
    for (i = 0; i < n; i++) {
        sumX  += x[i];
        sumY  += y[i];
        sumXY += x[i] * y[i];
        sumX2 += x[i] * x[i];
    }

    // Normal equations solved directly:
    // b = (n*sumXY - sumX*sumY) / (n*sumX2 - sumX*sumX)
    // a = (sumY - b*sumX) / n
    b = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    a = (sumY - b * sumX) / n;

    printf("\nFitted line: y = %.4f + %.4fx\n", a, b);

    // Optional: show predicted values
    printf("\nx\ty(actual)\ty(fitted)\n");
    for (i = 0; i < n; i++) {
        printf("%.2f\t%.2f\t\t%.4f\n", x[i], y[i], a + b * x[i]);
    }

    return 0;
}