#include <iostream>
#include <cmath>

int main () {

    double a;
    double b;
    double c;

    std:: cout << "enter side A :" ;
    std:: cin >> a;


    std:: cin >> b;

    c = sqrt (pow(a,2) + pow(b,2));

    std:: cout << "side c : " << c;

    return 0;
}
