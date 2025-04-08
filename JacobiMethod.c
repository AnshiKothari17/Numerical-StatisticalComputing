#include <stdio.h>
#include <math.h>

/* Function definitions for Jacobi's method */
#define f1(y, z)  (17 - y + 2 * z) / 20
#define f2(x, z)  (-18 - 3 * x + z) / 20
#define f3(x, y)  (25 - 2 * x + 3 * y) / 20

int main() {
    float x0 = 0, y0 = 0, z0 = 0, x1, y1, z1, e1, e2, e3, e;
    int count = 1;
    printf("Enter tolerable error: ");
    scanf("%f", &e);

    printf("\nCount\tx\ty\tz\n");

    do {
        // calculate new x, y, and z values
        x1 = f1(y0, z0);
        y1 = f2(x0, z0);
        z1 = f3(x0, y0);

        //the current iteration results
        printf("%d\t%0.4f\t%0.4f\t%0.4f\n", count, x1, y1, z1);

        // the errors for each variable
        e1 = fabs(x0 - x1);
        e2 = fabs(y0 - y1);
        e3 = fabs(z0 - z1);

        // Increment the iteration count
        count++;

        // Update the values of x, y, and z for the next iteration
        x0 = x1;
        y0 = y1;
        z0 = z1;

    } while (e1 > e && e2 > e && e3 > e);  // Continue until the error is within tolerance

    // the final solution
    printf("\nSolution: x = %0.3f, y = %0.3f, z = %0.3f\n", x1, y1, z1);

    return 0;
}
