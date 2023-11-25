#include <iostream>
#include "vehicle.h"
#include "customer.h"
#pragma once
using namespace std;

class Sales {
	double salePrice;
	double salesByDay;
	double salesByWeek;
	double salesByMonth;
	string salesmanName;
	Customer* tmpCust = new Customer();
	Vehicle* tmpVehic = new Vehicle();
public:
// CONSTRUCTORS AND DESTRUCTOR
	Sales();
	Sales(const string& sn, const double& sp, const double& sbd, const double& sbw, const double& sbm);
	Sales(Vehicle* vehicle, Customer* customer, const string& sn, const double& sp, const double& sbd, const double& sbw, const double& sbm);
	~Sales();

// SETTERS AND GETTERS

	Customer* GetCustomerObj();
	Vehicle* GetVehicleObj();

	void SetSalesPrice(const double& price);
	double GetSalesPrice() const;

	void SetSalesByDay(const double& sbd);
	double GetSalesByDay() const;

	void SetSalesByWeek(const double& sbw);
	double GetSalesByWeek() const;

	void SetSalesByMonth(const double& sbm);
	double GetSalesByMonth() const;

	void SetSalesmanName(const string& sn);
	string GetSalesmanName();

// NEED TO WRITE
	void PrintDaySales() const;
	void PrintWeekSales() const;
	void PrintMonthSales() const;
};


