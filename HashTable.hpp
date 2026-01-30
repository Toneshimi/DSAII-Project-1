#ifndef HASHTABLE_HPP
#define HASTABLE_HPP

#include <string> 
using namespace std;

struct Node {
    string userId;
    string password;
    Node* next;
};

class HashTable {
    private:
        static const int SIZE = 101;
        Node* table[SIZE];
        int hashFunction(string key);
    
    public:
        HashTable();
        ~HashTable();
        void insert(string userId, string password);
        string search(string userId);
};

#endif // HASHTABLE_HPP
