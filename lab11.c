// Gauss-Jordan Method
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
    double a[MAX][MAX + 1], pivot, factor, temp;
    int n, i, j, k, p;

    printf("Enter number of equations n: ");
    scanf("%d", &n);
    printf("Enter the augmented matrix row by row (%d x %d):\n", n, n + 1);
    for (i = 0; i < n; i++)
        for (j = 0; j <= n; j++)
            scanf("%lf", &a[i][j]);

    printf("\nInitial augmented matrix:\n");
    print_matrix(a, n);

    for (k = 0; k < n; k++) {
        /* Make sure the pivot is non-zero */
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

        /* Normalise pivot row */
        printf("\nStep %d\n", k + 1);
        pivot = a[k][k];
        for (j = 0; j <= n; j++)
            a[k][j] = a[k][j] / pivot;
        printf("R%d = R%d / (%.4f)\n", k + 1, k + 1, pivot);

        /* Eliminate the column from every other row */
        for (i = 0; i < n; i++) {
            if (i != k) {
                factor = a[i][k];
                for (j = 0; j <= n; j++)
                    a[i][j] = a[i][j] - factor * a[k][j];
                printf("R%d = R%d - (%.4f) * R%d\n", i + 1, i + 1, factor, k + 1);
            }
        }
        print_matrix(a, n);
    }

    printf("\nSolution:\n");
    for (i = 0; i < n; i++)
        printf("x%d = %.6f\n", i + 1, a[i][n]);

    return 0;
}