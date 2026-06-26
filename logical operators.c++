#include <iostream>

int main(){
  
    int temp;
    bool sunny = true ;

    std:: cout << "enter the temperature : " ;
    std:: cin >> temp ;

    if (temp <= 0 || temp >= 30){

        std:: cout << "the temperature is bad ! " ;

    }

    else{

        std:: cout << "temperatue is good ! " ; 
    }

    if (sunny){

        std :: cout << "its sunny outsided !" ;

    }

    else {

        std :: cout << "its is cloudy outside !" ;
    }

    return 0;
}
