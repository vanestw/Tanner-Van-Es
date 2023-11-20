#include "vehicle.h"

Vehicle::Vehicle() {
	cout << "VEHICLE DEFAULT CONSTRUCTOR CALLED" << endl;
}

Vehicle::~Vehicle() {
	cout << "VEHICLE DESTRUCTOR CALLED" << endl;
}

Vehicle::Vehicle(const int& yearCon, const string& makeCon, const string& modelCon, const string& colorCon, const int& daysOnLotCon, const double& priceCon, const string& vinCon) {
	this->SetYear(yearCon);
	this->SetMake(makeCon);
	this->SetModel(modelCon);
	this->SetColor(colorCon);
	this->SetDaysOnLot(daysOnLotCon);
	this->SetPrice(priceCon);
	this->SetVin(vinCon);
}

// Setters and Getters
void Vehicle::SetYear(const int& yearSet) {
	this->year = yearSet;
}

int Vehicle::GetYear() {
	return year;
}

void Vehicle::SetMake(const string& makeSet) {
	this->make = makeSet;
}

string Vehicle::GetMake() {
	return make;
}

void Vehicle::SetModel(const string& modelSet) {
	this->model = modelSet;
}

string Vehicle::GetModel() {
	return model;
}

void Vehicle::SetColor(const string& colorSet) {
	this->color = colorSet;
}

string Vehicle::GetColor() {
	return color;
}

void Vehicle::SetDaysOnLot(const int& daysOnLotSet) {
	this->daysOnLot = daysOnLotSet;
}

int Vehicle::GetDaysOnLot() {
	return daysOnLot;
}

void Vehicle::SetPrice(const double& priceSet) {
	this->price = priceSet;
}

double Vehicle::GetPrice() {
	return price;
}

void Vehicle::SetVin(const string& vinSet) {
	this->vin = vinSet;
}

string Vehicle::GetVin() {
	return vin;
}
