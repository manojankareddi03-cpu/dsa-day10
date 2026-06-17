#include <iostream>
using namespace std;

// Array deletion function
void deleteFromArray(int arr[], int &n, int position) {

    int operations = 0;

    if (position < 1 || position > n) {
        cout << "Invalid position!\n";
        return;
    }

    cout << "\nDeleting " << arr[position - 1]
         << " from Array...\n";

    // Shift elements left
    for (int i = position - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
        operations++;
    }

    n--;

    cout << "Updated Array: ";

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << "\nShifts performed: " << operations;
    cout << "\nTime Complexity: ";

    if (position == n + 1)
        cout << "O(1)\n";
    else
        cout << "O(n)\n";
}

// Linked List Node
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Insert at end
void insertAtEnd(Node*& head, int value) {

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
}

// Display linked list
void display(Node* head) {

    while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->next;
    }

    cout << "NULL\n";
}

// Delete node at position
void deleteFromLinkedList(Node*& head, int position) {

    int traversals = 0;

    if (head == nullptr) {
        cout << "Linked List is empty.\n";
        return;
    }

    if (position == 1) {

        Node* temp = head;
        head = head->next;

        cout << "\nDeleting " << temp->data
             << " from Linked List...\n";

        delete temp;

        cout << "Nodes traversed: 0";
        cout << "\nPointer updates: 1";
        cout << "\nTime Complexity: O(1)\n";

        return;
    }

    Node* current = head;

    for (int i = 1; current != nullptr && i < position - 1; i++) {
        current = current->next;
        traversals++;
    }

    if (current == nullptr || current->next == nullptr) {
        cout << "Invalid position!\n";
        return;
    }

    Node* temp = current->next;

    cout << "\nDeleting " << temp->data
         << " from Linked List...\n";

    current->next = temp->next;

    delete temp;

    cout << "Nodes traversed: " << traversals;
    cout << "\nPointer updates: 1";

    if (position == 1)
        cout << "\nTime Complexity: O(1)\n";
    else
        cout << "\nTime Complexity: O(n)\n";
}

int main() {

    int arr[100] = {10, 20, 30, 40, 50};
    int n = 5;

    Node* head = nullptr;

    for (int i = 0; i < n; i++) {
        insertAtEnd(head, arr[i]);
    }

    int position;

    cout << "Initial Array: ";

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << "\nInitial Linked List: ";
    display(head);

    cout << "\nEnter position to delete (1 to "
         << n << "): ";

    cin >> position;

    deleteFromArray(arr, n, position);

    deleteFromLinkedList(head, position);

    cout << "\nUpdated Linked List: ";
    display(head);

    return 0;
}
