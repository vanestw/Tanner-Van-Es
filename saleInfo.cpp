#include <iostream>
#include "saleInfo.h"

//Author : Cesar and Ian
//Input  : Input daySales.
//Process: Sets salesByDay equal to daySales
//Output : returns void
void SaleInfo::setSalesByDay(int daySales) {
	salesByDay = daySales;
}

//Author : Cesar and Ian
//Input  : Input weekSales.
//Process: Sets salesByWeek equal to weekSales
//Output : returns void
void SaleInfo::setSalesByWeek(int weekSales){
	salesByWeek = weekSales;
}

void SaleInfo::printDayBySales() {
	cout << "Here are the sales for the day: " << salesByDay << endl;
}//end PrintDaySales

// ***** Ethan and Gabe *****
void SaleInfo::printWeekBySales() {
    cout << "Sales for this week: " << salesByWeek << endl;
}//end PrintWeekBySales

void SaleInfo::printMonthBySales() {
    cout << "Sales for this month: " << salesByMonth << endl;
}//end PrintMonthBySales
// ***** Ethan and Gabe *****
