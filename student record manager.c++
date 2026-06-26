#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Student {
public:
    int id;
    string name;
    float cgpa;

    void input() {
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter CGPA: ";
        cin >> cgpa;
    }

    void display() {
        cout << "ID: " << id
             << " Name: " << name
             << " CGPA: " << cgpa << endl;
    }
};

void addStudent() {
    Student s;
    s.input();

    ofstream file("students.txt", ios::app);
    file << s.id << " "
         << s.name << " "
         << s.cgpa << endl;

    file.close();
}

void displayStudents() {
    ifstream file("students.txt");

    Student s;

    while(file >> s.id >> s.name >> s.cgpa) {
        s.display();
    }

    file.close();
}

int main() {

    int choice;

    while(true) {

        cout << "\n1.Add\n2.Display\n3.Exit\n";
        cin >> choice;

        if(choice == 1)
            addStudent();

        else if(choice == 2)
            displayStudents();

        else
            break;
    }

    return 0;
}
