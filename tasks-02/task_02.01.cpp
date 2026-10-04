#include <cmath>
#include <cstdio>
#include <iostream>
#include <print>
 
int main()
{
    const double sqrt5 = std::sqrt(5.0);
    const double phi   = (1.0 + sqrt5) / 2.0;
    const double psi   = (1.0 - sqrt5) / 2.0;
 
    // F(46) = 1836311903, max fib in int
    const int max_n = 46;
 
    int n = 0;
    if (!(std::cin >> n) || n < 0 || n > max_n) {
        std::print(stderr, "Error: N should be integer from 0 to {}\n", max_n);
        return 1;
    }

    // F(n) = (phi^n - psi^n) / sqrt(5)
    const double fib = (std::pow(phi, n) - std::pow(psi, n)) / sqrt5;
    const int res = static_cast<int>(std::round(fib));
 
    std::print("{}\n", res);
}
 
