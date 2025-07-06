#ifndef DUP_CHECKER_H
#define DUP_CHECKER_H

#include "Snippet.h"
#include <bits/stdc++.h>
using namespace std;

class DupChecker {
private:
    const int PRIME = 101;

    long long calculateHash(const string& str);
    int computeSimilarity(const string& a, const string& b); // returns % match

public:
    vector<pair<int, int>> findSimilarSnippets(const vector<Snippet>& snippets, const string& code); // {id, match%}
};

#endif
