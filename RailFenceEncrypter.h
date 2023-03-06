#include <vector>
#include "Encrypter.h"

using namespace std;

class RailFenceCipherEncrypter final : public Encrypter
{
    vector<vector<char>> store;
    RailFenceKeyType key;

    const int KEY_SIZE;

    void StoreChars(string msg);

    void initKey();

public:
    RailFenceCipherEncrypter();

    string encrypt(const string &msg);

    RailFenceKeyType getKey();
};