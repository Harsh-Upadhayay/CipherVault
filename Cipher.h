/**
 * @file cipher.h
 * @author Harsh Upadhayay
 * @brief Abstract class for ciphers types declaration.
 * @version 0.1
 * @date 2023-03-04
 *
 */

#ifndef __CIPHER_H__
#define __CIPHER_H__

#include <vector>
using namespace std;

class Cipher {
   protected:
    /**
     * @brief converts character to its equivalent ASCII-128 code.
     *
     * @param x char
     * @return int
     */
    int inline iChar(char x) { return x; }

    /**
     * @brief converts ASCII-128 code to its equivalent character.
     *
     * @param x int
     * @return char
     */
    char inline cInt(int x) { return x; }

    typedef vector<vector<char>> pfKeyType;
    typedef int caesarKeyType;
    typedef int RailFenceKeyType;
    typedef vector<vector<int>> hillKeyType;
    typedef vector<int> storeVec;
    typedef pair<int, int> affineKeyType;

   public:
    enum type {
        PLAY_FAIR_CIPHER,
        Caesar_CIPHER,
        Hill_CIPHER,
        VERNAM_CIPHER,
        VIGENERE_CIPHER,
        RAIL_FENCE_CIPHER,
        TRANSPOSITIONAL_CIPHER
    };

    Cipher() {}
};

#endif