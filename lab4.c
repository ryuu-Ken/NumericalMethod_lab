#include <stdio.h>
#include <math.h>

// x^3 - 9x + 1 = 0  rewritten as  x = (x^3 + 1) / 9
double g(double x) {
    return (x*x*x + 1) / 9.0;
}

int main() {
    double x0, x1 = 0, e;
    int i = 0;
    int maxIter = 1000;  // internal safety limit

    printf("Enter initial guess (x0): ");
    scanf("%lf", &x0);

    printf("Enter tolerance (e): ");
    scanf("%lf", &e);

    do {
        x1 = g(x0);
        i++;

        printf("Iteration %d: x0 = %.6lf, x1 = g(x0) = %.6lf\n", i, x0, x1);

        if (fabs(x1 - x0) < e)
            break;

        x0 = x1;

    } while (i < maxIter);

    printf("Approximate root = %.6lf (found in %d iterations)\n", x1, i);

    if (i >= maxIter)
        printf("(Warning: method did not converge, try a different g(x) or guess)\n");

    return 0;
}