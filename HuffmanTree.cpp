#include "node.cpp";

#include <map>
#include <string>
#include <queue>
#include <vector>

using namespace std;

class HuffmanTree {
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
        for (int i = 0; i < codeMap.size(); i++) {
            Node* newNode = new Node(codeMap[i]->first, codeMap[i].second);
            pq.push(newNode);
        }

        while (pq.size() > 1) {
            Node* temp1 = pq.top();
            pq.pop();
            Node* temp2 = pq.top();
            pq.pop();
            Node* parent = new Node(temp1->char + temp2->char, temp1->freq + temp2->freq);
            parent->left = temp1;
            parent->right = temp2;
        }
    }
};