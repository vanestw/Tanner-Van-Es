#pragma once
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Vehicle {
  private:
    int year;
    string make;
    string model;
    string color;
    int daysOnLot;
    int initialPrice;
    string vin;

  public:
	Vehicle();
	Vehicle(int year, string make, string model, string color, int daysOnLot, int price, string vin);
    void setYear(int userYear);
    void setMake(string userMake);
    void setModel(string userModel);
    void setColor(string userColor);
    void setDays(int userDays);
    void setPrice(int userPrice);
    void setVin(string userVin);
    int getPrice();
    int getYear();
    int getDays();
    string getMake();
    string getModel();
    string getColor();
    string getVin();
	void printAllVehicleInfo(vector<Vehicle> vehicle);
	void printVehicleInfo(Vehicle vehicle);
	void filterVehiclePrintResults(vector<Vehicle> vecVehicles);
    // void SearchBy(string type,/*make, model, color, year, daysOnLot*/ string parameter/*input to compare*/);
}; // end vehicle
