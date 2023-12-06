#pragma once
#include <iostream>
using namespace std;

class SaleInfo{

  private:
  int salesByDay;
  int salesByWeek;
  int salesByMonth;

  public:
  void setSalesByDay(int daySales);
  void setSalesByWeek(int weekSales);
  void setSalesByMonth(int monthSales);
  void PrintWeekBySales();
  void PrintMonthBySales();

};// end Sale
