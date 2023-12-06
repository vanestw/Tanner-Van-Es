#include "vehicle.h"
#include <chrono>

// Default constructor (Eli)
Vehicle::Vehicle() {
	year = 0;
	make = "UNKNOWN";
	model = "UNKNOWN";
	color = "UNKNOWN";
	daysOnLot = 0;
	initialPrice = 0;
	vin = "UNKNOWN";
}

// Paramaterized contstructor (Eli)
Vehicle::Vehicle(int year, string make, string model, string color, int daysOnLot, int price, string vin) {
	this->year = year;
	this->make = make;
	this->model = model;
	this->color = color;
	this->daysOnLot = daysOnLot;
	this->initialPrice = price;
	this->vin = vin;
}

//Input: vector of vehicles
//Process: Gets the color, year, make, model, VIN, and Days on lot of the veichles in the vector.
//Output: Displays the information of the vehicles.
void Vehicle::printAllVehicleInfo(vector<Vehicle> vehicle) { 
	char answer;
	cout << "Vehicle Information:" << endl;
	for(size_t i = 0; i < vehicle.size(); i++) { 
		cout << "Vehicle #" << i + 1 << endl;
		cout << "Make: " << vehicle.at(i).getMake() << endl;
		cout << "Model: " << vehicle.at(i).getModel() << endl;
		cout << "Color: " << vehicle.at(i).getColor() << endl;
		cout << "Days on lot: " << vehicle.at(i).getDays() << " days" << endl;
		cout << "Price: $" << vehicle.at(i).getPrice() << endl;
		cout << "VIN number: " << vehicle.at(i).getVin() << endl;
		cout << endl;
	} // ends for
	cout << "Would you like to filter the results? (y/n)" << endl;
	cin >> answer;
	switch(answer) {
		case 'y':
			filterVehiclePrintResults(vehicle);
		break;
		case 'n':
			cerr << "FIXME" << endl;
		break;
	} // ends swtich

} // ends printVehicleInfo()

// Prints individual vehicle information (Eli)
void Vehicle::printVehicleInfo(Vehicle vehicle) { 
	cout << "Vehicle Information:" << endl;
		cout << "Make: " << vehicle.getMake() << endl;
		cout << "Model: " << vehicle.getModel() << endl;
		cout << "Color: " << vehicle.getColor() << endl;
		cout << "Days on lot: " << vehicle.getDays() << " days" << endl;
		cout << "Price: $" << vehicle.getPrice() << endl;
		cout << "VIN number: " << vehicle.getVin() << endl;
	}

// Filters vehicle info so you can view certain information (Eli)
void Vehicle::filterVehiclePrintResults(vector<Vehicle> vecVehicles) {
	int choice = 0, tmpYear = 0;
	string tmpMake, tmpModel, tmpColor;
		do {
			cout << "1) Days each vehicle has been on the lot." << endl;
			cout << "2) Price of each vehicle." << endl;
			cout << "3) Number of cars sold by make, model, year, color, or time on lot." << endl;
			cout << "4) Quit to previous menu." << endl;
			cin >> choice;
			while(cin.fail() || choice < 1 || choice > 4) {
				cerr << "Invalid input. Please enter a number between 1 and 3." << endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cin >> choice;
			} // ends while
			size_t x = 0, counter = 0, index = 0;
			switch(choice) {
				case 1:
					for(Vehicle vehicle : vecVehicles) {
						cout << "Vehicle VIN number: " << vehicle.getVin() << endl;
						cout << "Is taking " << vehicle.getDays() << " days to sell." << endl;
						if(index != vecVehicles.size() - 1) {
							cout << endl;
						} // ends if
						index++;
					} // ends for
					break; // ends case 1 outer
				case 2:
					index = 0;
					for(Vehicle vehicle : vecVehicles) {
						cout << "Vehicle VIN number: " << vehicle.getVin() << endl;
						cout << "Is selling for $" << vehicle.getPrice() << " dollars." << endl;
						if(index != vecVehicles.size() - 1) {
							cout << endl;
						} // ends if
						index++;
					} // ends for
					break; // ends case 2 outer
				case 3:
					do {
						cout << "Choose an option to filter results by:" << endl;
						cout << "1) Make" << endl << "2) Model" << endl << "3) Year" << endl << "4) Color" << endl << "5) Time on lot" << endl << "6) Quit to previous menu" << endl;
						cin >> x;
						while(cin.fail() || x < 1 || x > 6) {
							cerr << "Invalid input. Please enter a number between 1 and 5." << endl;
							cin.clear();
							cin.ignore(numeric_limits<streamsize>::max(), '\n');
							cin >> x;
						} // ends while
						char y;
						bool found = false;
						switch(x) {
							case 1:
								cout << "Which make do you want to search for?" << endl;
								cin >> tmpMake;
								while(cin.fail()) {
									cerr << "Invalid input. Please enter a number between 1 and 5." << endl;
									cin.clear();
									cin.ignore(numeric_limits<streamsize>::max(), '\n');
									cin >> tmpMake;
								} // ends while
								counter = 0;
								for(Vehicle vehicle : vecVehicles) {
									if(vehicle.getMake() == tmpMake) {
										found = true;
										counter++;
									} // ends if
								} // ends for
								  // if the option was not found
								while(!found) {
									cerr << "There is no vehicle of make: " << tmpMake << " on the lot." << endl;
									cerr << "Please enter another vehicle make:" << endl;
									cin.clear();
									cin.ignore(numeric_limits<streamsize>::max(), '\n');
									cin >> tmpMake;
									for(Vehicle vehicle : vecVehicles) {
										if(vehicle.getMake() == tmpMake) {
											found = true;
											counter++;
										} // ends if
									} // ends for
								} // ends not found while
								if(counter != 1) {
									cout << "There are " << counter << " cars with " << tmpMake << " make." << endl;
									cout << "Would you like to view them?(y/n)" << endl;
								} else {
									cout << "There is " << counter << " car with " << tmpMake << " make." << endl;
									cout << "Would you like to view it?(y/n)" << endl;
								}
								cin >> y;
								while(cin.fail() ||(y != 'y' && y != 'n')) {
									cin.clear();
									cin.ignore(numeric_limits<streamsize>::max(), '\n');
									cin >> y;
								} // ends while
								if(y == 'n') {
									continue;
								} else {
									for(Vehicle vehicle: vecVehicles) {
										if(vehicle.getMake() == tmpMake) {
											printVehicleInfo(vehicle);
										} // ends if
									} // ends for
								} // ends if
								break; // ends case 1 inner
							case 2:
								found = false;
								counter = 0;

								cout << "Which model do you want to search for?" << endl;
								cin >> tmpModel;
								while(cin.fail()) {
									cerr << "Invalid input. Please enter a number between 1 and 5." << endl;
									cin.clear();
									cin.ignore(numeric_limits<streamsize>::max(), '\n');
									cin >> tmpModel;
								} // ends while
								for(Vehicle vehicle : vecVehicles) {
									if(vehicle.getModel() == tmpModel) {
										found = true;
										counter++;
									} // ends if
								} // ends for
								while(!found) {
									cerr << "There is no vehicle of model: " << tmpModel << " on the lot." << endl;
									cerr << "Please enter another vehicle model:" << endl;
									cin.clear();
									cin.ignore(numeric_limits<streamsize>::max(), '\n');
									cin >> tmpMake;
									for(Vehicle vehicle : vecVehicles) {
										if(vehicle.getModel() == tmpModel) {
											found = true;
											counter++;
										} // ends if
									} // ends for
								} // ends not found while
								if(counter != 1) {
									cout << "There are " << counter << " cars with " << tmpModel << " model." << endl;
									cout << "Would you like to view them?(y/n)" << endl;
								} else {
									cout << "There is " << counter << " car with " << tmpModel << " model." << endl;
									cout << "Would you like to view it?(y/n)" << endl;
								}
								cin >> y;
								while(cin.fail() ||(y != 'y' && y != 'n')) {
									cin.clear();
									cin.ignore(numeric_limits<streamsize>::max(), '\n');
									cin >> y;
								} // ends while
								if(y == 'n') {
									return;
								} else {
									for(Vehicle vehicle: vecVehicles) {
										if(vehicle.getModel() == tmpModel) {
											printVehicleInfo(vehicle);
										} // ends if
									} // ends for
								} // ends if
								break; // ends case 2 inner
							case 3:
								found = false;
								counter = 0;
								cout << "Which year do you want to search for?" << endl;
								cin >> tmpYear;
								while(cin.fail()) {
									cerr << "Invalid input. Please enter a number between 1 and 5." << endl;
									cin.clear();
									cin.ignore(numeric_limits<streamsize>::max(), '\n');
									cin >> tmpYear;
								} // ends while
								for(Vehicle vehicle : vecVehicles) {
									if(vehicle.getYear() == tmpYear) {
										found = true;
										counter++;
									} // ends if
								} // ends for
								while(!found) {
									cerr << "There are no vehicles made in " << tmpYear << " on the lot." << endl;
									cerr << "Please enter another vehicle year:" << endl;
									cin.clear();
									cin.ignore(numeric_limits<streamsize>::max(), '\n');
									cin >> tmpYear;
									for(Vehicle vehicle : vecVehicles) {
										if(vehicle.getYear() == tmpYear) {
											found = true;
											counter++;
										} // ends if
									} // ends for
								} // ends not found while
								if(counter != 1) {
									cout << "There are " << counter << " cars from the year " << tmpYear << " on the lot." << endl;
									cout << "Would you like to veiw them?(y/n)" << endl;
								} else {
									cout << "There is " << counter << " car from the year " << tmpYear << " on the lot." << endl;
									cout << "Would you like to view it?(y/n)" << endl;
								} // ends if
								cin >> y;
								while(cin.fail() ||(y != 'y' && y != 'n')) {
									cin.clear();
									cin.ignore(numeric_limits<streamsize>::max(), '\n');
									cin >> y;
								} // ends while
								if(y == 'n') {
									return;
								} else {
									for(Vehicle vehicle: vecVehicles) {
										if(vehicle.getModel() == tmpModel) {
											printVehicleInfo(vehicle);
										} // ends if
									} // ends for
								} // ends if

								break; // ends case 3 inner
							case 4:
								found = false;
								counter = 0;
								cout << "Which color do you want to search for?" << endl;
								cin >> tmpColor;
								while(cin.fail()) {
									cerr << "Invalid input. Please enter a number between 1 and 5." << endl;
									cin.clear();
									cin.ignore(numeric_limits<streamsize>::max(), '\n');
									cin >> tmpColor;
								} // ends while
								for(Vehicle vehicle : vecVehicles) {
									if(vehicle.getColor() == tmpColor) {
										found = true;
										counter++;
									} // ends if
								} // ends for
								while(!found) {
									cerr << "There are no vehicles colored " << tmpColor << " on the lot." << endl;
									cerr << "Please enter another vehicle color:" << endl;
									cin.clear();
									cin.ignore(numeric_limits<streamsize>::max(), '\n');
									cin >> tmpColor;
									for(Vehicle vehicle : vecVehicles) {
										if(vehicle.getColor() == tmpColor) {
											found = true;
											counter++;
										} // ends if
									} // ends for
								} // ends not found while
								if(counter != 1) {
									cout << "There are " << counter << " cars with " << tmpColor << " color." << endl;
									cout << "Would you like to view them?(y/n)" << endl;
								} else {
									cout << "There is " << counter << " car with " << tmpColor << " color." << endl;
									cout << "Would you like to view it?(y/n)" << endl;
								} // ends if
								cin >> y;
								while(cin.fail() ||(y != 'y' && y != 'n')) {
									cin.clear();
									cin.ignore(numeric_limits<streamsize>::max(), '\n');
									cin >> y;
								} // ends while
								if(y == 'n') {
									return;
								} else {
									for(Vehicle vehicle: vecVehicles) {
										if(vehicle.getColor() == tmpColor) {
											printVehicleInfo(vehicle);
										} // ends if
									} // ends for
								} // ends if
								break; // ends case 4 inner
							case 5:
								found = false;
								counter = 0;
								int timeOnLot;
								cout << "Enter the maximum time on lot(in days): " << endl;
								cin >> timeOnLot;
								while(cin.fail()) {
									cerr << "Invalid input. Please enter a number between 1 and 5." << endl;
									cin.clear();
									cin.ignore(numeric_limits<streamsize>::max(), '\n');
									cin >> timeOnLot;
								} // ends while
								for(Vehicle vehicle : vecVehicles) {
									if(vehicle.getDays() <= timeOnLot) {
										found = true;
										counter++;
									} // ends if
								} // ends for
								while(!found) {
									cerr << "No vehicles have been on the lot " << timeOnLot << " days or shorter." << endl;
									cerr << "Please enter another length of time:" << endl;
									cin.clear();
									cin.ignore(numeric_limits<streamsize>::max(), '\n');
									cin >> timeOnLot;
									for(Vehicle vehicle : vecVehicles) {
										if(vehicle.getDays() == timeOnLot) {
											found = true;
											counter++;
										} // ends if
									} // ends for
								} // ends not found while
								if(counter != 1) {
									cout << "There are " << counter << " cars with time on lot less than or equal to " << timeOnLot << " days." << endl;
									cout << "Would you like to view them?(y/n)" << endl;
								} else {
									cout << "There is " << counter << " car with time on lot less than or equal to " << timeOnLot << " days." << endl;
									cout << "Would you like to view it?(y/n)" << endl;
								} // ends if
								while(cin.fail() ||(y != 'y' && y != 'n')) {
									cin.clear();
									cin.ignore(numeric_limits<streamsize>::max(), '\n');
									cin >> y;
								} // ends while
								if(y == 'n') {
									return;
								} else {
									for(Vehicle vehicle: vecVehicles) {
										if(vehicle.getDays() == timeOnLot) {
											printVehicleInfo(vehicle);
										} // ends if
									} // ends for
								} // ends if
								break; // ends case 5 inner
							case 6:
								break; // ends case 6 inner
						} // ends inner switch
					} while(x != 6); // ends inner do while
					break; // ends case 3 outer
				case 4:
					break; // ends case 4 outer
			} // ends outer switch
		} while(choice != 4); // ends outer do while
} // ends FilterVehiclePrintResults()

/* void Vehicle::SearchBy(vector<Vehicle> vehicleVector, string type, string parameter) {
    int ii = 0;
    for (ii; ii < type.size(); ii++) {
        tolower(type.at(ii));
    }//end for
    switch (type.at(2)) {
        case 'k'://make
            for (ii = 0; ii < vehicleVector.size(); ii++) {
                if (vehicleVector.at(ii).make == parameter) {
                    PrintVehicle(vehicleVector);
                }//end if
            }//end for
        break;
        case 'd'://model
            for (ii = 0; ii < vehicleVector.size(); ii++) {
                if (vehicleVector.at(ii).model == parameter) {
                    PrintVehicle(vehicleVector);
                }//end if
            }//end for
        break;
        case 'l'://color
            for (ii = 0; ii < vehicleVector.size(); ii++) {
                if (vehicleVector.at(ii).color == parameter) {
                    PrintVehicle(vehicleVector);
                }//end if
            }//end for
        break;
        case 'a'://year
            for (ii = 0; ii < vehicleVector.size(); ii++) {
                string yearAsString = to_string(vehicleVector.at(ii).year);
                if (yearAsString == parameter) {
                    PrintVehicle(vehicleVector);
                }//end if
            }//end for
        break;
        case 'y'://daysOnLot
            for (ii = 0; ii < vehicleVector.size(); ii++) {
                string daysAsString = to_string(vehicleVector.at(ii).daysOnLot);
                if (daysAsString == parameter) {
                    PrintVehicle(vehicleVector);
                }//end if
            }//end for
        break;
        default:
      }//end switch
}//end SearchBy */
void Vehicle::setYear(int userYear){
  year = userYear;
}
void Vehicle::setMake(string userMake){
  make = userMake;
}
void Vehicle::setModel(string userModel){
  model = userModel;
}
void Vehicle::setColor(string userColor){
  color = userColor;
}
void Vehicle::setDays(int userDays){
  daysOnLot = userDays;
}
void Vehicle::setPrice(int userPrice){
  initialPrice = userPrice;
}
void Vehicle::setVin(string userVin){
  vin = userVin;
}
int Vehicle::getPrice(){
  return initialPrice;
}
int Vehicle::getYear(){
  return year;
}
string Vehicle::getMake(){
  return make;
}
string Vehicle::getModel(){
  return model;
}
string Vehicle::getColor(){
  return color;
}
int Vehicle::getDays(){
  return daysOnLot;
}
string Vehicle::getVin(){
  return vin;
}

