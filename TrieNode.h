#ifndef TRIE_NODE_H
#define TRIE_NODE_H

#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    unordered_map<char, TrieNode*> children;
    bool isEndOfWord = false;
    vector<int> snippetIds; // list of snippet IDs with this prefix
};

class Trie {
private:
    TrieNode* root;

    void dfs(TrieNode* node, vector<int>& result);

public:
    Trie();
    void insert(string word, int snippetId);
    vector<int> searchByPrefix(string prefix);
};

#endif
