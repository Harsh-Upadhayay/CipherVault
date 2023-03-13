#include <iostream>
#include "Decrypter.h"
using namespace std;

class AffineDecrypter final : public Decrypter { 

    affineKeyType key;

    const int KEY_SIZE;

    void initKey(affineKeyType key);

    int extendedEuclidean(int a, int b, int& x, int& y);

    int modInverse(int a, int m);

    public :

    AffineDecrypter(affineKeyType key);

    string decrypt(const string &msg);

};
