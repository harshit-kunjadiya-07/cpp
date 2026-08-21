#include <iostream>
using namespace std;

// ============================================================
// Base Class : Vehicle
// ============================================================
class Vehicle
{
private:
    int vehicleID;
    string manufacturer;
    string model;
    int year;

protected:
    void displayVehicleDetails()
    {
        cout << "Vehicle ID    : " << vehicleID << endl;
        cout << "Manufacturer  : " << manufacturer << endl;
        cout << "Model         : " << model << endl;
        cout << "Year          : " << year << endl;
    }

public:
    static int totalVehicles;

    // Default Constructor
    Vehicle()
    {
        vehicleID = 0;
        manufacturer = "";
        model = "";
        year = 0;
    }

    // Parameterized Constructor
    Vehicle(int id, string man, string mod, int y)
    {
        vehicleID = id;
        manufacturer = man;
        model = mod;
        year = y;

        totalVehicles++;
    }

    // Destructor
    virtual ~Vehicle()
    {
    }

    // Setters
    void setVehicleID(int id)
    {
        vehicleID = id;
    }

    void setManufacturer(string man)
    {
        manufacturer = man;
    }

    void setModel(string mod)
    {
        model = mod;
    }

    void setYear(int y)
    {
        year = y;
    }

    // Getters
    int getVehicleID()
    {
        return vehicleID;
    }

    string getManufacturer()
    {
        return manufacturer;
    }

    string getModel()
    {
        return model;
    }

    int getYear()
    {
        return year;
    }

    virtual void display()
    {
        displayVehicleDetails();
    }
};

// Initialize Static Member
int Vehicle::totalVehicles = 0;

// ============================================================
// Car
// Single Inheritance : Car -> Vehicle
// ============================================================
class Car : public Vehicle
{
private:
    string fuelType;

public:
    Car()
    {
        fuelType = "";
    }

    Car(int id, string man, string mod, int y, string fuel)
        : Vehicle(id, man, mod, y)
    {
        fuelType = fuel;
    }

    void setFuelType(string fuel)
    {
        fuelType = fuel;
    }

    string getFuelType()
    {
        return fuelType;
    }

    void display()
    {
        displayVehicleDetails();

        cout << "Fuel Type     : " << fuelType << endl;
    }
};

// ============================================================
// ElectricCar
// Multilevel Inheritance : ElectricCar -> Car -> Vehicle
// ============================================================
class ElectricCar : public Car
{
private:
    float batteryCapacity;

public:
    ElectricCar()
    {
        batteryCapacity = 0;
    }

    ElectricCar(int id, string man, string mod, int y,
                string fuel, float battery)
        : Car(id, man, mod, y, fuel)
    {
        batteryCapacity = battery;
    }

    void setBatteryCapacity(float battery)
    {
        batteryCapacity = battery;
    }

    float getBatteryCapacity()
    {
        return batteryCapacity;
    }

    void display()
    {
        displayVehicleDetails();

        cout << "Fuel Type     : " << getFuelType() << endl;
        cout << "Battery (kWh) : " << batteryCapacity << endl;
    }
};

// ============================================================
// SportsCar
// Multilevel Inheritance : SportsCar -> ElectricCar -> Car
// ============================================================
class SportsCar : public ElectricCar
{
private:
    int topSpeed;

public:
    SportsCar()
    {
        topSpeed = 0;
    }

    SportsCar(int id, string man, string mod, int y,
              string fuel, float battery, int speed)
        : ElectricCar(id, man, mod, y, fuel, battery)
    {
        topSpeed = speed;
    }

    void setTopSpeed(int speed)
    {
        topSpeed = speed;
    }

    int getTopSpeed()
    {
        return topSpeed;
    }

    void display()
    {
        displayVehicleDetails();

        cout << "Fuel Type     : " << getFuelType() << endl;
        cout << "Battery (kWh) : " << getBatteryCapacity() << endl;
        cout << "Top Speed     : " << topSpeed << " km/h" << endl;
    }
};

// ============================================================
// Aircraft
// Base Class for Multiple Inheritance
// ============================================================
class Aircraft
{
private:
    int flightRange;

public:
    Aircraft()
    {
        flightRange = 0;
    }

    Aircraft(int range)
    {
        flightRange = range;
    }

    void setFlightRange(int range)
    {
        flightRange = range;
    }

    int getFlightRange()
    {
        return flightRange;
    }

    void displayAircraft()
    {
        cout << "Flight Range  : " << flightRange << " km" << endl;
    }
};

// ============================================================
// FlyingCar
// Multiple Inheritance : FlyingCar -> Car + Aircraft
// ============================================================
class FlyingCar : public Car, public Aircraft
{
public:
    FlyingCar()
    {
    }

    FlyingCar(int id, string man, string mod, int y,
              string fuel, int range)
        : Car(id, man, mod, y, fuel),
          Aircraft(range)
    {
    }

    void display()
    {
        displayVehicleDetails();

        cout << "Fuel Type     : " << getFuelType() << endl;
        displayAircraft();
    }
};

// ============================================================
// Sedan
// Hierarchical Inheritance : Sedan -> Car
// ============================================================
class Sedan : public Car
{
public:
    Sedan()
    {
    }

    Sedan(int id, string man, string mod, int y, string fuel)
        : Car(id, man, mod, y, fuel)
    {
    }

    void display()
    {
        displayVehicleDetails();

        cout << "Fuel Type     : " << getFuelType() << endl;
        cout << "Vehicle Type  : Sedan" << endl;
    }
};

// ============================================================
// SUV
// Hierarchical Inheritance : SUV -> Car
// ============================================================
class SUV : public Car
{
public:
    SUV()
    {
    }

    SUV(int id, string man, string mod, int y, string fuel)
        : Car(id, man, mod, y, fuel)
    {
    }

    void display()
    {
        displayVehicleDetails();

        cout << "Fuel Type     : " << getFuelType() << endl;
        cout << "Vehicle Type  : SUV" << endl;
    }
};

// ============================================================
// Vehicle Registry
// ============================================================
class VehicleRegistry
{
private:
    Vehicle *vehicles[50];
    int count;

public:
    VehicleRegistry()
    {
        count = 0;

        for (int i = 0; i < 50; i++)
        {
            vehicles[i] = NULL;
        }
    }

    ~VehicleRegistry()
    {
        for (int i = 0; i < count; i++)
        {
            delete vehicles[i];
        }
    }

    // Add Vehicle
    void addVehicle()
    {
        int choice;

        cout << "\n========================================\n";
        cout << "          ADD NEW VEHICLE\n";
        cout << "========================================\n";

        cout << "1. Car\n";
        cout << "2. Electric Car\n";
        cout << "3. Sports Car\n";
        cout << "4. Flying Car\n";
        cout << "5. Sedan\n";
        cout << "6. SUV\n";

        cout << "\nEnter Vehicle Type : ";
        cin >> choice;

        int id, year;
        string manufacturer, model, fuel;
        float battery;
        int speed, range;

        cout << "\nEnter Vehicle ID   : ";
        cin >> id;

        // Check duplicate ID
        for (int i = 0; i < count; i++)
        {
            if (vehicles[i]->getVehicleID() == id)
            {
                cout << "\nVehicle ID already exists!\n";
                return;
            }
        }

        cout << "Enter Manufacturer : ";
        cin >> manufacturer;

        cout << "Enter Model        : ";
        cin >> model;

        cout << "Enter Year         : ";
        cin >> year;

        switch (choice)
        {
        case 1:
            cout << "Enter Fuel Type    : ";
            cin >> fuel;

            vehicles[count] =
                new Car(id, manufacturer, model, year, fuel);

            count++;

            cout << "\nCar added successfully!\n";
            break;

        case 2:
            cout << "Enter Fuel Type    : ";
            cin >> fuel;

            cout << "Battery Capacity (kWh) : ";
            cin >> battery;

            vehicles[count] =
                new ElectricCar(id, manufacturer, model,
                                year, fuel, battery);

            count++;

            cout << "\nElectric Car added successfully!\n";
            break;

        case 3:
            cout << "Enter Fuel Type    : ";
            cin >> fuel;

            cout << "Battery Capacity (kWh) : ";
            cin >> battery;

            cout << "Top Speed (km/h)  : ";
            cin >> speed;

            vehicles[count] =
                new SportsCar(id, manufacturer, model,
                              year, fuel, battery, speed);

            count++;

            cout << "\nSports Car added successfully!\n";
            break;

        case 4:
            cout << "Enter Fuel Type    : ";
            cin >> fuel;

            cout << "Flight Range (km) : ";
            cin >> range;

            vehicles[count] =
                new FlyingCar(id, manufacturer, model,
                              year, fuel, range);

            count++;

            cout << "\nFlying Car added successfully!\n";
            break;

        case 5:
            cout << "Enter Fuel Type    : ";
            cin >> fuel;

            vehicles[count] =
                new Sedan(id, manufacturer, model, year, fuel);

            count++;

            cout << "\nSedan added successfully!\n";
            break;

        case 6:
            cout << "Enter Fuel Type    : ";
            cin >> fuel;

            vehicles[count] =
                new SUV(id, manufacturer, model, year, fuel);

            count++;

            cout << "\nSUV added successfully!\n";
            break;

        default:
            cout << "\nInvalid Vehicle Type!\n";
        }
    }

    // Display All Vehicles
    void displayAllVehicles()
    {
        if (count == 0)
        {
            cout << "\nNo vehicles available in registry.\n";
            return;
        }

        cout << "\n========================================\n";
        cout << "          ALL REGISTERED VEHICLES\n";
        cout << "========================================\n";

        for (int i = 0; i < count; i++)
        {
            cout << "\n---------- Vehicle " << i + 1 << " ----------\n";

            vehicles[i]->display();
        }

        cout << "\n========================================\n";
        cout << "Total Vehicles : " << Vehicle::totalVehicles << endl;
        cout << "========================================\n";
    }

    // Search Vehicle By ID
    void searchVehicle()
    {
        int id;
        bool found = false;

        cout << "\nEnter Vehicle ID to Search : ";
        cin >> id;

        for (int i = 0; i < count; i++)
        {
            if (vehicles[i]->getVehicleID() == id)
            {
                cout << "\n========================================\n";
                cout << "           VEHICLE FOUND\n";
                cout << "========================================\n";

                vehicles[i]->display();

                cout << "========================================\n";

                found = true;
                break;
            }
        }

        if (!found)
        {
            cout << "\nVehicle with ID " << id
                 << " not found.\n";
        }
    }
};

// ============================================================
// Main Function
// ============================================================
int main()
{
    VehicleRegistry registry;

    int choice;

    do
    {
        cout << "\n\n========================================\n";
        cout << "       VEHICLE REGISTRY SYSTEM\n";
        cout << "========================================\n";

        cout << "1. Add Vehicle\n";
        cout << "2. View All Vehicles\n";
        cout << "3. Search Vehicle by ID\n";
        cout << "4. Exit\n";

        cout << "========================================\n";
        cout << "Enter Your Choice : ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            registry.addVehicle();
            break;

        case 2:
            registry.displayAllVehicles();
            break;

        case 3:
            registry.searchVehicle();
            break;

        case 4:
            cout << "\nThank you for using Vehicle Registry System!\n";
            cout << "Program ended successfully.\n";
            break;

        default:
            cout << "\nInvalid choice! Please try again.\n";
        }

    } while (choice != 4);

    return 0;
}