#include "dealership.h"
#include <iomanip>

Dealership::Dealership() {
	cout << "DEALERSHIP CONSTRUCTOR CALLED" << endl;
} // ends Dealership()

Dealership::~Dealership() {
	cout << "DEALERSHIP DESTRUCTOR CALLED" << endl;
	for(Customer* each : vecCustomers) {
		delete each;
	} // ends for 

	for(Vehicle* each : vecVehicles) {
		delete each;
	} // ends for
} // ends ~Dealership()

// Creates and adds custoer to vector
void Dealership::AddCustomer(const string& name, const string& phoneNumber, const string& emailAddress, bool interested, bool bought, const string& interestedVehicle, const string& interestedModel) {
	vecCustomers.emplace_back(new Customer(name, phoneNumber, emailAddress, interested, bought, interestedVehicle, interestedModel));
} // ends AddCustomer()

// Adds customer to vector if customer obj is passed in
void Dealership::AddCustomer(Customer* obj) {
	vecCustomers.emplace_back(obj);
} // ends AddCustomer()

// Prints customer info..
void Dealership::PrintCustomerInfo() const {
	cout << "Customer Information:" << endl;
	for(size_t i = 0; i < vecCustomers.size(); i++) { 
		cout << "Customer #" << i + 1 << endl;
		cout << "Name: " << vecCustomers.at(i)->GetName() << endl;
		cout << "Phone number: " << vecCustomers.at(i)->GetPhoneNumber() << endl;
		cout << "Email address: " << vecCustomers.at(i)->GetEmailAddresss() << endl;
		cout << "Is interested: " << boolalpha << vecCustomers.at(i)->GetIsInterested() <<  endl;
		cout << "Bought car: " << boolalpha << vecCustomers.at(i)->GetBoughtCar() << endl;
		cout << "Vehicle interested in: " << vecCustomers.at(i)->GetInterstedVehicle() << endl;
		cout << "Vehicle model interested in: " << vecCustomers.at(i)->GetInterestedModel() << endl;

		if(i != vecCustomers.size() - 1) {
			cout << endl;
		} // ends if
	} // ends for
} // ends PrintCustomerInfo()

// Overloaded so you can also pass customer object into it
void Dealership::PrintCustomerInfo(Customer* obj) const {
	cout << "Name: " << obj->GetName() << endl;
	cout << "Phone number: " << obj->GetPhoneNumber() << endl;
	cout << "Email address: " << obj->GetEmailAddresss() << endl;
	cout << "Is interested: " << boolalpha << obj->GetIsInterested() <<  endl;
	cout << "Bought car: " << boolalpha << obj->GetBoughtCar() << endl;
	cout << "Vehicle interested in: " << obj->GetInterstedVehicle() << endl;
	cout << "Vehicle model interested in: " << obj->GetInterestedModel() << endl;
} // ends PrintCustomerInfo()

// TODO 
void Dealership::FindInterestedCustomer() const {
}

// More like -- iterates throught vector to find name. We obv should implement some kind of sorting & searching algo to make this roar.
int Dealership::FindCurrentCustomerIndex(const string& nameToFind) const {
	for(size_t i = 0; i < vecCustomers.size(); i++) { 
		if(nameToFind == vecCustomers.at(i)->GetName()) {
			return i;
		} // ends if
	} // ends for
	return -1;
} // ends FindCurrentCustomer()

// Finds the customer you pass to it and prints out their information We obv should implement some kind of sorting & searching algo to make this roar.
void Dealership::FindCurrentCustomer(const string& nameToFind) const {
	for(size_t i = 0; i < vecCustomers.size(); i++) { 
		cout << "Searching for " << nameToFind << "..." << endl;
		if(nameToFind == vecCustomers.at(i)->GetName()) {
			cout << "FOUND " << nameToFind << endl;
			PrintCustomerInfo(vecCustomers.at(i));
		} // ends if
	} // ends for
} // ends FindCurrentCustomer()

// Same as above... we obj need to implement sorting & searching algo!
int Dealership::SearchForVehicleIndex(const string& vehicleToFind) const {
	for(size_t i = 0; i < vecVehicles.size(); i++) {
		if(vehicleToFind == vecVehicles.at(i)->GetVin()) {
			return i;
		} // ends if
	} // ends for
	return 1;
} // ends SearchForVehicle()

// Same as aove we obv should implement some kind of sorting & searching algo to make this roar.
void Dealership::SearchForVehicle(const string& vehicleToFind) const {
	for(size_t i = 0; i < vecVehicles.size(); i++) {
		if(vehicleToFind == vecVehicles.at(i)->GetVin()) {
			cout << "FOUND " << vehicleToFind << endl;
			PrintVehicleInfo(vecVehicles.at(i));
		} // ends if
	} // ends for
} // ends SearchForVehicle()

// VEHICLE STUFF BELOW
// This method is the same as the AddCustomer above
void Dealership::AddVehicle(const int& yearAdd, const string& makeAdd, const string& modelAdd, const string& colorAdd, const int& daysOnLotAdd, const double& priceAdd, const string& vinAdd) {
	vecVehicles.emplace_back(new Vehicle(yearAdd, makeAdd, modelAdd, colorAdd, daysOnLotAdd, priceAdd, vinAdd));
} // ends AddVehicle()

// Works same as AddCustomer above 
void Dealership::AddVehicle(Vehicle* obj) {
	vecVehicles.emplace_back(obj);
} // ends AddVehicle()

// The same as PrintCustomerInfo above
void Dealership::PrintVehicleInfo() const {
	cout << "Vehicle Information:" << endl;
	for(size_t i = 0; i < vecVehicles.size(); i++) { 
		cout << "Vehicle #" << i + 1 << endl;
		cout << "Make: " << vecVehicles.at(i)->GetMake() << endl;
		cout << "Model: " << vecVehicles.at(i)->GetModel() << endl;
		cout << "Color: " << vecVehicles.at(i)->GetColor() << endl;
		cout << "Days on lot: " << vecVehicles.at(i)->GetDaysOnLot() << " days" << endl;
		cout << "Price: $" << vecVehicles.at(i)->GetPrice() << endl;
		cout << "VIN number: " << vecVehicles.at(i)->GetVin() << endl;

		if(i != vecCustomers.size() - 1) {
			cout << endl;
		} // ends if
	} // ends for
} // ends PrintVehicleInfo()

// The same as PrintCustomerInfo above
void Dealership::PrintVehicleInfo(Vehicle* obj) const {
	cout << "Make: " << obj->GetMake() << endl;
	cout << "Model: " << obj->GetModel() << endl;
	cout << "Color: " << obj->GetColor() << endl;
	cout << "Days on lot: " << obj->GetDaysOnLot() <<  endl;
	cout << "Price: $" << obj->GetPrice() << endl;
	cout << "VIN number: " << obj->GetVin() << endl;
} // ends PrintVehicleInfo


// The same as PrintVehicleInfo above
void Dealership::PrintSalesInfo() const {
	cout << endl << endl;
	if(vecSales.size() <= 0) {
		cout << "No sales to report." << endl;
	} else { 
		cout << "Sales Info:" << endl;
		for(size_t i = 0; i < vecSales.size(); i++) {
			Vehicle* currVehicle = vecSales.at(i)->GetVehicleObj();
			Customer* currCustomer = vecSales.at(i)->GetCustomerObj();
			cout << "Customer Information: " << endl;
			PrintCustomerInfo(currCustomer);
			cout << "Vehicle Information: " << endl;
			PrintVehicleInfo(currVehicle);
			cout << "Sales price: $" << vecSales.at(i)->GetSalesPrice() << endl;
			cout << "Sales by day: " << vecSales.at(i)->GetSalesByDay() << endl;
			cout << "Sales by week: " << vecSales.at(i)->GetSalesByWeek() << endl;
			cout << "Sales by month: " << vecSales.at(i)->GetSalesByMonth() << endl;
			cout << "Salesman: " << vecSales.at(i)->GetSalesmanName() << endl;

			if(i != vecCustomers.size() - 1) {
				cout << endl;
			} // ends if
		} // ends for
	} // ends if
} // ends PrintSalesInfo()

// JUST A TMP METHOD FOR TESTING
void Dealership::BuyCar() {
	string name;
	string vname;
	cout << "You want to buy a car?, what is your name?" << endl;
	getline(cin, name);
	Customer* currCustomer = vecCustomers.at(FindCurrentCustomerIndex(name));
	if(FindCurrentCustomerIndex(name) == -1) {
		cout << endl << endl << "You are not in the database, sorry!" << endl;
		cout << "bye, bye." << endl;
		return;
	} else { 
		cout << "What car would you like to buy? (Type VIN number)" << endl;
		PrintVehicleInfo();
		getline(cin, vname);
		Vehicle* currVehicle = vecVehicles.at(SearchForVehicleIndex(vname));
		currCustomer->SetBoughtCar(true);
		Sales* currSale = new Sales(currVehicle, currCustomer, "Alex", 10.00, 2.32, 4.55, 500.39);
		vecSales.emplace_back(currSale);
	} // ends if
} // ends BuyCar()

// TODO: IMPLEMENT SALE STUFF
void Dealership::OpenFile() {
	string line;
	vecCustomers.clear();
	vecVehicles.clear();
	vecSales.clear();

	inputFile.open(customersFilename);
	if(!inputFile.is_open()) {
		cerr << customersFilename << " unable to open!" << endl;
		return;
	} // ends if

	while(getline(inputFile, line)) {
		if(line.find("Customer") != string::npos) {
			string name, pn, ea, interestedStr, boughtStr, iv, im;
			bool interested = false, bought = false;
			while(getline(inputFile, line) && !line.empty()) {
				if(line == "Name:") {
					getline(inputFile, name);
				} else if(line == "Phone:") {
					getline(inputFile, pn);
				} else if(line == "Email:") {
					getline(inputFile, ea);
				} else if(line == "Interested:") {
					getline(inputFile, interestedStr);
				} else if(line == "Bought:") {
					getline(inputFile, boughtStr);
				} else if(line == "Vehicle:") {
					getline(inputFile, iv);
				} else if(line == "Model:") {
					getline(inputFile, im);
				} // ends if

				if(!name.empty() && !pn.empty() && !ea.empty() && !interestedStr.empty() && !boughtStr.empty() && !iv.empty() && !im.empty()) { 
					istringstream(interestedStr) >> interested;
					istringstream(boughtStr) >> bought;
					cout << "Adding customer: " << name << ", " << pn << ", " << ea << ", " << interested << ", " << bought << ", " << iv << ", " << im << endl;
					AddCustomer(name, pn, ea, interested, bought, iv, im);
				} // ends if
			} // ends while
		} // ends if
	} // ends while
	inputFile.close(); // closing customers.txt

	inputFile.open(vehiclesFilename); // opening vehicles.txt
	if(!inputFile.is_open()) {
		cerr << vehiclesFilename << " unable to open!" << endl;
		return;
	} // ends if
	line.clear();
	while(getline(inputFile, line)) { 
		if(line.find("Vehicle") != string::npos) {
			string yearOpen, makeOpen, modelOpen, colorOpen, daysOnLotOpen, priceOpen, vinOpen;
			while(getline(inputFile, line) && !line.empty()) {
				if(line == "Year:") {
					getline(inputFile, yearOpen);
				} else if(line == "Make:") {
					getline(inputFile, makeOpen);
				} else if(line == "Model:") {
					getline(inputFile, modelOpen);
				} else if(line == "Color:") {
					getline(inputFile, colorOpen);
				} else if(line == "Days On Lot:") {
					getline(inputFile, daysOnLotOpen);
				} else if(line == "Price:") {
					getline(inputFile, priceOpen);
				} else if(line == "VIN:") {
					getline(inputFile, vinOpen);
				} // ends if

				if(!yearOpen.empty() && !makeOpen.empty() && !modelOpen.empty() && !colorOpen.empty() && !daysOnLotOpen.empty() && !priceOpen.empty() && !vinOpen.empty()) {
					int yearNew = stoi(yearOpen);
					int daysOnLotNew = stoi(daysOnLotOpen);
					double priceNew = stod(priceOpen);
					cout << "Adding vehicle: " << yearNew << ", " << makeOpen << ", " << modelOpen << ", " << colorOpen << ", " << daysOnLotNew << ", " << priceNew << ", " << vinOpen << endl;
					AddVehicle(yearNew, makeOpen, modelOpen, colorOpen, daysOnLotNew, priceNew, vinOpen);	
				} // ends if
			} // ends while
		} // ends if
	} // ends while
	inputFile.close();
} // ends OpenFile()

void Dealership::SaveToFile() {
	outputFile.open(customersFilename);
	if(!outputFile.is_open()) {
		cerr << customersFilename << " unable to open for writing!" << endl;
		return;
	} // ends if

	// Write customer data to the file
	for(Customer* curr: vecCustomers) {
		outputFile << "Customer" << endl;
		outputFile << "Name:" << endl << curr->GetName() << endl;
		outputFile << "Phone:" << endl << curr->GetPhoneNumber() << endl;
		outputFile << "Email:" << endl << curr->GetEmailAddresss() << endl;
		outputFile << "Interested:" << endl << curr->GetIsInterested() << endl;
		outputFile << "Bought:" << endl << curr->GetBoughtCar() << endl;
		outputFile << "Vehicle:" << endl << curr->GetInterstedVehicle() << endl;
		outputFile << "Model:" << endl << curr->GetInterestedModel() << endl;
		outputFile << endl; // Empty line between customers
	} // ends for
	  // Close the customer file
	outputFile.close();

	outputFile.open(vehiclesFilename);
	if(!outputFile.is_open()) {
		cerr << vehiclesFilename << " unable to open for writing!" << endl;
		return;
	} // ends if
	  // Write customer data to the file
	for(Vehicle* curr: vecVehicles) {
		outputFile << "Vehicle" << endl;
		outputFile << "Year:" << endl << curr->GetYear() << endl;
		outputFile << "Make:" << endl << curr->GetMake() << endl;
		outputFile << "Model:" << endl << curr->GetModel() << endl;
		outputFile << "Color:" << endl << curr->GetColor() << endl;
		outputFile << "Days On Lot:" << endl << curr->GetDaysOnLot() << endl;
		outputFile << "Price:" << endl << curr->GetPrice() << endl;
		outputFile << "VIN:" << endl << curr->GetVin() << endl;
		outputFile << endl; // Empty line between vehicles
	} // ends for
	  // Close the vehicle
	outputFile.close();
} // ends SaveToFile();
