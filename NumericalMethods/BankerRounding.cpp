#include <bits/stdc++.h>
using namespace std;

double bankerRounding(double num, int digit) {
    double scale = 1;
    while (num >= 10) { num /= 10; scale *= 10; }
    while (num > 0 && num < 1) { num *= 10; scale /= 10; }
    double factor = 1;
    for (int i = 1; i < digit; i++) factor *= 10;
    double scaledNum = num * factor;
    long long intPart = scaledNum;
    long long nextDigit = (long long)(scaledNum * 10) % 10;

    if (nextDigit > 5 || (nextDigit == 5 && intPart % 2 != 0)) intPart++;

    return (intPart / factor) * scale;
}

int main() {
    double num;
    int digit;

    cout << "Enter a number: ";
    cin >> num;
    cout << "Enter significant digits: ";
    cin >> digit;

    cout << "Rounded Value: " << bankerRounding(num, digit) << endl;
    return 0;
}
