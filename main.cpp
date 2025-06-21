#include<iostream>
#include<fstream>  // For file handling
#include "car.class.cpp"
#include "customer.class.cpp"
#include "rentalrecord.class.cpp"
#include "admin.cpp"

using namespace std;

#define MAX_CARS 100
#define MAX_RECORDS 100

Car cars[MAX_CARS];
RentalRecord rentalHistory[MAX_RECORDS];
int carCount = 0;
int rentalCount = 0;

// Updated admin login function to use the Admin class
bool adminLogin() {
    Admin admin;
    return admin.login();
}

// Function to view car details
void viewCarDetails(const Car& car) {
    cout << "Car ID: " << car.getCarID()
         << ", Brand: " << car.getBrand()
         << ", Model: " << car.getModel()
         << ", Price/Day: $" << car.getPricePerDay()
         << ", Available: " << (car.isAvailable() ? "Yes" : "No") << endl;
}

int main() {
    Customer customer1(201, "John Doe", "123-456-789");

    // Pre-adding some cars into the system
    cars[carCount++] = Car(101, "Toyota", "Corolla", 50.0, true);
    cars[carCount++] = Car(102, "Honda", "Civic", 60.0, true);
    cars[carCount++] = Car(103, "Suzuki", "Alto", 30.0, true);
    cars[carCount++] = Car(104, "Kia", "Sportage", 70.0, true);
    cars[carCount++] = Car(105, "Hyundai", "Elantra", 55.0, true);

    int mainChoice;
    bool exitProgram = false;

    cout << "===== Welcome to Car Rental System =====\n";

    while (!exitProgram) {
        cout << "\n1. Customer Portal\n2. Admin Portal\n3. Exit\nEnter Choice: ";
        cin >> mainChoice;

        if (mainChoice == 1) {
            int custChoice;
            do {
                cout << "\n--- Customer Menu ---\n";
                cout << "1. View Available Cars\n";
                cout << "2. Rent a Car\n";
                cout << "3. Return Car\n";
                cout << "4. View Rental Record\n";
                cout << "5. Back to Main Menu\n";
                cout << "Enter Choice: ";
                cin >> custChoice;

                if (custChoice == 1) {
                    cout << "\nAvailable Cars:\n";
                    for (int i = 0; i < carCount; i++) {
                        if (cars[i].isAvailable())
                            viewCarDetails(cars[i]);
                    }
                }
                else if (custChoice == 2) {
                    int carID, days;
                    cout << "\nEnter Car ID to rent: ";
                    cin >> carID;

                    bool found = false;
                    for (int i = 0; i < carCount; i++) {
                        if (cars[i].getCarID() == carID && cars[i].isAvailable()) {
                            found = true;
                            customer1.rentCar(carID);
                            cars[i].markUnavailable();

                            cout << "Enter number of days to rent: ";
                            cin >> days;

                            rentalHistory[rentalCount++] = RentalRecord(rentalCount + 301, customer1.getCustomerID(), carID, days, cars[i].getPricePerDay());

                            cout << "Car rented successfully!\n";
                            break;
                        }
                    }
                    if (!found) cout << "Car not available!\n";
                }
                else if (custChoice == 3) {
                    cout << "\nReturning car...\n";
                    int rentedID = customer1.getRentedCarID();
                    for (int i = 0; i < carCount; i++) {
                        if (cars[i].getCarID() == rentedID) {
                            cars[i].markAvailable();
                            break;
                        }
                    }
                    customer1.returnCar();
                    cout << "Car returned successfully!\n";
                }
                else if (custChoice == 4) {
                    cout << "\n--- Rental History ---\n";
                    for (int i = 0; i < rentalCount; i++) {
                        rentalHistory[i].displayRecord();
                    }
                }
                else if (custChoice == 5) {
                    break;
                }
                else {
                    cout << "Invalid Choice! Try again.\n";
                }

            } while (custChoice != 5);
        }

        else if (mainChoice == 2) {
            if (adminLogin()) {
                int adminChoice;
                do {
                    cout << "\n--- Admin Menu ---\n";
                    cout << "1. Add New Car\n";
                    cout << "2. View All Cars\n";
                    cout << "3. View Rental Records\n";
                    cout << "4. Back to Main Menu\n";
                    cout << "Enter Choice: ";
                    cin >> adminChoice;

                    if (adminChoice == 1) {
                        int id;
                        string brand, model;
                        float price;
                        cout << "Enter Car ID: "; cin >> id;
                        cout << "Enter Brand: "; cin >> brand;
                        cout << "Enter Model: "; cin >> model;
                        cout << "Enter Price/Day: "; cin >> price;

                        if (carCount < MAX_CARS) {
                            cars[carCount++] = Car(id, brand, model, price, true);
                            cout << "Car added successfully!\n";
                        } else {
                            cout << "Car list is full!\n";
                        }
                    }
                    else if (adminChoice == 2) {
                        cout << "\nAll Cars:\n";
                        for (int i = 0; i < carCount; i++) {
                            viewCarDetails(cars[i]);
                        }
                    }
                    else if (adminChoice == 3) {
                        cout << "\nRental History:\n";
                        for (int i = 0; i < rentalCount; i++) {
                            rentalHistory[i].displayRecord();
                        }
                    }
                    else if (adminChoice == 4) {
                        break;
                    }
                    else {
                        cout << "Invalid Choice! Try again.\n";
                    }

                } while (adminChoice != 4);
            }
            else {
                cout << "Wrong password!\n";
            }
        }

        else if (mainChoice == 3) {
            exitProgram = true;
            cout << "Exiting system. Thank you!\n";
        }
        else {
            cout << "Invalid Choice! Try again.\n";
        }
    }

    return 0;
}