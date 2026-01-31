CXX = g++
CXXFLAGS = -Wall

TARGET = test
SRCS = main.cpp Vigenere.cpp HashTable.cpp
OBJS = main.o Vigenere.o HashTable.o

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp Vigenere.hpp HashTable.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp

Vigenere.o: Vigenere.cpp Vigenere.hpp
	$(CXX) $(CXXFLAGS) -c Vigenere.cpp

HashTable.o: HashTable.cpp HashTable.hpp
	$(CXX) $(CXXFLAGS) -c HashTable.cpp

clean:
	rm -f $(TARGET) $(OBJS)

