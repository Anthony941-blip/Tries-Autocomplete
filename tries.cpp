#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct TrieNode {
    bool isEndOfWord;
    TrieNode* children[26];
};

TrieNode* createNode() {
    TrieNode* node = new TrieNode();
    node->isEndOfWord = false;
    for (int i = 0; i < 26; i++)
        node->children[i] = nullptr;
    return node;
}

int main() {

	return 0;
}
