#include "Vehicle.h"

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

  
