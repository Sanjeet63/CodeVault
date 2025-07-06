#ifndef SNIPPET_MANAGER_H
#define SNIPPET_MANAGER_H

#include "Snippet.h"
#include "TrieNode.h"
#include "DupChecker.h"
#include "VersionManager.h"
#include <bits/stdc++.h>
using namespace std;

class SnippetManager {
private:
    vector<Snippet> snippets;
    int nextId;
    VersionManager versionManager;
  
    
private:
    Trie trie;
private:
    DupChecker dupChecker;

public:
    SnippetManager();
    void searchByTitlePrefix();
    void addSnippet();
    void viewAll();
    void editSnippet();
    void viewSnippetHistory();
    void checkForDuplicate();
    void exportSnippetsToFile();
    void deleteSnippetById();
    void searchByTag();


};

#endif
