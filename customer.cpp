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

void Customer::PrintPotentialCustomerInfo() const {
   for(size_t index = 0; index < vecCustomers.size(); index++){
      if(vecCustomers.at(index)->isInterested == true){
         cout << "Name: " << vecCustomers.at(index)->name << endl;
         cout << "Email: " << vecCustomers.at(index)->emailAddress << endl;
         cout << "Phone Number: " << vecCustomers.at(index)->phoneNumber << endl;
         cout << "Interested Vehicle: " << vecCustomers.at(index)->interestedVehicle << endl;
         cout << "Interested Model: " << vecCustomers.at(index)->interestedModel << endl << endl;
      }//end if
   }//end for

}//end PrintPotentialCustomerInfo()

// Written by: CM
int Customer::FindCustomerIndex(const string& nameToFind, const vector<Customer>& vecCustomers) const {
   int index;
   for (index = 0; index < vecCustomers.size(); ++index) {
      if (nameToFind == vecCustomers.at(index).name) {
         return index;
      } // End if
   } // End for
   cout << "Customer not found, no index returned" << endl;
   return -1; // If customer not found
} // End FindCustomerIndex()

void Customer::PrintCustomersWhoBoughtCar() const{
   for(size_t index = 0; index < vecCustomers.size(); index++){
      if(vecCustomers.at(index)->boughtCar == true){
         cout << vecCustomers.at(index)->name << endl;
         cout << vecCustomers.at(index)->emailAddress << endl;
         cout << vecCustomers.at(index)->phoneNumber << endl;
      }//end if
   }//end for

}//endprintcustomershwoboughtcar
void Customer::PrintCustomerInfo(Customer obj) const{
	cout << "Name: " << obj.name << endl;
	cout << "Email: " << obj.emailAddress << endl;
	cout << "Phone Number: " << obj.phoneNumber << endl;
	cout << "Interested Vehicle: " << obj.interestedVehicle << endl;
	cout << "Interested Model: " << obj.interestedModel << endl;

}// end PrintCustomerInfo CC/WW

string Customer::FindCustomer(const string& ntf, vector<Customer> vecCustomers) {  // Benicio and Christian
   string customerName;
   for(int i = 0;i < vecCustomers.size(); i++) {
      if(ntf == vecCustomers.at(i)) {
         customerName = vecCustomers.at(i);
         return customerName;
         } // end if
      }// end for
    }// end FindCustomer
