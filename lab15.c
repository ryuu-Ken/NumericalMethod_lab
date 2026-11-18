/*
 * Power Method
 *   Finds the dominant (largest magnitude) eigenvalue and its eigenvector.
 *   Repeat:  y = A*x ;  lambda = largest component of y ;  x = y / lambda
 *
 * Compile : gcc power_method.c -o power_method -lm
 * Run     : ./power_method
 */

#include <stdio.h>
#include <math.h>

#define MAX 10

int main(void)
{
    double a[MAX][MAX], x[MAX], y[MAX];
    double lambda, lambda_old = 0, error, tol, sum;
    int n, maxit, iter, i, j, converged = 0;

    printf("Enter order of matrix n: ");
    scanf("%d", &n);
    printf("Enter matrix A row by row (%d x %d):\n", n, n);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%lf", &a[i][j]);
    printf("Enter initial vector (%d values):\n", n);
    for (i = 0; i < n; i++)
        scanf("%lf", &x[i]);
    printf("Enter tolerance: ");
    scanf("%lf", &tol);
    printf("Enter maximum iterations: ");
    scanf("%d", &maxit);

    printf("\n%-6s%-14s", "Iter", "Eigenvalue");
    for (i = 0; i < n; i++)
        printf("x%-11d", i + 1);
    printf("%-12s\n", "Error");

    for (iter = 1; iter <= maxit; iter++) {
        /* y = A * x */
        for (i = 0; i < n; i++) {
            sum = 0;
            for (j = 0; j < n; j++)
                sum = sum + a[i][j] * x[j];
            y[i] = sum;
        }

        /* lambda = component of y with the largest magnitude */
        lambda = y[0];
        for (i = 1; i < n; i++)
            if (fabs(y[i]) > fabs(lambda))
                lambda = y[i];

        if (fabs(lambda) < 1e-12) {
            printf("\nEigenvalue is zero: choose a different initial vector.\n");
            return 1;
        }

        /* x = y / lambda */
        for (i = 0; i < n; i++)
            x[i] = y[i] / lambda;

        error = fabs(lambda - lambda_old);

        printf("%-6d%-14.6f", iter, lambda);
        for (i = 0; i < n; i++)
            printf("%-12.6f", x[i]);
        printf("%-12.6f\n", error);

        if (error < tol) {
            converged = 1;
            break;
        }
        lambda_old = lambda;
    }

    if (converged)
        printf("\nConverged in %d iterations.\n", iter);
    else
        printf("\nDid not converge within %d iterations.\n", maxit);

    printf("\nDominant eigenvalue = %.6f\n", lambda);
    printf("Eigenvector:\n");
    for (i = 0; i < n; i++)
        printf("x%d = %.6f\n", i + 1, x[i]);

    return 0;
}