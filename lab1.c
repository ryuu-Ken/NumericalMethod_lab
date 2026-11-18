#include <stdio.h>
#include <math.h>

// f(x) = x^3 - 4x - 9
double f(double x) {
    return x*x*x - 4*x - 9;
}

int main() {
    double a, b, e, c;
    int i = 0;
    int maxIter = 1000;  // safety limit, not user-facing

    printf("Enter lower bound (a): ");
    scanf("%lf", &a);

    printf("Enter upper bound (b): ");
    scanf("%lf", &b);

    printf("Enter tolerance (e): ");
    scanf("%lf", &e);

    // Step 1: Check if bisection method can be applied
    if (f(a) * f(b) >= 0) {
        printf("Bisection method cannot be applied\n");
        return 0;
    }

    // Step 2: Iterate until tolerance is met
    do {
        c = (a + b) / 2.0;
        i++;

        printf("Iteration %d: a = %.4lf, b = %.4lf, c = %.4lf, f(c) = %.4lf\n",
               i, a, b, c, f(c));

        if (f(a) * f(c) < 0)
            b = c;
        else
            a = c;

    } while (fabs(f(c)) >= e && (b - a) / 2.0 >= e && i < maxIter);

    // Step 3: Print result
    printf("Approximate root = %.4lf (found in %d iterations)\n", c, i);

    if (i >= maxIter)
        printf("(Warning: reached internal safety limit without full convergence)\n");

    return 0;
}