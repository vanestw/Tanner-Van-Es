#include "dealership.h"
#include <vector>

int main() {
	Dealership dealership;
	Customer* customer = new Customer("Eli", "555-555-5555", "eli@eli.com", true, false, "Ford", "Fiesta");

	dealership.AddCustomer(customer);
	dealership.AddCustomer("Zara", "420-6969-CUTIE", "zara@zara.com", true, false, "Cat Mobile", "Cuteness");

	cout << "Customer info: " << endl;
    dealership.PrintCustomerInfo();
	
	cout << endl;
	cout << "Finding Eli: " << endl;
    dealership.FindCurrentCustomer("Eli");

	cout << endl;

	dealership.AddVehicle(2003, "Subaru", "Forester", "Black", 123, 23000, "ABC123456789XYZ");
	dealership.PrintVehicleInfo();

	cout << endl;
	cout << "Finding vehicle by VIN #" << endl;
	dealership.SearchForVehicle("ABC123456789XYZ");

	return 0;
}
