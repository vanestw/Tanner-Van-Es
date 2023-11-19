#include "customer.h"
#include <utility>

vector<Customer> Customer::vecCustomers;

Customer::Customer() {
	this->name = "NO NAME";
}

Customer::Customer(string n, string pn, string ea) {
	this->SetName(n);
	this->SetPhoneNumber(pn);
	this->SetEmailAddress(ea);

	vecCustomers.emplace_back(*this);
}

Customer::Customer(const Customer& other) {
    // Copy all member variables
    this->name = other.name;
    this->phoneNumber = other.phoneNumber;
    this->emailAddress = other.emailAddress;
}

// TODO: Write these methods
void Customer::FindInterestedCustomer() const {

}

void Customer::FindCurrentCustomer() const {

}

void Customer::PrintInfo() const {
	for(size_t i = 0; i < vecCustomers.size(); i++) { 
		cout << "Name: " << vecCustomers.at(i).GetName() << endl;
		cout << "Phone number: " << vecCustomers.at(i).GetPhoneNumber() << endl;
		cout << "Email address: " << vecCustomers.at(i).GetEmailAddresss() << endl;

		if(i != vecCustomers.size() - 1) { 
		cout << endl;
		}
	}
}

void Customer::SetInfo() {
	string n, pn, ea;
	cout << "Plese enter your first and last name:" << endl;
	getline(cin, n);
	this->SetName(n);
	cout << "Please enter your phone number:" << endl;
	getline(cin, pn);
	this->SetPhoneNumber(pn);
	cout << "PLease enter your email address:" << endl;
	getline(cin, ea);
	this->SetEmailAddress(ea);

	vecCustomers.emplace_back(*this);
}


// ALL SETTERS AND GETTERS BELOW
//

void Customer::SetName(string n) { 
	this->name = n;
}

string Customer::GetName() const {
	return name;
}

void Customer::SetSalesmanName(string sn) {
	this->salesmanName = sn;
}

string Customer::GetSalesmanName() const {
	return salesmanName;
}

void Customer::SetEmailAddress(string ea) {
	this->emailAddress = ea;
}

string Customer::GetEmailAddresss() const {
	return emailAddress;
}

void Customer::SetPhoneNumber(string pn) {
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

void Customer::SetInterstedVehicle(string iv) {
	this->interestedVehicle = iv;
}

string Customer::GetInterstedVehicle() const{
	return interestedVehicle;
}

void Customer::SetInterestedModel(string im) {
	this->interestedModel = im;
}

string Customer::GetInterestedModel() const {
	return interestedModel;
}
