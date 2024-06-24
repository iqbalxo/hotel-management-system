//
//  HotelManagementSystem.h
//  projectfinal2
//
//  Created by Muhammad Tariq on 23/06/2024.
//

#ifndef HOTELMANAGEMENTSYSTEM_H
#define HOTELMANAGEMENTSYSTEM_H

#include "Room.h"
#include <vector>
using namespace std;

class HotelManagementSystem {
private:
    vector<Room> rooms;
    void loadRoomsFromFile(const string& filename);

public:
    HotelManagementSystem(const string& filename);
    void displayHotelDescription() const;
    void checkInCustomer(int roomNumber, string customerName, string checkInDate, string checkOutDate);
    void checkOutCustomer(int roomNumber);
    void viewAvailableRooms() const;
    void viewBookedRooms() const;
    void saveCurrentStateToFile(const string& filename) const;
};

#endif
