#include "access-control.h"

AccessControl::AccessControl() {
	cout << "ACCESSCONTROL DEFAULT CONSTRUCTOR CALLED" << endl;
	userName = "NULL";
	userPassword = "NULL";
}

AccessControl::AccessControl(const string& user, const string& password) {
	cout << "ACCESSCONTROL PARAMATERIZED CONSTRUCTOR CALLED" << endl;
	userName = user;
	userPassword = password;
}

bool AccessControl::CheckLogin(const string& username, const string& password) {
    // Checking if provided credentials match any role
    map<string, string>::iterator it = roles.find(username); // setting iterator 'it' to username
    if(it != roles.end() && it->second == password) { // checks if username and password combo match
        // Set the current role based on the username
        role = it->first;
        return true;
    }
    return false; // returns false if no match
}

// Returns current role
string AccessControl::GetCurrentRole() const {
	return role;
}
