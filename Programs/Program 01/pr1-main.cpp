// Harley Coxon	    		     Program 1	    		     CMPS 2433	    		     Spring 2026
// **********************************************************************************************************
// Name: Harley Coxon																						

// Course: CMPS 2433 Discrete Structures & Analysis, Spring 26, Stringfellow     

// Purpose: This program uses 6 functions to edit or view permissions. Using constant 
// shorts to represent a permission mask. Each function uses the masks and bitwise
// operations to edit or view permissions. Main function controls user interaction. 
// **********************************************************************************************************

#include <iomanip>
#include <iostream>
using namespace std;

// **********************************************************************************************************
// *                                        FUNCTION PROTOTYPES                                             *
// **********************************************************************************************************

unsigned short givePermission(unsigned short current, unsigned short type);
unsigned short removePermission(unsigned short current, unsigned short type);
unsigned short togglePermission(unsigned short current, unsigned short type);
void checkPermission(unsigned short current, unsigned short mask);
void displayPermissions(unsigned short current);
void header();

// GLOBAL CONSTANT MASKS USING SHIFTS 
const unsigned short READ = 1 << 0;
const unsigned short WRITE = 1 << 1;
const unsigned short EXEC = 1 << 2;

// **********************************************************************************************************
// *                                            MAIN FUNCTION                                               *
// **********************************************************************************************************
int main()
{
	// call header to display welcome message 
	header();
	cout << "\n";
	// main user variables 
	int userinput;
	// permissions auto set to 0000
	unsigned short my_permissions = 0;
	// display current permissions 
	cout << "Current Permissions: "; 
	displayPermissions(my_permissions); 
	cout << "\n"; 

	// display options 
	cout << left << setw(20) << "1) Add Read" << left << setw(20) << "5) Check Read" << endl;
	cout << left << setw(20) << "2) Remove Read" << left << setw(20) << "6) Check Write" << endl;
	cout << left << setw(20) << "3) Add Write" << left << setw(20) << "7) Toggle Exec" << endl;
	cout << left << setw(20) << "4) Remove Write" << left << setw(20) << "8) Exit" << endl;

	// Switch case takes an INTEGER as user input and matches to case.
	// Each case calls respective function 
	// default case (any input besides 1-8) will prompt user to try again
	// loop 
	
	// **************************************************************************************************
	// *                                          USER INTERFACE                                        *
	// **************************************************************************************************	
	do
	{
		cout << "\nEnter an integer option: \n";
		cout << ">";
		cin >> userinput;

		switch (userinput)
		{
			// Option 1 Add Read
		case 1:
			my_permissions = givePermission(my_permissions, READ);
			// confirm choice with user
			cout << "ADDED READ\n";
			cout << "Current permissions: ";
			displayPermissions(my_permissions);
			break;

			// Option 2 Remove Read
		case 2:
			my_permissions = removePermission(my_permissions, READ);
			// confirm choice with user
			cout << "REMOVED READ\n";
			cout << "Current permissions: ";
			displayPermissions(my_permissions);
			break;

			// Option 3 Add Write
		case 3:
			my_permissions = givePermission(my_permissions, WRITE);
			// confirm choice with user
			cout << "ADDED WRITE\n";
			cout << "Current permissions: ";
			displayPermissions(my_permissions);
			break;

			// Option 4 Remove write 
		case 4:
			my_permissions = removePermission(my_permissions, WRITE);
			// confirm choice with user
			cout << "REMOVED WRITE\n";
			cout << "Current permissions: ";
			displayPermissions(my_permissions);
			break;

			// Option 5 Check Read
		case 5:
			cout << "Read ";
			checkPermission(my_permissions, READ);
			cout << "Current permissions: ";
			displayPermissions(my_permissions);
			break;

			// Option 6 Check Write 
		case 6:
			cout << "Write ";
			checkPermission(my_permissions, WRITE);
			cout << "Current permissions: ";
			displayPermissions(my_permissions);
			break;

			// Option 7 toggle execute 
		case 7:
			my_permissions = togglePermission(my_permissions, EXEC);
				// confirm choice with user
			if (my_permissions & EXEC)
				cout << "TOGGLED EXECUTE ON\n";
			else
				cout << "TOGGLED EXECUTE OFF\n";
			cout << "Current permissions: ";
			displayPermissions(my_permissions);
			break;

			// Exit program when an 8 or 0 is entered by user
		case 8:  
		case 0:  
			cout << "\nExiting Permissions Manager\nFinal permissions: ";
			displayPermissions(my_permissions);
			cout << "\nGoodbye :)" << endl;
			break;

		default:
			cout << "Invalid option. Please try again.\n";
			break;
		}

	// loops until 8 or 0 is entered by user 
	} while (userinput != 8 && userinput != 0);
} // end of main 

// **********************************************************************************************************
// *                                           FUNCTION DEFINITIONS                                         *
// **********************************************************************************************************

//FUNCTION: checkPermission
//INPUT: unsigned short, selected mask
//PROCESS: comapares current bits to selected mask bits using bitwise AND operator 
//RETURNS: NONE
void checkPermission(unsigned short current, unsigned short mask)
{
	if ((current & mask) != 0)
		cout << "permission ON" << endl;
	else
		cout << "no permission granted" << endl;
}

//FUNCTION: givePermission
//INPUT: unsigned short, selected mask type
//PROCESS: compares current bits with type bits using bitwise OR  
//RETURNS: unsigned short 
// this function will add specified permissions to the current permission
unsigned short givePermission(unsigned short current, unsigned short type)
{
	current |= type;
	return current;
};

//FUNCTION: removePermission
//INPUT: unsigned short, selected mask type
//PROCESS: &= will remove permission then negation flips the bits (any mathcing bits will become 0) 
//RETURNS: unsigned short 
unsigned short removePermission(unsigned short current, unsigned short type)
{
	current &= ~type; 
	return current; 
};

//FUNCTION: togglePermission
//INPUT: unsigned short, selected mask type
//PROCESS: takes currents bits and compares using bitwise XOR to flip the desired bit
//RETURNS: unsigned short 
unsigned short togglePermission(unsigned short current, unsigned short type)
{
	current ^= type;
	return current;
};

//FUNCTION: header
//INPUT: NONE
//PROCESS: prints header and program welcome 
//RETURNS: NONE
void header()
{
	cout << left << setw(20) << "Harley Coxon" << "Program 1" << endl; 
	cout << "CMPS 2433 Discrete Structures\n";
	cout << "\nWelcome to the Bitwise Permissions Manager!\n"; 
};

//FUNCTION: displayPermissions
//INPUT: unsigned short current
//PROCESS: prints current permissions in binary using a for loop & displays current perms after each case.
//RETURNS: NONE
void displayPermissions(unsigned short current)
{
	// takes current bits and right shifts by i bits each iteration. 
	// comparing to 1 using bitwise AND to go thru each bit 
	for (int i = 7; i >= 0; i--)
	{
		cout << ((current >> i) & 1);
	}

	// display current READ permission
	cout << " (Read: ";
	if (current & READ)
		cout << "ON, ";
	else
		cout << "OFF, ";

	// display current READ permission
	cout << "Write: ";
	if (current & WRITE)
		cout << "ON, ";
	else
		cout << "OFF, ";

	// display current READ permission
	cout << "Execute: ";
	if (current & EXEC)
		cout << "ON)\n";
	else
		cout << "OFF)\n";
};
//end of program 1 :)