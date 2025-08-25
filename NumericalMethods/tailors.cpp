#include <iostream>
#include <iomanip>   // for std::setw / std::setprecision
using namespace std;

/* ---------------------------------------------------------
   Example problem:
       dy/dx = x + y ,  y(0) = 1
   --------------------------------------------------------- */

// 1st derivative  y′ = f(x,y)
double f(double x, double y) {
    return x + y;
}

// 2nd derivative  y″ = ∂f/∂x + ∂f/∂y · y′
double f_prime(double x, double y) {
    double dy_dx = f(x, y);         // y′
    return 1 + dy_dx;               // ∂f/∂x = 1 , ∂f/∂y = 1
}

int main() {
    double x0, y0, h, xn;

    cout << "Initial x0       : ";  cin >> x0;   // e.g. 0
    cout << "Initial y0       : ";  cin >> y0;   // e.g. 1
    cout << "Step size h      : ";  cin >> h;    // e.g. 0.1
    cout << "Target x (xn)    : ";  cin >> xn;   // e.g. 0.2

    double x = x0, y = y0;
    int iter = 0;

    cout << "\nIter   x          y            y' (=f)     y''\n";
    cout << "------------------------------------------------------\n";
    cout << setw(3) << iter
         << "  " << setw(7) << x
         << "  " << setw(11) << y << '\n';

    while (x + 1e-12 < xn) {             // loop until we pass xn
        double y1 = f(x, y);             // y′
        double y2 = f_prime(x, y);       // y″

        // Taylor (2nd‑order):  y_{k+1} = y_k + h*y′ + h²/2 * y″
        y += h * y1 + (h * h / 2.0) * y2;
        x += h;
        ++iter;

        cout << setw(3) << iter
             << "  " << setw(7) << x
             << "  " << setw(11) << y
             << "  " << setw(10) << y1
             << "  " << setw(9) << y2 << '\n';
    }

    cout << "\nApproximate y(" << xn << ") = " << y << '\n';
    return 0;
}
