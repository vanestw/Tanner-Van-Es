#include "dealership.h"

Dealership::Dealership() {
	cout << "DEALERSHIP CONSTRUCTOR CALLED" << endl;
} // ends Dealership()

Dealership::~Dealership() {
	cout << "DEALERSHIP DESTRUCTOR CALLED" << endl;
	for (Customer* each : vecCustomers) {
            delete each;
	} // ends for 

	for (Vehicle* each : vecVehicles) {
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
	for(size_t i = 0; i < vecCustomers.size(); i++) { 
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
size_t Dealership::FindCurrentCustomer(const string& nameToFind) const {
	size_t index = 0;
	for(size_t i = 0; i < vecCustomers.size(); i++) { 
        if (nameToFind == vecCustomers.at(i)->GetName()) {
			index = i;
			return index;
        } // ends if
    } // ends for
	 return 1;
} // ends FindCurrentCustomer()

// int Dealership::FindCurrentCustomer(const string& nameToFind) const {
// 	size_t index;
// 	for(size_t i = 0; i < vecCustomers.size(); i++) { 
// 		cout << "Searching for " << nameToFind << "..." << endl;
//         if (nameToFind == vecCustomers.at(i)->GetName()) {
// 			cout << "FOUND " << nameToFind << endl;
// 			PrintCustomerInfo(vecCustomers.at(i));
// 			index = i;
//         } // ends if
//     } // ends for
// 	 return index;
// } // ends FindCurrentCustomer()

// Same as above... we obj need to implement sorting & searching algo!
size_t Dealership::SearchForVehicle(const string& vehicleToFind) const {
	size_t index = 0;
	for(size_t i = 0; i < vecVehicles.size(); i++) {
		if(vehicleToFind == vecVehicles.at(i)->GetVin()) {
			index = i;
			return index;
		} // ends if
	} // ends for
	  return 1;
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
	for(size_t i = 0; i < vecVehicles.size(); i++) { 
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
	}
} // ends PrintSalesInfo()

// JUST A TMP METHOD FOR TESTING
void Dealership::BuyCar() {
	string name;
	string vname;
	cout << "You want to buy a car?, what is your name?" << endl;
	getline(cin, name);
	Customer* currCustomer = vecCustomers.at(FindCurrentCustomer(name));
	if(FindCurrentCustomer(name) == 1) {
		cout << "You are not in the database, sorry!" << endl;
		cout << "bye, bye." << endl;
		return;
	} else { 
	cout << "What car would you like to buy? (Type VIN number)" << endl;
	PrintVehicleInfo();
	getline(cin, vname);
	Vehicle* currVehicle = vecVehicles.at(SearchForVehicle(vname));
	Sales* currSale = new Sales(currVehicle, currCustomer, "Alex", 10.00, 2.32, 4.55, 500.39);
	vecSales.emplace_back(currSale);
	}
} // ends BuyCar()
