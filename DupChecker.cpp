#include "DupChecker.h"

long long DupChecker::calculateHash(const string& str) {
    long long hash = 0, pow = 1;
    for (char c : str) {
        hash += (c * pow);
        pow *= PRIME;
    }
    return hash;
}

int DupChecker::computeSimilarity(const string& a, const string& b) {
    int len = min(a.size(), b.size());
    int cnt = 0;

    for (int i = 0; i < len; i++) {
        if (a[i] == b[i]) cnt++;
    }

    return (cnt * 100) / max(a.size(), b.size()); 
}

vector<pair<int, int>> DupChecker::findSimilarSnippets(const vector<Snippet>& snippets, const string& code) {
    vector<pair<int, int>> similar;
    for (const auto& s : snippets) {
        int match = computeSimilarity(s.code, code);
        if (match >= 50) { 
            similar.push_back({s.id, match});
        }
    }
    return similar;
}
