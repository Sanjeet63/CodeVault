# 🔐 CodeVault — CLI-Based DSA Snippet Manager in C++

> 📌 Your personal, searchable, and versioned vault for DSA code snippets — built entirely in modern C++.

---

## 📚 Overview

**CodeVault** is a powerful command-line tool for developers and competitive programmers to store, organize, and retrieve Data Structures & Algorithms (DSA) snippets. With built-in version control, tag filtering, and duplication detection, it’s designed to feel like your own local LeetCode — but for *your* solutions.

---

## 🚀 Features

- 📝 **Add Snippets** — with title, code, and custom tags  
- 🔍 **Prefix Search** — fast title lookup using Trie (O(L) time)  
- 🧠 **Version Control** — every edit is saved using Doubly Linked List  
- 🏷️ **Search by Tags** — find snippets by topics like `dp`, `array`, `graph`  
- 📋 **Duplicate Detection** — detect similar code using Rabin-Karp hashing  
- 📤 **Export to JSON** — backup or share your full snippet vault  
- 🗑️ **Delete by ID** — remove outdated or unwanted snippets  

---

## 🛠️ Tech Stack

- **Language**: C++17
- **DSA Used**: Trie, Doubly Linked List, Hashing (Rabin-Karp)
- **Paradigm**: Modular OOP design
- **I/O**: File export via `fstream`

---

## ⚙️ How to Run

### 🧱 Compile

```bash
g++ -std=c++17 main.cpp SnippetManager.cpp Trie.cpp VersionManager.cpp DupChecker.cpp -o codevault
.\codevault.exe
