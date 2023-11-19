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
	string GetEmailAddress();
	void SetPhoneNumber(int phoneNumber);
	int GetPhoneNumber() const;
	void SetBoughtCar(bool boughtCar);
	bool GetBoughtCar() const;
	void SetInterestedVehicle(string interestedVehicle);
	string GetInterestedVehicle() const;
	void SetInterestedModel(string interestedModel);
	string GetInterestedModel();
	void PrintInfo();
	void FindInterestedCustomer();
	void FindCurrentCustomer();
	void PrintCustomer();
};
