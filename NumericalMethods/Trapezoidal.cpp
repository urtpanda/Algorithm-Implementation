
#include <bits/stdc++.h>
using namespace std;

// Integrand: f(x) = x / (1 + x)
double f(double x) {
    return x / (1.0 + x);
}

// Trapezoidal Rule implementation
double trapezoidalRule(double a, double b, int n) {
    double h = (b - a) / n;          // step size
    double sum = f(a) + f(b);        // first and last terms

    // sum the interior terms, each multiplied by 2
    for (int i = 1; i < n; ++i) {
        double x = a + i * h;
        sum += 2.0 * f(x);
    }

    return (h / 2.0) * sum;          // final result
}
int main() {
    double a, b;
    int tanha;

    // User input
    cout << "Enter lower limit (a): ";
    cin >> a;
    cout << "Enter upper limit (b): ";
    cin >> b;
    cout << "Enter number of subintervals (tanha): ";
    cin >> tanha;

    // Input validation
    if (tanha <= 0 || a >= b) {
        cout << "Invalid input! Ensure that a < b and tanha > 0.\n";
        return 1;
    }

    // Compute step size for display
    double h = (b - a) / tanha;

    // Apply Trapezoidal Rule
    double result = trapezoidalRule(a, b, tanha);

    // Output
    cout << fixed << setprecision(6);   // higher precision for h
    cout << "\nStep size (h)           : " << h << '\n';

    cout << setprecision(3);          
    cout << "Integral (Trapezoidal)   : " << result << '\n';

    return 0;
}
