//
//  main.cpp
//  projectfinal2
//
//  Created by Muhammad Tariq on 23/06/2024.
//

#include "HotelManagementSystem.h"
#include <iostream>
using namespace std;

void displayMenu() {
    cout << "1. Display Hotel Description" << endl;
    cout << "2. Check-in Customer" << endl;
    cout << "3. Check-out Customer" << endl;
    cout << "4. View Available Rooms" << endl;
    cout << "5. View Booked Rooms" << endl;
    cout << "6. Save Current State to File" << endl;
    cout << "7. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    HotelManagementSystem hms("hotel_data.txt");
    int choice;
    do {
        displayMenu();
        cin >> choice;
        switch (choice) {
            case 1:
                hms.displayHotelDescription();
                break;
            case 2: {
                int roomNumber;
                string customerName, checkInDate, checkOutDate;
                cout << "Enter Room Number: ";
                cin >> roomNumber;
                cout << "Enter Customer Name: ";
                cin >> customerName;
                cout << "Enter Check-in Date (YYYY-MM-DD): ";
                cin >> checkInDate;
                cout << "Enter Check-out Date (YYYY-MM-DD): ";
                cin >> checkOutDate;
                hms.checkInCustomer(roomNumber, customerName, checkInDate, checkOutDate);
                break;
            }
            case 3: {
                int roomNumber;
                cout << "Enter Room Number: ";
                cin >> roomNumber;
                hms.checkOutCustomer(roomNumber);
                break;
            }
            case 4:
                hms.viewAvailableRooms();
                break;
            case 5:
                hms.viewBookedRooms();
                break;
            case 6:
                hms.saveCurrentStateToFile("hotel_data.txt");
                break;
            case 7:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    } while (choice != 7);
    return 0;
}
