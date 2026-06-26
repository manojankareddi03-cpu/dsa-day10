#include<iostream>
using namespace std;

class Bank{

private:

    double balance;

public:

    Bank(){

        balance=0;
    }

    void deposit(double amount){

        balance+=amount;

        cout<<"Deposited Successfully\n";
    }

    void withdraw(double amount){

        if(amount<=balance){

            balance-=amount;

            cout<<"Withdraw Successful\n";
        }

        else{

            cout<<"Insufficient Balance\n";
        }
    }

    void showBalance(){

        cout<<"Current Balance: "<<balance<<endl;
    }
};

int main(){

    Bank user;

    int choice;

    double amount;

    while(true){

        cout<<"\n1.Deposit\n2.Withdraw\n3.Show Balance\n4.Exit\n";

        cin>>choice;

        switch(choice){

            case 1:
                cin>>amount;
                user.deposit(amount);
                break;

            case 2:
                cin>>amount;
                user.withdraw(amount);
                break;

            case 3:
                user.showBalance();
                break;

            case 4:
                return 0;
        }
    }
}
