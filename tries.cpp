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

void insert(TrieNode* root, const string& word);

int main() {

	return 0;
}

void insert(TrieNode* root, const string& word) {
    TrieNode* curr = root;

    for (char ch : word) {
        if (!isalpha(ch)) continue;
        int idx = tolower(ch) - 'a';

        if (curr->children[idx] == nullptr)
            curr->children[idx] = createNode();

        curr = curr->children[idx];
    }
    curr->isEndOfWord = true;
}
