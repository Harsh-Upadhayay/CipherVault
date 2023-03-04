#include <iostream>
#include "CaesarEncrypter.h"
using namespace std;



void CaesarEncrypter :: initKey() {

    key = rand() % KEY_SIZE;

}


CaesarEncrypter :: CaesarEncrypter() : KEY_SIZE(128) {
    initKey();
}

string CaesarEncrypter :: encrypt(const string &msg) {
    
    string encryptedMsg = "";

    for(char ch : msg) 
        
        encryptedMsg += (char)((ch + key) % KEY_SIZE);

    return encryptedMsg;
}

CaesarEncrypter :: caesarKeyType CaesarEncrypter :: getKey() {

    return key;

}


