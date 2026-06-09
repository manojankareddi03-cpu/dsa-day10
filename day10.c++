#include <iostream>
using namespace std;
 int main(){
    int i,j ;
    int test[3] [3] = {{2,3,4} , {5,6,7} , {8,9,0}} ;
      for (int i = 0; i<3 ; i++)
      {
        for (int j = 0; j<3 ; j++){
            cout<<test[i] [j]<< " ";

        }
        cout<<"\n";
      }
      return 0 ;
 }