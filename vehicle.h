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
    void setMake(int userMake);
    void setModel(int userModel);
    void setColor(int userColor);
    void setDays(int userDys);
    void setPrice(int userPrice);
    void setVin(int userVin);
    void PrintVehicle();
    void SearchBy(string searchType, string searchParameter);
    
    
  
  
};// end vehicle
