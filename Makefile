
CXX=clang++ $(CXXFLAGS)
CXXFLAGS=-Wall -O2 # Enable all warnings
DEBUG=-g

OBJECTS = hashTable.o getWordInGrid.o wordPuzzle.o primenumber.o timer.o

a.out: $(OBJECTS)
	$(CXX) $(DEBUG) $(OBJECTS) -o a.out

hashTable.o: hashTable.cpp
	$(CXX) -c hashTable.cpp

getWordInGrid.o: getWordInGrid.cpp
	$(CXX) -c getWordInGrid.cpp

wordPuzzle.o: wordPuzzle.cpp
	$(CXX) -c wordPuzzle.cpp

primenumber.o: primenumber.cpp
	$(CXX) -c primenumber.cpp

timer.o: timer.cpp
	$(CXX) -c timer.cpp

.PHONY: clean
clean:
	-rm -f *.o *~ a.out

wordPuzzle.o: wordPuzzle.cpp timer.h hashTable.h
primenumber.o: primenumber.cpp
hashTable.o: hashTable.cpp hashTable.h
getWordInGrid.o: getWordInGrid.cpp
timer.o: timer.cpp timer.h