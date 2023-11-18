#include <iostream>
#include <string>
using namespace std;

class Vehicle {
	int year;
	string make;
	string model;
	string color;
	int daysOnLot;
	int price;
	string vin;
public:
	void SetYear(int year);
	int GetYear();
	void SetMake(string make);
	string GetMake();
	void SetModel(string model);
	string GetModel();
	void SetColor(string color);
	string GetColor();
	void SetDaysOnLot(int daysOnLot);
	int GetDaysOnLot();
	void SetPrice(int price);
	int GetPrice();
	void SetVin(string vin);
	string GetVin();
};
