#include <iostream>
#include <string>
#include <chrono>

using namespace std;
using namespace std::chrono;

int main()
{
    string sentence =
        "Programming is the art of solving problems using code";

    cout << "=============================\n";
    cout << "      Typing Speed Test\n";
    cout << "=============================\n\n";

    cout << "Type the following sentence:\n\n";
    cout << sentence << "\n\n";

    cout << "Press Enter when you are ready...";
    cin.get();

    cout << "\nStart Typing:\n";

    auto start = high_resolution_clock::now();

    string userInput;
    getline(cin, userInput);

    auto stop = high_resolution_clock::now();

    auto duration =
        duration_cast<seconds>(stop - start);

    int timeTaken = duration.count();

    int correctChars = 0;

    for(int i = 0;
        i < min(sentence.length(), userInput.length());
        i++)
    {
        if(sentence[i] == userInput[i])
        {
            correctChars++;
        }
    }

    double accuracy =
        ((double)correctChars / sentence.length()) * 100;

    int wordCount = userInput.length() / 5;

    double wpm = 0;

    if(timeTaken > 0)
    {
        wpm = (wordCount * 60.0) / timeTaken;
    }

    cout << "\n========== RESULT ==========\n";
    cout << "Time Taken : "
         << timeTaken << " seconds\n";

    cout << "Accuracy   : "
         << accuracy << "%\n";

    cout << "Typing Speed : "
         << wpm << " WPM\n";

    return 0;
}
