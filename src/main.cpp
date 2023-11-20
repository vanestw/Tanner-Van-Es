#include "customer.h"
#include <vector>

int main() {
	Customer* customer = new Customer("Eli", "555-555-5555", "eli@eli.com", true, false, "Ford", "Fiesta");
	customer->SetInfo();

	customer->FindCurrentCustomer("Eli");

	customer->PrintInfo();

	delete customer;

	return 0;
}
