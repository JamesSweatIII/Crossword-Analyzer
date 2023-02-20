// Import necessary libraries
#include <iostream>
#include <fstream>
#include <string>
#include "timer.h"
#include "hashTable.h"

using namespace std;

// Function to read in a grid of letters from a file
bool readInGrid(string filename, int& rows, int& cols);

// Function to retrieve a word in the grid given a starting position, direction, and length
string getWordInGrid(int startRow, int startCol, int dir, int len, int numRows, int numCols);

// Function to calculate the next prime number greater than a given integer
int getNextPrime(unsigned int n);

// Variable to keep track of the number of lines in the input file
int numoflines;

/** Function to read in the dictionary file and insert its words into a hash table
 * @return true or false, depending on whether the file was successfully opened
 * @param filename The file name to read in -- the file format: .txt
 * @param dictionary The grid name to read in -- the file format: .grid.txt
 */
bool printWord(string filename, hashTable &dictionary){

	// Variable to keep track of the current line in the input file
    string line;

    // Open the dictionary file for reading
    ifstream file(filename);

    // If the file could not be opened, print an error message and return false
    if (!file.is_open()) {
        cout << "File was not opened" << endl;
        return false;
    }

    // Count the number of lines in the file
    while (getline(file, line)) {
        numoflines++; 
    }

    // Reset the file position to the beginning
    file.clear();
    file.seekg(0);

    // Read each word from the file and insert it into the hash table
    while (numoflines > 0){
        string data;
        file >> data;
        dictionary.insert(data);
        numoflines--;
    }

    // Close the file
    file.close();

    // Return true to indicate success
    return true;   
}



int main(int argc, char *argv[]) {

// Start the timer
timer timer;
timer.start();

// Initialize variables to keep track of word count, grid dimensions, and hash table size
int wordcount = 0;
int rows, cols;
int tableSize = 0;

// Read in the grid dimensions and allocate space for the hash table
readInGrid(argv[2], rows, cols);
tableSize = getNextPrime((rows + cols) * 2);
hashTable dictionary(tableSize);

// Populate the hash table with words from the dictionary file
printWord(argv[1], dictionary);

// Define an array of directions for word searching
string direction[8] = {"N", "NE", "E", "SE", "S", "SW", "W", "NW"};

// Iterate over each position in the grid and for each position iterate over each direction and word length to find words
for (int a = 0; a <= rows; a++) {
	for (int b = 0; b <= cols; b++){
		for (int c = 0; c <= 7; c++) {
			for (int d = 3; d <= 22; d++) {

				// Variable to keep track of the word in the grid we are searching for
				string check = (getWordInGrid(a,b,c,d,rows,cols));

				// Check if the word is in the hash table and print it to the console if it is
				if(dictionary.find(check)){
					cout << direction[c] << " " << "(" << a << ", " << b << "): " << check << endl;
					wordcount++;
				}

				// If the next word length is the same as the current, skip it to avoid duplicates
				if(getWordInGrid(a,b,c,d+1,rows,cols) == check)
					break;
			}
		}
	}
}

// Print out the total number of words found and the elapsed time
cout << wordcount << " words found" << endl;
timer.stop();
cout << "Found all words in " << timer.getTime() << " seconds" << endl;
return 0;
}
