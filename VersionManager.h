#ifndef VERSION_MANAGER_H
#define VERSION_MANAGER_H

#include "Snippet.h"
#include <bits/stdc++.h>
using namespace std;

struct VersionNode {
    Snippet data;
    VersionNode* prev;
    VersionNode* next;

    VersionNode(Snippet d) : data(d), prev(nullptr), next(nullptr) {}
};

class VersionManager {
private:
    unordered_map<int, VersionNode*> versionMap; // current head per snippet ID

public:
    void saveOldVersion(Snippet s);
    void showHistory(int snippetId);
};

#endif
