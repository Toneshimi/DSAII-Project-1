#include <iostream>
#include "Vigenere.hpp"
using namespace std;

int main() {
    //Test case for Vigenere cipher
    Vigenere cipher("jones");

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

    return 0;
}
