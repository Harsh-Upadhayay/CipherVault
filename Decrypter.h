/**
 * @file Decrypter.h
 * @author Harsh Upadhayay
 * @brief Abstract class for Decrypter
 * @version 0.1
 * @date 2023-03-04
 * 
 */

#ifndef __DECRYPTER_H__
#define __DECRYPTER_H__

#include "Cipher.h"
using namespace std;

class Decrypter : protected Cipher{

    public :

    /**
     * @brief Decrypts the input string
     * 
     * @param s cipher text
     * @return decrypted text 
     */
    virtual string decrypt(const string &s) = 0;
};  

#endif