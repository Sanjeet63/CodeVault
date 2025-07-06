#include "SnippetManager.h"
#include <bits/stdc++.h>
using namespace std;

int main()
{
    SnippetManager manager;
    int choice;

    while (true)
    {
        cout << "\n📁 CodeVault CLI\n";
        cout << "1. Add Snippet\n";
        cout << "2. View All Snippets\n";
        cout << "3. Search Snippet by Title Prefix\n";
        cout << "4. Edit Snippet (with versioning)\n";
        cout << "5. View Version History\n";
        cout << "6. Check for Duplicate Snippet\n";
        cout << "7. Export Snippets to File\n";
        cout << "8. Delete Snippet by ID\n";
        cout << "9. Search Snippet by Tag\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            manager.addSnippet();
            break;
        case 2:
            manager.viewAll();
            break;
        case 3:
            manager.searchByTitlePrefix();
            break;
        case 4:
            manager.editSnippet();
            break;
        case 5:
            manager.viewSnippetHistory();
            break;
        case 6:
            manager.checkForDuplicate();
            break;
        case 7:
            manager.exportSnippetsToFile();
            break;
        case 8:
            manager.deleteSnippetById();
            break;
        case 9:
            manager.searchByTag();
            break;

        case 0:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice.\n";
        }
    }
}
