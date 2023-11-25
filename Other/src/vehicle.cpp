#include "vehicle.h"

// Constructors and Destructor
Vehicle::Vehicle() {
	cout << "VEHICLE DEFAULT CONSTRUCTOR CALLED" << endl;
} // ends Vehicle()

Vehicle::Vehicle(const int& yearCon, const string& makeCon, const string& modelCon, const string& colorCon, const int& daysOnLotCon, const double& priceCon, const string& vinCon) {
	year = yearCon;
	make = makeCon;
	model = modelCon;
	color = colorCon;
	daysOnLot = daysOnLotCon;
	price = priceCon;
	vin = vinCon;
} // ends paramaterized Vehicle()

Vehicle::Vehicle(Vehicle* other) {
	year = other->year;
	make = other->make;
	model = other->model;
	color = other->color;
	daysOnLot = other->daysOnLot;
	price = other->price;
	vin = other->vin;
}

Vehicle::~Vehicle() {
	cout << "VEHICLE DESTRUCTOR CALLED" << endl;
} // ends ~Vehicle()

// ALL SETTERS AND GETTERS
void Vehicle::SetYear(const int& yearSet) {
	this->year = yearSet;
}

int Vehicle::GetYear() const {
	return year;
}

void Vehicle::SetMake(const string& makeSet) {
	this->make = makeSet;
}

string Vehicle::GetMake() const {
	return make;
}

void Vehicle::SetModel(const string& modelSet) {
	this->model = modelSet;
}

string Vehicle::GetModel() const {
	return model;
}

void Vehicle::SetColor(const string& colorSet) {
	this->color = colorSet;
}

string Vehicle::GetColor() const {
	return color;
}

void Vehicle::SetDaysOnLot(const int& daysOnLotSet) {
	this->daysOnLot = daysOnLotSet;
}

int Vehicle::GetDaysOnLot() const {
	return daysOnLot;
}

void Vehicle::SetPrice(const double& priceSet) {
	this->price = priceSet;
}

double Vehicle::GetPrice() const {
	return price;
}

void Vehicle::SetVin(const string& vinSet) {
	this->vin = vinSet;
}

string Vehicle::GetVin() const {
	return vin;
}
