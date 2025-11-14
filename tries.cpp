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

void collectWords(TrieNode* node, string prefix, vector<string>& out) {
    if (!node) return;

    if (node->isEndOfWord)
        out.push_back(prefix);

    for (int i = 0; i < 26; i++) {
        if (node->children[i]) {
            char c = 'a' + i;
            collectWords(node->children[i], prefix + c, out);
        }
    }
}


vector<string> autocomplete(TrieNode* root, const string& prefix) {
    TrieNode* node = searchPrefix(root, prefix);
    vector<string> results;

    if (!node)
        return results;

    collectWords(node, prefix, results);
    return results;
}


int main() {
    TrieNode* root = createNode();

    insert(root, "apple");
    insert(root, "application");
    insert(root, "apply");
    insert(root, "apt");
    insert(root, "banana");
    insert(root, "band");
    insert(root, "bandana");

    string prefix;
    cout << "Enter a prefix: ";
    cin >> prefix;

    vector<string> suggestions = autocomplete(root, prefix);

    if (suggestions.empty()) {
        cout << "No suggestions found.\n";
    } else {
        cout << "Autocomplete Suggestions:\n";
        for (const string& w : suggestions)
            cout << " - " << w << endl;
    }

    return 0;
}

