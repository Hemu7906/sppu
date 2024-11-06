#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char character, int frequency) {
        ch = character;
        freq = frequency;
        left = right = nullptr;
    }
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq; 
    }
};

void generateCodes(Node* root, string code, unordered_map<char, string>& huffmanCodes) {
    if (!root) return;

    if (!root->left && !root->right) {
        huffmanCodes[root->ch] = code;
    }

    generateCodes(root->left, code + "0", huffmanCodes);
    generateCodes(root->right, code + "1", huffmanCodes);
}

unordered_map<char, string> huffmanCoding(const unordered_map<char, int>& frequencies) {
    priority_queue<Node*, vector<Node*>, Compare> minHeap;

    for (const auto& entry : frequencies) {
        minHeap.push(new Node(entry.first, entry.second));
    }

    while (minHeap.size() > 1) {
        Node *left = minHeap.top(); minHeap.pop();
        Node *right = minHeap.top(); minHeap.pop();

        int sumFreq = left->freq + right->freq;
        Node* newNode = new Node('\0', sumFreq);
        newNode->left = left;
        newNode->right = right;

        minHeap.push(newNode);
    }

    Node* root = minHeap.top();

    unordered_map<char, string> huffmanCodes;
    generateCodes(root, "", huffmanCodes);

    return huffmanCodes;
}

int main() {
    unordered_map<char, int> frequencies = {
        {'a', 5}, {'b', 9}, {'c', 12}, {'d', 13}, {'e', 16}, {'f', 45}
    };

    unordered_map<char, string> huffmanCodes = huffmanCoding(frequencies);
    cout << "Huffman Codes:\n";
    for (const auto& entry : huffmanCodes) {
        cout << entry.first << " : " << entry.second << endl;
    }

    return 0;
}
