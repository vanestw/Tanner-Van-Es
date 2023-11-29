#include "customer.h"

// Constructors and Destructor
Customer::Customer() {
	// cout << "CUSTOMER DEFAULT CONSTRUCTOR CALLED" << endl;
} // ends Customer()

Customer::Customer(const string& n, const string& pn, const string& ea, bool interested, bool bought, const string& vi, const string& vmi) {
	// cout << "CUSTOMER PARAMATERIZED CONSTRUCTOR CALLED" << endl;
	name = n;
	phoneNumber = pn;
	emailAddress = ea;
	isInterested = interested;
	boughtCar = bought;
	interestedVehicle = vi;
	interestedModel = vmi;
} // ends paramaterized Customer()

Customer::Customer(Customer* other) {
	name = other->name;
	phoneNumber = other->phoneNumber;
	emailAddress = other->emailAddress;
	isInterested = other->isInterested;
	boughtCar = other->boughtCar;
	interestedVehicle = other->interestedVehicle;
	interestedModel = other->interestedModel;
} // ends copy constructor

Customer::~Customer() {
	// cout << "CUSTOMER DESTRUCTOR CALLED" << endl;
} // ends ~Customer()

// TODO .h file
void Customer::PrintPotentialCustomerInfo(){

   for(int index = 0; index < vecCustomers.size(); index++){
      if(vecCustomers.at(index)->isInterested == true){
         cout << "Name: " << vecCustomers.at(index)->name << endl;
         cout << "Email: " << vecCustomers.at(index)->emailAddress << endl;
         cout << "Phone Number: " << vecCustomers.at(index)->phoneNumber << endl;
         cout << "Interested Vehicle: " << vecCustomers.at(index)->interestedVehicle << endl;
         cout << "Interested Model: " << vecCustomers.at(index)->interestedModel << endl << endl;
      }//end if
   }//end for

}//end PrintPotentialCustomerInfo()

void Customer::PrintCustomersWhoBoughtCar() const{
   int index;

   for(index = 0; index < vecCustomers.size(); index++){
      if(vecCustomers.at(index)->boughtCar == true){
         cout << vecCustomers.at(index)->name << endl;
         cout << vecCustomers.at(index)->emailAddress << endl;
         cout << vecCustomers.at(index)->phoneNumber << endl;
      }//end if
   }//end for

}//endprintcustomershwoboughtcar
