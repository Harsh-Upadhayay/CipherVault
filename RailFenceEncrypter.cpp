#include <iostream>
#include <vector>
#include "RailFenceEncrypter.h"

using namespace std;

void RailFenceCipherEncrypter ::initKey()
{
    key = rand() % KEY_SIZE;
}

RailFenceCipherEncrypter ::RailFenceCipherEncrypter() : KEY_SIZE(128)
{
    initKey();
}

void RailFenceCipherEncrypter::StoreChars(string msg)
{
    vector<vector<char>> tmp(key, vector<char>(msg.size()));

    for (int i = 0; i < key; i++)
    {
        for (int j = 0; j < msg.length(); j++)
        {
            tmp[i][j] = '\n';
        }
    }

    bool dir_down = false;
    int row = 0, col = 0;

    for (int i = 0; i < msg.length(); i++)
    {

        if (row == 0 || row == key - 1)
        {
            dir_down = !dir_down;
        }
        tmp[row][col++] = msg[i];
        dir_down ? row++ : row--;
    }

    store = tmp;
}

string RailFenceCipherEncrypter ::encrypt(const string &msg)
{
    string encrypted = "";

    StoreChars(msg);

    for (int i = 0; i < key; i++)
    {
        for (int j = 0; j < msg.length(); j++)
        {
            if (store[i][j] != '\n')
            {
                encrypted.push_back(store[i][j]);
            }
        }
    }
    return encrypted;
}

RailFenceCipherEncrypter ::RailFenceKeyType RailFenceCipherEncrypter ::getKey()
{
    return key;
}
