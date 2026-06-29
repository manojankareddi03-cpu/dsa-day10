#include <iostream>
using namespace std;

void reverseString(string str, int index)
{
    if (index < 0)
        return;

    cout << str[index];

    reverseString(str, index - 1);
}

int main()
{
    string str;
    cin >> str;

    reverseString(str, str.length() - 1);

    return 0;
}
