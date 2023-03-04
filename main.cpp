#include <iostream>
#include "CaesarEncrypter.h"
#include "CaesarDecrypter.h"

using namespace std;

int main() {

    CaesarEncrypter pf;
    CaesarDecrypter pfD(pf.getKey()); 

    string msg = "Hello I'm Harsh Upadhayay!",
        cipher = pf.encrypt(msg);

    // cout << cipher << "\n\n";
    cout << pfD.decrypt(cipher);
}