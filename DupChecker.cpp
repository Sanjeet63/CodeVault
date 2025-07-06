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
    int minLen = min(a.size(), b.size());
    int matchCount = 0;

    for (int i = 0; i < minLen; i++) {
        if (a[i] == b[i]) matchCount++;
    }

    return (matchCount * 100) / max(a.size(), b.size()); // % similarity
}

vector<pair<int, int>> DupChecker::findSimilarSnippets(const vector<Snippet>& snippets, const string& code) {
    vector<pair<int, int>> similar;
    for (const auto& s : snippets) {
        int match = computeSimilarity(s.code, code);
        if (match >= 50) { // threshold
            similar.push_back({s.id, match});
        }
    }
    return similar;
}
