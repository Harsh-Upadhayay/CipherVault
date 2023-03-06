#include <iostream>
#include "CaesarEncrypter.h"
#include "CaesarDecrypter.h"
#include "RailFenceEncrypter.h"
#include "RailFenceDecrypter.h"

using namespace std;

int main()
{

    RailFenceCipherEncrypter pf;
    RailFenceCipherDecrypter pfD(pf.getKey());

    string msg = "defend the east wall";
    string cipher = pf.encrypt(msg);

    cout << pf.getKey() << "\n";

    cout << cipher << "\n\n";
    cout << pfD.decrypt(cipher);
}