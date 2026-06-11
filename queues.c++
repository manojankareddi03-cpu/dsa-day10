#include <iostream>
using namespace std ;
int main (){
    int n;
    cin >> n;
     
    for (int i=1; i<n; i++)
    {
        int num = i;
        string binary = "";
         
        while (num>0){
            binary = char ((num % 2) + '0') + binary ;
            num /= 2;
        }
        cout << binary << endl ;
    
    }
    return 0 ;
}
