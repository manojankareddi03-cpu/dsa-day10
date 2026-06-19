#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

class Snippet {
public:
    string title;
    string language;
    string tag;
    string code;
};

vector<Snippet> snippets;

void loadSnippets() {
    ifstream file("snippets.txt");

    if (!file.is_open()) return;

    Snippet s;
    string line;

    while (getline(file, s.title)) {
        getline(file, s.language);
        getline(file, s.tag);
        getline(file, s.code);

        snippets.push_back(s);

        getline(file, line); // Separator
    }

    file.close();
}

void saveSnippets() {
    ofstream file("snippets.txt");

    for (const auto& s : snippets) {
        file << s.title << '\n';
        file << s.language << '\n';
        file << s.tag << '\n';
        file << s.code << '\n';
        file << "---\n";
    }

    file.close();
}

void addSnippet() {
    Snippet s;

    cin.ignore();

    cout << "\nEnter snippet title: ";
    getline(cin, s.title);

    cout << "Enter programming language: ";
    getline(cin, s.language);

    cout << "Enter tag: ";
    getline(cin, s.tag);

    cout << "Enter code (single line): ";
    getline(cin, s.code);

    snippets.push_back(s);
    saveSnippets();

    cout << "\nSnippet added successfully!\n";
}

void viewSnippets() {
    if (snippets.empty()) {
        cout << "\nNo snippets found!\n";
        return;
    }

    for (size_t i = 0; i < snippets.size(); i++) {
        cout << "\n----------------------------\n";
        cout << "ID: " << i + 1 << endl;
        cout << "Title: " << snippets[i].title << endl;
        cout << "Language: " << snippets[i].language << endl;
        cout << "Tag: " << snippets[i].tag << endl;
        cout << "Code: " << snippets[i].code << endl;
    }
}

void searchByTag() {
    cin.ignore();

    string searchTag;
    cout << "\nEnter tag: ";
    getline(cin, searchTag);

    bool found = false;

    for (const auto& s : snippets) {
        if (s.tag == searchTag) {
            cout << "\nTitle: " << s.title << endl;
            cout << "Language: " << s.language << endl;
            cout << "Code: " << s.code << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "\nNo matching snippets found!\n";
    }
}

void deleteSnippet() {
    int id;

    cout << "\nEnter snippet ID to delete: ";
    cin >> id;

    if (id < 1 || id > snippets.size()) {
        cout << "Invalid ID!\n";
        return;
    }

    snippets.erase(snippets.begin() + id - 1);
    saveSnippets();

    cout << "Snippet deleted successfully!\n";
}

int main() {
    loadSnippets();

    int choice;

    do {
        cout << "\n===== SnippetVault =====\n";
        cout << "1. Add Snippet\n";
        cout << "2. View Snippets\n";
        cout << "3. Search by Tag\n";
        cout << "4. Delete Snippet\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";

        cin >> choice;

        switch (choice) {
            case 1:
                addSnippet();
                break;
            case 2:
                viewSnippets();
                break;
            case 3:
                searchByTag();
                break;
            case 4:
                deleteSnippet();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}
