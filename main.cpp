#include <iostream>
#include <string>
#include <map>
#include <fstream>

#include "HuffmanTree.h"

using namespace std;

map<char, int> buildCodeMap(string inputText) {
    map<char, int> codeMap;
    for (char i : inputText) {
        codeMap[i]++;
    }
    return codeMap;
}

int main() {

    ifstream inputFile("input.txt");
    
    if (!inputFile.is_open()) {
        cout << "Error: Could not open input.txt" << endl;
        return 1;
    }
    
    // Reads the contents of the file
    string inputText;
    string line;
    while (getline(inputFile, line)) {
        inputText += line;
        if (!inputFile.eof()) {
            inputText += '\n';
        }
    }
    
    inputFile.close();

    map<char, int> codeMap = buildCodeMap(inputText);

    // Builds Huffman Tree from user input
    HuffmanTree huffman(codeMap);
    huffman.buildMinHeap();

    // Prints out prefix codes
    cout << "Here are your codes: " << endl;
    for (auto& pair : huffman.encodeMap) {
        cout << "'" << pair.first << "': " << pair.second << endl;
    }

    // Determines and prints encoded text
    string encodedText = "";
    for (char c : inputText) {
        encodedText += huffman.encodeMap[c];
    }
    
    cout << "Encoded text: " << encodedText << endl;

    return 0;
} 

