//
//  HotelManagementSystem.cpp
//  projectfinal2
//
//  Created by Muhammad Tariq on 23/06/2024.
//

#include "HotelManagementSystem.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
using namespace std;

HotelManagementSystem::HotelManagementSystem(const string& filename) {
    loadRoomsFromFile(filename);
}

void HotelManagementSystem::loadRoomsFromFile(const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        while (file.peek() != EOF) {
            Room room;
            room.loadFromFile(file);
            rooms.push_back(room);
        }
        file.close();
    } else {
        cout << "Unable to open file" << endl;
    }
}

void HotelManagementSystem::displayHotelDescription() const {
    for (const auto& room : rooms) {
        room.displayRoomInfo();
        if (!room.getIsAvailable()) {
            cout << "Total Bill: $" << fixed << setprecision(2) << room.calculateBill() << endl;
        }
    }
}
void HotelManagementSystem::checkInCustomer(int roomNumber, string customerName, string checkInDate, string checkOutDate) {
    bool roomFound = false;
    for (auto& room : rooms) {
        if (room.getRoomNumber() == roomNumber && room.getIsAvailable()) {
            room.bookRoom(customerName, checkInDate, checkOutDate);
            roomFound = true;
            cout << "Room Number " << roomNumber << " has been checked in to " << customerName
                 << " from " << checkInDate << " to " << checkOutDate << "." << endl;
            cout << "Total Bill: $" << fixed << setprecision(2) << room.calculateBill() << endl;
            break;
        }
    }
    if (!roomFound) {
        cout << "Room Number " << roomNumber << " is either not available or does not exist." << endl;
    }
}


void HotelManagementSystem::checkOutCustomer(int roomNumber) {
    bool roomFound = false;
    for (auto& room : rooms) {
        if (room.getRoomNumber() == roomNumber && !room.getIsAvailable()) {
            cout << "Room Number " << roomNumber << " has been checked out." << endl;
            cout << "Total Bill: $" << fixed << setprecision(2) << room.calculateBill() << endl;
            room.checkoutRoom();
            roomFound = true;
            break;
        }
    }
    if (!roomFound) {
        cout << "Room Number " << roomNumber << " is either not booked or does not exist." << endl;
    }
}

void HotelManagementSystem::viewAvailableRooms() const {
    for (const auto& room : rooms) {
        if (room.getIsAvailable()) {
            room.displayRoomInfo();
        }
    }
}

void HotelManagementSystem::viewBookedRooms() const {
    for (const auto& room : rooms) {
        if (!room.getIsAvailable()) {
            room.displayRoomInfo();
        }
    }
}

void HotelManagementSystem::saveCurrentStateToFile(const string& filename) const {
    ofstream file(filename);
    if (file.is_open()) {
        for (const auto& room : rooms) {
            room.saveToFile(file);
        }
        file.close();
    } else {
        cout << "Unable to open file" << endl;
    }
}
