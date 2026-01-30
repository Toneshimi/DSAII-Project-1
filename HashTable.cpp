#include "HashTable.hpp"

HashTable::HashTable() {
    for(int i = 0; i < SIZE; i++) {
        table[i] = nullptr;
    }
}

HashTable::~HashTable() {
    for(int i = 0; i < SIZE; i++) {
        Node* current = table[i];
        while(current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
}

int HashTable::hashFunction(string key) {
    int sum = 0;
    for(int i = 0; i < key.length(); i++) {
        sum += key[i];
    }
    return sum % SIZE;
}

void HashTable::insert(string userId, string password) {
    int index = hashFunction(userId);

    Node* newNode = new Node;
    newNode->userId = userId;
    newNode->password = password;
    newNode->next = table[index];

    table[index] = newNode;
}

string HashTable::search(string userId) {
    int index = hashFunction(userId);
    Node* current = table[index];

    while(current != nullptr) {
        if(current->userId == userId) {
            return current->password;
        }
        current = current->next;
    }
    return ""; // Return empty string if userId not found
}


