#include <iostream>
#include "AffineDecrypter.h"
using namespace std;

void AffineDecrypter :: initKey(affineKeyType key) {

    this -> key = key;

}

AffineDecrypter :: AffineDecrypter(affineKeyType key) : KEY_SIZE(128) {

    initKey(key);

}


int AffineDecrypter :: extendedEuclidean(int a, int b, int& x, int& y) {
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

int AffineDecrypter :: modInverse(int a, int m) {
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

string AffineDecrypter :: decrypt(const string &msg) {

    string decryptedMsg = "";
    int aInv = modInverse(key.first, KEY_SIZE),
        b = key.second;
    cout << key.first << " " << aInv << "\n";
    if(aInv == -1) return decryptedMsg;

    for(char ch : msg) 
        decryptedMsg += (char)((aInv * (iChar(ch) - b + KEY_SIZE)) % KEY_SIZE);

    return decryptedMsg;
}



