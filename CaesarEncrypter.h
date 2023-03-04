#include <iostream>
#include "Encrypter.h"
using namespace std;

class CaesarEncrypter final : public Encrypter { 

    caesarKeyType key;

    const int KEY_SIZE;

    void initKey();

    public :

    CaesarEncrypter();

    string encrypt(const string &msg);

    caesarKeyType getKey();

};
