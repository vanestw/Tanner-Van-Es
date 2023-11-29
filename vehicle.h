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
    void SearchBy(string type,/*make, model, color, year, daysOnLot*/ string parameter/*input to compare*/)
    void PrintVehicle();
    void SearchBy(string searchType, string searchParameter);
    
    
  
  
};// end vehicle
