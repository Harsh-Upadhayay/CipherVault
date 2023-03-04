#include <iostream>
#include "Decrypter.h"
using namespace std;

class CaesarDecrypter final : public Decrypter { 

    caesarKeyType key;

    const int KEY_SIZE;

    void initKey(caesarKeyType key);

    public :

    CaesarDecrypter(caesarKeyType key);

    string decrypt(const string &msg);

};
