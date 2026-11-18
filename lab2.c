#include <stdio.h>
#include <math.h>

// f(x) = x^3 - 4x - 9
double f(double x) {
    return x*sin(x) - 1;
}

int main() {
    double a, b, e, c, cOld;
    int i = 0;
    int maxIter = 1000;  // safety limit, not user-facing

    printf("Enter lower bound (a): ");
    scanf("%lf", &a);

    printf("Enter upper bound (b): ");
    scanf("%lf", &b);

    printf("Enter tolerance (e): ");
    scanf("%lf", &e);

    // Step 1: Check if Regula Falsi can be applied
    if (f(a) * f(b) >= 0) {
        printf("Regula Falsi method cannot be applied\n");
        return 0;
    }

    cOld = a;

    // Step 2: Iterate until tolerance is met
    do {
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));
        i++;

        printf("Iteration %d: a = %.4lf, b = %.4lf, c = %.4lf, f(c) = %.4lf\n",
               i, a, b, c, f(c));

        if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;

        if (fabs(c - cOld) < e || fabs(f(c)) < e)
            break;

        cOld = c;

    } while (i < maxIter);

    // Step 3: Print result
    printf("Approximate root = %.4lf (found in %d iterations)\n", c, i);

    if (i >= maxIter)
        printf("(Warning: reached internal safety limit without full convergence)\n");

    return 0;
}