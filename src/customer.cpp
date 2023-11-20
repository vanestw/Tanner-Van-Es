#include "customer.h"


Customer::Customer() {
	cout << "CONSTRUCTOR CALLED" << endl;
	this->name = "NO NAME";
}

Customer::Customer(string n, string pn, string ea, bool interested) {
	cout << "PARAM CONSTRUCTOR CALLED" << endl;
	this->SetName(n);
	this->SetPhoneNumber(pn);
	this->SetEmailAddress(ea);
	this->SetIsInterested(interested);

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

void Customer::FindCurrentCustomer() const {

}

void Customer::PrintInfo() const {
	for(size_t i = 0; i < GetVector().size(); i++) { 
		cout << "Name: " << GetVector().at(i)->GetName() << endl;
		cout << "Phone number: " << GetVector().at(i)->GetPhoneNumber() << endl;
		cout << "Email address: " << GetVector().at(i)->GetEmailAddresss() << endl;
		if(GetVector().at(i)->GetIsInterested() == 1) {
			cout << "Is interested: true" <<  endl;
		} else {
			cout << "Is interested: false" <<  endl;
		}

		if(i != GetVector().size() - 1) { 
		cout << endl;
		}
	}
}

// This method is so basic... just getting the most basic logic working... FIXME CHANGE THIS ALL OF COURSE ESPECIALLY THE CHECKING IF INTERESTED PART.
void Customer::SetInfo() {
	Customer* newCustomer = new Customer();
	string n, pn, ea;
	char inter;
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
	cout << "Type 'y' if you are you interested in buying a car?" << endl;
	cin >> inter;
		if(inter != 'y') {
			interested = false;	
		} else { 
			interested = true;
		}
	newCustomer->SetIsInterested(interested);

	GetVector().emplace_back(newCustomer);
}


// ALL SETTERS AND GETTERS BELOW
//

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
