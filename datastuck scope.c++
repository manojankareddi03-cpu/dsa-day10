#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

class ArrayVisualizer {
private:
    vector<int> arr;

public:
    void insertElement(int value, int position) {
        if (position < 0 || position > arr.size()) {
            cout << "Invalid position!\n";
            return;
        }

        auto start = high_resolution_clock::now();

        arr.insert(arr.begin() + position, value);

        auto stop = high_resolution_clock::now();

        cout << "\nElement inserted successfully.\n";
        display();

        auto duration = duration_cast<nanoseconds>(stop - start);

        cout << "Time Complexity: O(n)\n";
        cout << "Execution Time: " << duration.count() << " ns\n";
    }

    void deleteElement(int position) {
        if (position < 0 || position >= arr.size()) {
            cout << "Invalid position!\n";
            return;
        }

        auto start = high_resolution_clock::now();

        arr.erase(arr.begin() + position);

        auto stop = high_resolution_clock::now();

        cout << "\nElement deleted successfully.\n";
        display();

        auto duration = duration_cast<nanoseconds>(stop - start);

        cout << "Time Complexity: O(n)\n";
        cout << "Execution Time: " << duration.count() << " ns\n";
    }

    void display() {
        cout << "Array: ";

        if (arr.empty()) {
            cout << "Empty";
        } else {
            for (int num : arr) {
                cout << num << " ";
            }
        }

        cout << "\n";
    }
};

int main() {
    ArrayVisualizer visualizer;
    int choice, value, position;

    do {
        cout << "\n===== DataStructScope =====\n";
        cout << "1. Insert Element\n";
        cout << "2. Delete Element\n";
        cout << "3. Display Array\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> value;

                cout << "Enter position: ";
                cin >> position;

                visualizer.insertElement(value, position);
                break;

            case 2:
                cout << "Enter position to delete: ";
                cin >> position;

                visualizer.deleteElement(position);
                break;

            case 3:
                visualizer.display();
                break;

            case 4:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}
