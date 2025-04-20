CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

all: huffman

huffman: main.cpp HuffmanTree.h node.h
	$(CXX) $(CXXFLAGS) main.cpp -o huffman

clean:
	rm -f huffman