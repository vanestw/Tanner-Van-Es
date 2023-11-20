#include "dealership.h"
#include <iostream>

Dealership::Dealership() {
	cout << "DEALERSHIP CONSTRUCTOR CALLED" << endl;
}

Dealership::~Dealership() {
	cout << "DEALERSHIP DESTRUCTOR CALLED" << endl;
	for (Customer* each : vecCustomers) {
            delete each;
    }

	for (Vehicle* each : vecVehicles) {
            delete each;
    }
}

void Dealership::AddCustomer(const string& name, const string& phoneNumber, const string& emailAddress, bool interested, bool bought, const string& interestedVehicle, const string& interestedModel) {
    vecCustomers.emplace_back(new Customer(name, phoneNumber, emailAddress, interested, bought, interestedVehicle, interestedModel));
}

void Dealership::AddCustomer(Customer* obj) {
	vecCustomers.emplace_back(obj);
}

void Dealership::PrintCustomerInfo() const {
	for(size_t i = 0; i < vecCustomers.size(); i++) { 
		cout << "Name: " << vecCustomers.at(i)->GetName() << endl;
		cout << "Phone number: " << vecCustomers.at(i)->GetPhoneNumber() << endl;
		cout << "Email address: " << vecCustomers.at(i)->GetEmailAddresss() << endl;
		cout << "Is interested: " << boolalpha << vecCustomers.at(i)->GetIsInterested() <<  endl;
		cout << "Bought car: " << boolalpha << vecCustomers.at(i)->GetBoughtCar() << endl;
		cout << "Vehicle interested in: " << vecCustomers.at(i)->GetInterstedVehicle() << endl;
		cout << "Vehicle model interested in: " << vecCustomers.at(i)->GetInterestedModel() << endl;

		if(i != vecCustomers.size() - 1) {
		cout << endl;
		}
	}
}

void Dealership::PrintCustomerInfo(Customer* obj) const {
		cout << "Name: " << obj->GetName() << endl;
		cout << "Phone number: " << obj->GetPhoneNumber() << endl;
		cout << "Email address: " << obj->GetEmailAddresss() << endl;
		cout << "Is interested: " << boolalpha << obj->GetIsInterested() <<  endl;
		cout << "Bought car: " << boolalpha << obj->GetBoughtCar() << endl;
		cout << "Vehicle interested in: " << obj->GetInterstedVehicle() << endl;
		cout << "Vehicle model interested in: " << obj->GetInterestedModel() << endl;
	}

void Dealership::FindInterestedCustomer() const {
}

void Dealership::FindCurrentCustomer(const string& nameToFind) const {
	for(size_t i = 0; i < vecCustomers.size(); i++) { 
		cout << "Searching for " << nameToFind << "..." << endl;
        if (nameToFind == vecCustomers.at(i)->GetName()) {
			cout << "FOUND " << nameToFind << endl;
			PrintCustomerInfo(vecCustomers.at(i));
        }
    }
}

void Dealership::SearchForVehicle(const string& vehicleToFind) const {
	for(size_t i = 0; i < vecVehicles.size(); i++) {
		cout << "Searching for " << vehicleToFind << "..." << endl;
		if(vehicleToFind == vecVehicles.at(i)->GetVin()) {
			cout << "FOUND " << vehicleToFind << endl;
			PrintVehicleInfo(vecVehicles.at(i));
		}
	}
}


// VEHICLE STUFF BELOW

void Dealership::AddVehicle(const int& yearAdd, const string& makeAdd, const string& modelAdd, const string& colorAdd, const int& daysOnLotAdd, const double& priceAdd, const string& vinAdd) {
	vecVehicles.emplace_back(new Vehicle(yearAdd, makeAdd, modelAdd, colorAdd, daysOnLotAdd, priceAdd, vinAdd));
}

void Dealership::AddVehicle(Vehicle* obj) {
	vecVehicles.emplace_back(obj);
}

void Dealership::PrintVehicleInfo() const {
	for(size_t i = 0; i < vecVehicles.size(); i++) { 
		cout << "Make: " << vecVehicles.at(i)->GetMake() << endl;
		cout << "Model: " << vecVehicles.at(i)->GetModel() << endl;
		cout << "Color: " << vecVehicles.at(i)->GetColor() << endl;
		cout << "Days on lot: " << vecVehicles.at(i)->GetDaysOnLot() <<  endl;
		cout << "Price: " << vecVehicles.at(i)->GetPrice() << endl;
		cout << "VIN number: " << vecVehicles.at(i)->GetVin() << endl;

		if(i != vecCustomers.size() - 1) {
		cout << endl;
		}
	}
}

void Dealership::PrintVehicleInfo(Vehicle* obj) const {
		cout << "Make: " << obj->GetMake() << endl;
		cout << "Model: " << obj->GetModel() << endl;
		cout << "Color: " << obj->GetColor() << endl;
		cout << "Days on lot: " << obj->GetDaysOnLot() <<  endl;
		cout << "Price: " << obj->GetPrice() << endl;
		cout << "VIN number: " << obj->GetVin() << endl;
}
