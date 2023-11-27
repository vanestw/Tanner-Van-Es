#include "customer.h"

// Constructors and Destructor
Customer::Customer() {
	// cout << "CUSTOMER DEFAULT CONSTRUCTOR CALLED" << endl;
} // ends Customer()

Customer::Customer(const string& n, const string& pn, const string& ea, bool interested, bool bought, const string& vi, const string& vmi) {
	// cout << "CUSTOMER PARAMATERIZED CONSTRUCTOR CALLED" << endl;
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
	// cout << "CUSTOMER DESTRUCTOR CALLED" << endl;
} // ends ~Customer()

// INPUT: Customer object pointer
// PROCESS: pushes the pointer to the Customer object into the vector of Customer object pointers
// OUTPUT: N/A
void Customer::AddCustomer(Customer* obj) {
	vecCustomers.emplace_back(obj);
} // ends AddCustomer()

void Customer::AddCustomer(const string& nameAdd, const string& phoneNumberAdd, const string& emailAddressAdd, bool interestedAdd, bool boughtAdd, const string& interestedVehicleAdd, const string& interestedModelAdd) {
	vecCustomers.emplace_back(new Customer(nameAdd, phoneNumberAdd, emailAddressAdd, interestedAdd, boughtAdd, interestedVehicleAdd, interestedModelAdd));
} // ends AddCustomer()

// INPUT: Customer object pointer
// PROCESS: Prints the objects information
// OUTPUT: N/A
void Customer::PrintCustomerInfo(Customer* obj) const {
	cout << "Name: " << obj->GetName() << endl;
	cout << "Phone number: " << obj->GetPhoneNumber() << endl;
	cout << "Email address: " << obj->GetEmailAddress() << endl;
	cout << "Is interested: " << boolalpha << obj->GetIsInterested() <<  endl;
	cout << "Bought car: " << boolalpha << obj->GetBoughtCar() << endl;
	cout << "Vehicle interested in: " << obj->GetInterstedVehicle() << endl;
	cout << "Vehicle model interested in: " << obj->GetInterestedModel() << endl;
} // ends PrintCustomerInfo()

// INPUT: N/A
// PROCESS: Prints every objects information in the vector of object pointers to stdout
// OUTPUT: N/A
void Customer::PrintEntirCustomerVector() {
	cout << "Customer Information:" << endl;
	unsigned int customerIndex = 0;
	for(const Customer* customer : vecCustomers) {
		cout << "Customer #" << customerIndex + 1 << endl;
		cout << "Name: " << customer->GetName() << endl;
		cout << "Phone number: " << customer->GetPhoneNumber() << endl;
		cout << "Email address: " << customer->GetEmailAddress() << endl;
		// boolalpha makes it print "true" or "false" instead of 0 and 1
		cout << "Is interested: " << boolalpha << customer->GetIsInterested() <<  endl;
		cout << "Bought car: " << boolalpha << customer->GetBoughtCar() << endl;
		cout << "Vehicle interested in: " << customer->GetInterstedVehicle() << endl;
		if(customerIndex != vecCustomers.size() - 1) {
			cout << endl;
		} // ends if
		customerIndex++;
	} // ends for
	  
} // ends PrintCustomerInfo()

// INPUT: N/A
// PROCESS: Finds which customers are interested in purchasing a car and prints those customers info to stdout
// OUTPUT: N/A
void Customer::PrintPotentialCustomerInfo() const {
	cout << "Potential Customer Information:" << endl;
	unsigned int customerIndex = 0;
	for(Customer* customer : vecCustomers) {
		bool check = false;
		if(customer->GetIsInterested()) {
			cout << "Customer #" << customerIndex + 1 << endl;
			PrintCustomerInfo(customer);
			check = true;
		} // ends if
		if(check) {
			cout << endl;
		}  // ends if
		customerIndex++;
	} // ends for
} // ends PrintCustomerInfo()

// INPUT: N/A
// PROCESS: Finds which customers have bought a car and prints those customers info to stdout
// OUTPUT: N/A
void Customer::PrintCustomersWhoBoughtCar() const {
	cout << "Customers Who Have Purchased a Vehicle's Information:" << endl;
	unsigned int customerIndex = 0;
	for(Customer* customer : vecCustomers) {
		bool check = false;
		if(customer->GetBoughtCar()) {
			cout << "Customer #" << customerIndex + 1 << endl;
			PrintCustomerInfo(customer);
			check = true;
		} // ends if
		  if(check) { 
			cout << endl;
		  }  // ends if
		customerIndex++;
	} // ends for
} // ends PrintCustomersWhoBoughtCar()

// INPUT: String
// PROCESS: Searches vector for the object with a name that matches the string
// OUTPUT: Index in vector for matching customer and -1 if not found
int Customer::FindCustomerIndex(const string& nameToFind) const {
	int i = 0;
	for(const Customer* customer : vecCustomers) {
		if(nameToFind == customer->GetName()) {
			return i;
		} // ends if
		i++;
	} // ends for
	return -1;
} // ends FindCurrentCustomer()

// INPUT: String
// PROCESS: Searches vector for the object with a name that matches the string
// OUTPUT: Matching customers information and nullptr if not found
Customer* Customer::FindCustomer(const string& nameToFind) const {
	for(Customer* customer : vecCustomers) {
		if(nameToFind == customer->GetName()) {
			return customer;
		} // ends if
	} // ends for
	return nullptr;
} // ends FindCurrentCustomer()

// ALL SETTERS AND GETTERS 
void Customer::SetIsInterested(bool interested) {
	isInterested = interested;	
} // ends SetIsInterested()

bool Customer::GetIsInterested() const {
	return isInterested;
} // ends GetIsInterested()

void Customer::SetName(const string& n) { 
	name = n;
} // ends SetName()

string Customer::GetName() const {
	return name;
} // ends GetName()

void Customer::SetEmailAddress(const string& ea) {
	emailAddress = ea;
} // ends SetEmailAdress()

string Customer::GetEmailAddress() const {
	return emailAddress;
} // ends GetEmailAddress()

void Customer::SetPhoneNumber(const string& pn) {
	phoneNumber = pn;
} // ends SetPhoneNumber()

string Customer::GetPhoneNumber() const {
	return phoneNumber;
} // ends GetPhoneNumber()

void Customer::SetBoughtCar(bool bc) {
	boughtCar = bc;
} // ends SetBoughtCar()

bool Customer::GetBoughtCar() const {
	return boughtCar;
} // ends GetBoughtCar()

void Customer::SetInterstedVehicle(const string& iv) {
	interestedVehicle = iv;
} // ends SetInterestedVehicle()

string Customer::GetInterstedVehicle() const{
	return interestedVehicle;
} // ends GetInterestedVehicle()

void Customer::SetInterestedModel(const string& im) {
	interestedModel = im;
} // ends SetInterestedModel()

string Customer::GetInterestedModel() const {
	return interestedModel;
} // ends GetInterestedModel()
