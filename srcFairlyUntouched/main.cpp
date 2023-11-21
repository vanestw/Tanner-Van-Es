#include "customer.h"
#include <vector>

int main() {
	Customer customer1;
	Customer customer("Jane Doe", "555-555-5555", "Jane@doe.com");
	customer1.SetInfo();

	customer.PrintInfo();

	return 0;
}
