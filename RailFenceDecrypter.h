#include <iostream>
#include <vector>
#include "Decrypter.h"

using namespace std;

class RailFenceCipherDecrypter final : public Decrypter
{
    RailFenceKeyType key;

    vector<vector<char>> store;

    const int KEY_SIZE;

    void initKey(RailFenceKeyType key);

    void createStore(string msg, int size);

public:
    RailFenceCipherDecrypter(RailFenceKeyType key);

    string decrypt(const string &s);
};