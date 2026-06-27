#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class Transaction
{
public:
    string type;
    string description;
    double amount;

    Transaction(string t, string d, double a)
    {
        type = t;
        description = d;
        amount = a;
    }
};

int main()
{
    vector<Transaction> history;
    double balance = 0.0;
    int choice;

    while (true)
    {
        cout << "\n========== EXPENSE TRACKER ==========\n";
        cout << "1. Add Income\n";
        cout << "2. Add Expense\n";
        cout << "3. View Balance\n";
        cout << "4. View Transaction History\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string desc;
            double amount;

            cout << "Enter Income Description: ";
            cin.ignore();
            getline(cin, desc);

            cout << "Enter Amount: ";
            cin >> amount;

            balance += amount;
            history.push_back(Transaction("Income", desc, amount));

            cout << "\nIncome Added Successfully!\n";
            break;
        }

        case 2:
        {
            string desc;
            double amount;

            cout << "Enter Expense Description: ";
            cin.ignore();
            getline(cin, desc);

            cout << "Enter Amount: ";
            cin >> amount;

            if (amount > balance)
            {
                cout << "\nInsufficient Balance!\n";
            }
            else
            {
                balance -= amount;
                history.push_back(Transaction("Expense", desc, amount));
                cout << "\nExpense Added Successfully!\n";
            }
            break;
        }

        case 3:
        {
            cout << fixed << setprecision(2);
            cout << "\nCurrent Balance: ₹" << balance << endl;
            break;
        }

        case 4:
        {
            if (history.empty())
            {
                cout << "\nNo Transactions Found!\n";
            }
            else
            {
                cout << "\n========== TRANSACTION HISTORY ==========\n";

                for (int i = 0; i < history.size(); i++)
                {
                    cout << i + 1 << ". "
                         << history[i].type
                         << " | "
                         << history[i].description
                         << " | ₹"
                         << history[i].amount << endl;
                }
            }
            break;
        }

        case 5:
        {
            cout << "\nThank You for using Expense Tracker!\n";
            return 0;
        }

        default:
        {
            cout << "\nInvalid Choice! Try Again.\n";
        }
        }
    }

    return 0;
}
