#include <iostream>
#include <vector>
using namespace std;

class Book{
public:
    int id;
    string title;
    bool issued;

    Book(int i,string t){
        id=i;
        title=t;
        issued=false;
    }
};

int main(){

    vector<Book> books;

    int choice;

    while(true){

        cout<<"\n1.Add Book\n2.Show Books\n3.Issue Book\n4.Exit\n";
        cin>>choice;

        if(choice==1){

            int id;
            string title;

            cout<<"Enter ID: ";
            cin>>id;

            cout<<"Enter Title: ";
            cin>>title;

            books.push_back(Book(id,title));
        }

        else if(choice==2){

            for(auto &b:books){

                cout<<b.id<<" "
                    <<b.title<<" ";

                if(b.issued)
                    cout<<"Issued";
                else
                    cout<<"Available";

                cout<<endl;
            }
        }

        else if(choice==3){

            int id;
            cout<<"Enter Book ID: ";
            cin>>id;

            for(auto &b:books){

                if(b.id==id){

                    b.issued=true;

                    cout<<"Book Issued\n";
                }
            }
        }

        else
            break;
    }

    return 0;
}
