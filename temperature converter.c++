#include <iostream>

int main (){

    double temp ;
    char unit ;

    std:: cout << "********TEMPERATURE CONVERTRE*************\n";
    std:: cout << "F = Fahrenheit \n";
    std:: cout << "C = Celciues \n";
    std::cout << "what unit whould you like to convert to : " ;
    std:: cin >> unit ;
    
    if (unit == 'F' || unit == 'f'){

        std:: cout<< "enter the temperature in celciues:" ;
        std:: cin >> temp ;

        temp = (1.8 * temp) + 32.0 ;
        std::cout << "enter is : " << temp << "F \n";

    }
    else if (unit == 'C' || unit == 'c'){

        std:: cout<< "enter the temperature in fahrenheit:" ;
        std:: cin >> temp ;

        temp = (temp - 32 ) / 1.8 ;
        std::cout << "temperature is : "<< temp << "C \n";
     }

     else {
        std:: cout << "plese enter only C or F \n";
     }
    
    std:: cout << "******************************************\n";

    return 0;
}
