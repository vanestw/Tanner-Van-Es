#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Customer {
	string name;
	string salesmanName;
	string emailAddress;
	string phoneNumber;
	bool boughtCar;
	string interestedVehicle;
	string interestedModel;
	static vector<Customer> vecCustomers;
public:
	Customer();
	Customer(string n, string pn, string ea);
	Customer(const Customer& other);
	void SetInfo();
	void PrintInfo() const;
	void SetName(string n);
	string GetName() const;
	void SetSalesmanName(string sn);
	string GetSalesmanName() const;
	void SetEmailAddress(string ea);
	string GetEmailAddresss() const;
	void SetPhoneNumber(string pn);
	string GetPhoneNumber() const;
	void SetBoughtCar(bool bc);
	bool GetBoughtCar() const;
	void SetInterstedVehicle(string iv);
	string GetInterstedVehicle() const;
	void SetInterestedModel(string im);
	string GetInterestedModel() const;
	void FindInterestedCustomer() const;
	void FindCurrentCustomer() const;
};
