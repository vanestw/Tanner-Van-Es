#include "dealership.h"
#include <iomanip> // for isstringstream
#include <limits> // for numeric_limits

string Dealership::currentRole = "NULL"; // initialization needed for static variable

Dealership::Dealership() : accessControl("defaultUser", "defaultPassword") {
	cout << "DEALERSHIP CONSTRUCTOR CALLED" << endl;
} // ends Dealership()

// Destructor deletes each object in all vectors
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

bool Dealership::Login() {
	string username, password;
	cout << "Enter username: ";
	getline(cin, username);
	cout << "Enter password: ";
	getline(cin, password);

	// Checking login credentials
	if(accessControl.CheckLogin(username, password)) {
		cout << "Login successful!" << endl;
		// Assign currentRole from AccessControl class using AccessControls getter method
		currentRole = accessControl.GetCurrentRole();
		return true;
	} else {
		cerr << "Invalid username or password. Login failed." << endl;
		return false;
	} // ends if
} // ends Login()

int Dealership::MainMenu() {
	int choice = 0, x = 0;
	do {
		cout << "Hello, what would you like to do?" << endl;
		cout << "1) Login" << endl;
		cout << "2) Create account" << endl;
		cout << "3) Quit" << endl;
		cout << "~> ";
		cin >> choice;
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		while(cin.fail()) {
			cerr << "Invalid input. Please enter a number between 1 and 3." << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "~> ";
			cin >> choice;
		} // ends while

		switch(choice) {
			case 1:
				if(this->Login()) {
					OpenFile();
					if(currentRole == "owner") {
						do {
							cout << "Welcome, please choose which option you would like to do." << endl;
							cout << "1) View a list of customers." << endl;
							cout << "2) View a list of potential customers." << endl;
							cout << "3) View a list of vehicles being sold." << endl;
							cout << "4) View a list of all previous sales." << endl;
							cout << "5) Quit to main menu." << endl;
							cout << "~> ";
							cin >> x;

							while(cin.fail()) {
								cerr << "Invalid input. Please enter a number between 1 and 4." << endl;
								cin.clear();
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
								cout << "~> ";
								cin >> x;
							} // ends while

							switch(x) {
								case 1:
									PrintCustomerInfo();
									break;
								case 2:
									PrintPotentialCustomerInfo();
									break;
								case 3:
									PrintVehicleInfo();
									break;
								case 4:
									PrintSalesInfo();
									break;
								case 5:
									break; // Exit to return to main menu
								default:
									cerr << "Invalid input. Please enter a number between 1 and 4." << endl;
							} // ends switch
						} while(x != 5);
					} // ends if currentRole == owner
				} // ends if this->Login()
				break; // ends case 1
			case 2:
				cout << "NEED TO WRITE THIS METHOD" << endl;
				break;
			case 3:
				cout << "Goodbye!" << endl;
				break; // Exits the loop and closes the program
			default:
				cerr << "Invalid input. Please enter a number between 1 and 3." << endl;
		} // ends switch
	} while(choice != 3);

	return 0;
} // ends MainMenu()

// CUSTOMER STUFF BELOW
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
	size_t customerIndex = 0;
	for(const Customer* customer : vecCustomers) {
		cout << "Customer #" << customerIndex + 1 << endl;
		cout << "Name: " << customer->GetName() << endl;
		cout << "Phone number: " << customer->GetPhoneNumber() << endl;
		cout << "Email address: " << customer->GetEmailAddresss() << endl;
		cout << "Is interested: " << boolalpha << customer->GetIsInterested() <<  endl;
		cout << "Bought car: " << boolalpha << customer->GetBoughtCar() << endl;
		cout << "Vehicle interested in: " << customer->GetInterstedVehicle() << endl;
		cout << "Vehicle model interested in: " << customer->GetInterestedModel() << endl;
		if(customerIndex != vecCustomers.size() - 1) {
			cout << endl;
		} // ends if
		customerIndex++;
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

// Prints customer info..
void Dealership::PrintPotentialCustomerInfo() const {
	if(currentRole == "owner") { 
		cout << "Potential Customer Information:" << endl;
		size_t customerIndex = 0;
		for(const Customer* customer : vecCustomers) {
			if(customer->GetIsInterested()) {
				cout << "Customer #" << customerIndex << endl;
				cout << "Name: " << customer->GetName() << endl;
				cout << "Phone number: " << customer->GetPhoneNumber() << endl;
				cout << "Email address: " << customer->GetEmailAddresss() << endl;
				cout << "Is interested: " << boolalpha << customer->GetIsInterested() <<  endl;
				cout << "Bought car: " << boolalpha << customer->GetBoughtCar() << endl;
				cout << "Vehicle interested in: " << customer->GetInterstedVehicle() << endl;
				cout << "Vehicle model interested in: " << customer->GetInterestedModel() << endl;
			} // ends if
			if(customerIndex != vecCustomers.size() - 1) {
				cout << endl;
			} // ends if
			customerIndex++;
		} // ends for
	} else {
		cerr << "You do not have the correct permissions to view potential customer information." << endl;
	} // ends if
} // ends PrintCustomerInfo()

// More like -- iterates throught vector to find name. We obv should implement some kind of sorting & searching algo to make this roar.
int Dealership::FindCustomerIndex(const string& nameToFind) const {
	int i = 0;
	for(const Customer* customer : vecCustomers) { 	
		if(nameToFind == customer->GetName()) {
			return i;
		} // ends if
		i++;
	} // ends for
	return -1;
} // ends FindCurrentCustomer()

// Finds the customer you pass to it and prints out their information We obv should implement some kind of sorting & searching algo to make this roar.
Customer* Dealership::FindCustomer(const string& nameToFind) const {
	for(Customer* customer : vecCustomers) { 	
		if(nameToFind == customer->GetName()) {
			return customer;
		} // ends if
	} // ends for
	return nullptr;
} // ends FindCurrentCustomer()

// VEHICLE STUFF BELOW
// This method is the same as the AddCustomer above
void Dealership::AddVehicle(const int& yearAdd, const string& makeAdd, const string& modelAdd, const string& colorAdd, const int& daysOnLotAdd, const double& priceAdd, const string& vinAdd) {
	vecVehicles.emplace_back(new Vehicle(yearAdd, makeAdd, modelAdd, colorAdd, daysOnLotAdd, priceAdd, vinAdd));
} // ends AddVehicle()

// Works same as AddCustomer above 
void Dealership::AddVehicle(Vehicle* obj) {
	vecVehicles.emplace_back(obj);
} // ends AddVehicle()

// Same as cusotmer one above... we obj need to implement sorting & searching algo!
int Dealership::FindVehicleIndex(const string& vehicleToFind) const {
	int in = 0;
	for(const Vehicle* vehicle : vecVehicles) { 	
		if(vehicleToFind == vehicle->GetVin()) {
			return in;
		} // ends if
	} // ends for
	return 1;
} // ends SearchForVehicle()

// Same as aove we obv should implement some kind of sorting & searching algo to make this roar.
Vehicle* Dealership::FindVehicle(const string& vehicleToFind) const {
	for(Vehicle* vehicle : vecVehicles) { 	
		if(vehicleToFind == vehicle->GetVin()) {
			return vehicle;
		} // ends if
	} // ends for
	return nullptr;
} // ends SearchForVehicle()

// Prints vehicle info, has some extra options if currentRole is owner (TODO add separate options for manager and salesman)
void Dealership::PrintVehicleInfo() const {
	string tmpMake, tmpModel, tmpColor;
	size_t choice = 0, index = 0;
	int tmpYear = 0;
	cout << "Vehicle Information:" << endl;
	for(const Vehicle* vehicle : vecVehicles) { 
		cout << "Vehicle #" << index + 1 << endl;
		cout << "Make: " << vehicle->GetMake() << endl;
		cout << "Model: " << vehicle->GetModel() << endl;
		cout << "Color: " << vehicle->GetColor() << endl;
		cout << "Days on lot: " << vehicle->GetDaysOnLot() << " days" << endl;
		cout << "Price: $" << vehicle->GetPrice() << endl;
		cout << "VIN number: " << vehicle->GetVin() << endl;

		if(index != vecVehicles.size() - 1) {
			cout << endl;
		} // ends if
		index++;
	} // ends for

// Checking current role for extra options
	if(currentRole == "owner") {
		char answer;
		cout << "Would you like to filter the results? (y/n)" << endl;
		cin >> answer;
		while(cin.fail() ||(answer != 'y' && answer != 'n')) {
			cerr << "Invalid input. Please enter y or n" << endl;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cin >> answer;
		} // ends if 

		if(answer == 'n') {
			return;
		} else {
			do { 
				cout << "How would you like to filter the results?" << endl;
				cout << "1) Days each vehicle has been on the lot." << endl;
				cout << "2) Price of each vehicle." << endl;
				cout << "3) Number of cars sold by make, model, year, color, or time on lot." << endl;
				cout << "4) Quit to previous menu." << endl;
				cin >> choice;
				while(cin.fail() || choice < 1 || choice > 4) {
					cerr << "Invalid input. Please enter a number between 1 and 3." << endl;
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cin >> choice;
				} // ends while
				size_t x = 0, counter = 0;
				switch(choice) {
					case 1:
						index = 0;
						for(const Vehicle* vehicle : vecVehicles) { 
							cout << "Vehicle VIN number: " << vehicle->GetVin() << endl;
							cout << "Is taking " << vehicle->GetDaysOnLot() << " days to sell." << endl;
							if(index != vecVehicles.size() - 1) {
								cout << endl;
							} // ends if
							index++;
						} // ends for
						break; // ends case 1 outer
					case 2:
						index = 0;
						for(const Vehicle* vehicle : vecVehicles) { 
							cout << "Vehicle VIN number: " << vehicle->GetVin() << endl;
							cout << "Is selling for $" << vehicle->GetPrice() << " dollars." << endl;
							if(index != vecVehicles.size() - 1) {
								cout << endl;
							} // ends if
							index++;
						} // ends for
						break; // ends case 2 outer
					case 3:
						do { 
							cout << "Choose an option to filter results by:" << endl;
							cout << "1) Make" << endl << "2) Model" << endl << "3) Year" << endl << "4) Color" << endl << "5) Time on lot" << endl << "6) Quit to previous menu" << endl;
							cin >> x;
							while(cin.fail() || x < 1 || x > 6) {
								cerr << "Invalid input. Please enter a number between 1 and 5." << endl;
								cin.clear();
								cin.ignore(numeric_limits<streamsize>::max(), '\n');
								cin >> x;
							} // ends while
							switch(x) {
								case 1:
									cout << "Which make do you want to search for?" << endl;
									cin >> tmpMake;
									while(cin.fail()) {
										cerr << "Invalid input. Please enter a number between 1 and 5." << endl;
										cin.clear();
										cin.ignore(numeric_limits<streamsize>::max(), '\n');
										cin >> tmpMake;
									} // ends while
									counter = 0;
									for(const Vehicle* vehicle : vecVehicles) { 
										if(vehicle->GetMake() == tmpMake) {
											counter++;
										} // ends if
									} // ends for
									if(counter != 1) { 
										cout << "There are " << counter << " cars with " << tmpMake << " make." << endl;
									} else {
										cout << "There is " << counter << " car with " << tmpMake << " make." << endl;
									} // ends if
									break; // ends case 1 inner
								case 2:
									cout << "Which model do you want to search for?" << endl;
									cin >> tmpModel;
									while(cin.fail()) {
										cerr << "Invalid input. Please enter a number between 1 and 5." << endl;
										cin.clear();
										cin.ignore(numeric_limits<streamsize>::max(), '\n');
										cin >> tmpModel;
									} // ends while
									counter = 0;
									for(const Vehicle* vehicle : vecVehicles) { 
										if(vehicle->GetModel() == tmpModel) {
											counter++;
										} // ends if
									} // ends for
									if(counter != 1) { 
										cout << "There are " << counter << " cars with " << tmpModel << " model." << endl;
									} else {
										cout << "There is " << counter << " car with " << tmpModel << " model." << endl;
									}
									break; // ends case 2 inner
								case 3:
									cout << "Which year do you want to search for?" << endl;
									cin >> tmpYear;
									while(cin.fail()) {
										cerr << "Invalid input. Please enter a number between 1 and 5." << endl;
										cin.clear();
										cin.ignore(numeric_limits<streamsize>::max(), '\n');
										cin >> tmpYear;
									} // ends while
									counter = 0;
									for(const Vehicle* vehicle : vecVehicles) { 
										if(vehicle->GetYear() == tmpYear) {
											counter++;
										} // ends if
									} // ends for
									cout << "There are " << counter << " cars from the year " << tmpYear << "." << endl;
									break; // ends case 3 inner
								case 4:
									cout << "Which color do you want to search for?" << endl;
									cin >> tmpColor;
									while(cin.fail()) {
										cerr << "Invalid input. Please enter a number between 1 and 5." << endl;
										cin.clear();
										cin.ignore(numeric_limits<streamsize>::max(), '\n');
										cin >> tmpColor;
									} // ends while
									counter = 0;
									for(const Vehicle* vehicle : vecVehicles) { 
										if(vehicle->GetColor() == tmpColor) {
											counter++;
										} // ends if
									} // ends for
									if(counter != 1) { 
										cout << "There are " << counter << " cars with " << tmpColor << " color." << endl;
									} else {
										cout << "There is " << counter << " car with " << tmpColor << " color." << endl;
									} // ends if
									break; // ends case 4 inner
								case 5:
									int timeOnLot;
									cout << "Enter the maximum time on lot(in days): " << endl;
									cin >> timeOnLot;
									while(cin.fail()) {
										cerr << "Invalid input. Please enter a number between 1 and 5." << endl;
										cin.clear();
										cin.ignore(numeric_limits<streamsize>::max(), '\n');
										cin >> timeOnLot;
									} // ends while
									counter = 0;
									for(const Vehicle* vehicle : vecVehicles) { 
										if(vehicle->GetDaysOnLot() <= timeOnLot) {
											counter++;
										} // ends if
									} // ends for
									if(counter != 1) {
										cout << "There are " << counter << " cars with time on lot less than or equal to " << timeOnLot << " days." << endl;
									} else {
										cout << "There is " << counter << " car with time on lot less than or equal to " << timeOnLot << " days." << endl;
									} // ends if
									break; // ends case 5 inner
								case 6:
									break; // ends case 6 inner
							} // ends inner switch
						} while(x != 6);
						break; // ends case 3 outer
					case 4:
						break;
				} // ends outer switch
			} while(choice != 4);
		} // ends if currentRole == "owner" if
	} // ends check if you want to filter
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

// SALES STUFF BELOW
void Dealership::AddSale(Vehicle* vehicle, Customer* customer, const string& sn, const double& sp, const double& sbd, const double& sbw, const double& sbm) {
	vecSales.emplace_back(new Sales(vehicle, customer, sn, sp, sbd, sbw, sbm));
} // ends AddSale()

void Dealership::AddSale(Sales* obj) {
	vecSales.emplace_back(obj);
} // ends AddSale()

// Prints all previous sales information
void Dealership::PrintSalesInfo() const {
	cout << endl << endl; // just creating space
	if(vecSales.size() <= 0) {
		cerr << "No sales to report." << endl;
	} else {
		cout << endl << "Sales Info:" << endl;
		size_t counter = 0;
		for(Sales* sale : vecSales) { 
			// Getting vehicle and customer obj so it can print their information with getters
			Vehicle* currVehicle = sale->GetVehicleObj();
			Customer* currCustomer = sale->GetCustomerObj();

			cout << "Customer Information: " << endl;
			if(currCustomer != nullptr) {
				PrintCustomerInfo(currCustomer);
			} else {
				cerr << "Customer information not available." << endl;
			} // ends if

			cout << endl << "Vehicle Information: " << endl;
			if(currVehicle != nullptr) {
				PrintVehicleInfo(currVehicle);
			} else {
				cerr << "Vehicle information not available." << endl;
			} // ends if

			cout << "Sales price: $" << sale->GetSalesPrice() << endl;
			cout << "Sales by day: " << sale->GetSalesByDay() << endl;
			cout << "Sales by week: " << sale->GetSalesByWeek() << endl;
			cout << "Sales by month: " << sale->GetSalesByMonth() << endl;
			cout << "Salesman: " << sale->GetSalesmanName() << endl;

			if(counter != vecSales.size() - 1) {
				cout << endl;
			} // ends if
			counter++;
		} // ends for
	} // ends if
} // ends PrintSalesInfo()

// TODO: FIX SALE STUFF
void Dealership::OpenFile() {
	// Making sure vectors are empty
	vecCustomers.clear();
	vecVehicles.clear();
	vecSales.clear();

	inputFile.open(customersFilename); // opening customers.txt
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
					AddVehicle(yearNew, makeOpen, modelOpen, colorOpen, daysOnLotNew, priceNew, vinOpen);
				} // ends if
			} // ends while
		} // ends if
	} // ends while
	inputFile.close(); // closing vehicles.txt

	inputFile.open(salesFilename); // opening sales.txt
	if(!inputFile.is_open()) {
		cerr << salesFilename << " unable to open!" << endl;
		return;
	} // ends if
	string salesmanName, salePriceStr, salesByDayStr, salesByWeekStr, salesByMonthStr, customerName, vehicleVin;
	while(getline(inputFile, line)) {
		if(line.find("Sale") != string::npos) {
			while(getline(inputFile, line) && !line.empty()) {
				if(line == "Salesman's Name:") { 
					getline(inputFile, salesmanName);
				} else if(line == "Sale Price:") { 
					getline(inputFile, salePriceStr);
				} else if(line == "Sales By Day:") { 
					getline(inputFile, salesByDayStr);
				} else if(line == "Sales By Week:") { 
					getline(inputFile, salesByWeekStr);
				} else if(line == "Sales By Month:") { 
					getline(inputFile, salesByMonthStr);
				} else if(line == "Customer") { 
					getline(inputFile, customerName);
				} else if(line == "Vehicle") { 
					getline(inputFile, vehicleVin);
				} // ends if
			} // ends while
			if(!salesmanName.empty() && !salePriceStr.empty() && !salesByDayStr.empty() && !salesByWeekStr.empty() && !salesByMonthStr.empty() && !customerName.empty() && !vehicleVin.empty()) {
				double salePrice = stod(salePriceStr);
				double salesByDay = stod(salesByDayStr);
				double salesByWeek = stod(salesByWeekStr);
				double salesByMonth = stod(salesByMonthStr);

				Customer* customer;
				customer = FindCustomer(customerName);
				Vehicle* vehicle;
				vehicle = FindVehicle(vehicleVin);
				if(customer != nullptr && vehicle != nullptr) {
					AddSale(vehicle, customer, salesmanName, salePrice, salesByDay, salesByWeek, salesByMonth);
				} else {
					cerr << "Skipping sale - Customer or vehicle not found." << endl;
				} // ends if
			} else {
				cerr << "Skipping sale - Incomplete sales data." << endl;
			} // ends else
		} // ends if
	} // ends while
	inputFile.close(); // closing sales.txt
} // ends OpenFile()


// FIXME
void Dealership::SaveToFile() {
	outputFile.open(customersFilename);
	if(!outputFile.is_open()) {
		cerr << customersFilename << " unable to open for writing!" << endl;
		return;
	} // ends if
	for(const Customer* curr: vecCustomers) {
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
	for(const Vehicle* curr: vecVehicles) {
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

	outputFile.open(salesFilename);
	if(!outputFile.is_open()) {
		cerr << salesFilename << " unable to open for writing!" << endl;
		return;
	} // ends if
	for(Sales* curr: vecSales) { // can't be const bc it modifies obj
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
	outputFile.close(); // close sale.txt
	cout << "SAVED" << endl;
} // ends SaveToFile();

// JUST A TMP METHOD FOR TESTING
int Dealership::BuyCar() {
	string name;
	string vname;
	cout << "You want to buy a car?, what is your name?" << endl;
	getline(cin, name);
	if(FindCustomerIndex(name) == -1) { 
		cerr << endl << endl << "You are not in the database!" << endl;
		cout << "bye, bye." << endl;
		return 1;
	} else { 
		Customer* currCustomer = vecCustomers.at(FindCustomerIndex(name));
		cout << "What car would you like to buy?(Type VIN number)" << endl;
		PrintVehicleInfo();
		getline(cin, vname);
		Vehicle* currVehicle = vecVehicles.at(FindVehicleIndex(vname));
		currCustomer->SetBoughtCar(true);
		Sales* currSale = new Sales(currVehicle, currCustomer, "Alex", 10.00, 2.32, 4.55, 500.39);
		vecSales.emplace_back(currSale);
	} // ends if
	return 0;
} // ends BuyCar()
