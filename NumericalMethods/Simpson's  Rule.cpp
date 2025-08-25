
#include <iostream>
#include <cmath>
using namespace std;

// Function to be integrated
double f(double x) {
    return 1 / (1 + x * x); // Example: f(x) = 1 / (1 + x^2)
}

int main() {
    double a, b;  // Limits
    int n;        // Number of intervals

    // Input
    cout << "Enter lower limit (a): ";
    cin >> a;
    cout << "Enter upper limit (b): ";
    cin >> b;
    cout << "Enter number of intervals (even number): ";
    cin >> n;

    // Check if n is even
    if (n % 2 != 0) {
        cout << "Number of intervals must be even.\n";
        return 1;
    }

    double h = (b - a) / n;
    double sum = 0;

    cout << "\nIteration details:\n";
    cout << "i\t x\t\t f(x)\t\t weight\t weight * f(x)\n";

    for (int i = 0; i <= n; i++) {
        double x = a + i * h;
        double fx = f(x);
        int weight;

        if (i == 0 || i == n)
            weight = 1;
        else if (i % 2 == 0)
            weight = 2;
        else
            weight = 4;

        sum += weight * fx;

        cout << i << "\t " << x << "\t " << fx << "\t " << weight << "\t " << weight * fx << endl;
    }

    double result = (h / 3) * sum;
    cout << "\nApproximate integral using Simpson's 1/3 Rule = " << result << endl;

    return 0;
}
