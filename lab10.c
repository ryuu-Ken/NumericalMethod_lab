// * Gauss Elimination Method
 
#include <stdio.h>
#include <math.h>

#define MAX 10

void print_matrix(double a[MAX][MAX + 1], int n)
{
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j <= n; j++)
            printf("%10.4f ", a[i][j]);
        printf("\n");
    }
}

int main(void)
{
    double a[MAX][MAX + 1], x[MAX], factor, temp, sum;
    int n, i, j, k, p;

    printf("Enter number of equations n: ");
    scanf("%d", &n);
    printf("Enter the augmented matrix row by row (%d x %d):\n", n, n + 1);
    for (i = 0; i < n; i++)
        for (j = 0; j <= n; j++)
            scanf("%lf", &a[i][j]);

    printf("\nInitial augmented matrix:\n");
    print_matrix(a, n);

    /* Forward elimination */
    for (k = 0; k < n - 1; k++) {
        if (fabs(a[k][k]) < 1e-12) {
            p = -1;
            for (i = k + 1; i < n; i++) {
                if (fabs(a[i][k]) > 1e-12) {
                    p = i;
                    break;
                }
            }
            if (p == -1) {
                printf("\nZero pivot: no unique solution.\n");
                return 1;
            }
            for (j = 0; j <= n; j++) {
                temp = a[k][j];
                a[k][j] = a[p][j];
                a[p][j] = temp;
            }
            printf("\nSwapped R%d and R%d\n", k + 1, p + 1);
        }

        printf("\nStep %d (pivot = %.4f)\n", k + 1, a[k][k]);
        for (i = k + 1; i < n; i++) {
            factor = a[i][k] / a[k][k];
            for (j = k; j <= n; j++)
                a[i][j] = a[i][j] - factor * a[k][j];
            printf("R%d = R%d - (%.4f) * R%d\n", i + 1, i + 1, factor, k + 1);
        }
        print_matrix(a, n);
    }

    if (fabs(a[n - 1][n - 1]) < 1e-12) {
        printf("\nZero pivot: no unique solution.\n");
        return 1;
    }

    /* Back substitution */
    printf("\nBack substitution:\n");
    for (i = n - 1; i >= 0; i--) {
        sum = a[i][n];
        for (j = i + 1; j < n; j++)
            sum = sum - a[i][j] * x[j];
        x[i] = sum / a[i][i];
        printf("x%d = %.6f\n", i + 1, x[i]);
    }

    printf("\nSolution:\n");
    for (i = 0; i < n; i++)
        printf("x%d = %.6f\n", i + 1, x[i]);

    return 0;
}