#include <iostream>
#include "CaesarDecrypter.h"
using namespace std;

void CaesarDecrypter :: initKey(caesarKeyType key) {

    this -> key = key;

}

CaesarDecrypter :: CaesarDecrypter(caesarKeyType key) : KEY_SIZE(128) {

    initKey(key);

}

string CaesarDecrypter :: decrypt(const string &msg) {

    string decryptedMsg = "";

    for(char ch : msg) 
        decryptedMsg += (char)((ch - key + KEY_SIZE) % KEY_SIZE);

    return decryptedMsg;
}
