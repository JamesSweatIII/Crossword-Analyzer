#ifndef HASHTABLE_H // include guards to avoid redefinition
#define HASHTABLE_H

#include <iostream>
#include <vector>
#include <string>
#include <list> // for the linked lists

using namespace std; 

class hashTable{
  
public:
    // Constructor
    hashTable(int s);

    // Insert a string into the hash table
    void insert(string x);

    // Check if a string is in the hash table
    bool find(string x);

    // Vector of linked lists that will store our strings
    vector< list<string> > table;

private:
    int tableSize; // The number of linked lists to create

    // Hash function to map a string to an index in our table vector
    int tableFunc(string x);
};

#endif
