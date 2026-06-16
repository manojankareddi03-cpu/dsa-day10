#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = nullptr;
    }

    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);

        newNode->next = head;
        head = newNode;

        cout << value << " inserted at beginning.\n";
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node(value);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* temp = head;

        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = newNode;

        cout << value << " inserted at end.\n";
    }

    void insertAtPosition(int value, int position) {

        if (position <= 1) {
            insertAtBeginning(value);
            return;
        }

        Node* newNode = new Node(value);
        Node* temp = head;

        for (int i = 1; temp != nullptr && i < position - 1; i++) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Invalid position.\n";
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;

        cout << value << " inserted at position " << position << ".\n";
    }

    void deleteByValue(int value) {

        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;

            cout << value << " deleted.\n";
            return;
        }

        Node* current = head;

        while (current->next != nullptr &&
               current->next->data != value) {
            current = current->next;
        }

        if (current->next == nullptr) {
            cout << "Value not found.\n";
            return;
        }

        Node* temp = current->next;
        current->next = temp->next;

        delete temp;

        cout << value << " deleted.\n";
    }

    void search(int value) {

        Node* temp = head;
        int position = 1;

        while (temp != nullptr) {

            if (temp->data == value) {
                cout << value << " found at position "
                     << position << ".\n";
                return;
            }

            temp = temp->next;
            position++;
        }

        cout << value << " not found.\n";
    }

    void reverse() {

        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;

        while (current != nullptr) {

            next = current->next;
            current->next = prev;

            prev = current;
            current = next;
        }

        head = prev;

        cout << "Linked List reversed.\n";
    }

    void display() {

        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;

        cout << "Linked List: ";

        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL\n";
    }

    ~LinkedList() {

        Node* current = head;

        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {

    LinkedList list;
    int choice, value, position;

    while (true) {

        cout << "\n===== LINKED LIST MENU =====\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert at Position\n";
        cout << "4. Delete by Value\n";
        cout << "5. Search\n";
        cout << "6. Reverse List\n";
        cout << "7. Display\n";
        cout << "8. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Enter value: ";
            cin >> value;
            list.insertAtBeginning(value);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> value;
            list.insertAtEnd(value);
            break;

        case 3:
            cout << "Enter value: ";
            cin >> value;

            cout << "Enter position: ";
            cin >> position;

            list.insertAtPosition(value, position);
            break;

        case 4:
            cout << "Enter value to delete: ";
            cin >> value;

            list.deleteByValue(value);
            break;

        case 5:
            cout << "Enter value to search: ";
            cin >> value;

            list.search(value);
            break;

        case 6:
            list.reverse();
            break;

        case 7:
            list.display();
            break;

        case 8:
            return 0;

        default:
            cout << "Invalid choice.\n";
        }
    }
}
