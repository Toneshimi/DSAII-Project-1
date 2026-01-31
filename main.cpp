#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include "Vigenere.hpp"
#include "HashTable.hpp"
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
    //Test case for Vigenere cipher
    /*Vigenere cipher("jones");

    string test = "abcdefghi";
    string result = cipher.encrypt(test);

    cout << "Input: " << test << endl;
    cout << "Expected Output: jpphwouum" << endl;
    cout << "Actual Output: " << result << endl;

    if (result == "jpphwouum") {
        cout << "Test passed!" << endl;
    } else {
        cout << "Test failed!" << endl;
    }
        */

    ifstream inFile("names.txt"); //Change to names.txt for final run
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

    ifstream testFile("rawdata.txt");
    if(!testFile) {
        cerr << "Error: Unable to open rawdata.txt" << endl;
        return 1;
    }

    string testUserId[5];
    string testPassword[5];

    string tempUserId;
    string tempPassword;

    int lineNum = 0;
    int testIndex = 0;

    while (testFile >> tempUserId >> tempPassword) {
        lineNum++;
        if (lineNum == 1 || lineNum == 3 || lineNum == 5 || lineNum == 7 || lineNum == 9) {
            testUserId[testIndex] = tempUserId;
            testPassword[testIndex] = tempPassword;
            testIndex++;
        }
    }

    testFile.close();

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


    
    //cout << "About to read rawdata.txt" << endl;

    while(rawFile >> userId >> password) {
        string encryptedPassword = cipher.encrypt(password);
        encryptedFile << userId << " " << encryptedPassword << endl;
        //cout << userId << " " << encryptedPassword << endl;
    }

    //cout << "Finished reading rawdata.txt" << endl;

    rawFile.close();
    encryptedFile.close();

    cout << "Passwords encrypted and saved to encrypteddata.txt" << endl;

    HashTable hashTable;

    ifstream encryptedFileIn("encrypteddata.txt");
    if(!encryptedFileIn) {
        cerr << "Error: Unable to open encrypteddata.txt" << endl;
        return 1;
    }

    string userIdEnc;
    string encryptedPassword;

    while(encryptedFileIn >> userIdEnc >> encryptedPassword) {
        hashTable.insert(userIdEnc, encryptedPassword);
    }
    encryptedFileIn.close();

    cout << "Data inserted into hash table." << endl;


    /* Test search functionality 
    string found = hashTable.search("SMITH");
    
    if(found != "") {
        cout << "Password for SMITH: " << found << endl;
    } else {
        cout << "User ID SMITH not found." << endl;
    }
    */
    

    //Legal test cases
    cout << "\nLegal: " << endl;
    cout << left << setw(15) << "UserID"
            << setw(18) << "Password(file)"
            << setw(20) << "Password(table/un)"
            <<"Result" << endl;
            

    for (int i = 0; i < 5; i++) {
        string encryptedModified = cipher.encrypt(testPassword[i]);
        string encryptedFromTable = hashTable.search(testUserId[i]);

        string result = (encryptedModified == encryptedFromTable) ? "Match" : "No Match";

        cout << left << setw(15) << testUserId[i]
             << setw(18) << testPassword[i]
             << setw(20) << testPassword[i]
             << result << endl;
    }
    
    //illegal test case
    cout << "\nIllegal: " << endl;
    cout << left << setw(15) << "UserID"
            << setw(18) << "Password(mod)"
            << setw(20) << "Password(table/un)"
            <<"Result" << endl;

    for(int i = 0; i < 5; i++) {
        string modifiedPassword = testPassword[i];
        modifiedPassword[0] = (modifiedPassword[0] == 'a') ? 'b' : 'z'; // Change first character

        string encryptedModified = cipher.encrypt(modifiedPassword);
        string encryptedFromTable = hashTable.search(testUserId[i]);
        string result = (encryptedModified == encryptedFromTable) ? "Match" : "No Match";

        cout << left << setw(15) << testUserId[i]
             << setw(18) << modifiedPassword
             << setw(20) << testPassword[i]
             << result << endl;
    }

    return 0;
}
