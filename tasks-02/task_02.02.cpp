#include <cmath>
#include <cstdio>
#include <iostream>
#include <print>

int main()
{
    const double epsilon = 1e-9;

    double a = 0.0;
    double b = 0.0;
    double c = 0.0;

    if (!(std::cin >> a >> b >> c)) {
        std::print(stderr, "Error: expected a, b and c\n");
        return 1;
    }

    if (std::abs(a) < epsilon) {
        // a = 0
        if (std::abs(b) < epsilon) {
            // b = 0
            if (std::abs(c) < epsilon) {
                std::print("Infinity roots\n");
            } else {
                std::print("No roots\n");
            }
        } else {
            const double x = -c / b;
            std::print("One real root: x = {}\n", x);
        }
    } else {
        const double d = b * b - 4.0 * a * c;

        if (std::abs(d) < epsilon) {
            // d = 0
            const double x = -b / (2.0 * a);
            std::print("One real root: x = {}\n", x);
        } else if (d > 0.0) {
            // d > 0
            const double sqrt_d = std::sqrt(d);
            const double x1 = (-b - sqrt_d) / (2.0 * a);
            const double x2 = (-b + sqrt_d) / (2.0 * a);
            std::print("Two real roots: x1 = {}, x2 = {}\n", x1, x2);
        } else {
            // d < 0
            const double re = -b / (2.0 * a);
            const double im = std::sqrt(-d) / (2.0 * std::abs(a));
            std::print("Complex roots: x1 = {} - {}i, x2 = {} + {}i\n", re, im, re, im);
        }
    }
}