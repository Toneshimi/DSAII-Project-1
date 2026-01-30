#ifndef VIGENERE_HPP
#define VIGENERE_HPP

#include <string> 
using namespace std;

class Vigenere {

    private:
        string key;

    public:
        Vigenere(string key);
        string encrypt(string plaintext);

};


#endif // VIGENERE_HPP