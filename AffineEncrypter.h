#include <iostream>
#include <string>
#include "Encrypter.h"
using namespace std;

class AffineEncrypter final : public Encrypter { 

    affineKeyType key;

    const int KEY_SIZE;

    int gcd(int a, int b);

    void initKey();

    public :

    AffineEncrypter();

    string encrypt(const string &msg);

    affineKeyType getKey();
};
