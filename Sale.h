#include <iostream>
using namespace std;

class Sale{

  private:
  int salesByDay;
  int salesByWeek;
  int salesByMonth;

  public:
  void setSalesByDay(int daySales);
  void setSalesByWeek(int weekSales);
  void setSalesByMonth(int monthSales);
  void GenerateSales();

  

};// end Sale