#include <iostream>
#include <vector>

using namespace std;

class Password
{
public:
    string website;
    string username;
    string password;

    Password(string w, string u, string p)
    {
        website = w;
        username = u;
        password = p;
    }
};

int main()
{
    vector<Password> passwords;
    int choice;

    while (true)
    {
        cout << "\n========== PASSWORD MANAGER ==========\n";
        cout << "1. Add Password\n";
        cout << "2. View Passwords\n";
        cout << "3. Search Password\n";
        cout << "4. Delete Password\n";
        cout << "5. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string website, username, password;

            cout << "Enter Website: ";
            cin >> website;

            cout << "Enter Username: ";
            cin >> username;

            cout << "Enter Password: ";
            cin >> password;

            passwords.push_back(Password(website, username, password));

            cout << "\nPassword Saved Successfully!\n";
            break;
        }

        case 2:
        {
            if (passwords.empty())
            {
                cout << "\nNo Passwords Found!\n";
            }
            else
            {
                cout << "\n========== SAVED PASSWORDS ==========\n";

                for (int i = 0; i < passwords.size(); i++)
                {
                    cout << "\nWebsite : " << passwords[i].website;
                    cout << "\nUsername: " << passwords[i].username;
                    cout << "\nPassword: " << passwords[i].password;
                    cout << "\n-----------------------------\n";
                }
            }
            break;
        }

        case 3:
        {
            string searchWebsite;
            bool found = false;

            cout << "Enter Website Name: ";
            cin >> searchWebsite;

            for (int i = 0; i < passwords.size(); i++)
            {
                if (passwords[i].website == searchWebsite)
                {
                    cout << "\nPassword Found!\n";
                    cout << "Website : " << passwords[i].website << endl;
                    cout << "Username: " << passwords[i].username << endl;
                    cout << "Password: " << passwords[i].password << endl;

                    found = true;
                    break;
                }
            }

            if (!found)
            {
                cout << "\nWebsite Not Found!\n";
            }

            break;
        }

        case 4:
        {
            string deleteWebsite;
            bool deleted = false;

            cout << "Enter Website to Delete: ";
            cin >> deleteWebsite;

            for (int i = 0; i < passwords.size(); i++)
            {
                if (passwords[i].website == deleteWebsite)
                {
                    passwords.erase(passwords.begin() + i);
                    cout << "\nPassword Deleted Successfully!\n";
                    deleted = true;
                    break;
                }
            }

            if (!deleted)
            {
                cout << "\nWebsite Not Found!\n";
            }

            break;
        }

        case 5:
        {
            cout << "\nThank You for using Password Manager!\n";
            return 0;
        }

        default:
        {
            cout << "\nInvalid Choice!\n";
        }
        }
    }

    return 0;
}
