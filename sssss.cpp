#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

// Structure for Room details
struct Room {
    string name;
    string category;
    double price;
    string amenities;
};

// Structure for Guest details
struct Guest {
    string name;
    string email;
    string phone;
    string specialRequest;
};

// Structure for Booking details
struct Booking {
    int bookingID;
    Room room;
    Guest guest;
    string checkInDate;
    string checkOutDate;
};

// Global data
vector<Room> availableRooms;
map<int, Booking> bookings;
int bookingCounter = 1;

// Functions for each interface
void displayHomePage() {
    cout << "\n=== Royal Hotel Online Reservation ===\n";
    cout << "Welcome to luxury and refinement.\n";
    cout << "1. Explore Rooms\n2. Book a Room\n3. Learn More\n4. Contact Us\n5. Exit\n";
}

void displayRooms() {
    cout << "\n=== Available Rooms ===\n";
    for (size_t i = 0; i < availableRooms.size(); i++) {
        cout << i + 1 << ". " << availableRooms[i].name << " (" << availableRooms[i].category << ")\n";
        cout << "   Price: $" << availableRooms[i].price << " per night\n";
        cout << "   Amenities: " << availableRooms[i].amenities << "\n";
    }
}

void viewRoomDetails(int roomIndex) {
    if (roomIndex < 0 || roomIndex >= availableRooms.size()) {
        cout << "Invalid room selection.\n";
        return;
    }
    Room room = availableRooms[roomIndex];
    cout << "\n=== Room Details ===\n";
    cout << "Name: " << room.name << "\nCategory: " << room.category << "\n";
    cout << "Price: $" << room.price << " per night\n";
    cout << "Amenities: " << room.amenities << "\n";
}

void bookRoom(int roomIndex) {
    if (roomIndex < 0 || roomIndex >= availableRooms.size()) {
        cout << "Invalid room selection.\n";
        return;
    }
    Guest guest;
    Room room = availableRooms[roomIndex];

    cout << "\n=== Booking Form ===\n";
    cout << "Name: "; getline(cin, guest.name);
    cout << "Email: "; getline(cin, guest.email);
    cout << "Phone: "; getline(cin, guest.phone);
    cout << "Special Requests: "; getline(cin, guest.specialRequest);

    Booking booking;
    booking.bookingID = bookingCounter++;
    booking.room = room;
    booking.guest = guest;
    cout << "Check-in Date (YYYY-MM-DD): ";
    cin >> booking.checkInDate;
    cout << "Check-out Date (YYYY-MM-DD): ";
    cin >> booking.checkOutDate;
    cin.ignore(); // Ignore newline character from previous input

    bookings[booking.bookingID] = booking;

    cout << "Room successfully booked! Booking ID: " << booking.bookingID << "\n";
}

void displayBookings() {
    cout << "\n=== My Bookings ===\n";
    for (const auto &entry : bookings) {
        const Booking &booking = entry.second;
        cout << "Booking ID: " << booking.bookingID << "\n";
        cout << "Room: " << booking.room.name << " (" << booking.room.category << ")\n";
        cout << "Guest: " << booking.guest.name << "\n";
        cout << "Dates: " << booking.checkInDate << " to " << booking.checkOutDate << "\n";
        cout << "---------------------------------\n";
    }
}

void contactUs() {
    cout << "\n=== Contact Us ===\n";
    cout << "Phone: +123 456 7890\nEmail: contact@royalhotel.com\n";
    cout << "Address: 123 Luxury St, Royal City\n";
}

int main() {
    // Populate sample rooms
    availableRooms.push_back({"Deluxe Room", "Deluxe", 200, "WiFi, TV, Mini Bar"});
    availableRooms.push_back({"Executive Suite", "Suite", 400, "WiFi, TV, Kitchen, Living Area"});
    availableRooms.push_back({"Presidential Suite", "Suite", 800, "Private Pool, Butler Service, Luxury Amenities"});

    while (true) {
        displayHomePage();
        int choice;
        cout << "Select an option: ";
        cin >> choice;
        cin.ignore(); // Ignore newline character from input

        switch (choice) {
            case 1:
                displayRooms();
                break;
            case 2: {
                int roomChoice;
                displayRooms();
                cout << "Select a room number to book: ";
                cin >> roomChoice;
                cin.ignore(); // Ignore newline character from input
                bookRoom(roomChoice - 1);
                break;
            }
            case 3:
                cout << "\nExperience unmatched luxury at the Royal Hotel. Visit us to explore premium services.\n";
                break;
            case 4:
                contactUs();
                break;
            case 5:
                cout << "Thank you for visiting Royal Hotel. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}
