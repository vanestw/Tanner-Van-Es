#pragma once
#include <iostream>
using namespace std;

class Vehicle{

  private:
    int year;
    string make;
    string model;
    string color;
    int daysOnLot;
    int initialPrice;
    string vin;


  public:
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
    void SearchBy(string type,/*make, model, color, year, daysOnLot*/ string parameter/*input to compare*/);
    void PrintVehicle();
};// end vehicle
#endif // VEHICLE_H
