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

    while (iteration < max_iterations) {

        c = (a*f(b) - b*f(a)) / (f(b) - f(a));
        
        if (fabs(f(c)) < 0.001) {
            break; 
        }

        a = b;
        b = c;

        iteration++;
    }


    printf("The root of the function is approximately: %.3lf\n", c);

    return 0;
}
