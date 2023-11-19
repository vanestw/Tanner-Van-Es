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
<<<<<<< HEAD
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
=======
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
>>>>>>> f8c0f6e (Starting to work on methods. Added SetInfo and PrintInfo... only with very basic stuff to get it working first.)
};
