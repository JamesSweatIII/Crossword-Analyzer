#include "hashTable.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
using namespace std;

// Constructor initializes the table with a given size and creates empty linked lists
hashTable::hashTable(int size){
  tableSize =  size;
  list<string> book;
  for (int i = 0; i < tableSize; ++i) {
    table.push_back(book);
  }
}

// Function to calculate the hash value for the given string using FNV hash algorithm
int hashTable::tableFunc(string x){
  int index;

  uint32_t result = 2166136261u; // FNV-1a offset basis
  const char* data = x.c_str();
  for (size_t i = 0; i < x.length(); ++i)
  {
      result ^= static_cast<uint32_t>(data[i]); // XOR with current byte
      result *= 16777619u; // FNV-1a prime
  }
  index = result % tableSize;
  return index;
}

// Function to insert the given string into the hash table
void hashTable::insert(string x){
  int index = tableFunc(x);
  // Ignore strings with length less than 3
  if (x.length() >= 3) {
    table[index].push_back(x);
  }
}

// Function to find the given string in the hash table
bool hashTable::find(string x){
  int index = tableFunc(x);
  list<string>::iterator pages = table[index].begin();
  for (int i = 0; i < table[index].size(); ++i){
    // If string matches and it's not the end of the list, return true
    if(*pages == x && pages != table[index].end()){
      return true;
    }
    pages++;
  }
  // String not found
  return false;
}
