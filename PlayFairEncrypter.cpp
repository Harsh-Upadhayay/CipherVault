#include <iostream>
#include <vector>
#include "PlayFairEncrypter.h"

using namespace std;


void PlayFairEncrypter :: putInKey(char ch) {
    
    int r  = rand() % KEY_SIZE_V;
    int c = rand() % KEY_SIZE_H;

    while(key[r][c] != '-')
        r  = rand() % KEY_SIZE_V,
        c  = rand() % KEY_SIZE_H;
    
    key[r][c] = ch;
}

void PlayFairEncrypter :: createKey() {

    vector<char> initCol(KEY_SIZE_H, '-');
    for(int i = 0; i < KEY_SIZE_V; i++) 
        key.push_back(initCol);

    for(int ch = 0; ch < (KEY_SIZE_H * KEY_SIZE_V); ch++) 

        putInKey(ch);


}

void PlayFairEncrypter :: createCharMap() {

    vector<vector<int>> tmap(KEY_SIZE_H * KEY_SIZE_V, vector<int>(2, -1));

    for(int i = 0; i < KEY_SIZE_V; i++) {
        for(int j = 0; j < KEY_SIZE_H; j++) {

            tmap[iChar(key[i][j])][0] = i, 
            tmap[iChar(key[i][j])][1] = j; 

        }
    }

    charMap = tmap;
}

void PlayFairEncrypter :: initKey() {
    
    createKey();
    createCharMap();

}

vector<pair<char, char>> PlayFairEncrypter :: createPair(const string &msg) {
    
    vector<pair<char, char>> pairs;

    int it = 0;
    while(it < msg.size() - 1) {

        pair<char, char> curPair;

        if(msg[it] == msg[it + 1])
            curPair = {msg[it], slackChar},
            it++;
        else
            curPair = {msg[it], msg[it + 1]},
            it += 2;

        pairs.push_back(curPair);
    }     

    if(it == msg.size() - 1)
        pairs.push_back({msg[it], slackChar});
    
    return pairs;
}

PlayFairEncrypter :: PlayFairEncrypter() {
    initKey();
}

void PlayFairEncrypter :: displayKey() {

    for(auto x : key) {
        for(char y : x)
            cout << y << " ";
        cout << "\n";
    }


    cout << "__________\n";

}

void PlayFairEncrypter :: displayPairs(const string &s) {
    
    auto ps = createPair(s);
    for(auto x : ps)
        cout << x.first << " " << x.second << "\n";

}

string PlayFairEncrypter :: encrypt(const string &msg) {

    string encryptedMsg = "";
    auto pairs = createPair(msg);

    for(auto it : pairs) {

        char a = iChar(it.first),
                b = iChar(it.second);
        
        int ra = charMap[a][0],
            ca = charMap[a][1],
            rb = charMap[b][0],
            cb = charMap[b][1];

        if(ra == rb) {
            encryptedMsg += (key[ra][(ca + 1) % KEY_SIZE_H]),
            encryptedMsg += (key[rb][(cb + 1) % KEY_SIZE_H]);
        }
        else if(ca == cb) {
            encryptedMsg += (key[(ra + 1) % KEY_SIZE_V][ca]),
            encryptedMsg += (key[(rb + 1) % KEY_SIZE_V][cb]);
        }
        else {
            encryptedMsg += (key[ra][cb]),
            encryptedMsg += (key[rb][ca]);
        }
    }

    return encryptedMsg;
}

PlayFairEncrypter :: pfKeyType PlayFairEncrypter :: getKey() {
    
    return key;
}

