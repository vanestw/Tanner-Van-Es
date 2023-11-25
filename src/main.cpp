File: [1maccess-control.cpp[0m
[35m#include[0m [32m"[0m[32maccess-control.h[0m[32m"[0m

AccessControl::[34mAccessControl[0m() {
    cout [35m<<[0m [32m"[0m[32mACCESSCONTROL DEFAULT CONSTRUCTOR CALLED[0m[32m"[0m [35m<<[0m endl;
    userName [35m=[0m [32m"[0m[32mNULL[0m[32m"[0m;
    userPassword [35m=[0m [32m"[0m[32mNULL[0m[32m"[0m;
}

AccessControl::[34mAccessControl[0m([35mconst[0m string[35m&[0m user, [35mconst[0m string[35m&[0m password) {
    cout [35m<<[0m [32m"[0m[32mACCESSCONTROL PARAMATERIZED CONSTRUCTOR CALLED[0m[32m"[0m [35m<<[0m endl;
    userName [35m=[0m user;
    userPassword [35m=[0m password;
}

[35mbool[0m AccessControl::[34mCheckLogin[0m([35mconst[0m string[35m&[0m username, [35mconst[0m string[35m&[0m password) {
    [32m//[0m[32m Checking if provided credentials match any role[0m
    map<string, string>::iterator it [35m=[0m roles.find(username); [32m//[0m[32m setting iterator 'it' to username[0m
    [35mif[0m(it [35m!=[0m roles.end() [35m&&[0m it->second [35m==[0m password) { [32m//[0m[32m checks if username and password combo match[0m
        [32m//[0m[32m Set the current role based on the username[0m
        role [35m=[0m it->first;
        [35mreturn[0m [33mtrue[0m;
    }
    [35mreturn[0m [33mfalse[0m; [32m//[0m[32m returns false if no match[0m
}

[32m//[0m[32m Returns current role[0m
string AccessControl::[34mGetCurrentRole[0m() [35mconst[0m {
    [35mreturn[0m role;
}

File: [1mcustomer.cpp[0m
[35m#include[0m [32m"[0m[32mcustomer.h[0m[32m"[0m

[32m//[0m[32m Constructors and Destructor[0m
Customer::[34mCustomer[0m() {
    cout [35m<<[0m [32m"[0m[32mCUSTOMER DEFAULT CONSTRUCTOR CALLED[0m[32m"[0m [35m<<[0m endl;
} [32m//[0m[32m ends Customer()[0m

Customer::[34mCustomer[0m([35mconst[0m string[35m&[0m n, [35mconst[0m string[35m&[0m pn, [35mconst[0m string[35m&[0m ea, [35mbool[0m interested, [35mbool[0m bought, [35mconst[0m string[35m&[0m vi, [35mconst[0m string[35m&[0m vmi) {
    cout [35m<<[0m [32m"[0m[32mCUSTOMER PARAMATERIZED CONSTRUCTOR CALLED[0m[32m"[0m [35m<<[0m endl;
    name [35m=[0m n;
    phoneNumber [35m=[0m pn;
    emailAddress [35m=[0m ea;
    isInterested [35m=[0m interested;
    boughtCar [35m=[0m bought;
    interestedVehicle [35m=[0m vi;
    interestedModel [35m=[0m vmi;
} [32m//[0m[32m ends paramaterized Customer()[0m

Customer::[34mCustomer[0m(Customer[35m*[0m other) {
    name [35m=[0m other->name;
    phoneNumber [35m=[0m other->phoneNumber;
    emailAddress [35m=[0m other->emailAddress;
    isInterested [35m=[0m other->isInterested;
    boughtCar [35m=[0m other->boughtCar;
    interestedVehicle [35m=[0m other->interestedVehicle;
    interestedModel [35m=[0m other->interestedModel;
}

Customer::[34m~Customer[0m() {
    cout [35m<<[0m [32m"[0m[32mCUSTOMER DESTRUCTOR CALLED[0m[32m"[0m [35m<<[0m endl;
} [32m//[0m[32m ends ~Customer()[0m

[32m//[0m[32m ALL SETTERS AND GETTERS [0m
[35mvoid[0m Customer::[34mSetIsInterested[0m([35mbool[0m interested) {
    this->isInterested [35m=[0m interested;    
}

[35mbool[0m Customer::[34mGetIsInterested[0m() [35mconst[0m {
    [35mreturn[0m isInterested;
}

[35mvoid[0m Customer::[34mSetName[0m([35mconst[0m string[35m&[0m n) { 
    this->name [35m=[0m n;
}

string Customer::[34mGetName[0m() [35mconst[0m {
    [35mreturn[0m name;
}

[35mvoid[0m Customer::[34mSetSalesmanName[0m([35mconst[0m string[35m&[0m sn) {
    this->salesmanName [35m=[0m sn;
}

string Customer::[34mGetSalesmanName[0m() [35mconst[0m {
    [35mreturn[0m salesmanName;
}

[35mvoid[0m Customer::[34mSetEmailAddress[0m([35mconst[0m string[35m&[0m ea) {
    this->emailAddress [35m=[0m ea;
}

string Customer::[34mGetEmailAddresss[0m() [35mconst[0m {
    [35mreturn[0m emailAddress;
}

[35mvoid[0m Customer::[34mSetPhoneNumber[0m([35mconst[0m string[35m&[0m pn) {
    this->phoneNumber [35m=[0m pn;
}

string Customer::[34mGetPhoneNumber[0m() [35mconst[0m {
    [35mreturn[0m phoneNumber;
}

[35mvoid[0m Customer::[34mSetBoughtCar[0m([35mbool[0m bc) {
    this->boughtCar [35m=[0m bc;
}

[35mbool[0m Customer::[34mGetBoughtCar[0m() [35mconst[0m {
    [35mreturn[0m boughtCar;
}

[35mvoid[0m Customer::[34mSetInterstedVehicle[0m([35mconst[0m string[35m&[0m iv) {
    this->interestedVehicle [35m=[0m iv;
}

string Customer::[34mGetInterstedVehicle[0m() [35mconst[0m{
    [35mreturn[0m interestedVehicle;
}

[35mvoid[0m Customer::[34mSetInterestedModel[0m([35mconst[0m string[35m&[0m im) {
    this->interestedModel [35m=[0m im;
}

string Customer::[34mGetInterestedModel[0m() [35mconst[0m {
    [35mreturn[0m interestedModel;
}

File: [1mdealership.cpp[0m
[35m#include[0m [32m"[0m[32mdealership.h[0m[32m"[0m
[35m#include[0m [32m<[0m[32miomanip[0m[32m>[0m [32m//[0m[32m for isstringstream[0m
[35m#include[0m [32m<[0m[32mlimits[0m[32m>[0m [32m//[0m[32m for numeric_limits[0m

string Dealership::currentRole [35m=[0m [32m"[0m[32mNULL[0m[32m"[0m; [32m//[0m[32m initialization needed for static variable[0m

Dealership::[34mDealership[0m() {
    cout [35m<<[0m [32m"[0m[32mDEALERSHIP CONSTRUCTOR CALLED[0m[32m"[0m [35m<<[0m endl;
} [32m//[0m[32m ends Dealership()[0m

[32m//[0m[32m Destructor deletes each object in all vectors[0m
Dealership::[34m~Dealership[0m() {
    cout [35m<<[0m [32m"[0m[32mDEALERSHIP DESTRUCTOR CALLED[0m[32m"[0m [35m<<[0m endl;
    [35mfor[0m(Customer[35m*[0m each [35m:[0m vecCustomers) {
        [35mdelete[0m each;
    } [32m//[0m[32m ends for [0m

    [35mfor[0m(Vehicle[35m*[0m each [35m:[0m vecVehicles) {
        [35mdelete[0m each;
    } [32m//[0m[32m ends for[0m

    [35mfor[0m(Sales[35m*[0m each [35m:[0m vecSales) {
        [35mdelete[0m each;
    } [32m//[0m[32m ends for[0m
} [32m//[0m[32m ends ~Dealership()[0m

[35mbool[0m Dealership::[34mLogin[0m() {
    string username, password;
    cout [35m<<[0m [32m"[0m[32mEnter username: [0m[32m"[0m;
    getline(cin, username);
    cout [35m<<[0m [32m"[0m[32mEnter password: [0m[32m"[0m;
    getline(cin, password);

    [32m//[0m[32m Checking login credentials[0m
    [35mif[0m(accessControl.CheckLogin(username, password)) {
        cout [35m<<[0m [32m"[0m[32mLogin successful![0m[32m"[0m [35m<<[0m endl;
        [32m//[0m[32m Assign currentRole from AccessControl class using AccessControls getter method[0m
        currentRole [35m=[0m accessControl.GetCurrentRole();
        [35mreturn[0m [33mtrue[0m;
    } [35melse[0m {
        cerr [35m<<[0m [32m"[0m[32mInvalid username or password. Login failed.[0m[32m"[0m [35m<<[0m endl;
        [35mreturn[0m [33mfalse[0m;
    } [32m//[0m[32m ends if[0m
} [32m//[0m[32m ends Login()[0m

[35mint[0m Dealership::[34mMainMenu[0m() {
    [35mint[0m choice [35m=[0m [33m0[0m, x [35m=[0m [33m0[0m;
    [35mdo[0m {
        cout [35m<<[0m [32m"[0m[32mHello, what would you like to do?[0m[32m"[0m [35m<<[0m endl;
        cout [35m<<[0m [32m"[0m[32m1) Login[0m[32m"[0m [35m<<[0m endl;
        cout [35m<<[0m [32m"[0m[32m2) Create account[0m[32m"[0m [35m<<[0m endl;
        cout [35m<<[0m [32m"[0m[32m3) Quit[0m[32m"[0m [35m<<[0m endl;
        cout [35m<<[0m [32m"[0m[32m~> [0m[32m"[0m;
        cin [35m>>[0m choice;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), [32m'[0m[36m\n[0m[32m'[0m);
        [35mwhile[0m(cin.fail()) {
            cerr [35m<<[0m [32m"[0m[32mInvalid input. Please enter a number between 1 and 3.[0m[32m"[0m [35m<<[0m endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), [32m'[0m[36m\n[0m[32m'[0m);
            cout [35m<<[0m [32m"[0m[32m~> [0m[32m"[0m;
            cin [35m>>[0m choice;
        } [32m//[0m[32m ends while[0m

        [35mswitch[0m(choice) {
            [35mcase[0m [33m1[0m:
                [35mif[0m(this->Login()) {
                    OpenFile();
                    [35mif[0m(currentRole [35m==[0m [32m"[0m[32mowner[0m[32m"[0m) {
                        [35mdo[0m {
                            cout [35m<<[0m [32m"[0m[32mWelcome, please choose which option you would like to do.[0m[32m"[0m [35m<<[0m endl;
                            cout [35m<<[0m [32m"[0m[32m1) View a list of customers.[0m[32m"[0m [35m<<[0m endl;
                            cout [35m<<[0m [32m"[0m[32m2) View a list of potential customers.[0m[32m"[0m [35m<<[0m endl;
                            cout [35m<<[0m [32m"[0m[32m3) View a list of vehicles being sold.[0m[32m"[0m [35m<<[0m endl;
                            cout [35m<<[0m [32m"[0m[32m4) View a list of all previous sales.[0m[32m"[0m [35m<<[0m endl;
                            cout [35m<<[0m [32m"[0m[32m5) Quit to main menu.[0m[32m"[0m [35m<<[0m endl;
                            cout [35m<<[0m [32m"[0m[32m~> [0m[32m"[0m;
                            cin [35m>>[0m x;

                            [35mwhile[0m(cin.fail() [35m||[0m x < [33m1[0m [35m||[0m x > [33m5[0m) {
                                cerr [35m<<[0m [32m"[0m[32mInvalid input. Please enter a number between 1 and 4.[0m[32m"[0m [35m<<[0m endl;
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), [32m'[0m[36m\n[0m[32m'[0m);
                                cout [35m<<[0m [32m"[0m[32m~> [0m[32m"[0m;
                                cin [35m>>[0m x;
                            } [32m//[0m[32m ends while[0m

                            [35mswitch[0m(x) {
                                [35mcase[0m [33m1[0m:
                                    PrintEntirCustomerVector();
                                    [35mbreak[0m;
                                [35mcase[0m [33m2[0m:
                                    PrintPotentialCustomerInfo();
                                    [35mbreak[0m;
                                [35mcase[0m [33m3[0m:
                                    PrintVehicleInfo();
                                    [35mbreak[0m;
                                [35mcase[0m [33m4[0m:
                                    PrintEntireSalesVector();
                                    [35mbreak[0m;
                                [35mcase[0m [33m5[0m:
                                    [35mbreak[0m; [32m//[0m[32m Exit to return to main menu[0m
                                [35mdefault[0m:
                                    cerr [35m<<[0m [32m"[0m[32mInvalid input. Please enter a number between 1 and 4.[0m[32m"[0m [35m<<[0m endl;
                            } [32m//[0m[32m ends switch[0m
                        } [35mwhile[0m(x [35m!=[0m [33m5[0m);
                    } [32m//[0m[32m ends if currentRole == owner[0m
                    [35mif[0m(currentRole [35m==[0m [32m"[0m[32mmanager[0m[32m"[0m) {
                        [35mdo[0m {
                            cout [35m<<[0m [32m"[0m[32mWelcome, please choose which option you would like to do.[0m[32m"[0m [35m<<[0m endl;
                            cout [35m<<[0m [32m"[0m[32m1) View a list of vehicles.[0m[32m"[0m [35m<<[0m endl;
                            cout [35m<<[0m [32m"[0m[32m2) Quit to main menu.[0m[32m"[0m [35m<<[0m endl;
                            cout [35m<<[0m [32m"[0m[32m~> [0m[32m"[0m;
                            cin [35m>>[0m x;

                            [35mwhile[0m(cin.fail() [35m||[0m x < [33m1[0m [35m||[0m x > [33m5[0m) {
                                cerr [35m<<[0m [32m"[0m[32mInvalid input. Please enter a number between 1 and 4.[0m[32m"[0m [35m<<[0m endl;
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), [32m'[0m[36m\n[0m[32m'[0m);
                                cout [35m<<[0m [32m"[0m[32m~> [0m[32m"[0m;
                                cin [35m>>[0m x;
                            } [32m//[0m[32m ends while[0m

                            [35mswitch[0m(x) {
                                [35mcase[0m [33m1[0m:
                                    PrintVehicleInfo();
                                    [35mbreak[0m;
                                [35mcase[0m [33m2[0m:
                                    [35mbreak[0m;
                                [35mdefault[0m:
                                    cerr [35m<<[0m [32m"[0m[32mInvalid input. Please enter a number bewteen 1 and 2[0m[32m"[0m [35m<<[0m endl;
                            } [32m//[0m[32m ends swtich[0m
                        } [35mwhile[0m(x [35m!=[0m [33m2[0m);
                    } [32m//[0m[32m ends if currentRole == manager[0m
                } [32m//[0m[32m ends if this->Login()[0m
                [35mbreak[0m; [32m//[0m[32m ends case 1[0m
            [35mcase[0m [33m2[0m:
                cerr [35m<<[0m [32m"[0m[32mNEED TO WRITE THIS METHOD[0m[32m"[0m [35m<<[0m endl;
                [35mbreak[0m;
            [35mcase[0m [33m3[0m:
                [35mthrow[0m runtime_error([32m"[0m[32mGoodbye![0m[32m"[0m);
                [35mbreak[0m; [32m//[0m[32m Exits the loop and closes the program[0m
            [35mdefault[0m:
                cerr [35m<<[0m [32m"[0m[32mInvalid input. Please enter a number between 1 and 3.[0m[32m"[0m [35m<<[0m endl;
        } [32m//[0m[32m ends switch[0m
    } [35mwhile[0m(choice [35m!=[0m [33m3[0m);

    [35mreturn[0m [33m0[0m;
} [32m//[0m[32m ends MainMenu()[0m

[32m//[0m[32m CUSTOMER STUFF BELOW[0m
[32m//[0m[32m Creates and adds customer to vector[0m
[35mvoid[0m Dealership::[34mAddCustomer[0m([35mconst[0m string[35m&[0m name, [35mconst[0m string[35m&[0m phoneNumber, [35mconst[0m string[35m&[0m emailAddress, [35mbool[0m interested, [35mbool[0m bought, [35mconst[0m string[35m&[0m interestedVehicle, [35mconst[0m string[35m&[0m interestedModel) {
    vecCustomers.emplace_back([35mnew[0m Customer(name, phoneNumber, emailAddress, interested, bought, interestedVehicle, interestedModel));
} [32m//[0m[32m ends AddCustomer()[0m

[32m//[0m[32m Adds customer to vector if customer obj is passed in[0m
[35mvoid[0m Dealership::[34mAddCustomer[0m(Customer[35m*[0m obj) {
    vecCustomers.emplace_back(obj);
} [32m//[0m[32m ends AddCustomer()[0m

[32m//[0m[32m Prints customer info..[0m
[35mvoid[0m Dealership::[34mPrintEntirCustomerVector[0m() [35mconst[0m {
    cout [35m<<[0m [32m"[0m[32mCustomer Information:[0m[32m"[0m [35m<<[0m endl;
    size_t customerIndex [35m=[0m [33m0[0m;
    [35mfor[0m([35mconst[0m Customer[35m*[0m customer [35m:[0m vecCustomers) {
        cout [35m<<[0m [32m"[0m[32mCustomer #[0m[32m"[0m [35m<<[0m customerIndex [35m+[0m [33m1[0m [35m<<[0m endl;
        cout [35m<<[0m [32m"[0m[32mName: [0m[32m"[0m [35m<<[0m customer->GetName() [35m<<[0m endl;
        cout [35m<<[0m [32m"[0m[32mPhone number: [0m[32m"[0m [35m<<[0m customer->GetPhoneNumber() [35m<<[0m endl;
        cout [35m<<[0m [32m"[0m[32mEmail address: [0m[32m"[0m [35m<<[0m customer->GetEmailAddresss() [35m<<[0m endl;
        cout [35m<<[0m [32m"[0m[32mIs interested: [0m[32m"[0m [35m<<[0m boolalpha [35m<<[0m customer->GetIsInterested() [35m<<[0m  endl;
        cout [35m<<[0m [32m"[0m[32mBought car: [0m[32m"[0m [35m<<[0m boolalpha [35m<<[0m customer->GetBoughtCar() [35m<<[0m endl;
        cout [35m<<[0m [32m"[0m[32mVehicle interested in: [0m[32m"[0m [35m<<[0m customer->GetInterstedVehicle() [35m<<[0m endl;
        cout [35m<<[0m [32m"[0m[32mVehicle model interested in: [0m[32m"[0m [35m<<[0m customer->GetInterestedModel() [35m<<[0m endl;
        [35mif[0m(customerIndex [35m!=[0m vecCustomers.size() [35m-[0m [33m1[0m) {
            cout [35m<<[0m endl;
        } [32m//[0m[32m ends if[0m
        customerIndex[35m++[0m;
    } [32m//[0m[32m ends for[0m
} [32m//[0m[32m ends PrintCustomerInfo()[0m

[32m//[0m[32m Overloaded so you can also pass customer object into it[0m
[35mvoid[0m Dealership::[34mPrintCustomerInfo[0m(Customer[35m*[0m obj) [35mconst[0m {
    cout [35m<<[0m [32m"[0m[32mName: [0m[32m"[0m [35m<<[0m obj->GetName() [35m<<[0m endl;
    cout [35m<<[0m [32m"[0m[32mPhone number: [0m[32m"[0m [35m<<[0m obj->GetPhoneNumber() [35m<<[0m endl;
    cout [35m<<[0m [32m"[0m[32mEmail address: [0m[32m"[0m [35m<<[0m obj->GetEmailAddresss() [35m<<[0m endl;
    cout [35m<<[0m [32m"[0m[32mIs interested: [0m[32m"[0m [35m<<[0m boolalpha [35m<<[0m obj->GetIsInterested() [35m<<[0m  endl;
    cout [35m<<[0m [32m"[0m[32mBought car: [0m[32m"[0m [35m<<[0m boolalpha [35m<<[0m obj->GetBoughtCar() [35m<<[0m endl;
    cout [35m<<[0m [32m"[0m[32mVehicle interested in: [0m[32m"[0m [35m<<[0m obj->GetInterstedVehicle() [35m<<[0m endl;
    cout [35m<<[0m [32m"[0m[32mVehicle model interested in: [0m[32m"[0m [35m<<[0m obj->GetInterestedModel() [35m<<[0m endl;
} [32m//[0m[32m ends PrintCustomerInfo()[0m

[32m//[0m[32m Prints customer info..[0m
[35mvoid[0m Dealership::[34mPrintPotentialCustomerInfo[0m() [35mconst[0m {
    [35mif[0m(currentRole [35m==[0m [32m"[0m[32mowner[0m[32m"[0m) { 
        cout [35m<<[0m [32m"[0m[32mPotential Customer Information:[0m[32m"[0m [35m<<[0m endl;
        size_t customerIndex [35m=[0m [33m0[0m;
        [35mfor[0m([35mconst[0m Customer[35m*[0m customer [35m:[0m vecCustomers) {
            [35mif[0m(customer->GetIsInterested()) {
                cout [35m<<[0m [32m"[0m[32mCustomer #[0m[32m"[0m [35m<<[0m customerIndex [35m<<[0m endl;
                cout [35m<<[0m [32m"[0m[32mName: [0m[32m"[0m [35m<<[0m customer->GetName() [35m<<[0m endl;
                cout [35m<<[0m [32m"[0m[32mPhone number: [0m[32m"[0m [35m<<[0m customer->GetPhoneNumber() [35m<<[0m endl;
                cout [35m<<[0m [32m"[0m[32mEmail address: [0m[32m"[0m [35m<<[0m customer->GetEmailAddresss() [35m<<[0m endl;
                cout [35m<<[0m [32m"[0m[32mIs interested: [0m[32m"[0m [35m<<[0m boolalpha [35m<<[0m customer->GetIsInterested() [35m<<[0m  endl;
                cout [35m<<[0m [32m"[0m[32mBought car: [0m[32m"[0m [35m<<[0m boolalpha [35m<<[0m customer->GetBoughtCar() [35m<<[0m endl;
                cout [35m<<[0m [32m"[0m[32mVehicle interested in: [0m[32m"[0m [35m<<[0m customer->GetInterstedVehicle() [35m<<[0m endl;
                cout [35m<<[0m [32m"[0m[32mVehicle model interested in: [0m[32m"[0m [35m<<[0m customer->GetInterestedModel() [35m<<[0m endl;
            } [32m//[0m[32m ends if[0m
            [35mif[0m(customerIndex [35m!=[0m vecCustomers.size() [35m-[0m [33m1[0m) {
                cout [35m<<[0m endl;
            } [32m//[0m[32m ends if[0m
            customerIndex[35m++[0m;
        } [32m//[0m[32m ends for[0m
    } [35melse[0m {
        cerr [35m<<[0m [32m"[0m[32mYou do not have the correct permissions to view potential customer information.[0m[32m"[0m [35m<<[0m endl;
    } [32m//[0m[32m ends if[0m
} [32m//[0m[32m ends PrintCustomerInfo()[0m

[32m//[0m[32m More like -- iterates throught vector to find name. We obv should implement some kind of sorting & searching algo to make this roar.[0m
[35mint[0m Dealership::[34mFindCustomerIndex[0m([35mconst[0m string[35m&[0m nameToFind) [35mconst[0m {
    [35mint[0m i [35m=[0m [33m0[0m;
    [35mfor[0m([35mconst[0m Customer[35m*[0m customer [35m:[0m vecCustomers) {  
        [35mif[0m(nameToFind [35m==[0m customer->GetName()) {
            [35mreturn[0m i;
        } [32m//[0m[32m ends if[0m
        i[35m++[0m;
    } [32m//[0m[32m ends for[0m
    [35mreturn[0m [35m-[0m[33m1[0m;
} [32m//[0m[32m ends FindCurrentCustomer()[0m

[32m//[0m[32m Finds the customer you pass to it and prints out their information We obv should implement some kind of sorting & searching algo to make this roar.[0m
Customer[35m*[0m Dealership::[34mFindCustomer[0m([35mconst[0m string[35m&[0m nameToFind) [35mconst[0m {
    [35mfor[0m(Customer[35m*[0m customer [35m:[0m vecCustomers) {    
        [35mif[0m(nameToFind [35m==[0m customer->GetName()) {
            [35mreturn[0m customer;
        } [32m//[0m[32m ends if[0m
    } [32m//[0m[32m ends for[0m
    [35mreturn[0m [33mnullptr[0m;
} [32m//[0m[32m ends FindCurrentCustomer()[0m

[32m//[0m[32m VEHICLE STUFF BELOW[0m
[32m//[0m[32m This method is the same as the AddCustomer above[0m
[35mvoid[0m Dealership::[34mAddVehicle[0m([35mconst[0m [35mint[0m[35m&[0m yearAdd, [35mconst[0m string[35m&[0m makeAdd, [35mconst[0m string[35m&[0m modelAdd, [35mconst[0m string[35m&[0m colorAdd, [35mconst[0m [35mint[0m[35m&[0m daysOnLotAdd, [35mconst[0m [35mdouble[0m[35m&[0m priceAdd, [35mconst[0m string[35m&[0m vinAdd) {
    vecVehicles.emplace_back([35mnew[0m Vehicle(yearAdd, makeAdd, modelAdd, colorAdd, daysOnLotAdd, priceAdd, vinAdd));
} [32m//[0m[32m ends AddVehicle()[0m

[32m//[0m[32m Works same as AddCustomer above [0m
[35mvoid[0m Dealership::[34mAddVehicle[0m(Vehicle[35m*[0m obj) {
    vecVehicles.emplace_back(obj);
} [32m//[0m[32m ends AddVehicle()[0m

[32m//[0m[32m Same as cusotmer one above... we obj need to implement sorting & searching algo![0m
[35mint[0m Dealership::[34mFindVehicleIndex[0m([35mconst[0m string[35m&[0m vehicleToFind) [35mconst[0m {
    [35mint[0m in [35m=[0m [33m0[0m;
    [35mfor[0m([35mconst[0m Vehicle[35m*[0m vehicle [35m:[0m vecVehicles) {     
        [35mif[0m(vehicleToFind [35m==[0m vehicle->GetVin()) {
            [35mreturn[0m in;
        } [32m//[0m[32m ends if[0m
    } [32m//[0m[32m ends for[0m
    [35mreturn[0m [33m1[0m;
} [32m//[0m[32m ends SearchForVehicle()[0m

[32m//[0m[32m Same as aove we obv should implement some kind of sorting & searching algo to make this roar.[0m
Vehicle[35m*[0m Dealership::[34mFindVehicleObj[0m([35mconst[0m string[35m&[0m vehicleToFind) [35mconst[0m {
    [35mfor[0m(Vehicle[35m*[0m vehicle [35m:[0m vecVehicles) {   
        [35mif[0m(vehicleToFind [35m==[0m vehicle->GetVin()) {
            [35mreturn[0m vehicle;
        } [32m//[0m[32m ends if[0m
    } [32m//[0m[32m ends for[0m
    [35mreturn[0m [33mnullptr[0m;
} [32m//[0m[32m ends SearchForVehicle()[0m

[32m//[0m[32m Prints vehicle info, has some extra options if currentRole is owner (TODO add separate options for manager and salesman)[0m
[35mvoid[0m Dealership::[34mPrintVehicleInfo[0m() [35mconst[0m {
    size_t index [35m=[0m [33m0[0m;
    cout [35m<<[0m [32m"[0m[32mVehicle Information:[0m[32m"[0m [35m<<[0m endl;
    [35mfor[0m([35mconst[0m Vehicle[35m*[0m vehicle [35m:[0m vecVehicles) { 
        cout [35m<<[0m [32m"[0m[32mVehicle #[0m[32m"[0m [35m<<[0m index [35m+[0m [33m1[0m [35m<<[0m endl;
        cout [35m<<[0m [32m"[0m[32mMake: [0m[32m"[0m [35m<<[0m vehicle->GetMake() [35m<<[0m endl;
        cout [35m<<[0m [32m"[0m[32mModel: [0m[32m"[0m [35m<<[0m vehicle->GetModel() [35m<<[0m endl;
        cout [35m<<[0m [32m"[0m[32mColor: [0m[32m"[0m [35m<<[0m vehicle->GetColor() [35m<<[0m endl;
        cout [35m<<[0m [32m"[0m[32mDays on lot: [0m[32m"[0m [35m<<[0m vehicle->GetDaysOnLot() [35m<<[0m [32m"[0m[32m days[0m[32m"[0m [35m<<[0m endl;
        cout [35m<<[0m [32m"[0m[32mPrice: $[0m[32m"[0m [35m<<[0m vehicle->GetPrice() [35m<<[0m endl;
        cout [35m<<[0m [32m"[0m[32mVIN number: [0m[32m"[0m [35m<<[0m vehicle->GetVin() [35m<<[0m endl;

        [35mif[0m(index [35m!=[0m vecVehicles.size() [35m-[0m [33m1[0m) {
            cout [35m<<[0m endl;
        } [32m//[0m[32m ends if[0m
        index[35m++[0m;
    } [32m//[0m[32m ends for[0m
      [32m//[0m[32m Checking current role for extra options[0m
    [35mchar[0m answer;
    cout [35m<<[0m [32m"[0m[32mWould you like to filter the results? (y/n)[0m[32m"[0m [35m<<[0m endl;
    cout [35m<<[0m [32m"[0m[32m~> [0m[32m"[0m;
    cin [35m>>[0m answer;
    [35mwhile[0m(cin.fail() [35m||[0m(answer [35m!=[0m [32m'[0m[32my[0m[32m'[0m [35m&&[0m answer [35m!=[0m [32m'[0m[32mn[0m[32m'[0m)) {
        cerr [35m<<[0m [32m"[0m[32mInvalid input. Please enter y or n[0m[32m"[0m [35m<<[0m endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), [32m'[0m[36m\n[0m[32m'[0m);
        cin [35m>>[0m answer;
    } [32m//[0m[32m ends if [0m
    [35mif[0m(answer [35m==[0m [32m'[0m[32mn[0m[32m'[0m) {
        [35mreturn[0m;
    } [35melse[0m {
        FilterVehiclePrintResults(currentRole);
    } [32m//[0m[32m ends if[0m
}  [32m//[0m[32m ends PrintVehicleInfo()[0m

[32m//[0m[32m Method to allow user to filter what they see when they view vehicle information[0m
[35mvoid[0m Dealership::[34mFilterVehiclePrintResults[0m([35mconst[0m string[35m&[0m cRole) [35mconst[0m { 
    size_t choice [35m=[0m [33m0[0m, index [35m=[0m [33m0[0m;
    [35mint[0m tmpYear [35m=[0m [33m0[0m;
    string tmpMake, tmpModel, tmpColor;

    [35mif[0m(cRole [35m==[0m [32m"[0m[32mowner[0m[32m"[0m) { 
        [35mdo[0m { 
            cout [35m<<[0m [32m"[0m[32mHow would you like to filter the results?[0m[32m"[0m [35m<<[0m endl;
            cout [35m<<[0m [32m"[0m[32m1) Days each vehicle has been on the lot.[0m[32m"[0m [35m<<[0m endl;
            cout [35m<<[0m [32m"[0m[32m2) Price of each vehicle.[0m[32m"[0m [35m<<[0m endl;
            cout [35m<<[0m [32m"[0m[32m3) Number of cars sold by make, model, year, color, or time on lot.[0m[32m"[0m [35m<<[0m endl;
            cout [35m<<[0m [32m"[0m[32m4) Quit to previous menu.[0m[32m"[0m [35m<<[0m endl;
            cin [35m>>[0m choice;
            [35mwhile[0m(cin.fail() [35m||[0m choice < [33m1[0m [35m||[0m choice > [33m4[0m) {
                cerr [35m<<[0m [32m"[0m[32mInvalid input. Please enter a number between 1 and 3.[0m[32m"[0m [35m<<[0m endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), [32m'[0m[36m\n[0m[32m'[0m);
                cin [35m>>[0m choice;
            } [32m//[0m[32m ends while[0m
            size_t x [35m=[0m [33m0[0m, counter [35m=[0m [33m0[0m;
            [35mswitch[0m(choice) {
                [35mcase[0m [33m1[0m:
                    index [35m=[0m [33m0[0m;
                    [35mfor[0m([35mconst[0m Vehicle[35m*[0m vehicle [35m:[0m vecVehicles) { 
                        cout [35m<<[0m [32m"[0m[32mVehicle VIN number: [0m[32m"[0m [35m<<[0m vehicle->GetVin() [35m<<[0m endl;
                        cout [35m<<[0m [32m"[0m[32mIs taking [0m[32m"[0m [35m<<[0m vehicle->GetDaysOnLot() [35m<<[0m [32m"[0m[32m days to sell.[0m[32m"[0m [35m<<[0m endl;
                        [35mif[0m(index [35m!=[0m vecVehicles.size() [35m-[0m [33m1[0m) {
                            cout [35m<<[0m endl;
                        } [32m//[0m[32m ends if[0m
                        index[35m++[0m;
                    } [32m//[0m[32m ends for[0m
                    [35mbreak[0m; [32m//[0m[32m ends case 1 outer[0m
                [35mcase[0m [33m2[0m:
                    index [35m=[0m [33m0[0m;
                    [35mfor[0m([35mconst[0m Vehicle[35m*[0m vehicle [35m:[0m vecVehicles) { 
                        cout [35m<<[0m [32m"[0m[32mVehicle VIN number: [0m[32m"[0m [35m<<[0m vehicle->GetVin() [35m<<[0m endl;
                        cout [35m<<[0m [32m"[0m[32mIs selling for $[0m[32m"[0m [35m<<[0m vehicle->GetPrice() [35m<<[0m [32m"[0m[32m dollars.[0m[32m"[0m [35m<<[0m endl;
                        [35mif[0m(index [35m!=[0m vecVehicles.size() [35m-[0m [33m1[0m) {
                            cout [35m<<[0m endl;
                        } [32m//[0m[32m ends if[0m
                        index[35m++[0m;
                    } [32m//[0m[32m ends for[0m
                    [35mbreak[0m; [32m//[0m[32m ends case 2 outer[0m
                [35mcase[0m [33m3[0m:
                    [35mdo[0m { 
                        cout [35m<<[0m [32m"[0m[32mChoose an option to filter results by:[0m[32m"[0m [35m<<[0m endl;
                        cout [35m<<[0m [32m"[0m[32m1) Make[0m[32m"[0m [35m<<[0m endl [35m<<[0m [32m"[0m[32m2) Model[0m[32m"[0m [35m<<[0m endl [35m<<[0m [32m"[0m[32m3) Year[0m[32m"[0m [35m<<[0m endl [35m<<[0m [32m"[0m[32m4) Color[0m[32m"[0m [35m<<[0m endl [35m<<[0m [32m"[0m[32m5) Time on lot[0m[32m"[0m [35m<<[0m endl [35m<<[0m [32m"[0m[32m6) Quit to previous menu[0m[32m"[0m [35m<<[0m endl;
                        cin [35m>>[0m x;
                        [35mwhile[0m(cin.fail() [35m||[0m x < [33m1[0m [35m||[0m x > [33m6[0m) {
                            cerr [35m<<[0m [32m"[0m[32mInvalid input. Please enter a number between 1 and 5.[0m[32m"[0m [35m<<[0m endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), [32m'[0m[36m\n[0m[32m'[0m);
                            cin [35m>>[0m x;
                        } [32m//[0m[32m ends while[0m
                        [35mchar[0m y;
                        [35mbool[0m found [35m=[0m [33mfalse[0m;
                        [35mswitch[0m(x) {
                            [35mcase[0m [33m1[0m:
                                cout [35m<<[0m [32m"[0m[32mWhich make do you want to search for?[0m[32m"[0m [35m<<[0m endl;
                                cin [35m>>[0m tmpMake;
                                [35mwhile[0m(cin.fail()) {
                                    cerr [35m<<[0m [32m"[0m[32mInvalid input. Please enter a number between 1 and 5.[0m[32m"[0m [35m<<[0m endl;
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(), [32m'[0m[36m\n[0m[32m'[0m);
                                    cin [35m>>[0m tmpMake;
                                } [32m//[0m[32m ends while[0m
                                counter [35m=[0m [33m0[0m;
                                [35mfor[0m([35mconst[0m Vehicle[35m*[0m vehicle [35m:[0m vecVehicles) { 
                                    [35mif[0m(vehicle->GetMake() [35m==[0m tmpMake) {
                                        found [35m=[0m [33mtrue[0m;
                                        counter[35m++[0m;
                                    } [32m//[0m[32m ends if[0m
                                } [32m//[0m[32m ends for[0m
                                  [32m//[0m[32m if the option was not found[0m
                                [35mwhile[0m([35m![0mfound) {
                                    cerr [35m<<[0m [32m"[0m[32mThere is no vehicle of make: [0m[32m"[0m [35m<<[0m tmpMake [35m<<[0m [32m"[0m[32m on the lot.[0m[32m"[0m [35m<<[0m endl;
                                    cerr [35m<<[0m [32m"[0m[32mPlease enter another vehicle make:[0m[32m"[0m [35m<<[0m endl;
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(), [32m'[0m[36m\n[0m[32m'[0m);
                                    cin [35m>>[0m tmpMake;
                                    [35mfor[0m(Vehicle[35m*[0m vehicle [35m:[0m vecVehicles) {
                                        [35mif[0m(vehicle->GetMake() [35m==[0m tmpMake) {
                                            found [35m=[0m [33mtrue[0m;
                                            counter[35m++[0m;
                                        } [32m//[0m[32m ends if[0m
                                    } [32m//[0m[32m ends for[0m
                                } [32m//[0m[32m ends not found while[0m
                                [35mif[0m(counter [35m!=[0m [33m1[0m) { 
                                    cout [35m<<[0m [32m"[0m[32mThere are [0m[32m"[0m [35m<<[0m counter [35m<<[0m [32m"[0m[32m cars with [0m[32m"[0m [35m<<[0m tmpMake [35m<<[0m [32m"[0m[32m make.[0m[32m"[0m [35m<<[0m endl;
                                    cout [35m<<[0m [32m"[0m[32mWould you like to view them? (y/n)[0m[32m"[0m [35m<<[0m endl;
                                } [35melse[0m { 
                                    cout [35m<<[0m [32m"[0m[32mThere is [0m[32m"[0m [35m<<[0m counter [35m<<[0m [32m"[0m[32m car with [0m[32m"[0m [35m<<[0m tmpMake [35m<<[0m [32m"[0m[32m make.[0m[32m"[0m [35m<<[0m endl;
                                    cout [35m<<[0m [32m"[0m[32mWould you like to view it? (y/n)[0m[32m"[0m [35m<<[0m endl;
                                }
                                cin [35m>>[0m y;
                                [35mwhile[0m(cin.fail() [35m||[0m (y [35m!=[0m [32m'[0m[32my[0m[32m'[0m [35m&&[0m y [35m!=[0m [32m'[0m[32mn[0m[32m'[0m)) {
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(), [32m'[0m[36m\n[0m[32m'[0m);
                                    cin [35m>>[0m y;
                                } [32m//[0m[32m ends while[0m
                                [35mif[0m(y [35m==[0m [32m'[0m[32mn[0m[32m'[0m) {
                                    [35mcontinue[0m;
                                } [35melse[0m { 
                                    [35mfor[0m(Vehicle[35m*[0m vehicle[35m:[0m vecVehicles) {
                                        [35mif[0m(vehicle->GetMake() [35m==[0m tmpMake) {
                                            PrintVehicleInfo(vehicle);
                                        } [32m//[0m[32m ends if[0m
                                    } [32m//[0m[32m ends for[0m
                                } [32m//[0m[32m ends if[0m
                                [35mbreak[0m; [32m//[0m[32m ends case 1 inner[0m
                            [35mcase[0m [33m2[0m:
                                found [35m=[0m [33mfalse[0m;
                                counter [35m=[0m [33m0[0m;

                                cout [35m<<[0m [32m"[0m[32mWhich model do you want to search for?[0m[32m"[0m [35m<<[0m endl;
                                cin [35m>>[0m tmpModel;
                                [35mwhile[0m(cin.fail()) {
                                    cerr [35m<<[0m [32m"[0m[32mInvalid input. Please enter a number between 1 and 5.[0m[32m"[0m [35m<<[0m endl;
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(), [32m'[0m[36m\n[0m[32m'[0m);
                                    cin [35m>>[0m tmpModel;
                                } [32m//[0m[32m ends while[0m
                                [35mfor[0m([35mconst[0m Vehicle[35m*[0m vehicle [35m:[0m vecVehicles) { 
                                    [35mif[0m(vehicle->GetModel() [35m==[0m tmpModel) {
                                        found [35m=[0m [33mtrue[0m;
                                        counter[35m++[0m;
                                    } [32m//[0m[32m ends if[0m
                                } [32m//[0m[32m ends for[0m
                                [35mwhile[0m([35m![0mfound) {
                                    cerr [35m<<[0m [32m"[0m[32mThere is no vehicle of model: [0m[32m"[0m [35m<<[0m tmpModel [35m<<[0m [32m"[0m[32m on the lot.[0m[32m"[0m [35m<<[0m endl;
                                    cerr [35m<<[0m [32m"[0m[32mPlease enter another vehicle model:[0m[32m"[0m [35m<<[0m endl;
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(), [32m'[0m[36m\n[0m[32m'[0m);
                                    cin [35m>>[0m tmpMake;
                                    [35mfor[0m(Vehicle[35m*[0m vehicle [35m:[0m vecVehicles) {
                                        [35mif[0m(vehicle->GetModel() [35m==[0m tmpModel) {
                                            found [35m=[0m [33mtrue[0m;
                                            counter[35m++[0m;
                                        } [32m//[0m[32m ends if[0m
                                    } [32m//[0m[32m ends for[0m
                                } [32m//[0m[32m ends not found while[0m
                                [35mif[0m(counter [35m!=[0m [33m1[0m) { 
                                    cout [35m<<[0m [32m"[0m[32mThere are [0m[32m"[0m [35m<<[0m counter [35m<<[0m [32m"[0m[32m cars with [0m[32m"[0m [35m<<[0m tmpModel [35m<<[0m [32m"[0m[32m model.[0m[32m"[0m [35m<<[0m endl;
                                    cout [35m<<[0m [32m"[0m[32mWould you like to view them? (y/n)[0m[32m"[0m [35m<<[0m endl;
                                } [35melse[0m {
                                    cout [35m<<[0m [32m"[0m[32mThere is [0m[32m"[0m [35m<<[0m counter [35m<<[0m [32m"[0m[32m car with [0m[32m"[0m [35m<<[0m tmpModel [35m<<[0m [32m"[0m[32m model.[0m[32m"[0m [35m<<[0m endl;
                                    cout [35m<<[0m [32m"[0m[32mWould you like to view it? (y/n)[0m[32m"[0m [35m<<[0m endl;
                                }
                                cin [35m>>[0m y;
                                [35mwhile[0m(cin.fail() [35m||[0m (y [35m!=[0m [32m'[0m[32my[0m[32m'[0m [35m&&[0m y [35m!=[0m [32m'[0m[32mn[0m[32m'[0m)) {
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(), [32m'[0m[36m\n[0m[32m'[0m);
                                    cin [35m>>[0m y;
                                } [32m//[0m[32m ends while[0m
                                [35mif[0m(y [35m==[0m [32m'[0m[32mn[0m[32m'[0m) {
                                    [35mreturn[0m;
                                } [35melse[0m { 
                                    [35mfor[0m(Vehicle[35m*[0m vehicle[35m:[0m vecVehicles) {
                                        [35mif[0m(vehicle->GetModel() [35m==[0m tmpModel) {
                                            PrintVehicleInfo(vehicle);
                                        } [32m//[0m[32m ends if[0m
                                    } [32m//[0m[32m ends for[0m
                                } [32m//[0m[32m ends if[0m
                                [35mbreak[0m; [32m//[0m[32m ends case 2 inner[0m
                            [35mcase[0m [33m3[0m: 
                                found [35m=[0m [33mfalse[0m;  
                                counter [35m=[0m [33m0[0m;
                                cout [35m<<[0m [32m"[0m[32mWhich year do you want to search for?[0m[32m"[0m [35m<<[0m endl;
                                cin [35m>>[0m tmpYear;
                                [35mwhile[0m(cin.fail()) {
                                    cerr [35m<<[0m [32m"[0m[32mInvalid input. Please enter a number between 1 and 5.[0m[32m"[0m [35m<<[0m endl;
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(), [32m'[0m[36m\n[0m[32m'[0m);
                                    cin [35m>>[0m tmpYear;
                                } [32m//[0m[32m ends while[0m
                                [35mfor[0m([35mconst[0m Vehicle[35m*[0m vehicle [35m:[0m vecVehicles) { 
                                    [35mif[0m(vehicle->GetYear() [35m==[0m tmpYear) {
                                        found [35m=[0m [33mtrue[0m;
                                        counter[35m++[0m;
                                    } [32m//[0m[32m ends if[0m
                                } [32m//[0m[32m ends for[0m
                                [35mwhile[0m([35m![0mfound) {
                                    cerr [35m<<[0m [32m"[0m[32mThere are no vehicles made in [0m[32m"[0m [35m<<[0m tmpYear [35m<<[0m [32m"[0m[32m on the lot.[0m[32m"[0m [35m<<[0m endl;
                                    cerr [35m<<[0m [32m"[0m[32mPlease enter another vehicle year:[0m[32m"[0m [35m<<[0m endl;
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(), [32m'[0m[36m\n[0m[32m'[0m);
                                    cin [35m>>[0m tmpYear;
                                    [35mfor[0m(Vehicle[35m*[0m vehicle [35m:[0m vecVehicles) {
                                        [35mif[0m(vehicle->GetYear() [35m==[0m tmpYear) {
                                            found [35m=[0m [33mtrue[0m;
                                            counter[35m++[0m;
                                        } [32m//[0m[32m ends if[0m
                                    } [32m//[0m[32m ends for[0m
                                } [32m//[0m[32m ends not found while[0m
                                [35mif[0m(counter [35m!=[0m [33m1[0m) {
                                    cout [35m<<[0m [32m"[0m[32mThere are [0m[32m"[0m [35m<<[0m counter [35m<<[0m [32m"[0m[32m cars from the year [0m[32m"[0m [35m<<[0m tmpYear [35m<<[0m [32m"[0m[32m on the lot.[0m[32m"[0m [35m<<[0m endl;
                                    cout [35m<<[0m [32m"[0m[32mWould you like to veiw them? (y/n)[0m[32m"[0m [35m<<[0m endl;
                                } [35melse[0m {
                                    cout [35m<<[0m [32m"[0m[32mThere is [0m[32m"[0m [35m<<[0m counter [35m<<[0m [32m"[0m[32m car from the year [0m[32m"[0m [35m<<[0m tmpYear [35m<<[0m [32m"[0m[32m on the lot.[0m[32m"[0m [35m<<[0m endl;
                                    cout [35m<<[0m [32m"[0m[32mWould you like to view it? (y/n)[0m[32m"[0m [35m<<[0m endl;
                                } [32m//[0m[32m ends if[0m
                                cin [35m>>[0m y;
                                [35mwhile[0m(cin.fail() [35m||[0m (y [35m!=[0m [32m'[0m[32my[0m[32m'[0m [35m&&[0m y [35m!=[0m [32m'[0m[32mn[0m[32m'[0m)) {
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(), [32m'[0m[36m\n[0m[32m'[0m);
                                    cin [35m>>[0m y;
                                } [32m//[0m[32m ends while[0m
                                [35mif[0m(y [35m==[0m [32m'[0m[32mn[0m[32m'[0m) {
                                    [35mreturn[0m;
                                } [35melse[0m {
                                    [35mfor[0m(Vehicle[35m*[0m vehicle[35m:[0m vecVehicles) {
                                        [35mif[0m(vehicle->GetModel() [35m==[0m tmpModel) {
                                            PrintVehicleInfo(vehicle);
                                        } [32m//[0m[32m ends if[0m
                                    } [32m//[0m[32m ends for[0m
                                } [32m//[0m[32m ends if[0m

                                [35mbreak[0m; [32m//[0m[32m ends case 3 inner [0m
                            [35mcase[0m [33m4[0m:
                                found [35m=[0m [33mfalse[0m;
                                counter [35m=[0m [33m0[0m;
                                cout [35m<<[0m [32m"[0m[32mWhich color do you want to search for?[0m[32m"[0m [35m<<[0m endl;
                                cin [35m>>[0m tmpColor;
                                [35mwhile[0m(cin.fail()) {
                                    cerr [35m<<[0m [32m"[0m[32mInvalid input. Please enter a number between 1 and 5.[0m[32m"[0m [35m<<[0m endl;
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(), [32m'[0m[36m\n[0m[32m'[0m);
                                    cin [35m>>[0m tmpColor;
                                } [32m//[0m[32m ends while[0m
                                [35mfor[0m([35mconst[0m Vehicle[35m*[0m vehicle [35m:[0m vecVehicles) { 
                                    [35mif[0m(vehicle->GetColor() [35m==[0m tmpColor) {
                                        found [35m=[0m [33mtrue[0m;
                                        counter[35m++[0m;
                                    } [32m//[0m[32m ends if[0m
                                } [32m//[0m[32m ends for[0m
                                [35mwhile[0m([35m![0mfound) {
                                    cerr [35m<<[0m [32m"[0m[32mThere are no vehicles colored [0m[32m"[0m [35m<<[0m tmpColor [35m<<[0m [32m"[0m[32m on the lot.[0m[32m"[0m [35m<<[0m endl;
                                    cerr [35m<<[0m [32m"[0m[32mPlease enter another vehicle color:[0m[32m"[0m [35m<<[0m endl;
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(), [32m'[0m[36m\n[0m[32m'[0m);
                                    cin [35m>>[0m tmpColor;
                                    [35mfor[0m(Vehicle[35m*[0m vehicle [35m:[0m vecVehicles) {
                                        [35mif[0m(vehicle->GetColor() [35m==[0m tmpColor) {
                                            found [35m=[0m [33mtrue[0m;
                                            counter[35m++[0m;
                                        } [32m//[0m[32m ends if[0m
                                    } [32m//[0m[32m ends for[0m
                                } [32m//[0m[32m ends not found while[0m
                                [35mif[0m(counter [35m!=[0m [33m1[0m) { 
                                    cout [35m<<[0m [32m"[0m[32mThere are [0m[32m"[0m [35m<<[0m counter [35m<<[0m [32m"[0m[32m cars with [0m[32m"[0m [35m<<[0m tmpColor [35m<<[0m [32m"[0m[32m color.[0m[32m"[0m [35m<<[0m endl;
                                    cout [35m<<[0m [32m"[0m[32mWould you like to view them? (y/n)[0m[32m"[0m [35m<<[0m endl;
                                } [35melse[0m {
                                    cout [35m<<[0m [32m"[0m[32mThere is [0m[32m"[0m [35m<<[0m counter [35m<<[0m [32m"[0m[32m car with [0m[32m"[0m [35m<<[0m tmpColor [35m<<[0m [32m"[0m[32m color.[0m[32m"[0m [35m<<[0m endl;
                                    cout [35m<<[0m [32m"[0m[32mWould you like to view it? (y/n)[0m[32m"[0m [35m<<[0m endl;
                                } [32m//[0m[32m ends if[0m
                                cin [35m>>[0m y;
                                [35mwhile[0m(cin.fail() [35m||[0m (y [35m!=[0m [32m'[0m[32my[0m[32m'[0m [35m&&[0m y [35m!=[0m [32m'[0m[32mn[0m[32m'[0m)) {
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(), [32m'[0m[36m\n[0m[32m'[0m);
                                    cin [35m>>[0m y;
                                } [32m//[0m[32m ends while[0m
                                [35mif[0m(y [35m==[0m [32m'[0m[32mn[0m[32m'[0m) {
                                    [35mreturn[0m;
                                } [35melse[0m {
                                    [35mfor[0m(Vehicle[35m*[0m vehicle[35m:[0m vecVehicles) {
                                        [35mif[0m(vehicle->GetColor() [35m==[0m tmpColor) {
                                            PrintVehicleInfo(vehicle);
                                        } [32m//[0m[32m ends if[0m
                                    } [32m//[0m[32m ends for[0m
                                } [32m//[0m[32m ends if[0m
                                [35mbreak[0m; [32m//[0m[32m ends case 4 inner[0m
                            [35mcase[0m [33m5[0m: 
                                found [35m=[0m [33mfalse[0m;
                                counter [35m=[0m [33m0[0m;
                                [35mint[0m timeOnLot;
                                cout [35m<<[0m [32m"[0m[32mEnter the maximum time on lot(in days): [0m[32m"[0m [35m<<[0m endl;
                                cin [35m>>[0m timeOnLot;
                                [35mwhile[0m(cin.fail()) {
                                    cerr [35m<<[0m [32m"[0m[32mInvalid input. Please enter a number between 1 and 5.[0m[32m"[0m [35m<<[0m endl;
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(), [32m'[0m[36m\n[0m[32m'[0m);
                                    cin [35m>>[0m timeOnLot;
                                } [32m//[0m[32m ends while[0m
                                [35mfor[0m([35mconst[0m Vehicle[35m*[0m vehicle [35m:[0m vecVehicles) { 
                                    [35mif[0m(vehicle->GetDaysOnLot() [35m<=[0m timeOnLot) {
                                        found [35m=[0m [33mtrue[0m;
                                        counter[35m++[0m;
                                    } [32m//[0m[32m ends if[0m
                                } [32m//[0m[32m ends for[0m
                                [35mwhile[0m([35m![0mfound) {
                                    cerr [35m<<[0m [32m"[0m[32mNo vehicles have been on the lot [0m[32m"[0m [35m<<[0m timeOnLot [35m<<[0m [32m"[0m[32m days or shorter.[0m[32m"[0m [35m<<[0m endl;
                                    cerr [35m<<[0m [32m"[0m[32mPlease enter another length of time:[0m[32m"[0m [35m<<[0m endl;
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(), [32m'[0m[36m\n[0m[32m'[0m);
                                    cin [35m>>[0m timeOnLot;
                                    [35mfor[0m(Vehicle[35m*[0m vehicle [35m:[0m vecVehicles) {
                                        [35mif[0m(vehicle->GetDaysOnLot() [35m==[0m timeOnLot) {
                                            found [35m=[0m [33mtrue[0m;
                                            counter[35m++[0m;
                                        } [32m//[0m[32m ends if[0m
                                    } [32m//[0m[32m ends for[0m
                                } [32m//[0m[32m ends not found while[0m
                                [35mif[0m(counter [35m!=[0m [33m1[0m) {
                                    cout [35m<<[0m [32m"[0m[32mThere are [0m[32m"[0m [35m<<[0m counter [35m<<[0m [32m"[0m[32m cars with time on lot less than or equal to [0m[32m"[0m [35m<<[0m timeOnLot [35m<<[0m [32m"[0m[32m days.[0m[32m"[0m [35m<<[0m endl;
                                    cout [35m<<[0m [32m"[0m[32mWould you like to view them? (y/n)[0m[32m"[0m [35m<<[0m endl;
                                } [35melse[0m {
                                    cout [35m<<[0m [32m"[0m[32mThere is [0m[32m"[0m [35m<<[0m counter [35m<<[0m [32m"[0m[32m car with time on lot less than or equal to [0m[32m"[0m [35m<<[0m timeOnLot [35m<<[0m [32m"[0m[32m days.[0m[32m"[0m [35m<<[0m endl;
                                    cout [35m<<[0m [32m"[0m[32mWould you like to view it? (y/n)[0m[32m"[0m [35m<<[0m endl;
                                } [32m//[0m[32m ends if[0m
                                [35mwhile[0m(cin.fail() [35m||[0m (y [35m!=[0m [32m'[0m[32my[0m[32m'[0m [35m&&[0m y [35m!=[0m [32m'[0m[32mn[0m[32m'[0m)) {
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(), [32m'[0m[36m\n[0m[32m'[0m);
                                    cin [35m>>[0m y;
                                } [32m//[0m[32m ends while[0m
                                [35mif[0m(y [35m==[0m [32m'[0m[32mn[0m[32m'[0m) {
                                    [35mreturn[0m;
                                } [35melse[0m {
                                    [35mfor[0m(Vehicle[35m*[0m vehicle[35m:[0m vecVehicles) {
                                        [35mif[0m(vehicle->GetDaysOnLot() [35m==[0m timeOnLot) {
                                            PrintVehicleInfo(vehicle);
                                        } [32m//[0m[32m ends if[0m
                                    } [32m//[0m[32m ends for[0m
                                } [32m//[0m[32m ends if[0m
                                [35mbreak[0m; [32m//[0m[32m ends case 5 inner[0m
                            [35mcase[0m [33m6[0m:
                                [35mbreak[0m; [32m//[0m[32m ends case 6 inner[0m
                        } [32m//[0m[32m ends inner switch[0m
                    } [35mwhile[0m(x [35m!=[0m [33m6[0m); [32m//[0m[32m ends inner do while[0m
                    [35mbreak[0m; [32m//[0m[32m ends case 3 outer[0m
                [35mcase[0m [33m4[0m:
                    [35mbreak[0m; [32m//[0m[32m ends case 4 outer[0m
            } [32m//[0m[32m ends outer switch[0m
        } [35mwhile[0m(choice [35m!=[0m [33m4[0m); [32m//[0m[32m ends outer do while[0m
    } [32m//[0m[32m ends if currentRole == "owner" if[0m
    [35mif[0m(cRole [35m==[0m [32m"[0m[32mmanager[0m[32m"[0m) {
        choice [35m=[0m [33m0[0m;
        [35mdo[0m { 
            cout [35m<<[0m [32m"[0m[32mHow would you like to filter the results?[0m[32m"[0m [35m<<[0m endl;
            cout [35m<<[0m [32m"[0m[32m1) How long each vehicle has been on the lot.[0m[32m"[0m [35m<<[0m endl;
            cout [35m<<[0m [32m"[0m[32m2) Quit to previous menu.[0m[32m"[0m [35m<<[0m endl;
            cin [35m>>[0m choice;
            [35mwhile[0m(cin.fail() [35m||[0m choice < [33m1[0m [35m||[0m choice > [33m2[0m) {
                cerr [35m<<[0m [32m"[0m[32mInvalid input. Please enter a number between 1 and 2.[0m[32m"[0m [35m<<[0m endl;
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), [32m'[0m[36m\n[0m[32m'[0m);
                cin [35m>>[0m choice;
            } [32m//[0m[32m ends while[0m
            [35mswitch[0m(choice) {
                [35mcase[0m [33m1[0m:
                    index [35m=[0m [33m0[0m;
                    [35mfor[0m([35mconst[0m Vehicle[35m*[0m vehicle [35m:[0m vecVehicles) { 
                        cout [35m<<[0m [32m"[0m[32mVehicle VIN number: [0m[32m"[0m [35m<<[0m vehicle->GetVin() [35m<<[0m [32m"[0m[32m has been on the lot for [0m[32m"[0m [35m<<[0m vehicle->GetDaysOnLot() [35m<<[0m [32m"[0m[32m days.[0m[32m"[0m [35m<<[0m endl;
                        [35mif[0m(index [35m!=[0m vecVehicles.size() [35m-[0m [33m1[0m) {
                            cout [35m<<[0m endl;
                        } [32m//[0m[32m ends if[0m
                        index[35m++[0m;
                    } [32m//[0m[32m ends for[0m
                    [35mbreak[0m; [32m//[0m[32m ends case 1 outer[0m
                [35mcase[0m [33m2[0m:
                    [35mbreak[0m; [32m//[0m[32m ends case 2 outer[0m
            }
        } [35mwhile[0m(choice [35m!=[0m [33m2[0m);
    }  [32m//[0m[32m ends if currentRole == "manager" if[0m
} [32m//[0m[32m ends FilterVehiclePrintResults()[0m

[32m//[0m[32m Prints a vehicle objects information[0m
[35mvoid[0m Dealership::[34mPrintVehicleInfo[0m(Vehicle[35m*[0m obj) [35mconst[0m {
    cout [35m<<[0m [32m"[0m[32mMake: [0m[32m"[0m [35m<<[0m obj->GetMake() [35m<<[0m endl;
    cout [35m<<[0m [32m"[0m[32mModel: [0m[32m"[0m [35m<<[0m obj->GetModel() [35m<<[0m endl;
    cout [35m<<[0m [32m"[0m[32mColor: [0m[32m"[0m [35m<<[0m obj->GetColor() [35m<<[0m endl;
    cout [35m<<[0m [32m"[0m[32mDays on lot: [0m[32m"[0m [35m<<[0m obj->GetDaysOnLot() [35m<<[0m  endl;
    cout [35m<<[0m [32m"[0m[32mPrice: $[0m[32m"[0m [35m<<[0m obj->GetPrice() [35m<<[0m endl;
    cout [35m<<[0m [32m"[0m[32mVIN number: [0m[32m"[0m [35m<<[0m obj->GetVin() [35m<<[0m endl;
} [32m//[0m[32m ends PrintVehicleInfo[0m

[32m//[0m[32m SALES STUFF BELOW[0m
[35mvoid[0m Dealership::[34mAddSale[0m(Vehicle[35m*[0m vehicle, Customer[35m*[0m customer, [35mconst[0m string[35m&[0m sn, [35mconst[0m [35mdouble[0m[35m&[0m sp, [35mconst[0m [35mdouble[0m[35m&[0m sbd, [35mconst[0m [35mdouble[0m[35m&[0m sbw, [35mconst[0m [35mdouble[0m[35m&[0m sbm) {
    vecSales.emplace_back([35mnew[0m Sales(vehicle, customer, sn, sp, sbd, sbw, sbm));
} [32m//[0m[32m ends AddSale()[0m

[35mvoid[0m Dealership::[34mAddSale[0m(Sales[35m*[0m obj) {
    vecSales.emplace_back(obj);
} [32m//[0m[32m ends AddSale()[0m

[32m//[0m[32m Prints all previous sales information[0m
[35mvoid[0m Dealership::[34mPrintEntireSalesVector[0m() [35mconst[0m {
    cout [35m<<[0m endl [35m<<[0m endl; [32m//[0m[32m just creating space[0m
    [35mif[0m(vecSales.size() [35m<=[0m [33m0[0m) {
        cerr [35m<<[0m [32m"[0m[32mNo sales to report.[0m[32m"[0m [35m<<[0m endl;
    } [35melse[0m {
        cout [35m<<[0m endl [35m<<[0m [32m"[0m[32mSales Info:[0m[32m"[0m [35m<<[0m endl;
        size_t counter [35m=[0m [33m0[0m;
        [35mfor[0m(Sales[35m*[0m sale [35m:[0m vecSales) { 
            [32m//[0m[32m Getting vehicle and customer obj so it can print their information with getters[0m
            Vehicle[35m*[0m currVehicle [35m=[0m sale->GetVehicleObj();
            Customer[35m*[0m currCustomer [35m=[0m sale->GetCustomerObj();

            cout [35m<<[0m [32m"[0m[32mCustomer Information: [0m[32m"[0m [35m<<[0m endl;
            [35mif[0m(currCustomer [35m!=[0m [33mnullptr[0m) {
                PrintCustomerInfo(currCustomer);
            } [35melse[0m {
                cerr [35m<<[0m [32m"[0m[32mCustomer information not available.[0m[32m"[0m [35m<<[0m endl;
            } [32m//[0m[32m ends if[0m

            cout [35m<<[0m endl [35m<<[0m [32m"[0m[32mVehicle Information: [0m[32m"[0m [35m<<[0m endl;
            [35mif[0m(currVehicle [35m!=[0m [33mnullptr[0m) {
                PrintVehicleInfo(currVehicle);
            } [35melse[0m {
                cerr [35m<<[0m [32m"[0m[32mVehicle information not available.[0m[32m"[0m [35m<<[0m endl;
            } [32m//[0m[32m ends if[0m

            cout [35m<<[0m [32m"[0m[32mSales price: $[0m[32m"[0m [35m<<[0m sale->GetSalesPrice() [35m<<[0m endl;
            cout [35m<<[0m [32m"[0m[32mSales by day: [0m[32m"[0m [35m<<[0m sale->GetSalesByDay() [35m<<[0m endl;
            cout [35m<<[0m [32m"[0m[32mSales by week: [0m[32m"[0m [35m<<[0m sale->GetSalesByWeek() [35m<<[0m endl;
            cout [35m<<[0m [32m"[0m[32mSales by month: [0m[32m"[0m [35m<<[0m sale->GetSalesByMonth() [35m<<[0m endl;
            cout [35m<<[0m [32m"[0m[32mSalesman: [0m[32m"[0m [35m<<[0m sale->GetSalesmanName() [35m<<[0m endl;

            [35mif[0m(counter [35m!=[0m vecSales.size() [35m-[0m [33m1[0m) {
                cout [35m<<[0m endl;
            } [32m//[0m[32m ends if[0m
            counter[35m++[0m;
        } [32m//[0m[32m ends for[0m
    } [32m//[0m[32m ends if[0m
} [32m//[0m[32m ends PrintEntireSalesVector()[0m

[32m//[0m[32m TODO: FIX SALE STUFF[0m
[35mvoid[0m Dealership::[34mOpenFile[0m() {
    [32m//[0m[32m Making sure vectors are empty[0m
    vecCustomers.clear();
    vecVehicles.clear();
    vecSales.clear();

    inputFile.open(customersFilename); [32m//[0m[32m opening customers.txt[0m
    [35mif[0m([35m![0minputFile.is_open()) {
        cerr [35m<<[0m customersFilename [35m<<[0m [32m"[0m[32m unable to open![0m[32m"[0m [35m<<[0m endl;
        [35mreturn[0m;
    } [32m//[0m[32m ends if[0m

    [35mwhile[0m(getline(inputFile, line)) {
        [35mif[0m(line.find([32m"[0m[32mCustomer[0m[32m"[0m) [35m!=[0m string::npos) {
            string name, pn, ea, interestedStr, boughtStr, iv, im;
            [35mbool[0m interested [35m=[0m [33mfalse[0m, bought [35m=[0m [33mfalse[0m;
            [35mwhile[0m(getline(inputFile, line) [35m&&[0m [35m![0mline.empty()) {
                [35mif[0m(line [35m==[0m [32m"[0m[32mName:[0m[32m"[0m) {
                    getline(inputFile, name);
                } [35melse[0m [35mif[0m(line [35m==[0m [32m"[0m[32mPhone:[0m[32m"[0m) {
                    getline(inputFile, pn);
                } [35melse[0m [35mif[0m(line [35m==[0m [32m"[0m[32mEmail:[0m[32m"[0m) {
                    getline(inputFile, ea);
                } [35melse[0m [35mif[0m(line [35m==[0m [32m"[0m[32mInterested:[0m[32m"[0m) {
                    getline(inputFile, interestedStr);
                } [35melse[0m [35mif[0m(line [35m==[0m [32m"[0m[32mBought:[0m[32m"[0m) {
                    getline(inputFile, boughtStr);
                } [35melse[0m [35mif[0m(line [35m==[0m [32m"[0m[32mVehicle:[0m[32m"[0m) {
                    getline(inputFile, iv);
                } [35melse[0m [35mif[0m(line [35m==[0m [32m"[0m[32mModel:[0m[32m"[0m) {
                    getline(inputFile, im);
                } [32m//[0m[32m ends if[0m

                [35mif[0m([35m![0mname.empty() [35m&&[0m [35m![0mpn.empty() [35m&&[0m [35m![0mea.empty() [35m&&[0m [35m![0minterestedStr.empty() [35m&&[0m [35m![0mboughtStr.empty() [35m&&[0m [35m![0miv.empty() [35m&&[0m [35m![0mim.empty()) {  
                    istringstream(interestedStr) [35m>>[0m interested;
                    istringstream(boughtStr) [35m>>[0m bought;
                    AddCustomer(name, pn, ea, interested, bought, iv, im);
                } [32m//[0m[32m ends if[0m
            } [32m//[0m[32m ends while[0m
        } [32m//[0m[32m ends if[0m
    } [32m//[0m[32m ends while[0m
    inputFile.close(); [32m//[0m[32m closing customers.txt[0m

    inputFile.open(vehiclesFilename); [32m//[0m[32m opening vehicles.txt[0m
    [35mif[0m([35m![0minputFile.is_open()) {
        cerr [35m<<[0m vehiclesFilename [35m<<[0m [32m"[0m[32m unable to open![0m[32m"[0m [35m<<[0m endl;
        [35mreturn[0m;
    } [32m//[0m[32m ends if[0m
    line.clear();
    [35mwhile[0m(getline(inputFile, line)) {
        [35mif[0m(line.find([32m"[0m[32mVehicle[0m[32m"[0m) [35m!=[0m string::npos) {
            string yearOpen, makeOpen, modelOpen, colorOpen, daysOnLotOpen, priceOpen, vinOpen;
            [35mwhile[0m(getline(inputFile, line) [35m&&[0m [35m![0mline.empty()) {
                [35mif[0m(line [35m==[0m [32m"[0m[32mYear:[0m[32m"[0m) {
                    getline(inputFile, yearOpen);
                } [35melse[0m [35mif[0m(line [35m==[0m [32m"[0m[32mMake:[0m[32m"[0m) {
                    getline(inputFile, makeOpen);
                } [35melse[0m [35mif[0m(line [35m==[0m [32m"[0m[32mModel:[0m[32m"[0m) {
                    getline(inputFile, modelOpen);
                } [35melse[0m [35mif[0m(line [35m==[0m [32m"[0m[32mColor:[0m[32m"[0m) {
                    getline(inputFile, colorOpen);
                } [35melse[0m [35mif[0m(line [35m==[0m [32m"[0m[32mDays On Lot:[0m[32m"[0m) {
                    getline(inputFile, daysOnLotOpen);
                } [35melse[0m [35mif[0m(line [35m==[0m [32m"[0m[32mPrice:[0m[32m"[0m) {
                    getline(inputFile, priceOpen);
                } [35melse[0m [35mif[0m(line [35m==[0m [32m"[0m[32mVIN:[0m[32m"[0m) {
                    getline(inputFile, vinOpen);
                } [32m//[0m[32m ends if[0m

                [35mif[0m([35m![0myearOpen.empty() [35m&&[0m [35m![0mmakeOpen.empty() [35m&&[0m [35m![0mmodelOpen.empty() [35m&&[0m [35m![0mcolorOpen.empty() [35m&&[0m [35m![0mdaysOnLotOpen.empty() [35m&&[0m [35m![0mpriceOpen.empty() [35m&&[0m [35m![0mvinOpen.empty()) {
                    [35mint[0m yearNew [35m=[0m stoi(yearOpen);
                    [35mint[0m daysOnLotNew [35m=[0m stoi(daysOnLotOpen);
                    [35mdouble[0m priceNew [35m=[0m stod(priceOpen);
                    AddVehicle(yearNew, makeOpen, modelOpen, colorOpen, daysOnLotNew, priceNew, vinOpen);
                } [32m//[0m[32m ends if[0m
            } [32m//[0m[32m ends while[0m
        } [32m//[0m[32m ends if[0m
    } [32m//[0m[32m ends while[0m
    inputFile.close(); [32m//[0m[32m closing vehicles.txt[0m

    inputFile.open(salesFilename); [32m//[0m[32m opening sales.txt[0m
    [35mif[0m([35m![0minputFile.is_open()) {
        cerr [35m<<[0m salesFilename [35m<<[0m [32m"[0m[32m unable to open![0m[32m"[0m [35m<<[0m endl;
        [35mreturn[0m;
    } [32m//[0m[32m ends if[0m
    string salesmanName, salePriceStr, salesByDayStr, salesByWeekStr, salesByMonthStr, customerName, vehicleVin;
    [35mwhile[0m(getline(inputFile, line)) {
        [35mif[0m(line.find([32m"[0m[32mSale[0m[32m"[0m) [35m!=[0m string::npos) {
            [35mwhile[0m(getline(inputFile, line) [35m&&[0m [35m![0mline.empty()) {
                [35mif[0m(line [35m==[0m [32m"[0m[32mSalesman's Name:[0m[32m"[0m) { 
                    getline(inputFile, salesmanName);
                } [35melse[0m [35mif[0m(line [35m==[0m [32m"[0m[32mSale Price:[0m[32m"[0m) { 
                    getline(inputFile, salePriceStr);
                } [35melse[0m [35mif[0m(line [35m==[0m [32m"[0m[32mSales By Day:[0m[32m"[0m) { 
                    getline(inputFile, salesByDayStr);
                } [35melse[0m [35mif[0m(line [35m==[0m [32m"[0m[32mSales By Week:[0m[32m"[0m) { 
                    getline(inputFile, salesByWeekStr);
                } [35melse[0m [35mif[0m(line [35m==[0m [32m"[0m[32mSales By Month:[0m[32m"[0m) { 
                    getline(inputFile, salesByMonthStr);
                } [35melse[0m [35mif[0m(line [35m==[0m [32m"[0m[32mCustomer[0m[32m"[0m) { 
                    getline(inputFile, customerName);
                } [35melse[0m [35mif[0m(line [35m==[0m [32m"[0m[32mVehicle[0m[32m"[0m) { 
                    getline(inputFile, vehicleVin);
                } [32m//[0m[32m ends if[0m
            } [32m//[0m[32m ends while[0m
            [35mif[0m([35m![0msalesmanName.empty() [35m&&[0m [35m![0msalePriceStr.empty() [35m&&[0m [35m![0msalesByDayStr.empty() [35m&&[0m [35m![0msalesByWeekStr.empty() [35m&&[0m [35m![0msalesByMonthStr.empty() [35m&&[0m [35m![0mcustomerName.empty() [35m&&[0m [35m![0mvehicleVin.empty()) {
                [35mdouble[0m salePrice [35m=[0m stod(salePriceStr);
                [35mdouble[0m salesByDay [35m=[0m stod(salesByDayStr);
                [35mdouble[0m salesByWeek [35m=[0m stod(salesByWeekStr);
                [35mdouble[0m salesByMonth [35m=[0m stod(salesByMonthStr);

                Customer[35m*[0m customer;
                customer [35m=[0m FindCustomer(customerName);
                Vehicle[35m*[0m vehicle;
                vehicle [35m=[0m FindVehicleObj(vehicleVin);
                [35mif[0m(customer [35m!=[0m [33mnullptr[0m [35m&&[0m vehicle [35m!=[0m [33mnullptr[0m) {
                    AddSale(vehicle, customer, salesmanName, salePrice, salesByDay, salesByWeek, salesByMonth);
                } [35melse[0m {
                    cerr [35m<<[0m [32m"[0m[32mSkipping sale - Customer or vehicle not found.[0m[32m"[0m [35m<<[0m endl;
                } [32m//[0m[32m ends if[0m
            } [35melse[0m {
                cerr [35m<<[0m [32m"[0m[32mSkipping sale - Incomplete sales data.[0m[32m"[0m [35m<<[0m endl;
            } [32m//[0m[32m ends else[0m
        } [32m//[0m[32m ends if[0m
    } [32m//[0m[32m ends while[0m
    inputFile.close(); [32m//[0m[32m closing sales.txt[0m
} [32m//[0m[32m ends OpenFile()[0m


[32m//[0m[32m FIXME[0m
[35mvoid[0m Dealership::[34mSaveToFile[0m() {
    outputFile.open(customersFilename);
    [35mif[0m([35m![0moutputFile.is_open()) {
        cerr [35m<<[0m customersFilename [35m<<[0m [32m"[0m[32m unable to open for writing![0m[32m"[0m [35m<<[0m endl;
        [35mreturn[0m;
    } [32m//[0m[32m ends if[0m
    [35mfor[0m([35mconst[0m Customer[35m*[0m curr[35m:[0m vecCustomers) {
        outputFile [35m<<[0m [32m"[0m[32mCustomer[0m[32m"[0m [35m<<[0m endl;
        outputFile [35m<<[0m [32m"[0m[32mName:[0m[32m"[0m [35m<<[0m endl [35m<<[0m curr->GetName() [35m<<[0m endl;
        outputFile [35m<<[0m [32m"[0m[32mPhone:[0m[32m"[0m [35m<<[0m endl [35m<<[0m curr->GetPhoneNumber() [35m<<[0m endl;
        outputFile [35m<<[0m [32m"[0m[32mEmail:[0m[32m"[0m [35m<<[0m endl [35m<<[0m curr->GetEmailAddresss() [35m<<[0m endl;
        outputFile [35m<<[0m [32m"[0m[32mInterested:[0m[32m"[0m [35m<<[0m endl [35m<<[0m curr->GetIsInterested() [35m<<[0m endl;
        outputFile [35m<<[0m [32m"[0m[32mBought:[0m[32m"[0m [35m<<[0m endl [35m<<[0m curr->GetBoughtCar() [35m<<[0m endl;
        outputFile [35m<<[0m [32m"[0m[32mVehicle:[0m[32m"[0m [35m<<[0m endl [35m<<[0m curr->GetInterstedVehicle() [35m<<[0m endl;
        outputFile [35m<<[0m [32m"[0m[32mModel:[0m[32m"[0m [35m<<[0m endl [35m<<[0m curr->GetInterestedModel() [35m<<[0m endl;
        outputFile [35m<<[0m endl; [32m//[0m[32m Empty line between customers[0m
    } [32m//[0m[32m ends for[0m
      [32m//[0m[32m Close the customer file[0m
    outputFile.close();

    outputFile.open(vehiclesFilename);
    [35mif[0m([35m![0moutputFile.is_open()) {
        cerr [35m<<[0m vehiclesFilename [35m<<[0m [32m"[0m[32m unable to open for writing![0m[32m"[0m [35m<<[0m endl;
        [35mreturn[0m;
    } [32m//[0m[32m ends if[0m
    [35mfor[0m([35mconst[0m Vehicle[35m*[0m curr[35m:[0m vecVehicles) {
        outputFile [35m<<[0m [32m"[0m[32mVehicle[0m[32m"[0m [35m<<[0m endl;
        outputFile [35m<<[0m [32m"[0m[32mYear:[0m[32m"[0m [35m<<[0m endl [35m<<[0m curr->GetYear() [35m<<[0m endl;
        outputFile [35m<<[0m [32m"[0m[32mMake:[0m[32m"[0m [35m<<[0m endl [35m<<[0m curr->GetMake() [35m<<[0m endl;
        outputFile [35m<<[0m [32m"[0m[32mModel:[0m[32m"[0m [35m<<[0m endl [35m<<[0m curr->GetModel() [35m<<[0m endl;
        outputFile [35m<<[0m [32m"[0m[32mColor:[0m[32m"[0m [35m<<[0m endl [35m<<[0m curr->GetColor() [35m<<[0m endl;
        outputFile [35m<<[0m [32m"[0m[32mDays On Lot:[0m[32m"[0m [35m<<[0m endl [35m<<[0m curr->GetDaysOnLot() [35m<<[0m endl;
        outputFile [35m<<[0m [32m"[0m[32mPrice:[0m[32m"[0m [35m<<[0m endl [35m<<[0m curr->GetPrice() [35m<<[0m endl;
        outputFile [35m<<[0m [32m"[0m[32mVIN:[0m[32m"[0m [35m<<[0m endl [35m<<[0m curr->GetVin() [35m<<[0m endl;
        outputFile [35m<<[0m endl; [32m//[0m[32m Empty line between vehicles[0m
    } [32m//[0m[32m ends for[0m
      [32m//[0m[32m Close the vehicle[0m
    outputFile.close();

    outputFile.open(salesFilename);
    [35mif[0m([35m![0moutputFile.is_open()) {
        cerr [35m<<[0m salesFilename [35m<<[0m [32m"[0m[32m unable to open for writing![0m[32m"[0m [35m<<[0m endl;
        [35mreturn[0m;
    } [32m//[0m[32m ends if[0m
    [35mfor[0m(Sales[35m*[0m curr[35m:[0m vecSales) { [32m//[0m[32m can't be const bc it modifies obj[0m
        outputFile [35m<<[0m [32m"[0m[32mSales[0m[32m"[0m [35m<<[0m endl;
        outputFile [35m<<[0m [32m"[0m[32mSalesman's Name:[0m[32m"[0m [35m<<[0m endl [35m<<[0m curr->GetSalesmanName() [35m<<[0m endl;
        outputFile [35m<<[0m [32m"[0m[32mSale Price:[0m[32m"[0m [35m<<[0m endl [35m<<[0m curr->GetSalesPrice() [35m<<[0m endl;
        outputFile [35m<<[0m [32m"[0m[32mSales By Day: [0m[32m"[0m [35m<<[0m endl [35m<<[0m curr->GetSalesByDay() [35m<<[0m endl;
        outputFile [35m<<[0m [32m"[0m[32mSales By Week:[0m[32m"[0m [35m<<[0m endl [35m<<[0m curr->GetSalesByWeek() [35m<<[0m endl;
        outputFile [35m<<[0m [32m"[0m[32mSales By Month[0m[32m"[0m [35m<<[0m endl [35m<<[0m curr->GetSalesByMonth() [35m<<[0m endl;
        outputFile [35m<<[0m endl;
        cout [35m<<[0m [32m"[0m[32mCustomer[0m[32m"[0m [35m<<[0m endl;
        Customer[35m*[0m customer [35m=[0m curr->GetCustomerObj();
        outputFile [35m<<[0m customer->GetName();
        outputFile [35m<<[0m endl;
        outputFile [35m<<[0m [32m"[0m[32mVehicle[0m[32m"[0m [35m<<[0m endl;
        Vehicle[35m*[0m vehicle [35m=[0m curr->GetVehicleObj();
        outputFile [35m<<[0m vehicle->GetVin();
    } [32m//[0m[32m ends for[0m
    outputFile.close(); [32m//[0m[32m close sale.txt[0m
    cout [35m<<[0m [32m"[0m[32mSAVED[0m[32m"[0m [35m<<[0m endl;
} [32m//[0m[32m ends SaveToFile();[0m

[32m//[0m[32m JUST A TMP METHOD FOR TESTING[0m
[35mint[0m Dealership::[34mBuyCar[0m() {
    string name;
    string vname;
    cout [35m<<[0m [32m"[0m[32mYou want to buy a car?, what is your name?[0m[32m"[0m [35m<<[0m endl;
    getline(cin, name);
    [35mif[0m(FindCustomerIndex(name) [35m==[0m [35m-[0m[33m1[0m) { 
        cerr [35m<<[0m endl [35m<<[0m endl [35m<<[0m [32m"[0m[32mYou are not in the database![0m[32m"[0m [35m<<[0m endl;
        cout [35m<<[0m [32m"[0m[32mbye, bye.[0m[32m"[0m [35m<<[0m endl;
        [35mreturn[0m [33m1[0m;
    } [35melse[0m { 
        Customer[35m*[0m currCustomer [35m=[0m vecCustomers.at(FindCustomerIndex(name));
        cout [35m<<[0m [32m"[0m[32mWhat car would you like to buy?(Type VIN number)[0m[32m"[0m [35m<<[0m endl;
        PrintVehicleInfo();
        getline(cin, vname);
        Vehicle[35m*[0m currVehicle [35m=[0m vecVehicles.at(FindVehicleIndex(vname));
        currCustomer->SetBoughtCar([33mtrue[0m);
        Sales[35m*[0m currSale [35m=[0m [35mnew[0m Sales(currVehicle, currCustomer, [32m"[0m[32mAlex[0m[32m"[0m, [33m10[0m[33m.[0m[33m00[0m, [33m2[0m[33m.[0m[33m32[0m, [33m4[0m[33m.[0m[33m55[0m, [33m500[0m[33m.[0m[33m39[0m);
        vecSales.emplace_back(currSale);
    } [32m//[0m[32m ends if[0m
    [35mreturn[0m [33m0[0m;
} [32m//[0m[32m ends BuyCar()[0m

File: [1msales.cpp[0m
[35m#include[0m [32m"[0m[32msales.h[0m[32m"[0m

Sales::[34mSales[0m([35mconst[0m string[35m&[0m sn, [35mconst[0m [35mdouble[0m[35m&[0m sp, [35mconst[0m [35mdouble[0m[35m&[0m sbd, [35mconst[0m [35mdouble[0m[35m&[0m sbw, [35mconst[0m [35mdouble[0m[35m&[0m sbm) {
    salesmanName [35m=[0m sn;
    salePrice [35m=[0m sp;
    salesByDay [35m=[0m sbd,
    salesByWeek [35m=[0m sbw;
    salesByMonth [35m=[0m sbm;
} [32m//[0m[32m ends paramaterized Sales()[0m
  
Sales::[34mSales[0m(Vehicle[35m*[0m vehicle, Customer[35m*[0m customer, [35mconst[0m string[35m&[0m sn, [35mconst[0m [35mdouble[0m[35m&[0m sp, [35mconst[0m [35mdouble[0m[35m&[0m sbd, [35mconst[0m [35mdouble[0m[35m&[0m sbw, [35mconst[0m [35mdouble[0m[35m&[0m sbm) {
    tmpCust [35m=[0m customer;
    tmpVehic [35m=[0m vehicle;
    salesmanName [35m=[0m sn;
    salePrice [35m=[0m sp;
    salesByDay [35m=[0m sbd,
    salesByWeek [35m=[0m sbw;
    salesByMonth [35m=[0m sbm;
} [32m//[0m[32m ends paramaterized Sales()[0m

Sales::[34m~Sales[0m() {
    cout [35m<<[0m [32m"[0m[32mSALES DESTRUCTOR CALLED[0m[32m"[0m [35m<<[0m endl;
}

[32m//[0m[32m SETTERS AND GETTERS[0m

Customer[35m*[0m Sales::[34mGetCustomerObj[0m() {
    [35mreturn[0m tmpCust;
}

Vehicle[35m*[0m Sales::[34mGetVehicleObj[0m() {
    [35mreturn[0m tmpVehic;
}


[35mvoid[0m Sales::[34mSetSalesPrice[0m([35mconst[0m [35mdouble[0m[35m&[0m price) {
    this->salePrice [35m=[0m price;
}

[35mdouble[0m Sales::[34mGetSalesPrice[0m() [35mconst[0m {
    [35mreturn[0m salePrice;
}

[35mvoid[0m Sales::[34mSetSalesByDay[0m([35mconst[0m [35mdouble[0m[35m&[0m sbd) {
    this->salesByDay [35m=[0m sbd;
}

[35mdouble[0m Sales::[34mGetSalesByDay[0m() [35mconst[0m {
    [35mreturn[0m salesByDay;
}

[35mvoid[0m Sales::[34mSetSalesByWeek[0m([35mconst[0m [35mdouble[0m[35m&[0m sbw) {
    this->salesByWeek [35m=[0m sbw;
}

[35mdouble[0m Sales::[34mGetSalesByWeek[0m() [35mconst[0m {
    [35mreturn[0m salesByWeek;
}

[35mvoid[0m Sales::[34mSetSalesByMonth[0m([35mconst[0m [35mdouble[0m[35m&[0m sbm) {
    this->salesByMonth [35m=[0m sbm;
}

[35mdouble[0m Sales::[34mGetSalesByMonth[0m() [35mconst[0m {
    [35mreturn[0m salesByMonth;
}

[35mvoid[0m Sales::[34mSetSalesmanName[0m([35mconst[0m string[35m&[0m sn) {
    salesmanName [35m=[0m sn;
}

string Sales::[34mGetSalesmanName[0m() {
    [35mreturn[0m salesmanName;
}

File: [1mvehicle.cpp[0m
[35m#include[0m [32m"[0m[32mvehicle.h[0m[32m"[0m

[32m//[0m[32m Constructors and Destructor[0m
Vehicle::[34mVehicle[0m() {
    cout [35m<<[0m [32m"[0m[32mVEHICLE DEFAULT CONSTRUCTOR CALLED[0m[32m"[0m [35m<<[0m endl;
} [32m//[0m[32m ends Vehicle()[0m

Vehicle::[34mVehicle[0m([35mconst[0m [35mint[0m[35m&[0m yearCon, [35mconst[0m string[35m&[0m makeCon, [35mconst[0m string[35m&[0m modelCon, [35mconst[0m string[35m&[0m colorCon, [35mconst[0m [35mint[0m[35m&[0m daysOnLotCon, [35mconst[0m [35mdouble[0m[35m&[0m priceCon, [35mconst[0m string[35m&[0m vinCon) {
    year [35m=[0m yearCon;
    make [35m=[0m makeCon;
    model [35m=[0m modelCon;
    color [35m=[0m colorCon;
    daysOnLot [35m=[0m daysOnLotCon;
    price [35m=[0m priceCon;
    vin [35m=[0m vinCon;
} [32m//[0m[32m ends paramaterized Vehicle()[0m

Vehicle::[34mVehicle[0m(Vehicle[35m*[0m other) {
    year [35m=[0m other->year;
    make [35m=[0m other->make;
    model [35m=[0m other->model;
    color [35m=[0m other->color;
    daysOnLot [35m=[0m other->daysOnLot;
    price [35m=[0m other->price;
    vin [35m=[0m other->vin;
}

Vehicle::[34m~Vehicle[0m() {
    cout [35m<<[0m [32m"[0m[32mVEHICLE DESTRUCTOR CALLED[0m[32m"[0m [35m<<[0m endl;
} [32m//[0m[32m ends ~Vehicle()[0m

[32m//[0m[32m ALL SETTERS AND GETTERS[0m
[35mvoid[0m Vehicle::[34mSetYear[0m([35mconst[0m [35mint[0m[35m&[0m yearSet) {
    this->year [35m=[0m yearSet;
}

[35mint[0m Vehicle::[34mGetYear[0m() [35mconst[0m {
    [35mreturn[0m year;
}

[35mvoid[0m Vehicle::[34mSetMake[0m([35mconst[0m string[35m&[0m makeSet) {
    this->make [35m=[0m makeSet;
}

string Vehicle::[34mGetMake[0m() [35mconst[0m {
    [35mreturn[0m make;
}

[35mvoid[0m Vehicle::[34mSetModel[0m([35mconst[0m string[35m&[0m modelSet) {
    this->model [35m=[0m modelSet;
}

string Vehicle::[34mGetModel[0m() [35mconst[0m {
    [35mreturn[0m model;
}

[35mvoid[0m Vehicle::[34mSetColor[0m([35mconst[0m string[35m&[0m colorSet) {
    this->color [35m=[0m colorSet;
}

string Vehicle::[34mGetColor[0m() [35mconst[0m {
    [35mreturn[0m color;
}

[35mvoid[0m Vehicle::[34mSetDaysOnLot[0m([35mconst[0m [35mint[0m[35m&[0m daysOnLotSet) {
    this->daysOnLot [35m=[0m daysOnLotSet;
}

[35mint[0m Vehicle::[34mGetDaysOnLot[0m() [35mconst[0m {
    [35mreturn[0m daysOnLot;
}

[35mvoid[0m Vehicle::[34mSetPrice[0m([35mconst[0m [35mdouble[0m[35m&[0m priceSet) {
    this->price [35m=[0m priceSet;
}

[35mdouble[0m Vehicle::[34mGetPrice[0m() [35mconst[0m {
    [35mreturn[0m price;
}

[35mvoid[0m Vehicle::[34mSetVin[0m([35mconst[0m string[35m&[0m vinSet) {
    this->vin [35m=[0m vinSet;
}

string Vehicle::[34mGetVin[0m() [35mconst[0m {
    [35mreturn[0m vin;
}
