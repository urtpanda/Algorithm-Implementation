#include <bits/stdc++.h>
using namespace std;

int hornersRule(int terms[], int size, int val) {
    int res = terms[0];
    cout << "Step 1: P(" << size - 1 << ") = " << res << endl;

    for (int i = 1; i < size; i++) {
        res = res * val + terms[i];
        cout << "Step " << i + 1 << ": P(" << size - i - 1 << ") = " << res << endl;
    }

    return res;
}

int main() {
    int degree;
    cout << "Enter polynomial degree: ";
    cin >> degree;
    degree++;

    int terms[degree];
    cout << "Enter " << degree << " coefficients:" << endl;

    for (int i = 0; i < degree; i++) {
        cout << "a(" << degree - i - 1 << ") = ";
        cin >> terms[i];
    }

    int val;
    cout << "Enter x value: ";
    cin >> val;

    cout << "\nEvaluating P(x) step by step:\n";
    int result = hornersRule(terms, degree, val);

    cout << "\nFinal Result: f(" << val << ") = " << result << endl;

    if (result == 0) {
        cout << " Satisfied\n";
    } else {
        cout <<"  NOT satisfied\n";
    }

    return 0;
}
