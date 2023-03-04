#include <vector>
#include "Encrypter.h"

using namespace std;

class PlayFairEncrypter final : public Encrypter { 
    
    const int KEY_SIZE_H = 16,
              KEY_SIZE_V = 8;
    const char slackChar = '-';
    
    pfKeyType key;
    vector<vector<int>> charMap;

    /**
     * @brief Places the input character at a random position in the key.
     * 
     * @param ch 
     */
    void putInKey(char ch);

    /**
     * @brief Create a random key.
     * 
     */
    void createKey();

    /**
     * @brief Indexex key on the basis of characters.
     * 
     */
    void createCharMap();

    /**
     * @brief Initalize key.
     * 
     */
    void initKey() ;

      /**
     * @brief Create a list of pairs according to the rules of play fair cipher.
     * 
     * @param s string
     * @return vector<pair<char, char>> vector of created pairs.
     */
    vector<pair<char, char>> createPair(const string &s);
    
    void displayKey();

    void displayPairs(const string &s);

    public :

    /**
     * @brief Construct a new Play Fair Encrypter object
     * 
     */
    PlayFairEncrypter();

    /**
     * @brief Converts plain text to cipher 
     * 
     * @param s plain text 
     * @return cipher text 
     */
    string encrypt(const string &msg);

    /**
     * @brief Get the Key object
     * 
     * @return pfKeyType 
     */
    pfKeyType getKey();

};
