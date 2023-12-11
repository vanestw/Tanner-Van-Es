#pragma once
#include <iostream>
#include <string>
#include <vector>
#pragma once
using namespace std;

// TODO: implement actual searching algorithms
class Customer {
	string name;
	string emailAddress;
	string phoneNumber;
	bool boughtCar;
	bool isInterested;
	string interestedVehicle;
	string interestedModel;
	vector<Customer*> vecCustomers;
public:
	// Constructors and Destructor
	Customer();
	Customer(const string& n, const string& pn, const string& ea, bool interested, bool bought, const string& vi, const string& vmi);

	// Methods
	void PrintCustomerInfo(Customer obj) const;
	void PrintEntirCustomerVector();
	void PrintPotentialCustomerInfo() const;
	void PrintCustomersWhoBoughtCar() const;
	// int FindCustomerIndex(const string& nameToFind) const;
	// string FindCustomer(const string& ntf, vector<Customer> vecCustomers); // Benicio and Christian
	Customer FindCustomer(const string& nameToFind) const;
	int FindCustomerIndex(const string& nameToFind, const vector<Customer>& vecCustomers) const; // Edited by CM, add vector parameter

	// Setters and Getters
	void SetName(const string& n);
	string GetName() const;

	void SetEmailAddress(const string& ea);
	string GetEmailAddress() const;

	void SetPhoneNumber(const string& pn);
	string GetPhoneNumber() const;

	void SetBoughtCar(bool bc);
	bool GetBoughtCar() const;

	void SetInterstedVehicle(const string& iv);
	string GetInterstedVehicle() const;

	void SetInterestedModel(const string& im);
	string GetInterestedModel() const;

	void SetIsInterested(bool interested);
	bool GetIsInterested() const;
}; // ends Customer
