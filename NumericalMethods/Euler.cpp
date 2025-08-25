#include <bits/stdc++.h>
using namespace std;

// Function f(x, y) = dy/dx
double tanha(double x, double y) {
    return 1 - y;  // Updated: dy/dx = 1 - y
}

int main() {
    double x0, y0, h, xn;

    // Inputs
    cout << "Enter initial value of x (x0): ";
    cin >> x0;
    cout << "Enter initial value of y (y0): ";
    cin >> y0;
    cout << "Enter step size (h): ";
    cin >> h;
    cout << "Enter final value of x (xn): ";
    cin >> xn;

    // Header
    cout << "\nStep-by-step Euler method output:\n";
    cout << "x\t\ty\n";

    while (x0 <= xn + 1e-9) { // Add epsilon to include xn
        cout << fixed << setprecision(4) << x0 << "\t" << y0 << endl;
        y0 = y0 + h * tanha(x0, y0);
        x0 = x0 + h;
    }

    cout << "\nApproximate solution at x = " << xn << " is y = " << y0 << endl;

    return 0;
}
