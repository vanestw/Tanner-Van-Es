#include "customer.h"

// Constructors and Destructor
Customer::Customer() {
	cout << "CUSTOMER DEFAULT CONSTRUCTOR CALLED" << endl;
} // ends Customer()

Customer::Customer(const string& n, const string& pn, const string& ea, bool interested, bool bought, const string& vi, const string& vmi) {
	cout << "CUSTOMER PARAMATERIZED CONSTRUCTOR CALLED" << endl;
	name = n;
	phoneNumber = pn;
	emailAddress = ea;
	isInterested = interested;
	boughtCar = bought;
	interestedVehicle = vi;
	interestedModel = vmi;
} // ends paramaterized Customer()

Customer::Customer(Customer* other) {
	name = other->name;
	phoneNumber = other->phoneNumber;
	emailAddress = other->emailAddress;
	isInterested = other->isInterested;
	boughtCar = other->boughtCar;
	interestedVehicle = other->interestedVehicle;
	interestedModel = other->interestedModel;
} // ends copy constructor

Customer::~Customer() {
	cout << "CUSTOMER DESTRUCTOR CALLED" << endl;
} // ends ~Customer()

// ALL SETTERS AND GETTERS 
void Customer::SetIsInterested(bool interested) {
	this->isInterested = interested;	
}

bool Customer::GetIsInterested() const {
	return isInterested;
}

void Customer::SetName(const string& n) { 
	this->name = n;
}

string Customer::GetName() const {
	return name;
}

void Customer::SetSalesmanName(const string& sn) {
	this->salesmanName = sn;
}

string Customer::GetSalesmanName() const {
	return salesmanName;
}

void Customer::SetEmailAddress(const string& ea) {
	this->emailAddress = ea;
}

string Customer::GetEmailAddresss() const {
	return emailAddress;
}

void Customer::SetPhoneNumber(const string& pn) {
	this->phoneNumber = pn;
}

string Customer::GetPhoneNumber() const {
	return phoneNumber;
}

void Customer::SetBoughtCar(bool bc) {
	this->boughtCar = bc;
}

bool Customer::GetBoughtCar() const {
	return boughtCar;
}

void Customer::SetInterstedVehicle(const string& iv) {
	this->interestedVehicle = iv;
}

string Customer::GetInterstedVehicle() const{
	return interestedVehicle;
}

void Customer::SetInterestedModel(const string& im) {
	this->interestedModel = im;
}

string Customer::GetInterestedModel() const {
	return interestedModel;
}
