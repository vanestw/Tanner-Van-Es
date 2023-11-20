#include <iostream>
#include <string>
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
	Vehicle();
	~Vehicle();
	Vehicle(const int& yearCon, const string& makeCon, const string& modelCon, const string& colorCon, const int& daysOnLotCon, const double& priceCon, const string& vinCon);
	void SetYear(const int& yearSet);
	int GetYear();
	void SetMake(const string& makeSet);
	string GetMake();
	void SetModel(const string& modelSet);
	string GetModel();
	void SetColor(const string& colorSet);
	string GetColor();
	void SetDaysOnLot(const int& daysOnLotSet);
	int GetDaysOnLot();
	void SetPrice(const double& priceSet);
	double GetPrice();
	void SetVin(const string& vinSet);
	string GetVin();
};
