#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int main() {
    float a[SIZE][SIZE + 1], x[SIZE], ratio;
    int i, j, k, n;
    printf("Enter the number of unknowns: ");
    scanf("%d", &n);
    /* augmented matrix */
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n + 1; j++) {
            printf("a[%d][%d] = ", i, j);
            scanf("%f", &a[i][j]);
        }
    }
    /* Gauss Elimination Process */
    for (i = 1; i <= n - 1; i++) {
        if (a[i][i] == 0.0) {
            printf("Mathematical Error! (Zero pivot element)\n");
            exit(0);
        }
        /* Making the elements below the pivot element 0 */
        for (j = i + 1; j <= n; j++) {
            ratio = a[j][i] / a[i][i];
            for (k = 1; k <= n + 1; k++) {
                a[j][k] = a[j][k] - ratio * a[i][k];
            }
        }
    }
    /* Back Substitution to find the solution */
    x[n] = a[n][n + 1] / a[n][n];

    for (i = n - 1; i >= 1; i--) {
        x[i] = a[i][n + 1];
        for (j = i + 1; j <= n; j++) {
            x[i] = x[i] - a[i][j] * x[j];
        }
        x[i] = x[i] / a[i][i];
    }
    /* Displaying the Solution */
    printf("\nSolution:\n");
    for (i = 1; i <= n; i++) {
        printf("x[%d] = %.3f\n", i, x[i]);
    }

    return 0;
}
