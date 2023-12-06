#include <chrono>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "customer.h"
#include "saleInfo.h"
#include "vehicle.h"



int main() {
	vector<Vehicle> inventory;
	vector<Customer> customers;
	vector<SaleInfo> salesData;
	int year, daysOnLot, price;
	string name, make, model, color, vin, email, line, number;
	bool boughtCar, isinterested;

	



	ifstream inCarList;
	inCarList.open("carList.txt");
	if (!inCarList.is_open()) {
		cerr << "Couldn't open carList.txt." << endl;
		return 1;
	}//end of if

	while(getline(inCarList, line)) {
		inCarList >> year >> make >> model >> color >> daysOnLot >> price >> vin;
	ifstream inCustomerList;
	inCustomerList.open("customerList.txt");
	if (!inCustomerList.is_open()) {
		cerr << "Couldn't open customerList.txt." << endl;
		return 1;
	}//end of if

	while(getline(inCustomerList, line)){
		inCustomerList >> name >> email >> number >> boughtCar >> isinterested >> make >> model;
	}

	inCustomerList.close();

	ifstream inSaleInfo;
	inSaleInfo.open("salesInfo.txt");
	if(!inSaleInfo.is_open()) {
		cerr << "Couldn't open carList.txt." << endl;
		return 1;
	}//end of if
	while(getline(inSaleInfo, line)) {

	}
	while (!inCarList.eof()) {
		inCarList >> year >> make >> model >> color >> daysOnLot
			>> price >> vin;
		// TODO: write the constructor
		Vehicle car();
		inventory.push_back(car);


	}
		
}//end of main
