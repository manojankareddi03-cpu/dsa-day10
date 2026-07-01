#include <iostream>
using namespace std;

int main(){
    int age;
    cin >> age ;
    if (age>=18){
      cout <<"YOUR ELIGIBLE TO VOTE";
    }
      else if (age <=18){
      cout <<"YOU WILL ABALE TO VOTE SOON";
      }
    else{
      cout <<"YOU ARE NOT ELIGIBLE TO VOTE:";
    }
     return 0; 
}
