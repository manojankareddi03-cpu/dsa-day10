#include <iostream>
using namespace std;

void arrayInsertionCost(int n, int position) {
    int shifts = n - position;

    cout << "\n=== Array Insertion ===\n";
    cout << "Elements to shift: " << shifts << endl;
    cout << "Total operations: " << shifts + 1 << endl;
    cout << "Time Complexity: O(n)\n";
}

void linkedListInsertionCost(int n, int position) {
    int traversals = position - 1;

    cout << "\n=== Linked List Insertion ===\n";
    cout << "Nodes traversed: " << traversals << endl;
    cout << "Pointer updates: 2\n";
    cout << "Total operations: " << traversals + 2 << endl;

    if (position == 1)
        cout << "Time Complexity: O(1)\n";
    else
        cout << "Time Complexity: O(n)\n";
}

int main() {
    int n, position;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter insertion position (1 to " << n + 1 << "): ";
    cin >> position;

    if (position < 1 || position > n + 1) {
        cout << "Invalid position!\n";
        return 0;
    }

    arrayInsertionCost(n, position);
    linkedListInsertionCost(n, position);

    return 0;
}
