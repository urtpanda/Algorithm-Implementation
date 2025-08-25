#include <bits/stdc++.h>
using namespace std;

double f(double x) {
    return x * x * x - x - 1;
}

double bisection(double x1, double x2, double Tanha) {
    int iteration = 0;
    double x0;

    if (f(x1) * f(x2) >= 0) {
        cout << "Invalid interval! f(x1) and f(x2) must have opposite signs." << endl;
        return -1;
    }

    while ((x2 - x1) >= Tanha) {
        x0 = (x1 + x2) / 2;
        cout << "Iteration " << iteration + 1 << ": x" << iteration << " = " << x0 << ", f(x" << iteration << ") = " << f(x0) << endl;

        if (fabs(f(x0)) < Tanha)
            break;
        else if (f(x1) * f(x0) < 0)
            x2 = x0;
        else
            x1 = x0;

        iteration++;
    }

    cout << "Converged after " << iteration + 1 << " iterations." << endl;
    return x0;
}

int main() {
    double x1, x2, Tanha;

    // User input
    cout << "Enter initial interval [x1, x2]: ";
    cin >> x1 >> x2;

    cout << "Enter stopping criterion  (Tanha): ";
    cin >> Tanha;

    double root = bisection(x1, x2, Tanha);
    if (root != -1)
        cout << "Approximate root: " << root << endl;

    return 0;
}
