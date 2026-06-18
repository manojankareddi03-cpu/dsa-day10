#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

struct Student {
    int id;
    string name;
    float marks;
};

vector<Student> students;

// Save data to file
void saveToFile() {
    ofstream file("students.txt");

    for (const auto& s : students) {
        file << s.id << " "
             << s.name << " "
             << s.marks << endl;
    }

    file.close();
}

// Load data from file
void loadFromFile() {
    ifstream file("students.txt");

    Student s;
    while (file >> s.id >> s.name >> s.marks) {
        students.push_back(s);
    }

    file.close();
}

// Add student
void addStudent() {
    Student s;

    cout << "\nEnter Student ID: ";
    cin >> s.id;

    cout << "Enter Student Name: ";
    cin >> s.name;

    cout << "Enter Student Marks: ";
    cin >> s.marks;

    students.push_back(s);
    saveToFile();

    cout << "Student added successfully!\n";
}

// Display all students
void displayStudents() {
    if (students.empty()) {
        cout << "\nNo records found!\n";
        return;
    }

    cout << "\nID\tName\tMarks\n";
    cout << "-------------------------\n";

    for (const auto& s : students) {
        cout << s.id << "\t"
             << s.name << "\t"
             << s.marks << endl;
    }
}

// Search student
void searchStudent() {
    int id;
    cout << "\nEnter Student ID to search: ";
    cin >> id;

    for (const auto& s : students) {
        if (s.id == id) {
            cout << "\nStudent Found!\n";
            cout << "ID: " << s.id << endl;
            cout << "Name: " << s.name << endl;
            cout << "Marks: " << s.marks << endl;
            return;
        }
    }

    cout << "Student not found!\n";
}

// Sort students by marks
void sortByMarks() {
    sort(students.begin(), students.end(),
         [](Student a, Student b) {
             return a.marks > b.marks;
         });

    cout << "\nStudents sorted by marks.\n";
    displayStudents();
}

int main() {
    loadFromFile();

    int choice;

    do {
        cout << "\n===== Student Record Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Sort by Marks\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                sortByMarks();
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
