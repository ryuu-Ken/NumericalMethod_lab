#include <stdio.h>
#include <math.h>

// f(x) = x^3 - 4x - 9
double f(double x) {
    return x*x*x - 4*x - 9;
}

int main() {
    double x0, x1, x2 = 0, e;
    int i = 0;
    int maxIter = 1000;  // internal safety limit

    printf("Enter first guess (x0): ");
    scanf("%lf", &x0);

    printf("Enter second guess (x1): ");
    scanf("%lf", &x1);

    printf("Enter tolerance (e): ");
    scanf("%lf", &e);

    do {
        if (f(x1) - f(x0) == 0) {
            printf("Division by zero, method fails\n");
            return 0;
        }

        x2 = x1 - f(x1) * (x1 - x0) / (f(x1) - f(x0));
        i++;

        printf("Iteration %d: x0 = %.6lf, x1 = %.6lf, x2 = %.6lf, f(x2) = %.6lf\n",
               i, x0, x1, x2, f(x2));

        if (fabs(x2 - x1) < e)
            break;

        x0 = x1;
        x1 = x2;

    } while (i < maxIter);

    printf("Approximate root = %.6lf (found in %d iterations)\n", x2, i);

    if (i >= maxIter)
        printf("(Warning: reached internal safety limit without full convergence)\n");

    return 0;
}