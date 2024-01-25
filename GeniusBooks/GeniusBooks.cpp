#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

int main();

// Define a structure for books items
struct BooksItem {
	std::string name;
	std::string author;
	double price = 10;
	int qty = 1;
};

//FileName
const std::string filename = "books.txt";

// Function to display the main menu
void displayMenu() {
	cout << "\nGeniusBooks Management System\n";
	cout << "1. View Books\n";
	cout << "2. Add Books\n";
	cout << "3. Manage Books\n";
	cout << "4. Manage Sales Details\n";
	cout << "5. View Company Details\n";
	cout << "6. Logout\n";
	cout << "7. Exit\n";
	cout << "Enter your choice: ";
}

//Save Data In to TXT
void SaveDataTxt(const std::vector<BooksItem>& bookscache) {
	std::ofstream outFile(filename);
	if (outFile.is_open()) {
		for (const BooksItem& item : bookscache)
		{
			outFile << "Name: " << item.name << ", Author: " << item.author << ", Price: " << item.price << ", QTY: " << item.qty << "\n";

		}
		outFile.close();
		std::cout << "Books Saved to " << filename << ". \n";
	}
	else
	{
		std::cerr << "Unable to Open file for writing. \n";
	}
}


//Read Data 
void ReadDataTxt() {
	std::string line;
	ifstream file(filename);
	cout << "\n";
	while (getline(file, line)) {
		cout << line << "\n";
	}
	file.close();
}

struct User {
	std::string username;
	std::string password;
};

void ExitSystem() {
	cout << "Exiting the GeniusBooks Management System.\n";
	exit(0);
}

//ManageSalesDetails
void ManageSales() {
	int getchoice;
	cout << "1. View Sales Details\n";
	cout << "2. Go Back\n";
	cout << "3. Exit\n";
	cin >> getchoice;

	switch (getchoice)
	{
	case 1:
		cout << "Sales Details\n";
		cout << "--------------------------\n";
		cout << "Sales: 2000 Books\n";
		cout << "Profit: 25000LKR\n";
		cout << "--------------------------\n";
		break;
	case 2:
		break;
	case 3:
		ExitSystem();
	default:
		std::cout << "Invalid choice. Please try again.\n";
		break;
	}
}


//View Company Details
void ViewCompanyDetails() {
	int getchoice;
	cout << "Company Details\n";
	cout << "--------------------------\n";
	cout << "Name: Genius Books\n";
	cout << "Location: UK\n";
	cout << "About: GENIUS BOOKS : Elevating Minds, Enriching Souls, Literary Excellence Unleashed. \n";
	cout << "--------------------------\n";
	cout << "1. Go Back\n";
	cout << "2. Exit\n";
	cout << "Enter your choice: ";
	cin >> getchoice;

	if (getchoice == 1)
	{
		main();
	}
	else if(getchoice == 2)
	{
		ExitSystem();
	}
	else
	{
		exit(0);
	}

}

//Function to display available Books details 
void displayBooksItems() {
	std::cout << "Available Books:\n";
	ReadDataTxt();
}

std::vector<BooksItem> bookscache;
// Function to add a new books item
void addBooksItem(std::vector<BooksItem>& bookscache) {
	BooksItem newItem;
	std::cout << "Enter Book name: ";
	std::cin >> newItem.name;
	std::cout << "Enter Book author: ";
	std::cin >> newItem.author;
	std::cout << "Enter Book Price: ";
	std::cin >> newItem.price;
	std::cout << "Enter Book Qty: ";
	std::cin >> newItem.qty;
	//items.push_back(newItem);
	bookscache.push_back(newItem);
	SaveDataTxt(bookscache);
	std::cout << "Book Added and System Updated Successfully. \n";

}

bool loggedIn = false;

void login() {
	//Define Hardcoded Username And Password (Replace with a  proper authentication system)
	std::string correctUsername = "1";
	std::string correctPassword = "1";
	string username, password;
	User currentUser;
	cout << "Welcome To the Genius Books Login System!\n";
	cout << "Username: ";
	cin >> currentUser.username;
	cout << "Password: ";
	cin >> currentUser.password;
	//Check if the provided username and password match the correct ones
	if (currentUser.username == correctUsername && currentUser.password == correctPassword) {
		cout << "Login Successfull. Welcome, " << currentUser.username << "!\n";
		loggedIn = true;
	}
	else
	{
		loggedIn = false;
		cout << "Login Failed. Please Check your username and password\n";
		login();
	}

}


void logout() {
	bool loggedIn = false;
	cout << "Logged out.\n";
	login();
}

// Function to remove a Books by name from a text file
void removeBooksItemByName(const std::string& itemName) {
	std::ifstream inFile(filename);
	bool found = false;

	if (!inFile.is_open()) {
		std::cerr << "Unable to open file for reading.\n";
		return;
	}

	BooksItem item;
	while (inFile >> item.name) {
		if (item.name == itemName) {
			bookscache.push_back(item);
		}
		else {
			found = true;
		}
	}

	inFile.close();

	if (!found) {
		std::cout << "Book not found in the file.\n";
		return;
	}

	std::ofstream outFile(filename);
	if (!outFile.is_open()) {
		std::cerr << "Unable to open file for writing.\n";
		return;
	}

	for (const BooksItem& newItem : bookscache) {
		outFile << newItem.name << " " << newItem.author << " " << newItem.price << " " << newItem.qty << "\n";
	}

	outFile.close();

	std::cout << "Book removed successfully.\n";
	return;
}

void clearCache(std::vector<BooksItem>& cache) {
	cache.clear();
	std::cout << "Cache Cleared. All Books Removed\n";
}

void clearBookCache(std::vector<BooksItem>& bookscache) {
	bookscache.clear();
	std::cout << "Cache Cleared. All Books Removed\n";
}

//Function to Manage Books
void ManageBooksItem(std::vector<BooksItem> bookscache) {
	int getchoice;
	cout << "1. Remove Books\n";
	cout << "2. Go Back\n";
	cout << "3. Exit\n";
	std::cout << "Enter Your Choice: ";
	cin >> getchoice;
	std::string itemName;
	switch (getchoice)
	{
	case 1:
		std::cout << "Enter Item Name: ";
		cin >> itemName;
		removeBooksItemByName(itemName);
		break;
	case 2:
		break;
	case 3:
		ExitSystem();
	default:
		std::cout << "Invalid choice. Please try again.\n";
		ManageBooksItem(bookscache);
	}
}


int main()
{
	std::vector<BooksItem> bookscache;
	while (true) {
		if (loggedIn == true) {
			//std::vector<SalesTransaction> salesTransactions;

			int choice;


			displayMenu();
			cin >> choice;

			switch (choice) {
			case 1:
				// View Books
				// Implement logic to display Books
				// View Books
				displayBooksItems();
				break;
			case 2:
				// Add Books
				// Implement logic to add new Books
				addBooksItem(bookscache);
				break;
			case 3:
				// Manage Books
				// Implement logic to create and manage Books
				ManageBooksItem(bookscache);
				break;
			case 4:
				// Manage Sales Details
				// Implement logic to manage sales transactions
				ManageSales();
				break;
			case 5:
				// View Company Details
				// Implement logic to display company information
				ViewCompanyDetails();
				break;
			case 6:
				// Logout
				logout();
				break;
			case 7:
				// Exit the program
				ExitSystem();
				break;
			default:
				cout << "Invalid choice. Please try again.\n";
			}
		}
		else
		{
			login();
		}
	}
}

