#include <iostream>
#include <string>
#pragma once
using namespace std;

class Vehicle {
	int year;
	string make;
	string model;
	string color;
	int daysOnLot;
	double price;
	string vin;
public:
// Constructors and Destructor
	Vehicle();
	Vehicle(const int& yearCon, const string& makeCon, const string& modelCon, const string& colorCon, const int& daysOnLotCon, const double& priceCon, const string& vinCon);
	Vehicle(Vehicle* other);
	~Vehicle();

// Setters and Getters
	void SetYear(const int& yearSet);
	int GetYear() const;

	void SetMake(const string& makeSet);
	string GetMake() const;

	void SetModel(const string& modelSet);
	string GetModel() const;

	void SetColor(const string& colorSet);
	string GetColor() const;

	void SetDaysOnLot(const int& daysOnLotSet);
	int GetDaysOnLot() const;

	void SetPrice(const double& priceSet);
	double GetPrice() const;

	void SetVin(const string& vinSet);
	string GetVin() const;
};
