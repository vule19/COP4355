#include <iostream>
#include <string>
#include <map>

#include "node.cpp"
#include "HuffmanTree.cpp"

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
    return 0;
}