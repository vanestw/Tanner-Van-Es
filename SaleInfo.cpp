#include <iostream>
#include "SaleInfo.h"
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
