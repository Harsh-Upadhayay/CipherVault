#include <iostream>
#include <time.h>
#include <string>
#include <math.h>
#include "AffineEncrypter.h"
#include <cstdlib>
using namespace std;

int AffineEncrypter :: gcd(int a, int b)
{
    if (a == 0)
       return b;
    if (b == 0)
       return a;
  
    if (a == b)
        return a;
  
    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}

void AffineEncrypter :: initKey() {

    key.second = rand() % KEY_SIZE;
    key.first = 1 + rand() % 128;
    while(gcd(KEY_SIZE, key.first) != 1)
        key.first = 1 + rand() % 128;

}


AffineEncrypter :: AffineEncrypter() : KEY_SIZE(128) {
    initKey();
}

string AffineEncrypter :: encrypt(const string &msg)  {
    string encrypted = "";
    int a = key.first,
        b = key.second;
    for (char ch : msg)
        encrypted += cInt(((a * iChar(ch)) + b) % KEY_SIZE);
    
    return encrypted;
}

AffineEncrypter :: affineKeyType AffineEncrypter :: getKey() {

    return key;

}


