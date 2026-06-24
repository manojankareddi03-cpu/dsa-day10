#include <iostream>

int main() {
char grade ;

std:: cout << "what latter grade? " ;
std :: cin >> grade ;

switch (grade){
    case 'A': 
    std:: cout << "you did great!" ;
    break;

      case 'B': 
    std:: cout << "you did good!" ;
    break; 
    
    case 'C': 
    std:: cout << "you did better!" ;
    break;


  case 'D': 
    std:: cout << "you fail!" ;
    break;

    default :
    std:: cout << "pleace only enter in a letter grade (A-D)";
       
}
}  
