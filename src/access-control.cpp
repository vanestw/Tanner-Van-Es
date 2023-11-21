#include "access-control.h"

AccessControl::AccessControl() {
	userName = "NULL";
	userPassword = "NULL";
}

AccessControl::AccessControl(const string& user, const string& password) {
	userName = user;
	userPassword = password;
}

bool AccessControl::CheckLogin(const string& username, const string& password) {
    // Checking if provided credentials match any role
    auto it = roles.find(username);
    if(it != roles.end() && it->second == password) {
        // Set the current role based on the username
        role = it->first;
        return true;
    }
    return false;
}

string AccessControl::GetCurrentRole() const {
	return role;
}
