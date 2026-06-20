#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Insert at beginning
void insertAtBeginning(Node*& head, int value) {
    Node* newNode = new Node();

    newNode->data = value;
    newNode->next = head;

    head = newNode;
}

// Delete node from beginning
void deleteAtBeginning(Node*& head) {
    if (head == nullptr) {
        cout << "Linked List is empty!" << endl;
        return;
    }

    Node* temp = head;
    head = head->next;

    delete temp;
}

// Display the linked list
void display(Node* head) {
    Node* temp = head;

    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

int main() {
    Node* head = nullptr;

    insertAtBeginning(head, 30);
    insertAtBeginning(head, 20);
    insertAtBeginning(head, 10);

    cout << "Before deletion: ";
    display(head);

    deleteAtBeginning(head);

    cout << "After deletion: ";
    display(head);

    return 0;
}
