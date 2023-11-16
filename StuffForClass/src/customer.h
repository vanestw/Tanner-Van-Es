#include "sales.h"

class Customer {
	string name;
	string salesmanName;
	string emailAddress;
	int phoneNumbers;
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
	void SetPhoneNumber(int phoneNumbers);
	int GetPhoneNumber();
	void SetBoughtCar(bool boughtCar);
	bool GetBoughtCar();
	void SetnterstedVehicle(string interestedVehicle);
	string GetInterstedVehicle();
	void SetInterestedModel(string interestedModel);
	string GetInterestedModel();
	void PrintInfo();
	void FindInterestedCustomer();
	void FindCurrentCustomer();
	void PrintCustomer();
};
