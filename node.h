#pragma once

struct Node {
    char character;
    int freq;
    Node* left;
    Node* right;

    Node(char character_, int freq_) {
        character = character_;
        freq = freq_;
    }
};