#include <vector>
#include "Decrypter.h"

using namespace std;

class PlayFairDecrypter final : public Decrypter { 
    
    
    const int KEY_SIZE_H,
              KEY_SIZE_V;
    const char slackChar = '-';
    
    pfKeyType key;
    vector<vector<int>> charMap;

    /**
     * @brief Create a list of pairs according to the rules of play fair cipher.
     * 
     * @param s string
     * @return vector<pair<char, char>> vector of created pairs.
     */
    vector<pair<char, char>> createPair(const string &s);

    /**
     * @brief Indexes key on the basis of characters.
     * 
     */
    void createCharMap();
    
    /**
     * @brief Initalize key
     * 
     * @param key 
     */
    void initKey(pfKeyType key);

    /**
     * @brief Removes slack character form the string
     * 
     * @param msg string with slack character.
     * @return string 
     */
    string remSlackChar(const string &msg);

    /**
     * @brief Displays key
     * 
     */
    void displayKey();

    /**
     * @brief Creates and displays pairs of input string
     * 
     * @param s 
     */
    void displayPairs(const string &s);

    public :

    /**
     * @brief Construct a new Play Fair Decrypter object
     * 
     * @param key 
     */
    PlayFairDecrypter(pfKeyType key) ;
    
    /**
     * @brief Decrypts the input string
     * 
     * @param s cipher text
     * @return decrypted text 
     */
    string decrypt(const string &msg);

};
