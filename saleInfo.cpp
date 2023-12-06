#include <iostream>
#include "saleInfo.h"
using namespace std;

void SaleInfo::PrintMonthSales() {
	cout << salesByMonth << endl;
}

void printDaySales() {
	setSalesByDay(int daySales);
	cout << "Here are the sales for the day: " << salesByDay << endl;
}
void printWeekBySales(int salesByWeek) {

cout << "Sales for this week: " << salesByWeek << endl;

}

//Author : Cesar and Ian
//Input  : Input daySales.
//Process: Sets salesByDay equal to daySales
//Output : returns void
void setSalesByDay(int daySales) {
	salesByDay = daySales;
}

//Author : Cesar and Ian
//Input  : Input weekSales.
//Process: Sets salesByWeek equal to weekSales
//Output : returns void
void setSalesByWeek(int weekSales){
	salesByWeek = weekSales;
}
