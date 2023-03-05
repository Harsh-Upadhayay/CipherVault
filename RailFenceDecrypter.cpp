#include <iostream>
#include "RailFenceDecrypter.h"

using namespace std;

void RailFenceCipherDecrypter ::initKey(RailFenceKeyType key)
{
    this->key = key;
}

RailFenceCipherDecrypter ::RailFenceCipherDecrypter(RailFenceKeyType key) : KEY_SIZE(128)
{
    initKey(key);
}

void RailFenceCipherDecrypter::createStore(string msg, int size)
{
    vector<vector<char>> tmp(key, vector<char>(size));

    for (int i = 0; i < key; i++)
        for (int j = 0; j < size; j++)
            tmp[i][j] = '\n';

    bool dir_down;

    int row = 0, col = 0;
    for (int i = 0; i < size; i++)
    {

        if (row == 0)
            dir_down = true;
        if (row == key - 1)
            dir_down = false;

        tmp[row][col++] = '*';

        dir_down ? row++ : row--;
    }
    int index = 0;
    for (int i = 0; i < key; i++)
        for (int j = 0; j < size; j++)
            if (tmp[i][j] == '*' && index < size)
                tmp[i][j] = msg[index++];

    store = tmp;
}

string RailFenceCipherDecrypter ::decrypt(const string &msg)
{
    createStore(msg, msg.size());

    string org = "";

    bool dir_down;

    int row = 0, col = 0;
    for (int i = 0; i < msg.length(); i++)
    {

        if (row == 0)
            dir_down = true;
        if (row == key - 1)
            dir_down = false;

        if (store[row][col] != '*')
            org.push_back(store[row][col++]);

        dir_down ? row++ : row--;
    }

    return org;
}