#include "sales.h"
#include "access-control.h"
#include <vector>
#include <fstream>
#pragma once

class Dealership {
    vector<Customer*> vecCustomers;
    vector<Vehicle*> vecVehicles;
	vector<Sales*> vecSales;
	static string currentRole;
// File stream variables
	ifstream inputFile;
	ofstream outputFile;
	string line;
	string customersFilename = "../build/txtfiles/customers.txt";
	string vehiclesFilename = "../build/txtfiles/vehicles.txt";
	string salesFilename = "../build/txtfiles/sales.txt";
// Objects needed
	AccessControl accessControl;
public:
// Constructors and Destrcutor
    Dealership();
    ~Dealership();

// TODO CHANGE EVRERY FIND METHOD TO USE A SEARCHING ALGO
// TODO MAY NOT NEED THE OVERLOADED METHODS

// First up
	int MainMenu();
	bool Login();

// Customer Class Stuff
    void AddCustomer(const string& name, const string& phoneNumber, const string& emailAddress, bool interested, bool bought, const string& interestedVehicle, const string& interestedModel);
	void AddCustomer(Customer* obj);

	Customer* FindCustomer(const string& nameToFind) const;
    int FindCustomerIndex(const string& nameToFind) const;

    void PrintEntirCustomerVector() const;
    void PrintCustomerInfo(Customer* obj) const;
	void PrintPotentialCustomerInfo() const;

// Vehicle Class Stuff
    void AddVehicle(const int& yearAdd, const string& makeAdd, const string& modelAdd, const string& colorAdd, const int& daysOnLotAdd, const double& priceAdd, const string& vinAdd);
	void AddVehicle(Vehicle* obj);
	void PrintVehicleInfo(Vehicle* obj) const;
    int FindVehicleIndex(const string& vehicleToFind) const;
	bool FindVehicleType(Vehicle* vehicle, const string& vehicleToFind, const string& option) const;
    Vehicle* FindVehicleObj(const string& vehicleToFind) const;

	void FilterVehiclePrintResults(const string& cRole) const;

// Sales Class Stuff
	void PrintEntireSalesVector() const;
	void AddSale(Vehicle* vehicle, Customer* customer, const string& sn, const double& sp, const double& sbd, const double& sbw, const double& sbm);
	void AddSale(Sales* obj);
	double GetGrossSales();

// File Stuff

// TMP METHODS
	int BuyCar();

// Methods To Write OR FIXME
	void OpenFile(); // TODO
	void SaveToFile(); // TODO
    void PrintVehicleInfo() const; // TODO
};
