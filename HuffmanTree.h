#include "node.h"
#include <iostream>

#include <map>
#include <string>
#include <queue>
#include <vector>

using namespace std;
#pragma once

struct HuffmanTree {
    Node* root;
    map<char, int> codeMap;

    HuffmanTree(map<char, int> codeMap_) {
        codeMap = codeMap_;
    }

    struct Compare {
        bool operator()(Node* n1, Node* n2) {
            return n1->freq > n2->freq;
        }
    };

    void buildMinHeap() {
        priority_queue<Node*, vector<Node*>, Compare> pq;
        for (const auto& pair : codeMap) {
            Node* newNode = new Node(pair.first, pair.second);
            pq.push(newNode);
        }

         while (pq.size() > 1) {
             Node* temp1 = pq.top();
             pq.pop();
             Node* temp2 = pq.top();
             pq.pop();
             Node* parent = new Node('0', temp1->freq + temp2->freq);
             parent->left = temp1;
             parent->right = temp2;
             pq.push(parent);
         }
    }
};