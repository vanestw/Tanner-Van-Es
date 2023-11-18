#include <iostream>
#include <string>
using namespace std;

class Customer {
	string name;
	string salesmanName;
	string emailAddress;
	int phoneNumber;
	bool boughtCar;
	string interestedVehicle;
	string interestedModel;
public:
	void SetName(string name);
	string GetName();
	void SetSalesmanName(string salesmanName);
	string GetSalesmanName();
	void SetEmailAddress(string emailAddress);
	string GetEmailAddresss();
	void SetPhoneNumber(int phoneNumber);
	int GetPhoneNumber();
	void SetBoughtCar(bool boughtCar);
	bool GetBoughtCar();
	void SetInterstedVehicle(string interestedVehicle);
	string GetInterstedVehicle();
	void SetInterestedModel(string interestedModel);
	string GetInterestedModel();
	void PrintInfo();
	void FindInterestedCustomer();
	void FindCurrentCustomer();
	void PrintCustomer();
};
