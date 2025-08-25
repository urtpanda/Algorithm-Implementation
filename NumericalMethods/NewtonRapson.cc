#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double a, b, c;
    double x0, tolerance, x1, error;

    // User input
    cout << "Enter coefficients a, b, c : ";
    cin >> a >> b >> c;
    cout << "Enter initial guess: ";
    cin >> x0;
    cout << "Enter stopping criterion: ";
    cin >> tolerance;

    int count = 0;

    do {
        double fx0 = a * x0 * x0 + b * x0 + c;  // f(x)
        double dfx0 = 2 * a * x0 + b;           // f'(x)

        if (dfx0 == 0) {
            cout << "f'(x) is zero. Try a different initial guess." << endl;
            return 1;
        }

        x1 = x0 - (fx0 / dfx0);  // Newton-Raphson formula

        error = abs(x1 - x0);  // Absolute error calculation

        x0 = x1;  // Update x0 for next iteration
        count++;

        cout << "Iteration " << count << ": x = " << fixed << setprecision(4) << x1 << endl;

    } while (error >= tolerance);

    cout << "The root is: " << fixed << setprecision(4) << x1 << endl;

    return 0;
}
