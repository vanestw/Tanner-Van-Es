#include <iostream>
#include <string>
#pragma once
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
public:
	// Constructors and Destructor
	Customer(); 
	Customer(const string& n, const string& pn, const string& ea, bool interested, bool bought, const string& vi, const string& vmi);
	Customer(Customer* other);
	~Customer();

	// Setters and Getters
	void SetName(const string& n);
	string GetName() const;

	void SetSalesmanName(const string& sn);
	string GetSalesmanName() const;

	void SetEmailAddress(const string& ea);
	string GetEmailAddresss() const;

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
};
