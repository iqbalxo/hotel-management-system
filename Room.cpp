//
//  Room.cpp
//  projectfinal2
//
//  Created by Muhammad Tariq on 23/06/2024.
//

#include "Room.h"
#include <iostream>
#include <cmath>
using namespace std;

Room::Room(int number, string type, double price, bool available)
    : roomNumber(number), type(type), price(price), isAvailable(available), customerName(""), checkInDate(""), checkOutDate("") {}

int Room::getRoomNumber() const { return roomNumber; }
string Room::getType() const { return type; }
double Room::getPrice() const { return price; }
bool Room::getIsAvailable() const { return isAvailable; }
string Room::getCustomerName() const { return customerName; }
string Room::getCheckInDate() const { return checkInDate; }
string Room::getCheckOutDate() const { return checkOutDate; }

void Room::bookRoom(string customerName, string checkInDate, string checkOutDate) {
    if (isAvailable) {
        this->customerName = customerName;
        this->checkInDate = checkInDate;
        this->checkOutDate = checkOutDate;
        isAvailable = false;
    }
}

void Room::checkoutRoom() {
    if (!isAvailable) {
        customerName = "";
        checkInDate = "";
        checkOutDate = "";
        isAvailable = true;
    }
}

void Room::displayRoomInfo() const {
    cout << "Room Number: " << roomNumber << ", Type: " << type << ", Price: $" << price;
    if (isAvailable) {
        cout << ", Status: Available" << endl;
    } else {
        cout << ", Status: Booked, Customer: " << customerName << ", From: " << checkInDate << ", To: " << checkOutDate << endl;
    }
}

void Room::saveToFile(ofstream &outFile) const {
    outFile << roomNumber << " " << type << " " << price << " " << isAvailable << " ";
    if (!isAvailable) {
        outFile << customerName << " " << checkInDate << " " << checkOutDate;
    }
    outFile << endl;
}

void Room::loadFromFile(ifstream &inFile) {
    inFile >> roomNumber >> type >> price >> isAvailable;
    if (!isAvailable) {
        inFile >> customerName >> checkInDate >> checkOutDate;
    }
}
double Room::calculateBill() const {
    if (!isAvailable) {
        int nights = 0;
                if (!checkOutDate.empty() && !checkInDate.empty()) {
                    nights = static_cast<int>(ceil((stoi(checkOutDate.substr(8, 2)) - stoi(checkInDate.substr(8, 2))) / 24.0));
                }

               
                double bill = price * nights;
                return bill;
            } else {
                return 0.0; // Return 0 if room is available
            }
        }
