#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Node {
    char ch;
    int freq;
    Node* left;
    Node* right;

    Node(char c, int f) : ch(c), freq(f), left(nullptr), right(nullptr) {}
};

void sortNodes(vector<Node*>& nodes) {
    for (int i = 0; i < nodes.size(); i++) {
        for (int j = i + 1; j < nodes.size(); j++) {
            if (nodes[i]->freq > nodes[j]->freq) {
                swap(nodes[i], nodes[j]);
            }
        }
    }
}

void huffmanTree(const string& text) {
    vector<Node*> nodes;
    for (char ch : text) {
        bool found = false;
        for (auto node : nodes) {
            if (node->ch == ch) {
                node->freq++;
                found = true;
                break;
            }
        }
        if (!found) {
            nodes.push_back(new Node(ch, 1));
        }
    }

    sortNodes(nodes);

    while (nodes.size() > 1) {
        Node* left = nodes[0];
        Node* right = nodes[1];

        Node* newNode = new Node('\0', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;

        nodes.erase(nodes.begin());
        nodes.erase(nodes.begin());

        nodes.push_back(newNode);

        sortNodes(nodes);
    }

    Node* root = nodes[0];
    vector<string> huffmanCodes(256);

    vector<pair<Node*, string>> q;
    q.push_back({ root, "" });

    while (!q.empty()) {
        pair<Node*, string> front = q.back();
        q.pop_back();
        Node* node = front.first;
        string code = front.second;

        if (!node->left && !node->right) {
            huffmanCodes[node->ch] = code;
        }

        if (node->left) q.push_back({ node->left, code + "0" });
        if (node->right) q.push_back({ node->right, code + "1" });
    }

    for (int i = 0; i < 256; ++i) {
        if (huffmanCodes[i] != "") {
            cout << (char)i << ": " << huffmanCodes[i] << endl;
        }
    }
}

int main() {
    string text = "But the new year is coming soon";

    huffmanTree(text);

    return 0;
}
