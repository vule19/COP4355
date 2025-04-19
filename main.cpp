#include <iostream>
#include <string>
#include <map>

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
    cout << "Enter the text that you want to encode:" << endl;
    string inputText;
    cin >> inputText;

    map<char, int> codeMap = buildCodeMap(inputText);

    cout << "Here is your code: " << endl;

    HuffmanTree huffman(codeMap);
    huffman.buildMinHeap();

    for (auto& pair : codeMap) {
        cout << huffman.encodeMap[pair.first];
    }

    return 0;
}