#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(0));

    int randomNumber = rand() % 100 + 1;
    int guess;
    int attempts = 0;

    cout << "=====================================\n";
    cout << "     NUMBER GUESSING GAME\n";
    cout << "=====================================\n";
    cout << "Guess a number between 1 and 100.\n";

    do
    {
        cout << "\nEnter your guess: ";
        cin >> guess;

        attempts++;

        if (guess > randomNumber)
        {
            cout << "📈 Too High! Try Again.\n";
        }
        else if (guess < randomNumber)
        {
            cout << "📉 Too Low! Try Again.\n";
        }
        else
        {
            cout << "\n🎉 Congratulations!\n";
            cout << "You guessed the correct number.\n";
            cout << "Number = " << randomNumber << endl;
            cout << "Attempts = " << attempts << endl;
        }

    } while (guess != randomNumber);

    return 0;
}
