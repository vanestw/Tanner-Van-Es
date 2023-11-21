#include "dealership.h"
#include <iomanip>

Dealership::Dealership() {
	cout << "DEALERSHIP CONSTRUCTOR CALLED" << endl;
} // ends Dealership()

// destructor removes each object in all vectors
Dealership::~Dealership() {
	cout << "DEALERSHIP DESTRUCTOR CALLED" << endl;
	for(Customer* each : vecCustomers) {
		delete each;
	} // ends for 

	for(Vehicle* each : vecVehicles) {
		delete each;
	} // ends for

	for(Sales* each : vecSales) {
		delete each;
	} // ends for
} // ends ~Dealership()

// Creates and adds customer to vector
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
int Dealership::FindCustomerIndex(const string& nameToFind) const {
	for(size_t i = 0; i < vecCustomers.size(); i++) { 
		if(nameToFind == vecCustomers.at(i)->GetName()) {
			return i;
		} // ends if
	} // ends for
	return -1;
} // ends FindCurrentCustomer()

// Finds the customer you pass to it and prints out their information We obv should implement some kind of sorting & searching algo to make this roar.
Customer* Dealership::FindCustomer(const string& nameToFind) const {
	for(size_t i = 0; i < vecCustomers.size(); i++) { 
		if(nameToFind == vecCustomers.at(i)->GetName()) {
			return vecCustomers.at(i);
		} // ends if
	} // ends for
	return nullptr;
} // ends FindCurrentCustomer()

// Same as above... we obj need to implement sorting & searching algo!
int Dealership::FindVehicleIndex(const string& vehicleToFind) const {
	for(size_t i = 0; i < vecVehicles.size(); i++) {
		if(vehicleToFind == vecVehicles.at(i)->GetVin()) {
			return i;
		} // ends if
	} // ends for
	return 1;
} // ends SearchForVehicle()

// Same as aove we obv should implement some kind of sorting & searching algo to make this roar.
Vehicle* Dealership::FindVehicle(const string& vehicleToFind) const {
	for(size_t i = 0; i < vecVehicles.size(); i++) {
		if(vehicleToFind == vecVehicles.at(i)->GetVin()) {
			return vecVehicles.at(i);
		} // ends if
	} // ends for
	return nullptr;
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
		cout << endl << "Sales Info:" << endl;
			Vehicle* currVehicle = vecSales.at(0)->GetVehicleObj();
			Customer* currCustomer = vecSales.at(1)->GetCustomerObj();
		for(size_t i = 0; i < vecSales.size(); i++) {
			cout << "Customer Information: " << endl;
			PrintCustomerInfo(currCustomer);
			cout << endl << endl << "Vehicle Information: " << endl;
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
int Dealership::BuyCar() {
	string name;
	string vname;
	cout << "You want to buy a car?, what is your name?" << endl;
	getline(cin, name);
	if(FindCustomerIndex(name) == -1) { 
		cout << endl << endl << "You are not in the database, sorry!" << endl;
		cout << "bye, bye." << endl;
		return 1;
	} else { 
		Customer* currCustomer = vecCustomers.at(FindCustomerIndex(name));
		cout << "What car would you like to buy? (Type VIN number)" << endl;
		PrintVehicleInfo();
		getline(cin, vname);
		Vehicle* currVehicle = vecVehicles.at(FindVehicleIndex(vname));
		currCustomer->SetBoughtCar(true);
		Sales* currSale = new Sales(currVehicle, currCustomer, "Alex", 10.00, 2.32, 4.55, 500.39);
		vecSales.emplace_back(currSale);
	} // ends if
	return 0;
} // ends BuyCar()

// TODO: FIX SALE STUFF
void Dealership::OpenFile() {
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

	inputFile.open(salesFilename);
	if(!inputFile.is_open()) {
		cerr << salesFilename << " unable to open!" << endl;
		return;
	}
	ReadSalesData(inputFile);
	inputFile.close();

} // ends OpenFile()

void Dealership::AddSale(Vehicle* vehicle, Customer* customer, const string& sn, const double& sp, const double& sbd, const double& sbw, const double& sbm) {
	vecSales.emplace_back(new Sales(vehicle, customer, sn, sp, sbd, sbw, sbm));
} // ends AddSale()

void Dealership::AddSale(Sales* obj) {
	vecSales.emplace_back(obj);
} // ends AddSale()

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

	//Vehicle* vehicle, Customer* customer, string sn, double sp, double sbd, double sbw, double sbm)
	outputFile.open(salesFilename);
	if(!outputFile.is_open()) {
		cerr << salesFilename << " unable to open for writing!" << endl;
		return;
	} // ends if
	for(Sales* curr: vecSales) {
		outputFile << "Sales" << endl;
		outputFile << "Salesman's Name:" << endl << curr->GetSalesmanName() << endl;
		outputFile << "Sale Price:" << endl << curr->GetSalesPrice() << endl;
		outputFile << "Sales By Day: " << endl << curr->GetSalesByDay() << endl;
		outputFile << "Sales By Week:" << endl << curr->GetSalesByWeek() << endl;
		outputFile << "Sales By Month" << endl << curr->GetSalesByMonth() << endl;
		outputFile << endl;
		cout << "Customer" << endl;
		Customer* customer = curr->GetCustomerObj();
		outputFile << customer->GetName();
		outputFile << endl;
		outputFile << "Vehicle" << endl;
		Vehicle* vehicle = curr->GetVehicleObj();
		outputFile << vehicle->GetVin();
	} // ends for
	  // Close sale file
	outputFile.close();
	cout << "SAVED" << endl;
} // ends SaveToFile();

// TODO FIX THIS MESS
void Dealership::ReadSalesData(ifstream& file) {
	string salesmanName, salePriceStr, salesByDayStr, salesByWeekStr, salesByMonthStr, customerName, vehicleVin;

	while(getline(file, line)) {
		if(line.find("Sale") != string::npos) {
			while(getline(file, line) && !line.empty()) {
				if(line == "Salesman's Name:") {
					getline(file, salesmanName);
				} else if(line == "Sale Price:") {
					getline(file, salePriceStr);
				} else if(line == "Sales By Day:") {
					getline(file, salesByDayStr);
				} else if(line == "Sales By Week:") {
					getline(file, salesByWeekStr);
				} else if(line == "Sales By Month:") {
					getline(file, salesByMonthStr);
				} else if(line == "Customer") {
					getline(file, customerName);
				} else if(line == "Vehicle") {
					getline(file, vehicleVin);
				} // ends if

				if(!salesmanName.empty() && !salePriceStr.empty() && !salesByDayStr.empty() && !salesByWeekStr.empty() && !salesByMonthStr.empty()) {
					double salePrice = stod(salePriceStr);
					double salesByDay = stod(salesByDayStr);
					double salesByWeek = stod(salesByWeekStr);
					double salesByMonth = stod(salesByMonthStr);

					Customer* customer = nullptr;
					if(!customerName.empty()) {
						customer = FindCustomer(customerName);
					} else {
						cout << "Customer not found or missing sales data." << endl;
					}

					Vehicle* vehicle = nullptr;
					if(!vehicleVin.empty()) { 
						vehicle = FindVehicle(vehicleVin);
					} // ends if

					if(vehicle != nullptr && customer != nullptr) {
						AddSale(vehicle, customer, salesmanName, salePrice, salesByDay, salesByWeek, salesByMonth);
					} else {
						cout << "Vehicle not found." << endl;
					} // ends if
				} // ends while
			} // ends inner while
		} // ends if
	} // ends while
} // ends ReadSalesData()
