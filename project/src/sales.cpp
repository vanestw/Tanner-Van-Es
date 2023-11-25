#include "sales.h"

Sales::Sales(const string& sn, const double& sp, const double& sbd, const double& sbw, const double& sbm) {
	salesmanName = sn;
	salePrice = sp;
	salesByDay = sbd,
	salesByWeek = sbw;
	salesByMonth = sbm;
} // ends paramaterized Sales()
  
Sales::Sales(Vehicle* vehicle, Customer* customer, const string& sn, const double& sp, const double& sbd, const double& sbw, const double& sbm) {
	tmpCust = customer;
	tmpVehic = vehicle;
	salesmanName = sn;
	salePrice = sp;
	salesByDay = sbd,
	salesByWeek = sbw;
	salesByMonth = sbm;
} // ends paramaterized Sales()

Sales::~Sales() {
	cout << "SALES DESTRUCTOR CALLED" << endl;
}

// SETTERS AND GETTERS

Customer* Sales::GetCustomerObj() {
	return tmpCust;
}

Vehicle* Sales::GetVehicleObj() {
	return tmpVehic;
}


void Sales::SetSalesPrice(const double& price) {
	this->salePrice = price;
}

double Sales::GetSalesPrice() const {
	return salePrice;
}

void Sales::SetSalesByDay(const double& sbd) {
	this->salesByDay = sbd;
}

double Sales::GetSalesByDay() const {
	return salesByDay;
}

void Sales::SetSalesByWeek(const double& sbw) {
	this->salesByWeek = sbw;
}

double Sales::GetSalesByWeek() const {
	return salesByWeek;
}

void Sales::SetSalesByMonth(const double& sbm) {
	this->salesByMonth = sbm;
}

double Sales::GetSalesByMonth() const {
	return salesByMonth;
}

void Sales::SetSalesmanName(const string& sn) {
	salesmanName = sn;
}

string Sales::GetSalesmanName() {
	return salesmanName;
}
