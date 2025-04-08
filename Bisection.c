#include <stdio.h>
#include <math.h>

// f(x) = x^3 - x - 11
double f(double x) {
    return x * x * x - x - 11;
}

int main() {
    double a, b, c;
    int max_iterations, iteration = 0;

    // Read the input values
    printf("Enter the initial guesses a and b (a < b): ");
    scanf("%lf %lf", &a, &b);
    printf("Enter the maximum number of iterations: ");
    scanf("%d", &max_iterations);

    // Check if the initial points are valid
    if (f(a) * f(b) > 0) {
        printf("The function does not have opposite signs at the endpoints a and b.\n");
        return 1;  // Exit with error code
    }

    // Perform the bisection method loop
    while ((b - a) / 2.0 > 0.001 && iteration < max_iterations) {  // Stopping when the interval is less than 0.001
        // Find the midpoint
        c = (a + b) / 2.0;

        // Check if the midpoint is the root
        if (f(c) == 0.0) {
            break;  // Exact root found
        }

        // Decide which half to choose for the next iteration
        if (f(c) * f(a) < 0) {
            b = c;  // Root is in the left half
        } else {
            a = c;  /10/ Root is in the right half
        }

        iteration++;
    }

    // Print the result
    printf("The root of the function is approximately: %.3lf\n", (a + b) / 2.0);

    return 0;
}
