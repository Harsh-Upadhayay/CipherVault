#include <iostream>
#include <vector>
#include <string>
#include "PlayFairDecrypter.h"
using namespace std;


vector<pair<char, char>> PlayFairDecrypter :: createPair(const string &s) {
    vector<pair<char, char>> pairs;

    int it = 0;
    while(it < s.size() - 1) {

        pair<char, char> curPair;

        if(s[it] == s[it + 1])
            curPair = {s[it], slackChar},
            it++;
        else
            curPair = {s[it], s[it + 1]},
            it += 2;

        pairs.push_back(curPair);
    }     

    if(it == s.size() - 1)
        pairs.push_back({s[it], slackChar});
    
    return pairs;
}

PlayFairDecrypter :: PlayFairDecrypter(pfKeyType key) : 
KEY_SIZE_V (key.size()),  KEY_SIZE_H (key[0].size()) {    

    initKey(key);

}

void PlayFairDecrypter :: initKey(pfKeyType key) {

    this -> key = key;
    createCharMap();
}

void PlayFairDecrypter :: createCharMap() {

    vector<vector<int>> tmap(KEY_SIZE_H * KEY_SIZE_V, vector<int>(2, -1));

    for(int i = 0; i < KEY_SIZE_V; i++) {
        for(int j = 0; j < KEY_SIZE_H; j++) {

            tmap[iChar(key[i][j])][0] = i, 
            tmap[iChar(key[i][j])][1] = j; 

        }
    }

    charMap = tmap;
}

void PlayFairDecrypter :: displayKey() {

    for(auto x : key) {
        for(char y : x)
            cout << y << " ";
        cout << "\n";
    }


    cout << "__________\n";

    // for(int i = 0; i < 26; i++) 

    //     cout << cInt(i) << ": " << charMap[i][0] << " " << charMap[i][1] << "\n";


}

void PlayFairDecrypter :: displayPairs(const string &msg) {
    
    auto ps = createPair(msg);
    for(auto x : ps)
        cout << x.first << " " << x.second << "\n";

}

string PlayFairDecrypter :: remSlackChar(const string &msg) {

    string cleanStr;

    for(char ch : msg) if(ch != slackChar) cleanStr += ch;

    return cleanStr;
}

string PlayFairDecrypter :: decrypt(const string &msg) {


    string decryptedMsg = "";
    auto pairs = createPair(msg);

    for(auto it : pairs) {

        char a = iChar(it.first),
                b = iChar(it.second);
        
        int ra = charMap[a][0],
            ca = charMap[a][1],
            rb = charMap[b][0],
            cb = charMap[b][1];

        if(ra == rb) {
            decryptedMsg += (key[ra][(ca - 1 + KEY_SIZE_H) % KEY_SIZE_H]),
            decryptedMsg += (key[rb][(cb - 1 + KEY_SIZE_H) % KEY_SIZE_H]);
        }
        else if(ca == cb) {
            decryptedMsg += (key[(ra - 1 + KEY_SIZE_V) % KEY_SIZE_V][ca]),
            decryptedMsg += (key[(rb - 1 + KEY_SIZE_V) % KEY_SIZE_V][cb]);
        }
        else {
            decryptedMsg += (key[ra][cb]),
            decryptedMsg += (key[rb][ca]);
        }
    }

    return remSlackChar (decryptedMsg);
}
