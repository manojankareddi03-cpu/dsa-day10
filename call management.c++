#include <iostream>
#include <vector>
using namespace std;

class Contact
{
public:
    string name;
    string phone;

    Contact(string n, string p)
    {
        name = n;
        phone = p;
    }
};

int main()
{
    vector<Contact> contacts;
    int choice;

    while (true)
    {
        cout << "\n========== CONTACT MANAGEMENT SYSTEM ==========\n";
        cout << "1. Add Contact\n";
        cout << "2. View Contacts\n";
        cout << "3. Search Contact\n";
        cout << "4. Delete Contact\n";
        cout << "5. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string name, phone;

            cout << "Enter Name: ";
            cin >> name;

            cout << "Enter Phone Number: ";
            cin >> phone;

            contacts.push_back(Contact(name, phone));

            cout << "\nContact Added Successfully!\n";
            break;
        }

        case 2:
        {
            if (contacts.empty())
            {
                cout << "\nNo Contacts Found!\n";
            }
            else
            {
                cout << "\n------ Contact List ------\n";

                for (int i = 0; i < contacts.size(); i++)
                {
                    cout << i + 1 << ". "
                         << contacts[i].name
                         << " - "
                         << contacts[i].phone
                         << endl;
                }
            }
            break;
        }

        case 3:
        {
            string searchName;
            bool found = false;

            cout << "Enter Name to Search: ";
            cin >> searchName;

            for (int i = 0; i < contacts.size(); i++)
            {
                if (contacts[i].name == searchName)
                {
                    cout << "\nContact Found!\n";
                    cout << "Name : " << contacts[i].name << endl;
                    cout << "Phone: " << contacts[i].phone << endl;
                    found = true;
                    break;
                }
            }

            if (!found)
            {
                cout << "\nContact Not Found!\n";
            }

            break;
        }

        case 4:
        {
            string deleteName;
            bool deleted = false;

            cout << "Enter Name to Delete: ";
            cin >> deleteName;

            for (int i = 0; i < contacts.size(); i++)
            {
                if (contacts[i].name == deleteName)
                {
                    contacts.erase(contacts.begin() + i);
                    cout << "\nContact Deleted Successfully!\n";
                    deleted = true;
                    break;
                }
            }

            if (!deleted)
            {
                cout << "\nContact Not Found!\n";
            }

            break;
        }

        case 5:
            cout << "\nThank You!\n";
            return 0;

        default:
            cout << "\nInvalid Choice!\n";
        }
    }

    return 0;
}
