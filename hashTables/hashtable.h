#ifndef HASHTABLE_HASHTABLE_H
#define HASHTABLE_HASHTABLE_H
#include <iostream>
#include <string.h>
class HashTable{
private:
    int *avg;
    int length;

    int hash(const std::string);

public:
    HashTable(int);
    ~HashTable();
    void insert(const std::string, int avg);
    void remove(const std::string);
    int operator[](const std::string);
    void operator=(int);
};

HashTable::HashTable(int size) {
    avg = new int[size];
    length = size;
}

HashTable::~HashTable() {
    delete this->avg;
}

int HashTable::hash(const std::string NAME) {
    unsigned int hashValue = 0;
    for (char c : NAME) {
        hashValue += static_cast<unsigned int>(c);
    }
    return hashValue % length;
}

void HashTable::insert(const std::string NAME, int gpa){
    avg[hash(NAME)] = gpa;
}

void HashTable::remove(const std::string NAME) {
    avg[hash(NAME)] = 0;
}

int HashTable::operator[](const std::string NAME){
    return avg[hash(NAME)];
}

#endif //HASHTABLE_HASHTABLE_H
