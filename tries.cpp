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



TrieNode* searchPrefix(TrieNode* root, const string& prefix);

int main() {

	return 0;
}



TrieNode* searchPrefix(TrieNode* root, const string& prefix) {
    TrieNode* curr = root;

    for (char ch : prefix) {
        if (!isalpha(ch)) continue;
        int idx = tolower(ch) - 'a';

        if (!curr->children[idx])
            return nullptr;

        curr = curr->children[idx];
    }
    return curr;
}
