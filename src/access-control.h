#include <iostream>
#include <string>
#include <map>
#pragma once
using namespace std;

class AccessControl {
	string role;
	string userName;
	string userPassword;
	// Map for roles and corresponding password -- obv the worst possible implementation for security, but just learning and making it more of a mock program than anything.
    map<string, string> roles{ {"owner", "ownerPass"}, {"manager", "managerPass"}, {"salesman", "salesmanPass"} };
public:
	AccessControl();
	AccessControl(const string& user, const string& password);
	bool Login();
	bool CheckLogin(const string& userName, const string& password);
	string GetCurrentRole() const;
};
