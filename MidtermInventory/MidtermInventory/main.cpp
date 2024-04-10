#include <iostream>
#include <fstream>
#include <string>

using namespace std;
//structs
struct Date {
	int month;
	int day;
	int year;
};
struct Item {
	string description;
	int quantity;
	float wsCost;
	float retailCost;
	Date dateAdded;
};
//----------- function declerations
void printMenu();
void getItem(Item* i);
void displayItem(Item* itemPtr);

int main() {
	char choice = ' ';
	bool again = true;
	bool found = false;
	int linePos = 0;
	string lookUp = "";
	Item newItem;
	Item* itemPtr = &newItem;

	fstream ioFile;
	ioFile.open("InventoryList.txt", ios::in | ios::out);

	//exit program if error opening file
	if (!ioFile) {
		cout << "Error opening the file.\n\n";
		return 0;
	}

	//main program loop
	while (again)
	{
		//prompt user and recieve option 
		do {
			printMenu();
			cin >> choice;
		} while (choice != '1' && choice != '2' && choice != '3');

		switch (choice) {
			//===========================================
			//			Case 1: Add Item
			//===========================================
		case '1':
			//ask user for details
			getItem(&newItem);
			//add to file
			ioFile.clear();
			ioFile.seekg(0, ios::end);

			ioFile << newItem.description << endl;
			ioFile << newItem.quantity << endl;
			ioFile << newItem.wsCost << endl;
			ioFile << newItem.retailCost << endl;
			ioFile << newItem.dateAdded.month << endl << newItem.dateAdded.day << endl << newItem.dateAdded.year << endl;

			ioFile.seekg(0, ios::beg);
			cout << "Item Added to File!\n\n";
			break;
			//===========================================
			//		Case 2: Search and Print Item Data
			//===========================================
		case '2':
			cout << "Display Data." << endl;
			cout << "Enter the name of the Item you'd like to look up:" << endl;
			cin >> lookUp;

			ioFile.clear();
			ioFile.seekg(0, ios::beg);

			while (getline(ioFile, newItem.description)) {
				//if description matches, print out all of its info
				if (newItem.description == lookUp) {
					ioFile >> newItem.quantity >> newItem.wsCost >> newItem.retailCost >> newItem.dateAdded.month >> newItem.dateAdded.day >> newItem.dateAdded.year;
					displayItem(&newItem);
					found = true;
				}
			}//end of file scan
			if (!found){
				cout << "Item not found.\n\n";
			}
			break;
			//===========================================
			//		Case 3: Find and Edit Data
			//===========================================
		case '3':
			cout << "Edit an Item." << endl;
			cout << "Enter the name of the item you would like to edit:\n";
			cin >> lookUp;

			ioFile.clear();
			ioFile.seekg(0, ios::beg);

			while (getline(ioFile, newItem.description)) {
				if (newItem.description == lookUp) {					
					// Prompt user for new data
					cout << "Enter the new data for the item: ";
					ioFile.seekp(ioFile.tellg()); //go to beginning of the "struct" in the file
					getItem(&newItem);
					// Write new data to file
					ioFile << newItem.description << endl;
					ioFile << newItem.quantity << endl;
					ioFile << newItem.wsCost << endl;
					ioFile << newItem.retailCost << endl;
					ioFile << newItem.dateAdded.month << endl << newItem.dateAdded.day << endl << newItem.dateAdded.year << endl;
					cout << "Item data updated.\n\n";
					found = true;
				}
			}
			if (!found)
				cout << "Item not found.\n\n";
			break;
		default:
			cout << "invalid option.\n\n";
			choice = 9;
			break;
		}

		if (choice == '9')
			again = false;
		else {
			found = false; // if the user wants to use the program more, this piece must be false for cases 2,3 by default
			cout << "enter any character to continue using the system.\nEnter 9 to Exit." << endl;
			cin >> choice;
			if (choice == '9')
				again = false;
		}
	}

	ioFile.close();
	return 0;
}//end of main

//functions--------------------------------------------------------------------------

//print function
void printMenu() {
	cout << "-------------------------------------\n";
	cout << "Inventory System: Would you like to:\n";
	cout << "1. Add a new item\n";
	cout << "2. Display any item data\n";
	cout << "3. Edit an item \n";
	cout << "-------------------------------------\n";
}//end of print function

//display data function
void displayItem(Item* itemPtr) {
	cout << "Item: " << itemPtr->description << endl;
	cout << "Quantity: " << itemPtr->quantity << endl;
	cout << "Wholesale Cost: " << itemPtr->wsCost << endl;
	cout << "Retail Cost: " << itemPtr->retailCost << endl;
	cout << "Date Added: " << itemPtr->dateAdded.month << "/" << itemPtr->dateAdded.day << "/" << itemPtr->dateAdded.year << "\n\n";
}//end of display function

//input new data function (uses pointer)
void getItem(Item* itemPtr) {

	cout << "Add Item." << endl;
	cout << "Enter the name of the Item:\n";
	cin >> itemPtr->description;
	//ask user for quantity 
	do {
		cout << "Enter the quantity on hand:\n";
		cin >> itemPtr->quantity;
		if (itemPtr->quantity < 0)
			cout << "Please enter a positive number\n";
	} while (itemPtr->quantity < 0);
	//ask for wholesale cost
	do {
		cout << "Enter the Wholesale Cost:\n";
		cin >> itemPtr->wsCost;
		if (itemPtr->wsCost < 0)
			cout << "Please enter a positive number\n";
	} while (itemPtr->wsCost < 0);
	//ask for retail cost
	do {
		cout << "Enter the Retail Cost:\n";
		cin >> itemPtr->retailCost;
		if (itemPtr->retailCost < 0)
			cout << "Please enter a positive number\n";
	} while (itemPtr->retailCost < 0);

	//ask for date
	do {
		cout << "Enter today's day:\n";
		cin >> itemPtr->dateAdded.day;
	} while (itemPtr->dateAdded.day > 31 || itemPtr->dateAdded.day <= 0);
	do {
		cout << "Enter this month:\n";
		cin >> itemPtr->dateAdded.month;
	} while (itemPtr->dateAdded.month > 12 || itemPtr->dateAdded.month <=0);
	do {
		cout << "Enter the year:\n";
		cin >> itemPtr->dateAdded.year;
	} while (itemPtr->dateAdded.year < 2024);
}//end of adding data
