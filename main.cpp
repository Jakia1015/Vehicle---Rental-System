#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <stdexcept>
using namespace std;

// Person Base Class
class Person
{
protected:
    int id;
    string name;

public:

    Person()
    {
        id = 0;
        name = "";
    }

    Person(int i, string n)
    {
        id = i;
        name = n;
    }

    virtual void displayInfo() = 0;


    virtual ~Person()
    {

    }
};

// Vehicle Class
class Vehicle
{
private:
    // Vehicle information
    int vehicleID;
    string vehicleName;
    string brand;
    float rentPerDay;
    string status;

public:

    // Default Constructor
    Vehicle()
    {
        vehicleID = 0;
        vehicleName = "";
        brand = "";
        rentPerDay = 0;
        status = "Available";
    }

    // Parameterized Constructor
    Vehicle(int id, string name, string vehicleBrand, float rent, string vehicleStatus)
    {
        vehicleID = id;
        vehicleName = name;
        brand = vehicleBrand;
        rentPerDay = rent;
        status = vehicleStatus;
    }

    // Destructor
    ~Vehicle()
    {

    }


    // Take vehicle information
    void inputVehicle()
    {
        cout << "\nEnter Vehicle ID: ";
        cin >> vehicleID;

        cin.ignore();

        cout << "Enter Vehicle Name: ";
        getline(cin, vehicleName);

        cout << "Enter Brand: ";
        getline(cin, brand);

        cout << "Enter Rent Per Day: ";
        cin >> rentPerDay;

        status = "Available";
    }


    // Display vehicle in table format
    void displayVehicle()
{
    cout << left
         << setw(10) << vehicleID
         << setw(20) << vehicleName
         << setw(20) << brand
         << setw(12) << rentPerDay
         << setw(15) << status
         << endl;
}
    // Getter Functions
int getID()
{
    return vehicleID;
}

string getName()
{
    return vehicleName;
}

string getBrand()
{
    return brand;
}

float getRent()
{
    return rentPerDay;
}

string getStatus()
{
    return status;
}
void setStatus(string newStatus)
{
    status = newStatus;
}

bool isAvailable()
{
    return (status == "Available");
}
friend void showVehicleDetails(Vehicle v);
};

void showVehicleDetails(Vehicle v)
{
    cout << "\n========== VEHICLE DETAILS ==========\n";
    cout << "Vehicle ID   : " << v.vehicleID << endl;
    cout << "Vehicle Name : " << v.vehicleName << endl;
    cout << "Brand        : " << v.brand << endl;
    cout << "Rent Per Day : " << v.rentPerDay << endl;
    cout << "Status       : " << v.status << endl;
}

// Customer Class (Derived Class)
class Customer : public Person
{
private:
    string phone;
    string address;

public:

    Customer()
    {
        phone = "";
        address = "";
    }

    Customer(int i, string n, string p, string a) : Person(i, n)
    {
        phone = p;
        address = a;
    }

    void inputCustomer()
    {
        cout << "\nEnter Customer ID: ";
        cin >> id;

        cin.ignore();

        cout << "Enter Customer Name: ";
        getline(cin, name);

        cout << "Enter Phone Number: ";
        getline(cin, phone);

        cout << "Enter Address: ";
        getline(cin, address);
    }
    // Function Overriding (Polymorphism)
   void displayInfo() override
{
    cout << left
         << setw(10) << id
         << setw(20) << name
         << setw(20) << phone
         << setw(20) << address
         << endl;
}

    int getID()
    {
        return id;
    }

    string getName()
    {
        return name;
    }

    string getPhone()
    {
        return phone;
    }

    string getAddress()
    {
        return address;
    }
};

// Rental Class
class Rental
{
private:
    int rentalID;
    int customerID;
    int vehicleID;
    int totalDays;
    float totalBill;

public:

    Rental()
    {
        rentalID = 0;
        customerID = 0;
        vehicleID = 0;
        totalDays = 0;
        totalBill = 0;
    }

    Rental(int rid, int cid, int vid, int days, float bill)
    {
        rentalID = rid;
        customerID = cid;
        vehicleID = vid;
        totalDays = days;
        totalBill = bill;
    }

  void displayRental()
{
    cout << left
         << setw(12) << rentalID
         << setw(15) << customerID
         << setw(15) << vehicleID
         << setw(10) << totalDays
         << setw(12) << totalBill
         << endl;
}

    int getRentalID()
    {
        return rentalID;
    }

    int getCustomerID()
    {
        return customerID;
    }

    int getVehicleID()
    {
        return vehicleID;
    }

    int getDays()
    {
        return totalDays;
    }

    float getBill()
    {
        return totalBill;
    }
};


// Store multiple vehicle objects
Vehicle vehicles[5000];
Customer customers[5000];
Rental rentals[5000];

// Total Records
int vehicleCount = 0;
int customerCount = 0;
int rentalCount = 0;

// Function Prototypes
void welcomeScreen();
void mainMenu();
void vehicleMenu();
void addVehicle();
void displayVehicles();
void searchVehicle();
void updateVehicle();
void deleteVehicle();
void saveData();
void loadData(bool showMessage);
void notesMenu();
void viewNotes();
void addNote();
void customerMenu();
void addCustomer();
void displayCustomers();
void searchCustomer();
void updateCustomer();
void deleteCustomer();
void saveCustomerData();
void loadCustomerData();
void rentVehicle();
void returnVehicle();
void rentalHistory();

void saveRentalData();
void loadRentalData();
void dynamicMemoryDemo();


// Add new vehicle
void addVehicle()
{
    if(vehicleCount < 5000)
    {
        vehicles[vehicleCount].inputVehicle();

        vehicleCount++;

      cout << "\n======================================" << endl;
cout << " Vehicle Added Successfully." << endl;
cout << "======================================" << endl;
        saveData();
    }
    else
    {
        cout << "\nVehicle Storage Full." << endl;
    }
}
// Add New Customer
void addCustomer()
{
    if(customerCount < 5000)
    {
        customers[customerCount].inputCustomer();

        customerCount++;

    cout << "\n======================================" << endl;
cout << " Customer Added Successfully." << endl;
cout << "======================================" << endl;
        saveCustomerData();
    }
    else
    {
        cout << "\nCustomer Storage Full." << endl;
    }
}
// Display All Customers
void displayCustomers()
{
    if(customerCount == 0)
    {
        cout << "\nNo Customer Found." << endl;
        return;
    }
cout << "\n==========================================================================\n";
cout << "                           CUSTOMER LIST\n";
cout << "==========================================================================\n";

cout << left
     << setw(10) << "ID"
     << setw(20) << "Name"
     << setw(20) << "Phone"
     << setw(20) << "Address"
     << endl;

cout << "==========================================================================\n";

    for(int i = 0; i < customerCount; i++)
    {
        customers[i].displayInfo();
    }

    cout << "--------------------------------------------------------------------------" << endl;
}

// Search Customer
void searchCustomer()
{
    if(customerCount == 0)
    {
        cout << "\nNo Customer Found." << endl;
        return;
    }

    int searchID;
    bool found = false;

    cout << "\nEnter Customer ID to Search: ";
    cin >> searchID;

    for(int i = 0; i < customerCount; i++)
    {
        if(customers[i].getID() == searchID)
        {
            cout << "\nCustomer Found!" << endl;

            cout << "--------------------------------------------------------------------------" << endl;
            cout << "ID\tName\t\tPhone\t\t\tAddress" << endl;
            cout << "--------------------------------------------------------------------------" << endl;

            customers[i].displayInfo();

            cout << "--------------------------------------------------------------------------" << endl;

            found = true;
            break;
        }
    }

    if(found == false)
    {
        cout << "\nCustomer Not Found." << endl;
    }
}

// Update Customer
void updateCustomer()
{
    if(customerCount == 0)
    {
        cout << "\nNo Customer Found." << endl;
        return;
    }

    int updateID;
    bool found = false;

    cout << "\nEnter Customer ID to Update: ";
    cin >> updateID;

    for(int i = 0; i < customerCount; i++)
    {
        if(customers[i].getID() == updateID)
        {
            cout << "\nCustomer Found. Enter New Information:" << endl;

            customers[i].inputCustomer();

           cout << "\n======================================" << endl;
cout << " Customer Updated Successfully." << endl;
cout << "======================================" << endl;
            saveCustomerData();

            found = true;
            break;
        }
    }

    if(found == false)
    {
        cout << "\nCustomer Not Found." << endl;
    }
}

// Delete Customer
void deleteCustomer()
{
    if(customerCount == 0)
    {
        cout << "\nNo Customer Found." << endl;
        return;
    }

    int deleteID;
    bool found = false;

    cout << "\nEnter Customer ID to Delete: ";
    cin >> deleteID;

    for(int i = 0; i < customerCount; i++)
    {
        if(customers[i].getID() == deleteID)
        {
            // Shift data left
            for(int j = i; j < customerCount - 1; j++)
            {
                customers[j] = customers[j + 1];
            }

            customerCount--;

           cout << "\n======================================" << endl;
cout << " Customer Deleted Successfully." << endl;
cout << "======================================" << endl;
            saveCustomerData();

            found = true;
            break;
        }
    }

    if(found == false)
    {
        cout << "\nCustomer Not Found." << endl;
    }
}

// Save Customer Data
void saveCustomerData()
{
    ofstream file("customer.txt");

    if(!file)
    {
        cout << "\nFile Opening Error!" << endl;
        return;
    }

    for(int i = 0; i < customerCount; i++)
    {
        file << "==========================================" << endl;
        file << "Customer ID   : " << customers[i].getID() << endl;
        file << "Customer Name : " << customers[i].getName() << endl;
        file << "Phone Number  : " << customers[i].getPhone() << endl;
        file << "Address       : " << customers[i].getAddress() << endl;
        file << "------------------------------------------" << endl;
    }

    file.close();

    cout << "\nCustomer Data Saved Successfully." << endl;
}

// Save Rental Data
void saveRentalData()
{
    ofstream file("rental.txt");

    if(!file)
    {
        cout << "\nRental File Opening Error!" << endl;
        return;
    }

    for(int i = 0; i < rentalCount; i++)
    {
        file << "==========================================" << endl;
        file << "Rental ID   : " << rentals[i].getRentalID() << endl;
        file << "Customer ID : " << rentals[i].getCustomerID() << endl;
        file << "Vehicle ID  : " << rentals[i].getVehicleID() << endl;
        file << "Days        : " << rentals[i].getDays() << endl;
        file << "Total Bill  : " << rentals[i].getBill() << endl;
        file << "------------------------------------------" << endl;
    }

    file.close();
}

// Load Customer Data
void loadCustomerData()
{
    ifstream file("customer.txt");

    if(!file)
    {
        return;
    }

    customerCount = 0;

    string line, temp;
    int id;
    string name, phone, address;

    while(getline(file, line))
    {
        if(line.find("Customer ID") != string::npos)
        {
            temp = line.substr(line.find(":") + 2);
            id = stoi(temp);

            getline(file, line);
            name = line.substr(line.find(":") + 2);

            getline(file, line);
            phone = line.substr(line.find(":") + 2);

            getline(file, line);
            address = line.substr(line.find(":") + 2);

            getline(file, line); // ------------------------------------------

            customers[customerCount] = Customer(id, name, phone, address);
            customerCount++;
        }
    }

    file.close();

}

// Load Rental Data
void loadRentalData()
{
    ifstream file("rental.txt");

    if(!file)
    {
        return;
    }

    rentalCount = 0;

    string line, temp;
    int rentalID, customerID, vehicleID, days;
    float totalBill;

    while(getline(file, line))
    {
        if(line.find("Rental ID") != string::npos)
        {
            temp = line.substr(line.find(":") + 2);
            rentalID = stoi(temp);

            getline(file, line);
            customerID = stoi(line.substr(line.find(":") + 2));

            getline(file, line);
            vehicleID = stoi(line.substr(line.find(":") + 2));

            getline(file, line);
            days = stoi(line.substr(line.find(":") + 2));

            getline(file, line);
            totalBill = stof(line.substr(line.find(":") + 2));

            getline(file, line); // ------------------------------------------

            rentals[rentalCount] = Rental(rentalID, customerID, vehicleID, days, totalBill);
            rentalCount++;
        }
    }

    file.close();
}


// Display all vehicles
void displayVehicles()
{
    if(vehicleCount == 0)
    {
        cout << "\nNo Vehicle Found." << endl;
        return;
    }

    cout << "\n\n";
    cout << "==========================================================================\n";
cout << "                           VEHICLE LIST\n";
cout << "==========================================================================\n";

cout << left
     << setw(10) << "ID"
     << setw(20) << "Name"
     << setw(20) << "Brand"
     << setw(12) << "Rent"
     << setw(15) << "Status"
     << endl;

cout << "==========================================================================\n";

    for(int i = 0; i < vehicleCount; i++)
    {
        vehicles[i].displayVehicle();
    }


    cout << "---------------------------------------------------------------------------" << endl;
}
// Search Vehicle
void searchVehicle()
{
    if(vehicleCount == 0)
    {
        cout << "\nNo Vehicle Found." << endl;
        return;
    }

    int searchID;
    bool found = false;

    cout << "\nEnter Vehicle ID to Search: ";
    cin >> searchID;


    for(int i = 0; i < vehicleCount; i++)
    {
        if(vehicles[i].getID() == searchID)
        {
            cout << "\nVehicle Found!" << endl;

            cout << "---------------------------------------------------------------" << endl;
            cout << "ID\tName\t\tBrand\t\tRent\t\tStatus" << endl;
            cout << "---------------------------------------------------------------" << endl;

            vehicles[i].displayVehicle();

            cout << "---------------------------------------------------------------" << endl;

            found = true;
            break;
        }
    }


    if(found == false)
    {
        cout << "\nVehicle Not Found." << endl;
    }
}
// Update Vehicle
void updateVehicle()
{
    if(vehicleCount == 0)
    {
        cout << "\nNo Vehicle Found." << endl;
        return;
    }


    int updateID;
    bool found = false;


    cout << "\nEnter Vehicle ID to Update: ";
    cin >> updateID;


    for(int i = 0; i < vehicleCount; i++)
    {
        if(vehicles[i].getID() == updateID)
        {
            cout << "\nVehicle Found. Enter New Information:" << endl;


            vehicles[i].inputVehicle();


           cout << "\n======================================" << endl;
cout << " Vehicle Updated Successfully." << endl;
cout << "======================================" << endl;
            saveData();


            found = true;
            break;
        }
    }


    if(found == false)
    {
        cout << "\nVehicle Not Found." << endl;
    }
}
// Delete Vehicle
void deleteVehicle()
{
    if(vehicleCount == 0)
    {
        cout << "\nNo Vehicle Found." << endl;
        return;
    }


    int deleteID;
    bool found = false;


    cout << "\nEnter Vehicle ID to Delete: ";
    cin >> deleteID;


    for(int i = 0; i < vehicleCount; i++)
    {
        if(vehicles[i].getID() == deleteID)
        {

            // Shift data left
            for(int j = i; j < vehicleCount - 1; j++)
            {
                vehicles[j] = vehicles[j + 1];
            }


            vehicleCount--;


            cout << "\n======================================" << endl;
cout << " Vehicle Deleted Successfully." << endl;
cout << "======================================" << endl;
            saveData();

            found = true;
            break;
        }
    }


    if(found == false)
    {
        cout << "\nVehicle Not Found." << endl;
    }
}
// Save Vehicle Data
void saveData()
{
    ofstream file("vehicle.txt");

    if(!file)
    {
        cout << "\nFile Opening Error!" << endl;
        return;
    }


    file << "==================================================\n";
    file << "          VEHICLE RENTAL SYSTEM DATA\n";
    file << "==================================================\n\n";


    for(int i = 0; i < vehicleCount; i++)
    {
        file << "Vehicle ID   : " << vehicles[i].getID() << endl;
        file << "Vehicle Name : " << vehicles[i].getName() << endl;
        file << "Brand        : " << vehicles[i].getBrand() << endl;
        file << "Rent Per Day : " << vehicles[i].getRent() << endl;
        file << "Status       : " << vehicles[i].getStatus() << endl;

        file << "\n--------------------------------------------------\n\n";
    }


    file.close();
    saveCustomerData();

    cout << "\nData Saved Successfully." << endl;
}

// Load Vehicle Data
void loadData(bool showMessage = true)
{
    ifstream file("vehicle.txt");

    if(!file)
    {
        cout << "\nNo Saved Data Found." << endl;
        return;
    }


    vehicleCount = 0;

    string line;


    while(getline(file, line))
    {
        if(line.find("Vehicle ID") != string::npos)
        {
            int id;
            string name, brand, status;
            float rent;


            // ID
            id = stoi(line.substr(line.find(":") + 1));


            // Name
            getline(file, line);
            name = line.substr(line.find(":") + 1);
            name.erase(0, name.find_first_not_of(" "));


            // Brand
            getline(file, line);
            brand = line.substr(line.find(":") + 1);
            brand.erase(0, brand.find_first_not_of(" "));


            // Rent
            getline(file, line);
            rent = stof(line.substr(line.find(":") + 1));


            // Status
            getline(file, line);
            status = line.substr(line.find(":") + 1);
            status.erase(0, status.find_first_not_of(" "));


            vehicles[vehicleCount] = Vehicle(id, name, brand, rent, status);

            vehicleCount++;
        }
    }


 file.close();

loadCustomerData();
loadRentalData();
if(showMessage)
{
    cout << "\n==================================================" << endl;
    cout << "          DATA LOADED SUCCESSFULLY" << endl;
    cout << "==================================================" << endl;
    cout << "Total Vehicle Loaded : " << vehicleCount << endl;
    cout << "Total Customer Loaded: " << customerCount << endl;
    cout << "Total Rentals Loaded : " << rentalCount << endl;
    cout << "==================================================" << endl;
   cout << "\n========== VEHICLES ==========\n";
    displayVehicles();

    cout << endl;
cout << "\n========== CUSTOMERS ==========\n";
    displayCustomers();
cout << "\n========== RENTAL HISTORY ==========\n";

    rentalHistory();
cout << "\n========== NOTES ==========\n";
    viewNotes();
}
}

void rentVehicle()
{
    if(vehicleCount == 0)
    {
        cout << "\nNo Vehicle Available." << endl;
        return;
    }

    if(customerCount == 0)
    {
        cout << "\nNo Customer Found." << endl;
        return;
    }

    int customerID, vehicleID, days;

    try
    {
        cout << "\n========== RENT VEHICLE ==========\n";

        cout << "Enter Customer ID : ";
        cin >> customerID;

        if(customerID <= 0)
        {
            throw invalid_argument("Customer ID must be greater than 0.");
        }

        cout << "Enter Vehicle ID : ";
        cin >> vehicleID;

        if(vehicleID <= 0)
        {
            throw invalid_argument("Vehicle ID must be greater than 0.");
        }

        cout << "Enter Number of Days : ";
        cin >> days;

        if(days <= 0)
        {
            throw invalid_argument("Number of Days must be greater than 0.");
        }

        bool customerFound = false;
        bool vehicleFound = false;

        int customerIndex = -1;
        int vehicleIndex = -1;

        // Search Customer
        for(int i = 0; i < customerCount; i++)
        {
            if(customers[i].getID() == customerID)
            {
                customerFound = true;
                customerIndex = i;
                break;
            }
        }

        // Search Vehicle
        for(int i = 0; i < vehicleCount; i++)
        {
            if(vehicles[i].getID() == vehicleID)
            {
                vehicleFound = true;
                vehicleIndex = i;
                break;
            }
        }

        if(customerFound == false)
        {
            cout << "\nCustomer ID Not Found." << endl;
            return;
        }

        if(vehicleFound == false)
        {
            cout << "\nVehicle ID Not Found." << endl;
            return;
        }

        if(vehicles[vehicleIndex].isAvailable() == false)
        {
            cout << "\nThis Vehicle Is Already Rented." << endl;
            return;
        }

        // Calculate Total Bill
        float totalBill = vehicles[vehicleIndex].getRent() * days;

        // Change Vehicle Status
        vehicles[vehicleIndex].setStatus("Rented");

        // Save Rental Information
        rentals[rentalCount] = Rental(
            rentalCount + 1,
            customerID,
            vehicleID,
            days,
            totalBill
        );

        rentalCount++;

        saveRentalData();
        saveData();

        cout << "\n==================================================" << endl;
        cout << "          VEHICLE RENTED SUCCESSFULLY" << endl;
        cout << "==================================================" << endl;
        cout << "Rental ID   : " << rentalCount << endl;
        cout << "Customer ID : " << customerID << endl;
        cout << "Vehicle ID  : " << vehicleID << endl;
        cout << "Total Bill  : " << totalBill << " TK" << endl;
        cout << "==================================================" << endl;
    }
    catch(const exception &e)
    {
        cout << "\n==================================================" << endl;
        cout << "ERROR : " << e.what() << endl;
        cout << "==================================================" << endl;
    }
}
// Rental History
void rentalHistory()
{
    if(rentalCount == 0)
    {
        cout << "\nNo Rental History Found." << endl;
        return;
    }

    cout << "\n==========================================================================\n";
cout << "                          RENTAL HISTORY\n";
cout << "==========================================================================\n";

cout << left
     << setw(12) << "Rental ID"
     << setw(15) << "Customer ID"
     << setw(15) << "Vehicle ID"
     << setw(10) << "Days"
     << setw(12) << "Bill"
     << endl;

cout << "--------------------------------------------------------------------------\n";
    for(int i = 0; i < rentalCount; i++)
    {
        rentals[i].displayRental();
    }

  cout << "==========================================================================\n";
}


// Return Vehicle
void returnVehicle()
{
    if(rentalCount == 0)
    {
        cout << "\nNo Vehicle Is Currently Rented." << endl;
        return;
    }

    int vehicleID;

    cout << "\n==================================================" << endl;
cout << "         VEHICLE RETURNED SUCCESSFULLY" << endl;
cout << "==================================================" << endl;
    cout << "Enter Vehicle ID : ";
    cin >> vehicleID;
        bool found = false;
    int vehicleIndex = -1;

    for(int i = 0; i < vehicleCount; i++)
    {
        if(vehicles[i].getID() == vehicleID)
        {
            found = true;
            vehicleIndex = i;
            break;
        }
    }
        if(found == false)
    {
        cout << "\nVehicle Not Found." << endl;
        return;
    }
        if(vehicles[vehicleIndex].isAvailable())
    {
        cout << "\nThis Vehicle Is Already Available." << endl;
        return;
    }
        vehicles[vehicleIndex].setStatus("Available");

    saveData();

    cout << "\nVehicle Returned Successfully." << endl;
}

// Dynamic Memory Allocation Demo
void dynamicMemoryDemo()
{
    Vehicle *tempVehicle = new Vehicle();

    cout << "\nDynamic Memory Allocated Successfully." << endl;

    delete tempVehicle;

    cout << "Dynamic Memory Released Successfully." << endl;
}
// Vehicle Menu
void vehicleMenu()
{
    int choice;

    do
    {
        cout << "\n\n";
        cout << "==========================================================" << endl;
        cout << "              VEHICLE MANAGEMENT" << endl;
        cout << "==========================================================" << endl;

        cout << "1. Add Vehicle" << endl;
        cout << "2. Display Vehicles" << endl;
        cout << "3. Search Vehicle" << endl;
        cout << "4. Update Vehicle" << endl;
        cout << "5. Delete Vehicle" << endl;
        cout << "6. Back" << endl;

        cout << "==========================================================" << endl;
        cout << "Enter Your Choice : ";

        cin >> choice;


        switch(choice)
        {
        case 1:
            addVehicle();
            break;

        case 2:
            displayVehicles();
            break;

       case 3:
    searchVehicle();
    break;

        case 4:
    updateVehicle();
    break;

      case 5:
    deleteVehicle();
    break;

     case 6:
    cout << "\nReturning to Main Menu..." << endl;
    break;

        default:
            cout << "\nInvalid Choice!" << endl;
        }

    }while(choice != 6);
}
// Customer Menu
void customerMenu()
{
    int choice;

    do
    {
        cout << "\n\n";
        cout << "==========================================================" << endl;
        cout << "             CUSTOMER MANAGEMENT" << endl;
        cout << "==========================================================" << endl;

        cout << "1. Add Customer" << endl;
        cout << "2. Display Customers" << endl;
        cout << "3. Search Customer" << endl;
        cout << "4. Update Customer" << endl;
        cout << "5. Delete Customer" << endl;
        cout << "6. Back" << endl;

        cout << "==========================================================" << endl;
        cout << "Enter Your Choice : ";

        cin >> choice;

        switch(choice)
        {
        case 1:
            addCustomer();
            break;

        case 2:
            displayCustomers();
            break;

        case 3:
            searchCustomer();
            break;

        case 4:
            updateCustomer();
            break;

        case 5:
            deleteCustomer();
            break;

        case 6:
            cout << "\nReturning to Main Menu..." << endl;
            break;

        default:
            cout << "\nInvalid Choice!" << endl;
        }

    } while(choice != 6);
}
// Main Menu
void mainMenu()
{
    int choice;

    do
    {
        cout << "\n\n";
        cout << "==========================================================" << endl;
        cout << "                     MAIN MENU" << endl;
        cout << "==========================================================" << endl;

        cout << "1. Vehicle Management" << endl;
        cout << "2. Customer Management" << endl;
        cout << "3. Rent Vehicle" << endl;
        cout << "4. Return Vehicle" << endl;
        cout << "5. Rental History" << endl;
        cout << "6. Save Data" << endl;
        cout << "7. Load Data" << endl;
        cout << "8. Notes" << endl;
        cout << "9. Exit" << endl;

        cout << "==========================================================" << endl;
        cout << "Enter Your Choice : ";

        cin >> choice;

        switch(choice)
        {
        case 1:
            dynamicMemoryDemo();
            vehicleMenu();
            break;

        case 2:
           customerMenu();
           break;

       case 3:
    rentVehicle();
    break;

case 4:
    returnVehicle();
    break;

case 5:
    rentalHistory();
    break;

    case 6:
    if(vehicleCount == 0 && customerCount == 0)
    {
        cout << "\nNo Data To Save!" << endl;
    }
    else
    {
        saveData();
    }
    break;
        case 7:
            loadData();
            break;

        case 8:
            notesMenu();
            break;

        case 9:
            cout << "\nThank You for Using Vehicle Rental System." << endl;
            break;

        default:
            cout << "\nInvalid Choice!" << endl;
        }

    } while(choice != 9);
}
void notesMenu()
{
    int choice;

    do
    {
        cout << "\n\n";
        cout << "==========================================" << endl;
        cout << "               NOTES MENU" << endl;
        cout << "==========================================" << endl;

        cout << "1. View Notes" << endl;
        cout << "2. Add Note" << endl;
        cout << "3. Back" << endl;

        cout << "==========================================" << endl;
        cout << "Enter Your Choice : ";

        cin >> choice;
        cin.ignore();

        switch(choice)
        {
        case 1:
            viewNotes();
            break;

        case 2:
            addNote();
            break;

        case 3:
            cout << "\nReturning..." << endl;
            break;

        default:
            cout << "\nInvalid Choice!" << endl;
        }

    } while(choice != 3);
}
// Add Note
void addNote()
{
    ofstream file("notes.txt", ios::app);

    if(!file)
    {
        cout << "\nFile Opening Error!" << endl;
        return;
    }

    string note;

    cout << "\nWrite Your Note: ";

    getline(cin, note);

    file << note << endl;

    file.close();

    cout << "\nNote Saved Successfully." << endl;
}
// View Notes
void viewNotes()
{
    ifstream file("notes.txt");

    if(!file)
    {
        cout << "\nNo Notes Found." << endl;
        return;
    }

    string line;

    cout << "\n==========================================" << endl;
    cout << "              ALL NOTES" << endl;
    cout << "==========================================" << endl;

    while(getline(file, line))
    {
        cout << line << endl;
    }

    file.close();

    cout << "==========================================" << endl;
}

// Welcome Screen
void welcomeScreen()
{
    cout << "==========================================================" << endl;
    cout << "                VEHICLE RENTAL SYSTEM" << endl;
    cout << "             Object-Oriented Programming" << endl;
    cout << "==========================================================" << endl;

    cout << endl;

    cout << "Developed By : Group 5" << endl;
    cout << "----------------------------------------------------------" << endl;

    cout << "1. Tasnim Taaha" << endl;
    cout << "2. Jakia Sultana Jerin" << endl;
    cout << "3. Mariya sultana" << endl;
    cout << "4. Samira Hasan" << endl;

    cout << endl;

    cout << "==========================================================" << endl;
    cout << "Press Enter to Continue...";

    cin.get();

    mainMenu();
}


// Main Function
int main()
{
    loadData(false);
    welcomeScreen();

    return 0;
}
