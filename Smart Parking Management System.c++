#include <iostream>
#include <vector>
#include <unordered_map>
#include <ctime>

using namespace std;

class Vehicle {
public:
    string number;
    string type;
    time_t entryTime;

    Vehicle(string num, string t) {
        number = num;
        type = t;
        entryTime = time(0);
    }
};

class ParkingLot {
private:
    int totalSlots;
    int occupiedSlots;

    unordered_map<string, Vehicle> parkedVehicles;

public:
    ParkingLot(int slots) {
        totalSlots = slots;
        occupiedSlots = 0;
    }

    void parkVehicle(string number, string type) {

        if (occupiedSlots >= totalSlots) {
            cout << "Parking Full!\n";
            return;
        }

        parkedVehicles.emplace(number, Vehicle(number, type));

        occupiedSlots++;

        cout << "Vehicle parked successfully.\n";
        cout << "Allocated Slot: " << occupiedSlots << endl;
    }

    void exitVehicle(string number) {

        auto it = parkedVehicles.find(number);

        if (it == parkedVehicles.end()) {
            cout << "Vehicle not found.\n";
            return;
        }

        time_t exitTime = time(0);

        double hours = difftime(exitTime,
                                it->second.entryTime) / 3600.0;

        if (hours < 1)
            hours = 1;

        double fee = hours * 30;

        cout << "\n----- BILL -----\n";
        cout << "Vehicle: " << number << endl;
        cout << "Hours: " << hours << endl;
        cout << "Amount: Rs." << fee << endl;

        parkedVehicles.erase(it);

        occupiedSlots--;
    }

    void displayStatus() {

        cout << "\nAvailable Slots: "
             << totalSlots - occupiedSlots << endl;

        cout << "Occupied Slots: "
             << occupiedSlots << endl;
    }
};

int main() {

    ParkingLot lot(10);

    int choice;
    string number, type;

    while (true) {

        cout << "\n1. Park Vehicle\n";
        cout << "2. Exit Vehicle\n";
        cout << "3. Parking Status\n";
        cout << "4. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {

        case 1:
            cout << "Vehicle Number: ";
            cin >> number;

            cout << "Vehicle Type: ";
            cin >> type;

            lot.parkVehicle(number, type);
            break;

        case 2:
            cout << "Vehicle Number: ";
            cin >> number;

            lot.exitVehicle(number);
            break;

        case 3:
            lot.displayStatus();
            break;

        case 4:
            return 0;

        default:
            cout << "Invalid choice\n";
        }
    }
}
