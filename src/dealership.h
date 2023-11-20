#include "customer.h"
#include "vehicle.h"
#include <vector>
#pragma once

class Dealership {
    vector<Customer*> vecCustomers;
    vector<Vehicle*> vecVehicles;
	Customer* customer;
	Vehicle* vehicle;

public:
    Dealership();
    ~Dealership();

    void AddCustomer(const string& name, const string& phoneNumber, const string& emailAddress, bool interested, bool bought, const string& interestedVehicle, const string& interestedModel);
	void AddCustomer(Customer* obj);

    void PrintCustomerInfo() const;
    void PrintCustomerInfo(Customer* obj) const;
    void FindCurrentCustomer(const string& nameToFind) const;

    void AddVehicle(const int& yearAdd, const string& makeAdd, const string& modelAdd, const string& colorAdd, const int& daysOnLotAdd, const double& priceAdd, const string& vinAdd);
    void PrintVehicleInfo() const;
	void PrintVehicleInfo(Vehicle* obj) const;

    void FindInterestedCustomer() const;
    void SearchForVehicle(const string& vehicleToFind) const;
};

