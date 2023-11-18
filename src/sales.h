#include "vehicle.h"

class SaleInfo {
	double salePrice;
	double salesByDay;
	double salesByWeek;
	double salesByMonth;
public:
	void SetSalesPrice(double salePrice);
	double GetSalesPrice();
	void SetSalesByDay(double salesByWeek);
	double GetSalesByDay();
	void SetSalesByWeek(double salesByWeek);
	double GetSalesByWeek();
	void SetSalesByMonth(double salesByMonth);
	double GetSalesByMonth();
	void PrintDaySales();
	void PrintWeekSales();
	void PrintMonthSales();
};
