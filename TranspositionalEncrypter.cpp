#include "TranspositionalEncrypter.h"

#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

void TranspositonalEncrypter::initKey() {
    unordered_map<int, int> mp;
    int size = (rand() % (SIZE)) + SIZE;
    for (int i = 0; i < size; i++) {
        int key_idx = rand() % ALPHABETS;
        if (mp.find(key_idx) == mp.end()) {
            key.push_back(key_idx);
            mp[key_idx]++;
        }
    }
}

TranspositonalEncrypter::TranspositonalEncrypter() : KEY_SIZE(128) {
    initKey();
}

string TranspositonalEncrypter::breakMessage(string message) {
    string plainText = "";
    stringstream ss(message);
    string word;
    while (ss >> word) {
        plainText += word, plainText += "_";
    }
    plainText.pop_back();
    return plainText;
}

vector<string> TranspositonalEncrypter::readRowWise(string plainText, int rows,
                                                    int columns,
                                                    int message_size) {
    int itr = 0;
    vector<string> encryption;
    for (int i = 0; i < rows; i++) {
        string tmp = "";
        for (int i = 0; i < columns; i++) {
            if (itr < message_size) {
                tmp.push_back(plainText[itr]);
                itr++;
            } else {
                tmp.push_back('#');
            }
        }
        encryption.push_back(tmp);
    }
    return encryption;
}

vector<string> TranspositonalEncrypter::sendColumnWIse(
    vector<string> encryption, int columns, int rows) {
    vector<string> tmp;
    for (int i = 0; i < columns; i++) {
        string str = "";
        for (int j = 0; j < rows; j++) {
            str += encryption[j][i];
        }
        tmp.push_back(str);
    }
    return tmp;
}

string TranspositonalEncrypter::encrypt(const string &message) {
    string plainText = breakMessage(message);

    int sizeKey = key.size();
    int columns = sizeKey;
    int message_size = plainText.size();
    int rows = message_size / sizeKey;
    if (message_size % sizeKey != 0) {
        rows++;
    }

    vector<string> encryption =
        readRowWise(plainText, rows, columns, message_size);

    vector<string> tmp = sendColumnWIse(encryption, columns, rows);
    map<int, string> tupple;
    for (int i = 0; i < sizeKey; i++) {
        tupple.insert({key[i], tmp[i]});
    }

    string sendCipher = "";
    for (auto it : tupple) {
        sendCipher += it.second;
        sendCipher += " ";
    }
    return sendCipher;
}

TranspositonalEncrypter::storeVec TranspositonalEncrypter ::getKey() {
    return key;
}
