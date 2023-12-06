#include "vehicle.h"
#include <string>
using namespace std;

//Input: vector of vehicles
//Process: Gets the color, year, make, model, VIN, and Days on lot of the veichles in the vector.
//Output: Displays the information of the vehicles.
void PrintVehicle(vector<vehicle> vehicleList) {
	for (int count = 0; count < vehicleList.size(); count++) {
		cout << "Vehicle: " << vehicleList[count].color << " " << vehicleList[count].year << " "
             << vehicleList[count].make << " " << vehicleList[count].model << endl;
		cout << "V.I.N: " << vehicleList[count].vin << "\nDays on Lot: " << vehicleList[count].daysOnLot;
	}//end for
}//end PrintVehicle

void Vehicle::SearchBy(vector<Vehicle> vehicleVector(), string type, string parameter) {
    int ii = 0;
    for (ii; ii < type.size(); ii++) {
        tolower(type.at(ii));
    }//end for
    switch (type.at(2)) {
        case 'k'://make
            for (ii = 0; ii < vehicleVector.size(); ii++) {
                if (vehicleVector.at(ii).make == parameter) {
                    PrintVehicle(vehicleVector);
                }//end if
            }//end for
        break;
        case 'd'://model
            for (ii = 0; ii < vehicleVector.size(); ii++) {
                if (vehicleVector.at(ii).model == parameter) {
                    PrintVehicle(vehicleVector);
                }//end if
            }//end for
        break;
        case 'l'://color
            for (ii = 0; ii < vehicleVector.size(); ii++) {
                if (vehicleVector.at(ii).color == parameter) {
                    PrintVehicle(vehicleVector);
                }//end if
            }//end for
        break;
        case 'a'://year
            for (ii = 0; ii < vehicleVector.size(); ii++) {
                string yearAsString = to_string(vehicleVector.at(ii).year);
                if (yearAsString == parameter) {
                    PrintVehicle(vehicleVector);
                }//end if
            }//end for
        break;
        case 'y'://daysOnLot
            for (ii = 0; ii < vehicleVector.size(); ii++) {
                string daysAsString = to_string(vehicleVector.at(ii).daysOnLot);
                if (daysAsString == parameter) {
                    PrintVehicle(vehicleVector);
                }//end if
            }//end for
        break;
        default:
      }//end switch
}//end SearchBy
void Vehicle::setYear(int userYear){
  year = userYear;
}
void Vehicle::setMake(string userMake){
  make = userMake;
}
void Vehicle::setModel(string userModel){
  model = userModel;
}
void Vehicle::setColor(string userColor){
  color = userColor;
}
void Vehicle::setDays(int userDays){
  daysOnLot = userDays;
}
void Vehicle::setPrice(int userPrice){
  initialPrice = userPrice;
}
void Vehicle::setVin(string userVin){
  vin = userVin;
}
int Vehicle::getPrice(){
  return initialPrice;
}
int Vehicle::getYear(){
  return year;
}
string Vehicle::getMake(){
  return make;
}
string Vehicle::getModel(){
  return model;
}
string Vehicle::getColor(){
  return color;
}
int Vehicle::getDays(){
  return daysOnLot;
}
string Vehicle::getVin(){
  return vin;
}

