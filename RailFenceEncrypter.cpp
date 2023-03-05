#include <iostream>
#include <vector>
#include "RailFenceEncrypter.h"

using namespace std;

void RailFenceCipherEncrypter ::initKey()
{
    // key = rand() % KEY_SIZE;
    key = 3;
}

RailFenceCipherEncrypter ::RailFenceCipherEncrypter() : KEY_SIZE(128)
{
    initKey();
}

void RailFenceCipherEncrypter::StoreChars(string msg)
{
    vector<vector<char>> tmp(key);

    int i = 0;

    int turn = 0;

    for (auto it : msg)
    {

        if (!turn)
        {
            tmp[i++].push_back(it);
            if (i == key)
            {
                i = key - 2;
                turn = 1;
            }
        }
        else
        {
            tmp[i--].push_back(it);
            if (i < 0)
            {
                i = 1;
                turn = 0;
            }
        }
    }

    store = tmp;
}

string RailFenceCipherEncrypter ::encrypt(const string &msg)
{
    string encrypted = "";

    StoreChars(msg);

    for (auto it : store)
    {
        for (auto i : it)
        {
            encrypted.push_back(i);
        }
    }

    return encrypted;
}

RailFenceCipherEncrypter ::RailFenceKeyType RailFenceCipherEncrypter ::getKey()
{
    return key;
}
