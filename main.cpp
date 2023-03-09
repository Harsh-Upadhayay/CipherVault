#include <iostream>
#include "CaesarEncrypter.h"
#include "CaesarDecrypter.h"
#include "RailFenceEncrypter.h"
#include "RailFenceDecrypter.h"
#include "PlayFairDecrypter.h"
#include "PlayFairEncrypter.h"


using namespace std;

int main()
{

    PlayFairEncrypter pf;
    PlayFairDecrypter pfD(pf.getKey());

    string msg = "defend the east wall!";
    string cipher = pf.encrypt(msg);

    cout << cipher << "\n\n";
    cout << pfD.decrypt(cipher);
}