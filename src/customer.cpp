#include "customer.h"


// TODO: Write these methods
void FindInterestedCustomer() {

}

void FindCurrentCustomer() {

}

void PrintCustomer() {

}

void PrintInfo() {

}

// ALL SETTERS AND GETTERS BELOW
//
void Customer::SetName(string name) { 
	this->name = name;
}

string Customer::GetName() {
	return name;
}

void Customer::SetSalesmanName(string salesmanName) {
	this->salesmanName = salesmanName;
}

string Customer::GetSalesmanName() {
	return salesmanName;
}

void Customer::SetEmailAddress(string emailAddress) {
	this->emailAddress = emailAddress;
}

string Customer::GetEmailAddresss() {
	return emailAddress;
}

void Customer::SetPhoneNumber(int phoneNumber) {
	this->phoneNumber = phoneNumber;
}

int Customer::GetPhoneNumber() {
	return phoneNumber;
}

void Customer::SetBoughtCar(bool boughtCar) {
	this->boughtCar = boughtCar;
}

bool Customer::GetBoughtCar() {
	return boughtCar;
}

void Customer::SetInterstedVehicle(string interestedVehicle) {
	this->interestedVehicle = interestedVehicle;
}

string Customer::GetInterstedVehicle() {
	return interestedVehicle;
}

void Customer::SetInterestedModel(string interestedModel) {
	this->interestedModel = interestedModel;
}

string Customer::GetInterestedModel() {
	return interestedModel;
}
