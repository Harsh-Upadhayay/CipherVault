/**
 * @file Encrypter.h
 * @author Harsh Upadhayay
 * @brief Abstract Encrypter class.
 * @version 0.1
 * @date 2023-03-04
 * 
 */

# ifndef __ENCRYPTER_H__
# define __ENCRYPTER_H__

#include "Cipher.h"
#include <time.h>
using namespace std;

class Encrypter : protected Cipher{

    protected :

    /**
     * @brief Randomly initializes key of the cipher.
     * 
     */
    virtual void initKey() = 0;

    public :
    
    Encrypter() {
        srand(time(0));
    }

    /**
     * @brief Converts plain text to cipher 
     * 
     * @param s plain text 
     * @return cipher text 
     */
    virtual string encrypt(const string &s) = 0;
};  

# endif