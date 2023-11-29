#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Customer.h"
#include "SaleInfo.h"
#include "Vehicle.h"



int main() {
	vector<Vehicle> inventory;
	vector<Customer> customers;
	vector<SaleInfo> salesData;
	int year;
	string make;
	string model;
	string color;
	int daysOnLot;
	int price;
	string vin;
	



	ifstream inCarList;
	inCarList.open("carList.txt");
	if (!inCarList.is_open()) {
		cerr << "Couldn't open carList.txt." << endl;
		return 1;
	}//end of if

	ifstream inCustomerList;
	inCustomerList.open("customerList.txt");
	if (!inCustomerList.is_open()) {
		cerr << "Couldn't open customerList.txt." << endl;
		return 1;
	}//end of if

	while (!inCarList.eof()) {
		inCarList >> year >> make >> model >> color >> daysOnLot
			>> price >> vin;
		Vehicle car(year, make, model, color, daysOnLot, price, vin);
		inventory.push_back(car);
	}
		
}//end of main