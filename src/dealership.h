#include "sales.h"
#include <vector>
#include <fstream>
#pragma once

class Dealership {
    vector<Customer*> vecCustomers;
    vector<Vehicle*> vecVehicles;
	vector<Sales*> vecSales;
	Customer* customer;
	Vehicle* vehicle;
// File stream variables
	ifstream inputFile;
	ofstream outputFile;
	string customersFilename = "txtfiles/customers.txt";
	string vehiclesFilename = "txtfiles/vehicles.txt";
public:
// Constructors and Destrcutor
    Dealership();
    ~Dealership();

// Customer Class Stuff
    void AddCustomer(const string& name, const string& phoneNumber, const string& emailAddress, bool interested, bool bought, const string& interestedVehicle, const string& interestedModel);
	void AddCustomer(Customer* obj);

	void FindCurrentCustomer(const string& nameToFind) const;
    int FindCurrentCustomerIndex(const string& nameToFind) const;

    void PrintCustomerInfo() const;
    void PrintCustomerInfo(Customer* obj) const;

// Vehicle Class Stuff
    void AddVehicle(const int& yearAdd, const string& makeAdd, const string& modelAdd, const string& colorAdd, const int& daysOnLotAdd, const double& priceAdd, const string& vinAdd);
	void AddVehicle(Vehicle* obj);
    void PrintVehicleInfo() const;
	void PrintVehicleInfo(Vehicle* obj) const;
    void SearchForVehicle(const string& vehicleToFind) const;
    int SearchForVehicleIndex(const string& vehicleToFind) const;

// Sales Class Stuff
	void PrintSalesInfo() const;

// File Stuff
	void OpenFile();
	void SaveToFile();

// TMP METHODS
	void BuyCar();

// Methods To Write
    void FindInterestedCustomer() const;
};
