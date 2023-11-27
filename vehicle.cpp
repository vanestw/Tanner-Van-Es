#include "vehicle.h"

//Input: vector of vehicles
//Process: Gets the color, year, make, model, VIN, and Days on lot of the veichles in the vector.
//Output: Displays the information of the vehicles.
void PrintVehicle(vector<vehicle> vehicleList) {
	for (int count = 0; count < vehicleList.size(); count++) {
		cout << "Vehicle: " << vehicleList[count].color << " " << vehicleList[count].year << " " << vehicleList[count].make << " " << vehicleList[count].model << endl;
		cout << "V.I.N: " << vehicleList[count].vin << "\nDays on Lot: " << vehicleList[count].daysOnLot;
	}
}
