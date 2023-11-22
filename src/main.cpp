#include "dealership.h"

int main() {
	try { 
	Dealership dealership;
	dealership.MainMenu();
	dealership.OpenFile();
	} catch(const exception& e) {
		cout << e.what() << endl;
		return 0;
	} // ends try-catch block
	return 0;
} // ends main()

// SOME CODE TO TEST IF YOU SO PLEASE:
// Customer* customer = new Customer("Eli", "555-555-5555", "eli@eli.com", true, false, "Ford", "Fiesta");
	// Vehicle* vehicle = new Vehicle(2023, "Rolls-Royce", "Phantom", "White", 30, 500000, "RR456789XYZ123");
	// dealership.AddCustomer(customer);
	// dealership.AddCustomer("Zara", "303-3333-CUTIE", "zara@zara.com", true, false, "Cat Mobile", "Cuteness");
	// cout << "Customer info: " << endl;
    // dealership.PrintCustomerInfo();
	// cout << endl;
    // dealership.FindCurrentCustomer("Zara");
	// cout << endl;
	// dealership.AddVehicle(2003, "Subaru", "Forester", "Black", 123, 23000, "ABC123456789XYZ");
	// dealership.AddVehicle(vehicle);
	// cout << "Vehicle info: " << endl;
	// dealership.PrintVehicleInfo();
	// cout << endl;
	// cout << "Finding vehicle by VIN #" << endl;
	// dealership.SearchForVehicle("ABC123456789XYZ");
	// cout << "===============================================================================================================" << endl;
	// dealership.BuyCar();
	// dealership.PrintSalesInfo();
	

	// dealership.PrintSalesInfo();
	// if(dealership.Login()) { 
	// 	dealership.OpenFile();
	// 	// dealership.PrintCustomerInfo();
	// 	// cout << endl;
	// 	dealership.PrintVehicleInfo();
	// 	// dealership.BuyCar();
	// 	// dealership.PrintPotentialCustomerInfo();
	// 	// dealership.SaveToFile();
	// } else {
	// 	cerr << "Invalid login." << endl;
	// }

