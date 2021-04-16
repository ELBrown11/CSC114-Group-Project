

#include <iostream>
#include <iomanip>
#include<fstream>
using namespace std;

//function prototype
void DisplayMenu();
void totalTicketSale();
void storeRowPrices();
void purchaseTickets();
void numTicketSold();
void rowAvailability();

const int x = 30;           //Number of columns used for seating chart array
const int y = 15;           //Number of rows used for seating chart array
char seatingChart[x][y];    //Seating chart array (x = columns, y = rows)
void displayChart();        //Seating chart function
char Available = '#';       //Symbol used for an available seat
char Taken = '*';           //Symbol used for a taken seat

// constants for menu values
const int PURCHASE = 1,
TOATL_TIX_SALES_DOLS = 2,
TOTAL_TIX_SOLD = 3,
SEAT_AVAILABILITY_ROWS = 4,
SEAT_AVAILABILITY_AUD = 5,
EXIT_CHOICE = 6;
// choice variable for user input
int choice ;


int main()
{
	
	storeRowPrices();
	
	for (int rows = 0; rows < x; rows++)
	{
		for (int columns = 0; columns < y; columns++)
			seatingChart[rows][columns] = Available;
	}

	displayChart();

	do
	{
		DisplayMenu();

		
		




	} while (choice != EXIT_CHOICE);
	return 0;
	//Use these variables to test mapping seat availibilty into the seatingChart array
	int ROW = 14;
	int COLUMN = 29;

	//Set initial value of all seats to "Available" (#)


	seatingChart[ROW][COLUMN] = Taken;

	//Main menu would call for Seating chart, displayChart input condition would go true (example: if menu = 4 , then run displayChart function)
	displayChart();
	return 0;
}
//displayChart function definition
void displayChart() {

	//Seating chart array header/column numbers
	cout << "         1| 2| 3| 4| 5| 6| 7| 8| 9|10|11|12|13|14|15|16|17|18|19|20|21|22|23|24|25|26|27|28|29|30" << endl;
	cout << "         ----------------------------------------------------------------------------------------";

	//Double nested for loop generates 15 rows and 30 columns
	//Added the word Row at the beginning of each line within the seating chart array
	//std::setw(2) is used for y axis header alignment of the seating chart
	for (int row = 0; row < 15; row++) {
		cout << endl;
		cout << "Row: " << setw(2) << row + 1;

		//Added 2 spaces into the array for each seat to help with seating availability alignment
		for (int column = 0; column < 30; column++) {
			cout << "  " << seatingChart[row][column];
		}
	}
}

//***********************************************************
// Defintion of function DisplayMenu shows the menu options *
//***********************************************************

void DisplayMenu()
{
	cout << "\nTheather Options Menu\n\n"
		<< "1. Purchase Tickets\n"
		<< "2. Total Ticket Sales in Dollars\n"
		<< "3. Total Number of Tickets Sold\n"
		<< "4. Seat Availability in Each Row\n"
		<< "5. Seat Availability in Auditorium\n"
		<< "6. Exit\n"
		<< "Enter your choice: ";
	cin >> choice;
	
	while (choice < PURCHASE || CHOICE > EXIT_CHOICE)
	{
		cout << "Please enter a valid menu choice: ";
		cin >> choice;
	}
	
	switch (choice)
	{
	case PURCHASE: 
	{
		purchaseTickets()
		break;
	}

	case TOTAL_TIX_SALES_DOLS:
	{
		totalTicketSale();
		break;
	}

	case TOTAL_TIX_SOLD:
		numTicketSold();
		break;

	case SEAT_AVAILABILITY_ROWS:
		//seat avaiablity row function
		break;
	case SEAT_AVAILABILITY_AUD:
		//seat availablity auditorium function
	}


}

void numTicketSold()
{
	int totalSold = 0;

	for (int rowCounter = 0; rowCounter < 30; rowCounter++)
	{
		for (int colCounter = 0; colCounter < 15; colCounter++)
		{
			if (seatingChart[rowCounter][colCounter] == '*')
			{
				totalSold += 1;
			}
		}
	}

	cout << "The current number of tickets sold is " << totalSold << ".\n";
}



//Get seat info from user (Asma)

void purchaseTickets()
{
	int userSeats = 0,
		userRow = -1,
		userCol = -1,
		seatEnd = 0;

	int NumOfSeats;
	int RowNum;
	int ColNum;
	int rowAvailable = 0;
	
	while (userSeats <= 0)
	{
		cout << "How many seats would you like to purchase? ";
		cin >> userSeats;

		if (userSeats <= 0)
		{
			cout << "Please choose 1 or more seats.\n";
		}
	}

	while (rowAvailable < userSeats)
	{
		while (userRow - 1 < 0 || userRow - 1 > x)
		{
			cout << "In which row would you like to sit? ";
			cin >> userRow;

			if (userRow - 1 < 0 || userRow - 1 < x)
			{
				cout << "You have selected an invalid row number, please try again.\n";
			}
		}

		for (int numY = 0; numY < y; numY++)
		{
			if (seatingChart[userRow - 1][numY] == '#')
				rowAvailable += 1;
		}

		if (rowAvailable < userSeats)
			cout << "There are not enough seats available in this row, please pick another row.\n";
	}

	cout << "Row " << userRow << " has seats ";

	for (int countCol = 0; countCol < x; countCol++)
	{
		if (seatingChart[userRow - 1][countCol] == '#')
		{
			cout << countCol + 1 << ", ";
		}
	}

	cout << " available.\n";

	while (seatEnd <= 0)
	{
		while (userCol - 1 < 0 || userCol - 1 > x || seatingChart[userRow - 1][userCol - 1] == '*')
		{
			cout << "What seat number would you like to sit at? ";
			cin >> userCol;

			if (userCol - 1 < 0 || userCol - 1 > x || seatingChart[userRow - 1][userCol - 1] == '*')
			{
				cout << "You have chosen an invalid or taken seat number, please try again.\n";
			}
		}
		seatingChart[userRow - 1][userCol - 1] = '*';
		seatEnd++;
	}


	if (userSeats > 1)
	{
		while (seatEnd < userSeats)
		{
			userCol = 0;

			while (userCol - 1 < 0 || userCol - 1 > x || seatingChart[userRow - 1][userCol - 1] == '*')
			{
				cout << "What is the next seat number would you like to sit at? ";
				cin >> userCol;

				if (userCol - 1 < 0 || userCol - 1 > x || seatingChart[userRow - 1][userCol - 1] == '*')
				{
					cout << "You have chosen an invalid or taken seat number, please try again.\n";
				}
			} 

			seatingChart[userRow - 1][userCol - 1] = '*';
			seatEnd++;
		}

	}


	do
	{
		cout << "What seat number would you like to sit? ";
		cin >> userCol;

		if (seatingChart[userRow - 1][userCol - 1] == '*')
		{
			cout << "That seat is not available, please try again.\n"
		}

	} while (seatingChart[userRow - 1][userCol - 1] == '*')









	for (int num_seats_available = 0; num_seats_available < userSeats)
	{

	}
	while ()
	{



		if (userRow - 1 < 0 || userRow - 1 > 14)
		{
			cout << "Please choose a row number between 1 and 15.\n";
		}

		if ()
	}


	do 
	{
		
		cout << "What seat number would you like to sit? ";
		cin >> userCol;
		cout << "In which row would you like to sit? ";
		cin >> userRow;



		while (seatingChart[userRow - 1][userCol - 1] == '*')
		{
			cout << "This seat is currently unavailable.\n";
			cout << "What seat number would you like to sit? ";
			cin >> userCol;
		}
		seatingArray[userRow - 1][userCol - 1] = '*';

		for (int counter = 0; counter + 1 < userSeats; counter++)
		{
			cout << "Please pick your next seat number: ";
			cin >> userCol;
			seatingArray[userRow - 1][userCol - 1] = '*';
		}

	} while (seatingArray[userRow - 1][userCol - 1] == '*');

	for (int counter = 0; counter < userSeats; counter++) {
		
		seatingArray[userRow-1][] = '*';
	}


	if (NumOfSeats == 1)
	{
		seatingArray[RowNum][ColNum]

	}
}

void storeRowPrices() {
	//priceArray to temporarily store user declared values to later load into file
	double priceArray[15];

	cout << "Welcome to DTCC Theater!\n";

	//for loop to cycle through each row/array element while prompting user for price of each row
	for (int counter = 0; counter < 15; counter++) {

		while (priceArray[counter] < 0) {

			cout << "Please enter the cost for a seat in row " << counter + 1 << ": $";
			cin >> priceArray[counter];

			if ((priceArray[counter] < 0)) {
				cout << "Please enter a non-negative value.\n";
			}
		}
	}

	//define and open file for output, searches for/creates text file named "prices.txt"
	ofstream outputFile("prices.txt");

	//for loop to iterate through each array element and write to file with endline separating each entry
	for (int counter = 0; counter < 15; counter++) {
		outputFile << priceArray[counter] << endl;
	}

	//close outputFile
	outputFile.close();

	cout << endl;
}

void totalTicketSale()
{

	double total = 0, priceArray[15];
	//define and open "prices.txt" as inputFile
	ifstream inputFile("prices.txt");

	//for fill array with pricing info from file
	for (int rowCounter = 0; rowCounter < 15; rowCounter++)
	{
		inputFile >> priceArray[rowCounter];
	}

	//increment through 2D array, every time a seat is shown as taken the price for that particular row is added to the running total of "total"
	for (int seatCounter = 0; seatCounter < 30; seatCounter++)
	{
		for (int rowCounter = 0; rowCounter < 15; rowCounter++)
		{
			if (seatingChart[seatCounter][rowCounter] == '*')
			{
				total += priceArray[rowCounter];
			}
		}
	}

	//close inputFile
	inputFile.close();

	cout << "The current total is $" << fixed << setprecision(2) << total << endl;
}

void rowAvailability()
{
	for (int countRow = 0; countRow < y; countRow++)
	{
		cout << "Row " << countRow + 1 << " has seats ";

		for (int countCol = 0; countCol < x; countCol++)
		{

			if (seatingChart[countRow][countCol] == '#')
			{
				cout << countCol + 1 << ", ";
			}
		}

		cout << " available.\n";
	}
}
