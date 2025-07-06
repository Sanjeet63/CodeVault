#include "TrieNode.h"

Trie::Trie() {
    root = new TrieNode();
}

void Trie::insert(string word, int id) {
    TrieNode* node = root;
    for (char c : word) {
        if (!node->children.count(c)) {
            node->children[c] = new TrieNode();
        }
        node = node->children[c];
        node->snippetIds.push_back(id); 
    }
    node->end = true;
}

vector<int> Trie::searchByPrefix(string prefix) {
    TrieNode* node = root;
    for (char c : prefix) {
        if (!node->children.count(c)) return {};
        node = node->children[c];
    }
    return node->snippetIds;
}
