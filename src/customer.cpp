#include "customer.h"

#include <utility>


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
	this->name = std::move(name);
}

string Customer::GetName() {
	return name;
}

void Customer::SetSalesmanName(string salesmanName) {
	this->salesmanName = std::move(salesmanName);
}

string Customer::GetSalesmanName() {
	return salesmanName;
}

void Customer::SetEmailAddress(string emailAddress) {
	this->emailAddress = std::move(emailAddress);
}

string Customer::GetEmailAddress() {
	return emailAddress;
}

void Customer::SetPhoneNumber(int phoneNumber) {
	this->phoneNumber = phoneNumber;
}

int Customer::GetPhoneNumber() const {
	return phoneNumber;
}

void Customer::SetBoughtCar(bool boughtCar) {
	this->boughtCar = boughtCar;
}

bool Customer::GetBoughtCar() const {
	return boughtCar;
}

void Customer::SetInterestedVehicle(string interestedVehicle) {
	this->interestedVehicle = std::move(interestedVehicle);
}

string Customer::GetInterestedVehicle() const{
	return interestedVehicle;
}

void Customer::SetInterestedModel(string interestedModel) {
	this->interestedModel = std::move(interestedModel);
}

string Customer::GetInterestedModel() {
	return interestedModel;
}
