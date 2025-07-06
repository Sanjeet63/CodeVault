#include "SnippetManager.h"
#include <bits/stdc++.h>
using namespace std;

int main()
{
    SnippetManager manager;
    int choice;

    while (true)
    {
        cout << "\n CodeVault CLI\n";
        cout << "1. Add Snippet\n";
        cout << "2. View All Snippets\n";
        cout << "3. Search Snippet by Title Prefix\n";
        cout << "4. Search Snippet by Tag\n";
        cout << "5. Edit Snippet (with versioning)\n";
        cout << "6. View Version History\n";
        cout << "7. Check for Duplicate Snippet\n";
        cout << "8. Export Snippets to File\n";
        cout << "9. Delete Snippet by ID\n";
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
            manager.searchByTag();
            break;
        case 5:
            manager.editSnippet();
            break;
        case 6:
            manager.viewSnippetHistory();
            break;
        case 7:
            manager.checkForDuplicate();
            break;
        case 8:
            manager.exportSnippetsToFile();
            break;
        case 9:
            manager.deleteSnippetById();
            break;
        case 0:
            cout << "Exiting...\n";
            return 0;
        default:
            cout << "Invalid choice.\n";
        }
    }
}
