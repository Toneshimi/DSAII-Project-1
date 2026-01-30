#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Vigenere.hpp"
using namespace std;

string generatePassword() {
    string password = "";
    for(int i = 0; i < 9; i++) {
        int randomNum = rand() % 26;
        char letter = 'a' + randomNum;
        password += letter;
    }

    return password;
}

int main() {
    ifstream inFile("names_test.txt");
    ofstream outFile("rawdata.txt");

    if(!inFile) {
        cerr << "Error: Unable to open names.txt" << endl;
        return 1;
    }

    string name;
    string restOfLine;

    while(inFile >> name) {
        getline(inFile, restOfLine);
        string password = generatePassword();
        outFile << name << " " << password << endl;
    }


    inFile.close();
    outFile.close();

    cout << "Passwords generated and saved to rawdata.txt" << endl;

    ifstream rawFile("rawdata.txt");
    ofstream encryptedFile("encrypteddata.txt");
    if(!rawFile) {
        cerr << "Error: Unable to open rawdata.txt" << endl;
        return 1;
    }

    Vigenere cipher("jones");

    string userId;
    string password;

    cout << "About to read rawdata.txt" << endl;

    while(rawFile >> userId >> password) {
        string encryptedPassword = cipher.encrypt(password);
        encryptedFile << userId << " " << encryptedPassword << endl;
        cout << userId << " " << encryptedPassword << endl;
    }

    cout << "Finished reading rawdata.txt" << endl;

    rawFile.close();
    encryptedFile.close();

    cout << "Passwords encrypted and saved to encrypteddata.txt" << endl;

    return 0;
}
