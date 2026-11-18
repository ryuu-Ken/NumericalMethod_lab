/*
 * LU Factorization (Doolittle: L has 1s on the diagonal)
 *   A = L * U,  solve L*y = b (forward), then U*x = y (backward).
 *
 * Compile : gcc lu_factorization.c -o lu_factorization -lm
 * Run     : ./lu_factorization
 */

#include <stdio.h>
#include <math.h>

#define MAX 10

void print_square(const char *name, double m[MAX][MAX], int n)
{
    int i, j;
    printf("%s =\n", name);
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%10.4f ", m[i][j]);
        printf("\n");
    }
}

int main(void)
{
    double A[MAX][MAX], L[MAX][MAX], U[MAX][MAX];
    double b[MAX], y[MAX], x[MAX], sum;
    int n, i, j, k;

    printf("Enter order of matrix n: ");
    scanf("%d", &n);
    printf("Enter matrix A row by row (%d x %d):\n", n, n);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%lf", &A[i][j]);
    printf("Enter constants b (%d values):\n", n);
    for (i = 0; i < n; i++)
        scanf("%lf", &b[i]);

    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) {
            L[i][j] = 0;
            U[i][j] = 0;
        }

    /* Factorization */
    for (i = 0; i < n; i++) {
        /* Row i of U */
        for (j = i; j < n; j++) {
            sum = 0;
            for (k = 0; k < i; k++)
                sum = sum + L[i][k] * U[k][j];
            U[i][j] = A[i][j] - sum;
        }

        if (fabs(U[i][i]) < 1e-12) {
            printf("\nZero pivot U[%d][%d]: LU without pivoting fails.\n", i + 1, i + 1);
            return 1;
        }

        /* Column i of L */
        L[i][i] = 1;
        for (j = i + 1; j < n; j++) {
            sum = 0;
            for (k = 0; k < i; k++)
                sum = sum + L[j][k] * U[k][i];
            L[j][i] = (A[j][i] - sum) / U[i][i];
        }

        printf("\nAfter step %d:\n", i + 1);
        print_square("L", L, n);
        print_square("U", U, n);
    }

    /* Forward substitution: L*y = b */
    printf("\nForward substitution (L*y = b):\n");
    for (i = 0; i < n; i++) {
        sum = b[i];
        for (j = 0; j < i; j++)
            sum = sum - L[i][j] * y[j];
        y[i] = sum / L[i][i];
        printf("y%d = %.6f\n", i + 1, y[i]);
    }

    /* Backward substitution: U*x = y */
    printf("\nBackward substitution (U*x = y):\n");
    for (i = n - 1; i >= 0; i--) {
        sum = y[i];
        for (j = i + 1; j < n; j++)
            sum = sum - U[i][j] * x[j];
        x[i] = sum / U[i][i];
        printf("x%d = %.6f\n", i + 1, x[i]);
    }

    printf("\nSolution:\n");
    for (i = 0; i < n; i++)
        printf("x%d = %.6f\n", i + 1, x[i]);

    return 0;
}