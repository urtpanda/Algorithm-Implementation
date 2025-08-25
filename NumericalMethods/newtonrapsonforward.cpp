#include <bits/stdc++.h>
using namespace std;

// Function to calculate forward differences
void forwardDiffTable(double y[], double diff[], int n) {
    for (int i = 0; i < n - 1; i++) {
        diff[i] = y[i + 1] - y[i];
    }
}

// Function to calculate Newton Forward Interpolation
double newtonForward(double x[], double y[], int n, double x_value) {
    double diff[10], h = x[1] - x[0], u = (x_value - x[0]) / h;
    double result = y[0], term = 1;

    for (int i = 1; i < n; i++) {
        forwardDiffTable(y, diff, n);
        term *= (u - (i - 1)) / i;
        result += term * diff[0];
        for (int j = 0; j < n - 1; j++) y[j] = diff[j];
    }

    return result;
}

int main() {
    int n;
    cout << "Enter number of data points: ";
    cin >> n;

    double x[10], y[10], x_value;
    cout << "Enter x values: ";
    for (int i = 0; i < n; i++) cin >> x[i];

    cout << "Enter y values: ";
    for (int i = 0; i < n; i++) cin >> y[i];

    cout << "Enter x value to interpolate: ";
    cin >> x_value;

    cout << "Interpolated value at " << x_value << " is " << newtonForward(x, y, n, x_value) << endl;

    return 0;
}
