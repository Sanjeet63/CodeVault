#include "VersionManager.h"

void VersionManager::saveOldVersion(Snippet s) {
    VersionNode* node = new VersionNode(s);
    if (mpp.count(s.id)) {
        node->next = mpp[s.id];
        mpp[s.id]->prev = node;
    }
    mpp[s.id] = node;
}

void VersionManager::showHistory(int id) {
    if (!mpp.count(id)) {
        cout << "No version history found.\n";
        return;
    }

    cout << "Version History for Snippet ID: " << id << "\n";
    VersionNode* curr = mpp[id];
    int ver = 1;
    while (curr) {
        cout << "Version " << ver++ << " | Title: " << curr->data.title << "\n";
        cout << "Code:\n" << curr->data.code << "\n\n";
        curr = curr->next;
    }
}
