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
	bool isInterested;
	string interestedVehicle;
	string interestedModel;
	// static vector<Customer> vecCustomers;
public:
	Customer();
	Customer(string n, string pn, string ea, bool interested);
	Customer(const Customer& other);
	vector<Customer>& GetVector() const;
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

	void SetIsInterested(bool interested);
	bool GetIsInterested();
};
