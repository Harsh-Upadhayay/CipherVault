#include <iostream>

using namespace std;

int extendedEuclidean(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }

    int x1, y1;
    int gcd = extendedEuclidean(b, a % b, x1, y1);

    x = y1;
    y = x1 - (a / b) * y1;

    return gcd;
}

int modInverse(int a, int m) {
    int x = 0, y = 0;
    int gcd = extendedEuclidean(a, m, x, y);

    if (gcd != 1) {
        cout << "Inverse doesn't exist" << endl;
        return -1;
    }
    else {
        int result = (x % m + m) % m;
        return result;
    }
}

int main() {
    int a, m;
    cout << "Enter the number and the modulus: ";
    cin >> a >> m;

    int inverse = modInverse(a, m);

    if (inverse == -1) {
        cout << "Inverse doesn't exist" << endl;
    }
    else {
        cout << "Inverse of " << a << " mod " << m << " is " << inverse << endl;
    }

    return 0;
}
