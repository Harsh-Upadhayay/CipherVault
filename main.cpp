#include <iostream>

#include "CaesarDecrypter.h"
#include "CaesarEncrypter.h"
#include "PlayFairDecrypter.h"
#include "PlayFairEncrypter.h"
#include "RailFenceDecrypter.h"
#include "RailFenceEncrypter.h"
#include "TranspositionalDecrypter.h"
#include "TranspositionalEncrypter.h"
#include "AffineDecrypter.h"
#include "AffineEncrypter.h"

using namespace std;

int main() {
    AffineEncrypter pf;
    AffineDecrypter pfD(pf.getKey());

    string msg = "We";
    string cipher = pf.encrypt(msg);

    cout << cipher << endl;
    cout << pfD.decrypt(cipher) << endl;
}