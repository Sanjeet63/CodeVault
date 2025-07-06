#include "VersionManager.h"

void VersionManager::saveOldVersion(Snippet s) {
    VersionNode* newNode = new VersionNode(s);
    if (versionMap.count(s.id)) {
        newNode->next = versionMap[s.id];
        versionMap[s.id]->prev = newNode;
    }
    versionMap[s.id] = newNode;
}

void VersionManager::showHistory(int snippetId) {
    if (!versionMap.count(snippetId)) {
        cout << "❌ No version history found.\n";
        return;
    }

    cout << "\n📜 Version History for Snippet ID: " << snippetId << "\n";
    VersionNode* curr = versionMap[snippetId];
    int version = 1;
    while (curr) {
        cout << "Version " << version++ << " | Title: " << curr->data.title << "\n";
        cout << "Code:\n" << curr->data.code << "\n\n";
        curr = curr->next;
    }
}
