#ifndef SNIPPET_H
#define SNIPPET_H

#include <bits/stdc++.h>
using namespace std;

struct Snippet {
    int id;
    string title;
    string code;
    vector<string> tags;
    time_t timestamp;

    Snippet(int id, string title, string code, vector<string> tags)
        : id(id), title(title), code(code), tags(tags) {
        timestamp = time(nullptr);
    }
};

#endif
