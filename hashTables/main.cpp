#include "hashtable.h"

int main() {
    HashTable hashTable(1000);
    hashTable.insert("John", 99);
    hashTable.remove("John");
    hashTable.insert("John", 99);
    hashTable.insert("Jack", 99);
    hashTable.insert("Harry", 99);
    std::cout << hashTable["Harry"];


    return 0;
}