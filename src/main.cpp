#include "customer.h"
#include <vector>

int main() {
	// Instantiating customer with paramaterized constructor
	// Customer* customer = new Customer("John Doe", "303-555-5555", "johndoe@email.com", true, false, "Subaru", "Outback");
	Customer* customer = new Customer("John Doe", "303-555-5555", "johndoe@email.com", true, false, "Subaru", "Outback");

	// Adding customer to vector
	customer->AddCustomer(customer);

	// Instantiating customer and using setters to assign values
	Customer* customer1 = new Customer();
	customer1->SetName("Jane Doe");
	customer1->SetEmailAddress("janedoe@email.com");
	customer1->SetPhoneNumber("555-555-5555");
	customer1->SetBoughtCar(true);
	customer1->SetIsInterested(false);
	customer1->SetInterstedVehicle("Ford");
	customer1->SetInterestedModel("Explorer");

	// Adding customer1 to vector started by customer to the vector
	customer->AddCustomer(customer1);

	// Using AddCustomer method which uses paramaterized constructor to instatiate object and then push it into vector
	customer->AddCustomer("Ryan Smith", "123-456-7890", "ryan@email.com", true, false, "Jeep", "Wrangler");

	// Printing list of customers
	customer->PrintEntirCustomerVector();

	cout << endl;

	// Printing list of potential customers
	customer->PrintPotentialCustomerInfo();

	// Printing list of customers who have bought a car
	customer->PrintCustomersWhoBoughtCar();

	// Deleting customer objects
	delete customer;
	delete customer1;

	return 0;
}
