#include <iostream>

#include "CaesarDecrypter.h"
#include "CaesarEncrypter.h"
#include "PlayFairDecrypter.h"
#include "PlayFairEncrypter.h"
#include "RailFenceDecrypter.h"
#include "RailFenceEncrypter.h"
#include "TranspositionalDecrypter.h"
#include "TranspositionalEncrypter.h"

using namespace std;

int main() {
    PlayFairEncrypter pf;
    PlayFairDecrypter pfD(pf.getKey());

    string msg = "We are l hola flee at once!";
    string cipher = pf.encrypt(msg);

    cout << cipher << endl;
    cout << pfD.decrypt(cipher) << endl;
}