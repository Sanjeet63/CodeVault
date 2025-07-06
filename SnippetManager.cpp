#include "SnippetManager.h"

SnippetManager::SnippetManager()
{
    nextId = 1;
}

void SnippetManager::editSnippet()
{
    int id;
    cout << "Enter snippet ID to edit: ";
    cin >> id;
    cin.ignore();

    for (auto &s : snippets)
    {
        if (s.id == id)
        {
            versionManager.saveOldVersion(s); // Save current version

            string newTitle, newCode, tagLine;
            vector<string> newTags;

            cout << "Enter new title: ";
            getline(cin, newTitle);
            cout << "Enter new code:\n";
            getline(cin, newCode);
            cout << "Enter new tags (comma-separated): ";
            getline(cin, tagLine);

            stringstream ss(tagLine);
            string tag;
            while (getline(ss, tag, ','))
            {
                newTags.push_back(tag);
            }

            s.title = newTitle;
            s.code = newCode;
            s.tags = newTags;
            s.timestamp = time(nullptr);

            trie.insert(newTitle, s.id); // update title in Trie too

            cout << "✅ Snippet updated. Old version saved.\n";
            return;
        }
    }

    cout << "❌ Snippet ID not found.\n";
}

void SnippetManager::viewAll()
{
    cout << "\n--- All Snippets ---\n";
    for (const auto &s : snippets)
    {
        cout << "[" << s.id << "] " << s.title << "\n";
    }
}
void SnippetManager::searchByTitlePrefix()
{
    cin.ignore();
    string prefix;
    cout << "Enter title prefix: ";
    getline(cin, prefix);

    vector<int> ids = trie.searchByPrefix(prefix);

    if (ids.empty())
    {
        cout << "❌ No matching snippets found.\n";
        return;
    }

    cout << "\n📄 Matching Snippets:\n";
    for (int id : ids)
    {
        for (auto &s : snippets)
        {
            if (s.id == id)
            {
                cout << "[" << s.id << "] " << s.title << "\n";
                break;
            }
        }
    }
}

void SnippetManager::viewSnippetHistory()
{
    int id;
    cout << "Enter snippet ID to view history: ";
    cin >> id;

    versionManager.showHistory(id);
}
void SnippetManager::addSnippet()
{
    string title, code, tagLine;
    vector<string> tags;

    cin.ignore();
    cout << "Enter title: ";
    getline(cin, title);

    cout << "Enter code:\n";
    getline(cin, code);

    cout << "Enter tags (comma-separated): ";
    getline(cin, tagLine);
    stringstream ss(tagLine);
    string tag;
    while (getline(ss, tag, ','))
    {
        tags.push_back(tag);
    }

    Snippet s(nextId++, title, code, tags);
    snippets.push_back(s);

    trie.insert(title, s.id); // also add to Trie

    cout << "✅ Snippet added successfully.\n";
}
void SnippetManager::checkForDuplicate()
{
    cin.ignore();
    string inputCode;
    cout << "Paste your code to check for duplicates:\n";
    getline(cin, inputCode);

    auto matches = dupChecker.findSimilarSnippets(snippets, inputCode);

    if (matches.empty())
    {
        cout << "✅ No significant duplicate found.\n";
    }
    else
    {
        cout << "⚠️  Potential duplicates found:\n";
        for (auto &match : matches)
        {
            int id = match.first;
            int percent = match.second;
            cout << "Snippet ID: " << id << " → Match: " << percent << "%\n";
        }
    }
}
void SnippetManager::exportSnippetsToFile() {
    ofstream out("snippets.json");

    if (!out.is_open()) {
        cout << "❌ Failed to open file for writing.\n";
        return;
    }

    out << "[\n";

    for (size_t i = 0; i < snippets.size(); i++) {
        const Snippet& s = snippets[i];
        out << "  {\n";
        out << "    \"id\": " << s.id << ",\n";
        out << "    \"title\": \"" << s.title << "\",\n";
        out << "    \"code\": \"" << s.code << "\",\n";

        out << "    \"tags\": [";
        for (size_t j = 0; j < s.tags.size(); j++) {
            out << "\"" << s.tags[j] << "\"";
            if (j + 1 < s.tags.size()) out << ", ";
        }
        out << "],\n";

        out << "    \"timestamp\": " << s.timestamp << "\n";
        out << "  }";
        if (i + 1 < snippets.size()) out << ",";
        out << "\n";
    }

    out << "]\n";
    out.close();

    cout << "✅ Snippets exported to 'snippets.json'\n";
}
void SnippetManager::deleteSnippetById() {
    int id;
    cout << "Enter the snippet ID to delete: ";
    cin >> id;

    bool found = false;

    // Delete from main list
    for (auto it = snippets.begin(); it != snippets.end(); ++it) {
        if (it->id == id) {
            snippets.erase(it);
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "❌ Snippet ID not found.\n";
        return;
    }

    // (Optional) Version history cleanup
    // versionManager.deleteHistory(id); // only if implemented

    cout << "🗑️ Snippet ID " << id << " deleted.\n";
}
void SnippetManager::searchByTag() {
    cin.ignore();
    string targetTag;
    cout << "Enter tag to search for: ";
    getline(cin, targetTag);

    bool found = false;
    cout << "\n📄 Snippets with tag \"" << targetTag << "\":\n";

    for (const auto& s : snippets) {
        if (find(s.tags.begin(), s.tags.end(), targetTag) != s.tags.end()) {
            cout << "[" << s.id << "] " << s.title << "\n";
            found = true;
        }
    }

    if (!found) {
        cout << "❌ No snippets found with tag \"" << targetTag << "\".\n";
    }
}
