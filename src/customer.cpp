#include "customer.h"
#include <bits/stdc++.h>


Customer::Customer() {
	cout << "CONSTRUCTOR CALLED" << endl;
	this->name = "NO NAME";
}

Customer::Customer(string n, string pn, string ea, bool interested, bool bought, string vi, string vmi) {
	cout << "PARAM CONSTRUCTOR CALLED" << endl;
	this->SetName(n);
	this->SetPhoneNumber(pn);
	this->SetEmailAddress(ea);
	this->SetIsInterested(interested);
	this->SetBoughtCar(bought);
	this->SetInterstedVehicle(vi);
	this->SetInterestedModel(vmi);

	this->GetVector().emplace_back(this);
}

Customer::Customer(const Customer& other) {
	cout << "COPY CONSTRUCTOR CALLED" << endl;
    this->name = other.name;
    this->phoneNumber = other.phoneNumber;
    this->emailAddress = other.emailAddress;
	this->isInterested = other.isInterested;
}

// FIXME: Can't get this to not infinitely loop
// Customer::~Customer() {
// 	cout << "DESTRUCTOR CALLED" << endl;
//     for (Customer* customer : GetVector()) {
//             delete customer;
//     }
// }

Customer::~Customer() {
	cout << "DESTRUCTOR CALLED" << endl;
}

vector<Customer*>& Customer::GetVector() const {
	static vector<Customer*> vecCustomers;
	return vecCustomers;
}

// TODO: Write these methods
void Customer::FindInterestedCustomer() const {

}

void Customer::FindCurrentCustomer(string nameToFind) const {
	for(Customer* i : GetVector()) {
		if(nameToFind == i->GetName()) {
			cout << endl << "Searching for " << nameToFind << "..." << endl;
			cout << "Here's " << nameToFind << "'s info:" << endl;
			i->PrintInfo(i);
		}
	}
}

void Customer::PrintInfo() const {
	cout << endl << "Everyone in database: " << endl;
	for(size_t i = 0; i < GetVector().size(); i++) { 
		cout << "Name: " << GetVector().at(i)->GetName() << endl;
		cout << "Phone number: " << GetVector().at(i)->GetPhoneNumber() << endl;
		cout << "Email address: " << GetVector().at(i)->GetEmailAddresss() << endl;
		cout << "Is interested: " << boolalpha << GetVector().at(i)->GetIsInterested() <<  endl;
		cout << "Bought car: " << boolalpha << GetVector().at(i)->GetBoughtCar() << endl;
		cout << "Vehicle interested in: " << GetVector().at(i)->GetInterstedVehicle() << endl;
		cout << "Vehicle model interested in: " << GetVector().at(i)->GetInterestedModel() << endl;

		if(i != GetVector().size() - 1) { 
		cout << endl;
		}
	}
}

void Customer::PrintInfo(Customer* obj) {
		cout << "Name: " << obj->GetName() << endl;
		cout << "Phone number: " << obj->GetPhoneNumber() << endl;
		cout << "Email address: " << obj->GetEmailAddresss() << endl;
		cout << "Is interested: " << boolalpha << obj->GetIsInterested() <<  endl;
		cout << "Bought car: " << boolalpha << obj->GetBoughtCar() << endl;
		cout << "Vehicle interested in: " << obj->GetInterstedVehicle() << endl;
		cout << "Vehicle model interested in: " << obj->GetInterestedModel() << endl;

}

// FIXME THIS IS A TERRIBLE WAY TO GET THE DATA FROM USER. CHANGE THIS. I HAVE IT LIKE THIS TO EASILY GET LOGIC WORKING AND WHILE WE FIGURE OUT A BETTER WAY TO GET DATA FROM USER!!
	// CHANGE THIS ALL OF COURSE ESPECIALLY THE CHECKING IF INTERESTED PART. FIXME
void Customer::SetInfo() {
	Customer* newCustomer = new Customer();
	string n, pn, ea;
	char x;
	bool interested = false;
	cout << "Plese enter your first and last name:" << endl;
	getline(cin, n);
	newCustomer->SetName(n);
	cout << "Please enter your phone number:" << endl;
	getline(cin, pn);
	newCustomer->SetPhoneNumber(pn);
	cout << "PLease enter your email address:" << endl;
	getline(cin, ea);
	newCustomer->SetEmailAddress(ea);
	cout << "Type 'y' if you are you interested in buying a car." << endl;
	cin >> x;
		if(x != 'y') {
			interested = false;	
		} else { 
			interested = true;
		}
	newCustomer->SetIsInterested(interested);
	cout << "Type 'y' if you have bought a car." << endl;
	bool bought;
	cin >> x;
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(), '\n'); // completely clears input buffer
		if(x != 'y') {
			bought = false;	
		} else { 
			bought = true;
		}
	newCustomer->SetBoughtCar(bought);

	cout << "What vehicle are you interested in?" << endl;
	string iv;
	getline(cin, iv);
	newCustomer->SetInterstedVehicle(iv);
	
	cout << "What model of the " << iv << " are you interested in?" << endl;
	string model;
	getline(cin, model); 
	newCustomer->SetInterestedModel(model);

	GetVector().emplace_back(newCustomer);
}


// ALL SETTERS AND GETTERS BELOW

void Customer::SetIsInterested(bool interested) {
	this->isInterested = interested;	
}

bool Customer::GetIsInterested() {
	return isInterested;
}

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
