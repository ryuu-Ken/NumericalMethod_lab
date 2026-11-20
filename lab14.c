// Gauss-Seidel Iteration Method
#include <stdio.h>
#include <math.h>

#define MAX 10

int main(void)
{
    double a[MAX][MAX], b[MAX], x[MAX];
    double tol, sum, old, diff, error;
    int n, maxit, iter, i, j, converged = 0;

    printf("Enter number of equations n: ");
    scanf("%d", &n);
    printf("Enter coefficient matrix A row by row (%d x %d):\n", n, n);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%lf", &a[i][j]);
    printf("Enter constants b (%d values):\n", n);
    for (i = 0; i < n; i++)
        scanf("%lf", &b[i]);
    printf("Enter initial guess (%d values):\n", n);
    for (i = 0; i < n; i++)
        scanf("%lf", &x[i]);
    printf("Enter tolerance: ");
    scanf("%lf", &tol);
    printf("Enter maximum iterations: ");
    scanf("%d", &maxit);

    for (i = 0; i < n; i++) {
        if (fabs(a[i][i]) < 1e-12) {
            printf("\nZero on the diagonal: rearrange the equations.\n");
            return 1;
        }
    }

    printf("\n%-6s", "Iter");
    for (i = 0; i < n; i++)
        printf("x%-11d", i + 1);
    printf("%-12s\n", "Error");

    for (iter = 1; iter <= maxit; iter++) {
        error = 0;
        for (i = 0; i < n; i++) {
            old = x[i];
            sum = b[i];
            for (j = 0; j < n; j++)
                if (j != i)
                    sum = sum - a[i][j] * x[j];
            x[i] = sum / a[i][i];

            diff = fabs(x[i] - old);
            if (diff > error)
                error = diff;
        }

        printf("%-6d", iter);
        for (i = 0; i < n; i++)
            printf("%-12.6f", x[i]);
        printf("%-12.6f\n", error);

        if (error < tol) {
            converged = 1;
            break;
        }
    }

    if (converged)
        printf("\nConverged in %d iterations.\n", iter);
    else
        printf("\nDid not converge within %d iterations.\n", maxit);

    printf("\nSolution:\n");
    for (i = 0; i < n; i++)
        printf("x%d = %.6f\n", i + 1, x[i]);

    return 0;
}