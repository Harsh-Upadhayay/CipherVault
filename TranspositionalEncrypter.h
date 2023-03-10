#include <iostream>

#include "Encrypter.h"
using namespace std;

class TranspositonalEncrypter final : public Encrypter {
    storeVec key;

    const int SIZE = 5;

    const int ALPHABETS = 26;

    const int KEY_SIZE;

    void initKey();

    string breakMessage(string msg);

    vector<string> readRowWise(string plainText, int rows, int columns,
                               int message_size);

    vector<string> sendColumnWIse(vector<string> encryption, int columns,
                                  int rows);

   public:
    TranspositonalEncrypter();

    string encrypt(const string &msg);

    storeVec getKey();
};