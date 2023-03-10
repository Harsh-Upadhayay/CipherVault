#include "TranspositionalDecrypter.h"

#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

void TranspositonalDecrypter::initKey(storeVec key) { this->key = key; }

TranspositonalDecrypter::TranspositonalDecrypter(storeVec key) : KEY_SIZE(128) {
    initKey(key);
}

vector<string> TranspositonalDecrypter::readSeparateStrings(string cipherText) {
    vector<string> decryption;
    stringstream ss(cipherText);
    string word;
    while (ss >> word) {
        decryption.push_back(word);
    }
    return decryption;
}

string TranspositonalDecrypter::decrypt(const string &cipher) {
    int sizeKey = key.size();
    int columns = sizeKey;
    string cipherText = cipher;
    int cipher_size = cipherText.size();
    int rows = cipher_size / sizeKey;
    if (cipher_size % sizeKey != 0) {
        rows++;
    }

    vector<string> decryption = readSeparateStrings(cipherText);

    vector<int> tmpKey = key;
    sort(key.begin(), key.end());
    map<int, string> mp;
    for (int i = 0; i < sizeKey; i++) {
        mp.insert({key[i], decryption[i]});
    }

    vector<string> tmp;
    vector<pair<int, string>> tupple;
    for (int i = 0; i < sizeKey; i++) {
        tupple.push_back({tmpKey[i], mp[tmpKey[i]]});
    }
    key = tmpKey;

    int sz = tupple[0].second.size();
    vector<string> ans(sz, "");
    for (auto it : tupple) {
        string str = it.second;
        for (int i = 0; i < sz; i++) {
            ans[i] += str[i];
        }
    }

    string originalText = "";
    for (int i = 0; i < sz; i++) {
        originalText += ans[i];
    }

    string ansText = "";
    for (int i = 0; i < originalText.size(); i++) {
        if (originalText[i] == '_') {
            ansText += " ";
        } else if (originalText[i] == '#') {
            break;
        } else {
            ansText += originalText[i];
        }
    }
    return ansText;
}
