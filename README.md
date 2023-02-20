# Word Puzzle Solver
#### (Febuary 1, 2023)
#### James E. Sweat III

This program takes a word search puzzle and a list of words to find, and outputs the location of each word in the puzzle.

## Getting Started

To use this program, you will need to compile the C++ code using a C++ compiler.

### Prerequisites

- C++ compiler
- Access to terminal

### Installation

1. Clone this repository.

``` 
git clone https://github.com/JamesSweatIII/Word-Puzzle-Solver.git
```

2. Navigate to the project directory.

``` 
cd Word-Puzzle-Solver
```
3. Compile the program with Makefile.
``` 
Make
```
### Usage

```
./a.out wordlist_file grid_file
```
-  `wordlist_file` is the file containing the list of words to find. 
-  `grid_file` is the file containing the columns size, row size, and the word search puzzle.

Example:
``` 
./a.out wordlists/words.txt grids/3x3.grid.txt
```
`grids/3x3.grid.txt` contains:

``` 
3
3
obgyanjng
```

### Output

The program outputs the shortest path to the goal state and the number of steps. 

``` 
S (0, 1): ban
W (1, 2): nay
NE (2, 0): jag
N (2, 1): nab
4 words found
Found all words in 0.0158356 seconds
```
