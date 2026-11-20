#include <stdio.h>
#include <math.h>

double f(double x) {
    return (x * x * x * x) - x - 10.0;
}

double df(double x) {
    return 4.0 * (x * x * x) - 1.0;
}

int main() {
    double x0, x1, tol;
    int max_iter, iter = 0;

    printf("Enter initial guess: ");
    scanf("%lf", &x0);

    printf("Enter tolerance: ");
    scanf("%lf", &tol);

    printf("Enter maximum iterations: ");
    scanf("%d", &max_iter);

    printf("\n%-10s %-15s %-15s %-15s\n", "Iter", "x_n", "f(x_n)", "Error");
    printf("-----------------------------------------------------------\n");

    do {
        double fx = f(x0);
        double dfx = df(x0);

        if (fabs(dfx) < 1e-12) {
            printf("Derivative near zero; method may not converge.\n");
            return 1;
        }

        x1 = x0 - (fx / dfx);
        double err = fabs(x1 - x0);
        iter++;

        printf("%-10d %-15.8lf %-15.8lf %-15.8lf\n", iter, x1, f(x1), err);

        if (err <= tol) {
            printf("\nRoot = %.8lf (converged in %d iterations)\n", x1, iter);
            return 0;
        }

        x0 = x1;
    } while (iter < max_iter);

    printf("\nDid not converge within %d iterations. Last estimate: %.8lf\n", max_iter, x0);
    return 0;
}