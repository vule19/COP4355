#pragma once

#include <string>

using namespace  std;

struct Node {
    char character;
    int freq;
    Node* left = nullptr;
    Node* right = nullptr;
    string code = "";

    Node(char character_, int freq_) {
        character = character_;
        freq = freq_;
    }
};