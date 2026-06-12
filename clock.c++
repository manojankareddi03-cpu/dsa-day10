#include <iostream>
#include <ctime>
#include <iomanip>
#include <thread>
#include <chrono>

using namespace std;

int main() {
    while (true) {
        time_t now = time(0);
        tm *ltm = localtime(&now);

        cout << "\rCurrent Time: "
             << setw(2) << setfill('0') << ltm->tm_hour << ":"
             << setw(2) << setfill('0') << ltm->tm_min << ":"
             << setw(2) << setfill('0') << ltm->tm_sec;

        cout.flush();

        this_thread::sleep_for(chrono::seconds(1));
    }

    return 0;
}
