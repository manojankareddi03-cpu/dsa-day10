#include <iostream>
using namespace std;

const int MAX_BOOKS = 100;

class UserNode {
public:
    string userName;
    UserNode* next;

    UserNode(string name) {
        userName = name;
        next = nullptr;
    }
};

class Book {
public:
    int id;
    string title;
    string author;
    int copies;

    UserNode* waitlistHead;
    UserNode* waitlistTail;

    Book() {
        id = 0;
        copies = 0;
        waitlistHead = nullptr;
        waitlistTail = nullptr;
    }

    void addToWaitlist(string name) {
        UserNode* newUser = new UserNode(name);

        if (waitlistHead == nullptr) {
            waitlistHead = waitlistTail = newUser;
        } else {
            waitlistTail->next = newUser;
            waitlistTail = newUser;
        }
    }

    void assignBook() {
        if (waitlistHead == nullptr) {
            copies++;
            cout << "Book returned successfully.\n";
            return;
        }

        UserNode* temp = waitlistHead;

        cout << "Book automatically assigned to: "
             << temp->userName << endl;

        waitlistHead = waitlistHead->next;

        if (waitlistHead == nullptr) {
            waitlistTail = nullptr;
        }

        delete temp;
    }

    void displayWaitlist() {
        if (waitlistHead == nullptr) {
            cout << "No users in waitlist.\n";
            return;
        }

        UserNode* temp = waitlistHead;

        while (temp != nullptr) {
            cout << temp->userName << " -> ";
            temp = temp->next;
        }

        cout << "NULL\n";
    }
};

class Library {
private:
    Book books[MAX_BOOKS];
    int count;

public:
    Library() {
        count = 0;
    }

    void addBook() {
        if (count >= MAX_BOOKS) {
            cout << "Library is full.\n";
            return;
        }

        cout << "Enter Book ID: ";
        cin >> books[count].id;

        cin.ignore();

        cout << "Enter Title: ";
        getline(cin, books[count].title);

        cout << "Enter Author: ";
        getline(cin, books[count].author);

        cout << "Enter Number of Copies: ";
        cin >> books[count].copies;

        count++;

        cout << "Book added successfully.\n";
    }

    int searchBook(int id) {
        for (int i = 0; i < count; i++) {
            if (books[i].id == id) {
                return i;
            }
        }

        return -1;
    }

    void issueBook() {
        int id;
        string user;

        cout << "Enter Book ID: ";
        cin >> id;

        int index = searchBook(id);

        if (index == -1) {
            cout << "Book not found.\n";
            return;
        }

        cin.ignore();

        cout << "Enter User Name: ";
        getline(cin, user);

        if (books[index].copies > 0) {
            books[index].copies--;

            cout << "Book issued to "
                 << user << endl;
        } else {
            cout << "No copies available.\n";
            cout << user
                 << " added to waitlist.\n";

            books[index].addToWaitlist(user);
        }
    }

    void returnBook() {
        int id;

        cout << "Enter Book ID: ";
        cin >> id;

        int index = searchBook(id);

        if (index == -1) {
            cout << "Book not found.\n";
            return;
        }

        books[index].assignBook();
    }

    void displayBooks() {
        if (count == 0) {
            cout << "No books available.\n";
            return;
        }

        cout << "\n----- BOOKS -----\n";

        for (int i = 0; i < count; i++) {
            cout << "\nBook ID: " << books[i].id
                 << "\nTitle: " << books[i].title
                 << "\nAuthor: " << books[i].author
                 << "\nAvailable Copies: "
                 << books[i].copies << endl;
        }
    }

    void showWaitlist() {
        int id;

        cout << "Enter Book ID: ";
        cin >> id;

        int index = searchBook(id);

        if (index == -1) {
            cout << "Book not found.\n";
            return;
        }

        cout << "Waitlist for "
             << books[index].title << ":\n";

        books[index].displayWaitlist();
    }
};

int main() {

    Library lib;
    int choice;

    while (true) {

        cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Book\n";
        cout << "2. Issue Book\n";
        cout << "3. Return Book\n";
        cout << "4. Display Books\n";
        cout << "5. Show Waitlist\n";
        cout << "6. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            lib.addBook();
            break;

        case 2:
            lib.issueBook();
            break;

        case 3:
            lib.returnBook();
            break;

        case 4:
            lib.displayBooks();
            break;

        case 5:
            lib.showWaitlist();
            break;

        case 6:
            cout << "Thank you!\n";
            return 0;

       default:
       cout << "invalid choice.\n";
        }
    }
}
