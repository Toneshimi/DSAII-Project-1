#include "Vigenere.hpp"

Vigenere::Vigenere(string key) {
    this->key = key;
}

string Vigenere::encrypt(string plaintext){
    string encryptedText = "";

    for (int i = 0; i < plaintext.length(); i++) {
        char plainChar = plaintext[i];
        char keyChar = key[i % key.length()];

        int plainValue = plainChar - 'a';
        int keyValue = keyChar - 'a';

        int encryptedValue = (plainValue + keyValue) % 26;
        int encryptedChar = encryptedValue + 'a';

        encryptedText += encryptedChar;
    }

    return encryptedText;

}
