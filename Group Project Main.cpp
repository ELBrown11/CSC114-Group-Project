/*
CSC114-4C2
Group Project
Asma Rehman, Eboni Brown, Kenneth Navarro, Sammy Eyong, Trevor Brinton
*/

#include <iostream>
#include <iomanip>
#include<fstream>
using namespace std;

//function prototype
void DisplayMenu();      //Eboni + group
void totalTicketSale();  //Ken + group
void storeRowPrices();   //Sammy + Ken
void purchaseTickets();  //group
void numTicketSold();    //Asma
void rowAvailability();  //group
void displayChart();     //Trevor

const int x = 30;           //Number of columns used for seating chart array
const int y = 15;           //Number of rows used for seating chart array
char seatingChart[x][y];    //Seating chart array (x = columns, y = rows)
char Available = '#';       //Symbol used for an available seat
char Taken = '*';           //Symbol used for a taken seat
const int PURCHASE = 1,     //Variable used for displayMenu function
TOATL_TIX_SALES_DOLS = 2,   //Variable used for displayMenu function
TOTAL_TIX_SOLD = 3,         //Variable used for displayMenu function
SEAT_AVAILABILITY_ROWS = 4, //Variable used for displayMenu function
SEAT_AVAILABILITY_AUD = 5,  //Variable used for displayMenu function
EXIT_CHOICE = 6;            //Variable used for displayMenu function
int choice;                 //Choice variable for user input



int main()
{
	//Start program with storeRowPrices function to have user assign prices to each row.
	storeRowPrices();

	//Initialize all array elements to "Available/#"
	for (int rows = 0; rows < x; rows++)
	{
		for (int columns = 0; columns < y; columns++)
			seatingChart[rows][columns] = Available;
	}

	//Show seating chart
	displayChart();

	//Do/while loop to keep user in the menu until they choose to exit.
	do
	{
		DisplayMenu();
	} while (choice != EXIT_CHOICE);
	return 0;
}

//*******************************************************************************
// Defintion of function displayChart is to format and display the seating chart*
//*******************************************************************************
void displayChart() {

	//Seating chart array header/column numbers
	cout << "         1| 2| 3| 4| 5| 6| 7| 8| 9|10|11|12|13|14|15|16|17|18|19|20|21|22|23|24|25|26|27|28|29|30" << endl;
	cout << "         ----------------------------------------------------------------------------------------";

	//Double nested for loop generates 15 rows and 30 columns
	//Added the word Row at the beginning of each line within the seating chart array
	//std::setw(2) is used for y axis header alignment of the seating chart
	for (int row = 0; row < y; row++) {
		cout << endl;
		cout << "Row: " << setw(2) << row + 1;

		//Added 2 spaces into the array for each seat to help with seating availability alignment
		for (int column = 0; column < x; column++) {
			cout << "  " << seatingChart[column][row];
		}
	}
}

//***********************************************************
// Defintion of function DisplayMenu shows the menu options *
//***********************************************************
void DisplayMenu()
{
	//Menu display with formatting
	cout << "\n\nTheather Options Menu\n\n"
		<< "1. Purchase Tickets\n"
		<< "2. Total Ticket Sales in Dollars\n"
		<< "3. Total Number of Tickets Sold\n"
		<< "4. Seat Availability in Each Row\n"
		<< "5. Seat Availability in Auditorium\n"
		<< "6. Exit\n\n"
		<< "Enter your choice: ";
	cin >> choice;

	//input validation while loop
	while (choice < PURCHASE || choice > EXIT_CHOICE)
	{
		cout << "Please enter a valid menu choice: ";
		cin >> choice;
		cout << endl;
	}

	//Menu options where each case has its corresponding function.
	switch (choice)
	{
	case PURCHASE:
	{
		purchaseTickets();
		break;
	}

	case TOATL_TIX_SALES_DOLS:
	{
		totalTicketSale();
		break;
	}

	case TOTAL_TIX_SOLD:
		numTicketSold();
		break;

	case SEAT_AVAILABILITY_ROWS:
	{
		rowAvailability();
		break;
	}

	case SEAT_AVAILABILITY_AUD:
	{
		displayChart();
		break;
	}
	}
}

//***************************************************************************************************
// Defintion of function numTicketSold is to calculate the total number of tickets sold as a running*
//***************************************************************************************************
void numTicketSold()
{
	//Variable for running total of total tickets sold
	int totalSold = 0;

	//for loop with nested for loop with nested if statement to add to running total
	for (int rowCounter = 0; rowCounter < x; rowCounter++)
	{
		for (int colCounter = 0; colCounter < y; colCounter++)
		{
			if (seatingChart[rowCounter][colCounter] == Taken)
			{
				totalSold += 1;
			}
		}
	}

	cout << "The current number of tickets sold is " << totalSold << ".\n";
}

//********************************************************************************************************
// Defintion of function purchaseTickets is to allow the user to purchase tickets for any AVAILABLE seats*
//********************************************************************************************************
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

	//while loop with nested if statements for error messages
	while (userSeats <= 0 || userSeats > x * y)
	{
		cout << "How many seats would you like to purchase? ";
		cin >> userSeats;

		if (userSeats <= 0)
		{
			cout << "Please choose 1 or more seats.\n";
		}
		if (userSeats > x * y)
		{
			cout << "Ticket amount exceeds theater capacity, please try again.\n";
		}
	}

	//while loop to prompt the user for the row selection, for loop counts how many available seats in the specified row and if statement checks if there are enough available seats
	while (rowAvailable < userSeats)
	{
		while (userRow < 1 || userRow > y)
		{
			cout << "In which row would you like to sit? ";
			cin >> userRow;

			if (userRow < 1 || userRow > y)
			{
				cout << "You have selected an invalid row number, please try again.\n";
			}
		}

		for (int numY = 0; numY < y; numY++)
		{
			if (seatingChart[userRow - 1][numY] == Available)
				rowAvailable += 1;
		}

		if (rowAvailable < userSeats)
			cout << "There are not enough seats available in this row, please pick another row.\n";
	}

	//cout statement to start message about which seats in user-specified row are available.
	cout << "Row " << userRow << " has seats ";

	//for with nested ifs cout only the seat numbers that are currently available.
	for (int countCol = 0; countCol < x; countCol++)
	{
		if (seatingChart[userRow - 1][countCol] == Available)
		{
			cout << countCol + 1;

			if (countCol != x - 1)
				cout << ", ";
		}
	}

	//finish the rest of the message
	cout << " available.\n";

	//while loop with nested while loop and if statement to prompt user for the seat number they want, while checking for its avaiability and marking that seat as taken once purchased
	while (seatEnd <= 0)
	{
		while (userCol < 1 || userCol > x || seatingChart[userRow - 1][userCol - 1] == Taken)
		{
			cout << "What seat number would you like to sit at? ";
			cin >> userCol;

			if (userCol < 1 || userCol > x || seatingChart[userRow - 1][userCol - 1] == Taken)
			{
				cout << "You have chosen an invalid or taken seat number, please try again.\n";
			}
		}
		//seatingChart[userRow - 1][userCol - 1] = Taken;
		seatingChart[userCol - 1][userRow - 1] = Taken;
		seatEnd++;
	}

	//if the user requested more than one seat, this while loop executes, essentially the same as prev while loop but with slightly different wording to express that they are choosing subsequent seats
	if (userSeats > 1)
	{
		while (seatEnd < userSeats)
		{
			userCol = 0;

			while (userCol < 1 || userCol > x || seatingChart[userRow - 1][userCol - 1] == Taken)
			{
				cout << "What is the next seat number would you like to sit at? ";
				cin >> userCol;

				if (userCol < 1 || userCol > x || seatingChart[userRow - 1][userCol - 1] == Taken)
				{
					cout << "You have chosen an invalid or taken seat number, please try again.\n";
				}
			}
			//seatingChart[userRow - 1][userCol - 1] = Taken;
			seatingChart[userCol - 1][userRow - 1] = Taken;
			seatEnd++;
		}
	}
}

//****************************************************************************************************
// Defintion of function storeRowPrices is to greet the user and have them assign prices for each row*
//****************************************************************************************************
void storeRowPrices()
{
	//priceArray to temporarily store user defined values to later load into file
	double priceArray[y];

	//Since this function starts the program and is only executed in the very beginning, we included greeting here.
	cout << "Welcome to DTCC Theater!\n";

	//for loop to cycle through each row/array element while prompting user for price of each row and ensuring inputs are not invalid
	for (int counter = 0; counter < y; counter++) {

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
	for (int counter = 0; counter < y; counter++) {
		outputFile << priceArray[counter] << endl;
	}

	//close outputFile
	outputFile.close();

	cout << endl;
}

//****************************************************************************************************
// Defintion of function totalTicketSale is to calculate the running total of tickets sold in dollars*
//****************************************************************************************************
void totalTicketSale()
{

	double total = 0, priceArray[y];
	//define and open "prices.txt" as inputFile
	ifstream inputFile("prices.txt");

	//for fill array with pricing info from file
	for (int rowCounter = 0; rowCounter < y; rowCounter++)
	{
		inputFile >> priceArray[rowCounter];
	}

	//increment through 2D array, every time a seat is shown as taken the price for that particular row is added to the running total of "total"
	for (int seatCounter = 0; seatCounter < x; seatCounter++)
	{
		for (int rowCounter = 0; rowCounter < y; rowCounter++)
		{
			if (seatingChart[seatCounter][rowCounter] == Taken)
			{
				total += priceArray[rowCounter];
			}
		}
	}

	//close inputFile
	inputFile.close();

	cout << "The current total is $" << fixed << setprecision(2) << total << endl;
}

//***********************************************************************************************
// Defintion of function rowAvailability is to display the seats currently available in each row*
//***********************************************************************************************
void rowAvailability()
{
	//for loops to increment through each element while only displaying the seat numbers that are shown as available.
	for (int countRow = 0; countRow < y; countRow++)
	{
		cout << "Row " << countRow + 1 << " has seats ";

		for (int countCol = 0; countCol < x; countCol++)
		{

			if (seatingChart[countRow][countCol] == Available)
			{
				cout << countCol + 1 << ", ";
			}
		}

		cout << " available.\n";
	}
}