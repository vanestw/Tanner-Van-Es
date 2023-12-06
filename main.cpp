#include <chrono>
#include <iostream>
#include <fstream>
#include <string>
#include "customer.h"
#include "saleInfo.h"
#include "vehicle.h"

int main() {
	int year, daysOnLot, price;
	string name, make, model, color, vin, email, line, number;
	bool boughtCar, isInterested;
	ifstream inputFile;
	vector<Vehicle> inventory;
	vector<Customer> customers;
	vector<SaleInfo> salesData;
	Vehicle vehicle;


	inputFile.open("carList.txt");
	if(!inputFile.is_open()) {
		cerr << "Couldn't open carList.txt." << endl;
		return 1;
	}//end of if

	while(getline(inputFile, line)) {
		inputFile >> year >> make >> model >> color >> daysOnLot >> price >> vin;
		Vehicle newVehicle(year, make, model, color, daysOnLot, price, vin);
		inventory.emplace_back(newVehicle);
	}
	vehicle.printAllVehicleInfo(inventory);
	inputFile.close();

	inputFile.open("customerList.txt");
	if(!inputFile.is_open()) {
		cerr << "Couldn't open customerList.txt." << endl;
		return 1;
	}//end of if

	while(getline(inputFile, line)){
		inputFile >> name >> email >> number >> boughtCar >> isInterested >> make >> model;
		Customer newCustomer(name, number, email, isInterested, boughtCar, make, model);
		customers.emplace_back(newCustomer);
	}
	inputFile.close(); // close customer file

	// TODO: MAKE SALEINFO FILE
	inputFile.open("salesInfo.txt");
	if(!inputFile.is_open()) {
		cerr << "Couldn't open salesInfo.txt." << endl;
		return 1;
	}//end of if
	while(getline(inputFile, line)) {

	}

}//end of main
