#include <iostream>
#include <string>
using namespace std;

// Base class for all vehicles
class Vehicle {
protected:
    string vehicleID;
    string manufacturer;
    string model;
    int year;
    static int totalVehicles;

public:
    // Constructor
    Vehicle(const string& id, const string& man, const string& mod, int yr)
        : vehicleID(id), manufacturer(man), model(mod), year(yr) {
        totalVehicles++;
    }

    // Destructor
    virtual ~Vehicle() {
        totalVehicles--;
    }

    // Static method to get total vehicle count
    static int getTotalVehicles() {
        return totalVehicles;
    }

    // Getter for vehicle ID
    string getVehicleID() const {
        return vehicleID;
    }

    // Method to display vehicle details
    virtual void display() const {
        cout << "ID: " << vehicleID << ", Manufacturer: " << manufacturer
             << ", Model: " << model << ", Year: " << year << endl;
    }
};

int Vehicle::totalVehicles = 0;

// Derived class for Car
class Car : public Vehicle {
protected:
    string fuelType;

public:
    // Constructor
    Car(const string& id, const string& man, const string& mod, int yr, const string& fuel)
        : Vehicle(id, man, mod, yr), fuelType(fuel) {}

    // Overriding display method
    void display() const override {
        Vehicle::display();
        cout << "Fuel Type: " << fuelType << endl;
    }
};

// Derived class for ElectricCar
class ElectricCar : public Car {
protected:
    int batteryCapacity;

public:
    // Constructor
    ElectricCar(const string& id, const string& man, const string& mod, int yr, const string& fuel, int battery)
        : Car(id, man, mod, yr, fuel), batteryCapacity(battery) {}

    // Overriding display method
    void display() const override {
        Car::display();
        cout << "Battery Capacity: " << batteryCapacity << " kWh" << endl;
    }
};

// Base class for Aircraft
class Aircraft {
protected:
    int flightRange;

public:
    // Constructor
    Aircraft(int range) : flightRange(range) {}

    // Method to display aircraft details
    virtual void display() const {
        cout << "Flight Range: " << flightRange << " km" << endl;
    }
};

// Derived class for FlyingCar (Multiple Inheritance)
class FlyingCar : public Car, public Aircraft {
public:
    // Constructor
    FlyingCar(const string& id, const string& man, const string& mod, int yr, const string& fuel, int range)
        : Car(id, man, mod, yr, fuel), Aircraft(range) {}

    // Overriding display method
    void display() const override {
        Car::display();
        Aircraft::display();
    }
};

// Derived class for SportsCar (Multilevel Inheritance)
class SportsCar : public ElectricCar {
protected:
    int topSpeed;

public:
    // Constructor
    SportsCar(const string& id, const string& man, const string& mod, int yr, const string& fuel, int battery, int speed)
        : ElectricCar(id, man, mod, yr, fuel, battery), topSpeed(speed) {}

    // Overriding display method
    void display() const override {
        ElectricCar::display();
        cout << "Top Speed: " << topSpeed << " km/h" << endl;
    }
};

// Derived class for Sedan (Hierarchical Inheritance)
class Sedan : public Car {
public:
    // Constructor
    Sedan(const string& id, const string& man, const string& mod, int yr, const string& fuel)
        : Car(id, man, mod, yr, fuel) {}

    // Overriding display method
    void display() const override {
        cout << "Sedan: ";
        Car::display();
    }
};

// Derived class for SUV (Hierarchical Inheritance)
class SUV : public Car {
public:
    // Constructor
    SUV(const string& id, const string& man, const string& mod, int yr, const string& fuel)
        : Car(id, man, mod, yr, fuel) {}

    // Overriding display method
    void display() const override {
        cout << "SUV: ";
        Car::display();
    }
};

// Class to manage vehicle registration
class VehicleRegistry {
private:
    Vehicle** vehicles;  // Array of pointers to Vehicle objects
    int capacity;        // Array capacity
    int count;           // Number of vehicles currently registered

    // Method to resize the array when capacity is reached
    void resize() {
        int newCapacity = capacity * 2;
        Vehicle** newVehicles = new Vehicle*[newCapacity];

        for (int i = 0; i < count; i++) {
            newVehicles[i] = vehicles[i];
        }

        delete[] vehicles;
        vehicles = newVehicles;
        capacity = newCapacity;
    }

public:
    // Constructor
    VehicleRegistry(int initialCapacity = 10) : capacity(initialCapacity), count(0) {
        vehicles = new Vehicle*[capacity];
    }

    // Destructor
    ~VehicleRegistry() {
        for (int i = 0; i < count; i++) {
            delete vehicles[i];
        }
        delete[] vehicles;
    }

    // Method to add a new vehicle to the registry
    void addVehicle(Vehicle* vehicle) {
        if (count == capacity) {
            resize();
        }
        vehicles[count++] = vehicle;
    }

    // Method to display all registered vehicles
    void displayAllVehicles() const {
        for (int i = 0; i < count; i++) {
            vehicles[i]->display();
            cout << "---------------------" << endl;
        }
    }

    // Method to search for a vehicle by ID
    Vehicle* searchVehicleById(const string& id) const {
        for (int i = 0; i < count; i++) {
            if (vehicles[i]->getVehicleID() == id) {
                return vehicles[i];
            }
        }
        return nullptr;
    }
};

// Main function with a menu-driven approach
int main() {
    VehicleRegistry registry;
    int choice;

    do {
        cout << "Vehicle Registry System" << endl;
        cout << "1. Add Vehicle" << endl;
        cout << "2. View All Vehicles" << endl;
        cout << "3. Search Vehicle by ID" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        string id, man, mod, fuel;
        int year, battery, range, speed;

        switch (choice) {
            case 1:
                cout << "Enter Vehicle ID: ";
                cin >> id;
                cout << "Enter Manufacturer: ";
                cin >> man;
                cout << "Enter Model: ";
                cin >> mod;
                cout << "Enter Year: ";
                cin >> year;

                cout << "Select Vehicle Type:\n1. Car\n2. Electric Car\n3. Flying Car\n4. Sports Car\n5. Sedan\n6. SUV\n7. Aircraft" << endl;
                int type;
                cin >> type;

                switch (type) {
                    case 1:
                        cout << "Enter Fuel Type: ";
                        cin >> fuel;
                        registry.addVehicle(new Car(id, man, mod, year, fuel));
                        break;
                    case 2:
                        cout << "Enter Fuel Type: ";
                        cin >> fuel;
                        cout << "Enter Battery Capacity (kWh): ";
                        cin >> battery;
                        registry.addVehicle(new ElectricCar(id, man, mod, year, fuel, battery));
                        break;
                    case 3:
                        cout << "Enter Fuel Type: ";
                        cin >> fuel;
                        cout << "Enter Flight Range (km): ";
                        cin >> range;
                        registry.addVehicle(new FlyingCar(id, man, mod, year, fuel, range));
                        break;
                    case 4:
                        cout << "Enter Fuel Type: ";
                        cin >> fuel;
                        cout << "Enter Battery Capacity (kWh): ";
                        cin >> battery;
                        cout << "Enter Top Speed (km/h): ";
                        cin >> speed;
                        registry.addVehicle(new SportsCar(id, man, mod, year, fuel, battery, speed));
                        break;
                    case 5:
                        cout << "Enter Fuel Type: ";
                        cin >> fuel;
                        registry.addVehicle(new Sedan(id, man, mod, year, fuel));
                        break;
                    case 6:
                        cout << "Enter Fuel Type: ";
                        cin >> fuel;
                        registry.addVehicle(new SUV(id, man, mod, year, fuel));
                        break;
                    case 7: 
                
                         cout << "Enter flightrange: ";
                        cin >> range;
                        registry.addVehicle(new FlyingCar(id, man, mod, year, fuel, range));
                
                    default:
                        cout << "Invalid vehicle type selected." << endl;
                }
                break;
            case 2:
                registry.displayAllVehicles();
                break;
            case 3:
                cout << "Enter Vehicle ID to search: ";
                cin >> id;
                if (Vehicle* vehicle = registry.searchVehicleById(id)) {
                    vehicle->display();
                } else {
                    cout << "Vehicle not found." << endl;
                }
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
