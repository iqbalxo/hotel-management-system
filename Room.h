//
//  Room.h
//  projectfinal2
//
//  Created by Muhammad Tariq on 23/06/2024.
//

#ifndef ROOM_H
#define ROOM_H

#include <string>
#include <fstream>
using namespace std;

class Room {
private:
    int roomNumber;
    string type;
    double price;
    bool isAvailable;
    string customerName;
    string checkInDate;
    string checkOutDate;

public:
    Room(int number, string type, double price, bool available);
    Room() = default;  // Default constructor for file I/O
    int getRoomNumber() const;
    string getType() const;
    double getPrice() const;
    bool getIsAvailable() const;
    string getCustomerName() const;
    string getCheckInDate() const;
    string getCheckOutDate() const;
    void bookRoom(string customerName, string checkInDate, string checkOutDate);
    void checkoutRoom();
    void displayRoomInfo() const;
    void saveToFile(ofstream &outFile) const;  // Save room details to file
    void loadFromFile(ifstream &inFile);  // Load room details from file
    double calculateBill() const;
};

#endif
