#include <iostream>
#include <string>
using namespace std;

class Vehicle {
public:
    string licensePlate;
    string color;
    int speed;
    Vehicle* next;

    Vehicle(string l, string c, int s) {
        licensePlate = l;
        color = c;
        speed = s;
        next = nullptr;
    }

    void print() {
        cout << licensePlate << " - " << color << " - " << speed << " mph\n";
    }
};

class TrafficSystem {
public:
    Vehicle* head;
    int count;

    TrafficSystem() {
        head = nullptr;
        count = 0;
    }

    void addVehicle() {
        string l, c;
        int s;
        cout << "Enter vehicle details (license plate, color, speed): ";
        cin >> l >> c >> s;
        Vehicle* v = new Vehicle(l, c, s);
        if (head == nullptr) {
            head = v;
        }
        else {
            Vehicle* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = v;
        }
        count++;
        cout << "Vehicle added.\n";
    }

    void removeVehicle() {
        if (head == nullptr) {
            cout << "There are no vehicles in the system.\n";
        }
        else {
            string l;
            cout << "Enter the license plate of the vehicle to remove: ";
            cin >> l;
            Vehicle* current = head;
            Vehicle* previous = nullptr;
            while (current != nullptr && current->licensePlate != l) {
                previous = current;
                current = current->next;
            }
            if (current == nullptr) {
                cout << "Vehicle not found.\n";
            }
            else {
                if (previous == nullptr) {
                    head = current->next;
                }
                else {
                    previous->next = current->next;
                }
                delete current;
                count--;
                cout << "Vehicle removed.\n";
            }
        }
    }

    void displayVehicles() {
        if (head == nullptr) {
            cout << "There are no vehicles in the system.\n";
        }
        else {
            cout << "License Plate - Color - Speed\n";
            Vehicle* current = head;
            while (current != nullptr) {
                current->print();
                current = current->next;
            }
            cout << "Total vehicles: " << count << endl;
        }
    }
};

int main() {
    TrafficSystem ts;
    int choice;
    do {
        cout << "\nTraffic Management System Menu\n";
        cout << "1. Add Vehicle\n";
        cout << "2. Remove Vehicle\n";
        cout << "3. Display Vehicles\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            ts.addVehicle();
            break;
        case 2:
            ts.removeVehicle();
            break;
        case 3:
            ts.displayVehicles();
            break;
        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice.\n";
            break;
        }
    } while (choice != 4);
    return 0;
}





/* output
Traffic Management System Menu
1. Add Vehicle
2. Remove Vehicle
3. Display Vehicles
4. Exit
Enter your choice: 1
Enter vehicle details (license plate, color, speed): ABC-123 Red 50
Vehicle added.

Traffic Management System Menu
1. Add Vehicle
2. Remove Vehicle
3. Display Vehicles
4. Exit
Enter your choice: 1
Enter vehicle details (license plate, color, speed): XYZ-789 Blue 60
Vehicle added.

Traffic Management System Menu
1. Add Vehicle
2. Remove Vehicle
3. Display Vehicles
4. Exit
Enter your choice: 3
License Plate - Color - Speed
ABC-123 - Red - 50 mph
XYZ-789 - Blue - 60 mph
Total vehicles: 2

Traffic Management System Menu
1. Add Vehicle
2. Remove Vehicle
3. Display Vehicles
4. Exit
Enter your choice: 2
Enter the license plate of the vehicle to remove: ABC-123
Vehicle removed.

Traffic Management System Menu
1. Add Vehicle
2. Remove Vehicle
3. Display Vehicles
4. Exit
Enter your choice: 3
License Plate - Color - Speed
XYZ-789 - Blue - 60 mph
Total vehicles: 1

Traffic Management System Menu
1. Add Vehicle
2. Remove Vehicle
3. Display Vehicles
4. Exit
Enter your choice: 4
Exiting...

*/
