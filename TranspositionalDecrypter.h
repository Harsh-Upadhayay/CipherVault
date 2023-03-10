#include <iostream>

#include "Decrypter.h"
using namespace std;

class TranspositonalDecrypter final : public Decrypter {
    storeVec key;

    const int KEY_SIZE;

    void initKey(storeVec key);

    vector<string> readSeparateStrings(string cipherText);

   public:
    TranspositonalDecrypter(storeVec key);

    string decrypt(const string &msg);
};