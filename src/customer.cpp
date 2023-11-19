#include "customer.h"

<<<<<<< HEAD
#include <utility>

=======
vector<Customer> Customer::vecCustomers;

Customer::Customer() {
	this->name = "NO NAME";
}

Customer::Customer(string n, string pn, string ea) {
	cout << "Vector size at top of constructor: " << vecCustomers.size() << endl;
	this->SetName(n);
	this->SetPhoneNumber(pn);
	this->SetEmailAddress(ea);

	vecCustomers.emplace_back(*this);
	cout << "Vector size at bottom of constructor: " << vecCustomers.size() << endl;
}

Customer::Customer(const Customer& other) {
    // Copy all member variables
    this->name = other.name;
    this->phoneNumber = other.phoneNumber;
    this->emailAddress = other.emailAddress;
}
>>>>>>> f8c0f6e (Starting to work on methods. Added SetInfo and PrintInfo... only with very basic stuff to get it working first.)

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
	string name, phoneNumber, emailAddress;
	cout << "Plese enter your first and last name:" << endl;
	getline(cin, name);
	this->SetName(name);
	cout << "Please enter your phone number:" << endl;
	getline(cin, phoneNumber);
	this->SetPhoneNumber(phoneNumber);
	cout << "PLease enter your email address:" << endl;
	getline(cin, emailAddress);
	this->SetEmailAddress(emailAddress);

	vecCustomers.emplace_back(*this);
}


// ALL SETTERS AND GETTERS BELOW
//
<<<<<<< HEAD
void Customer::SetName(string name) {
	this->name = std::move(name);
=======
void Customer::SetName(string n) { 
	this->name = n;
>>>>>>> f8c0f6e (Starting to work on methods. Added SetInfo and PrintInfo... only with very basic stuff to get it working first.)
}

string Customer::GetName() const {
	return name;
}

<<<<<<< HEAD
void Customer::SetSalesmanName(string salesmanName) {
	this->salesmanName = std::move(salesmanName);
=======
void Customer::SetSalesmanName(string sn) {
	this->salesmanName = sn;
>>>>>>> f8c0f6e (Starting to work on methods. Added SetInfo and PrintInfo... only with very basic stuff to get it working first.)
}

string Customer::GetSalesmanName() const {
	return salesmanName;
}

<<<<<<< HEAD
void Customer::SetEmailAddress(string emailAddress) {
	this->emailAddress = std::move(emailAddress);
}

string Customer::GetEmailAddress() {
=======
void Customer::SetEmailAddress(string ea) {
	this->emailAddress = ea;
}

string Customer::GetEmailAddresss() const {
>>>>>>> f8c0f6e (Starting to work on methods. Added SetInfo and PrintInfo... only with very basic stuff to get it working first.)
	return emailAddress;
}

void Customer::SetPhoneNumber(string pn) {
	this->phoneNumber = pn;
}

<<<<<<< HEAD
int Customer::GetPhoneNumber() const {
=======
string Customer::GetPhoneNumber() const {
>>>>>>> f8c0f6e (Starting to work on methods. Added SetInfo and PrintInfo... only with very basic stuff to get it working first.)
	return phoneNumber;
}

void Customer::SetBoughtCar(bool bc) {
	this->boughtCar = bc;
}

bool Customer::GetBoughtCar() const {
	return boughtCar;
}

<<<<<<< HEAD
void Customer::SetInterestedVehicle(string interestedVehicle) {
	this->interestedVehicle = std::move(interestedVehicle);
}

string Customer::GetInterestedVehicle() const{
	return interestedVehicle;
}

void Customer::SetInterestedModel(string interestedModel) {
	this->interestedModel = std::move(interestedModel);
=======
void Customer::SetInterstedVehicle(string iv) {
	this->interestedVehicle = iv;
}

string Customer::GetInterstedVehicle() const {
	return interestedVehicle;
}

void Customer::SetInterestedModel(string im) {
	this->interestedModel = im;
>>>>>>> f8c0f6e (Starting to work on methods. Added SetInfo and PrintInfo... only with very basic stuff to get it working first.)
}

string Customer::GetInterestedModel() const {
	return interestedModel;
}
