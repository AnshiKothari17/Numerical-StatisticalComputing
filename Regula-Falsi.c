#include <stdio.h>
#include <math.h>

// f(x) = x^3 - x - 11
double f(double x) {
    return x * x * x - x - 11;
}

int main() {
    double a, b, c;
    int max_iterations, iteration = 0;

    printf("Enter the initial guesses a and b (a < b): ");
    scanf("%lf %lf", &a, &b);
    printf("Enter the maximum number of iterations: ");
    scanf("%d", &max_iterations);

    if (f(a) * f(b) > 0) {
        printf("The function does not have opposite signs at the endpoints a and b.\n");
        return 1;  // Exit with error code
    }

    while (iteration < max_iterations) {
        // Apply the Regula Falsi method
        c = b - (f(b) * (b - a)) / (f(b) - f(a));

        // Check if the approximation is sufficiently close to zero
        if (fabs(f(c)) < 0.001) {
            break;  // Root found
        }

        // Decide which side of the interval to update
        if (f(c) * f(a) < 0) {
            b = c;  // Root is in the left half
        } else {
            a = c;  // Root is in the right half
        }

        iteration++;
    }

    // Print the result
    printf("The root of the function is approximately: %.3lf\n", c);

    return 0;
}
