#include "customer.h"
#include <vector>

int main() {
	Customer* customer1 = new Customer();
	Customer* customer = new Customer("Eli", "555-555-5555", "eli@eli.com");
	customer1->SetInfo();

	customer->PrintInfo();

	return 0;
}
