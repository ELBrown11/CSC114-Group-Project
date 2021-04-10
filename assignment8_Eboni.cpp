
#include <iostream>
#include <iomanip>
#include<fstream>
using namespace std;

//function prototype
void DisplayMenu();
void totalTicketSale();
void storeRowPrices();

const int x = 30;           //Number of columns used for seating chart array
const int y = 15;           //Number of rows used for seating chart array
char seatingChart[x][y];    //Seating chart array (x = columns, y = rows)
void displayChart();        //Seating chart function
char Available = '#';       //Symbol used for an available seat
char Taken = '*';           //Symbol used for a taken seat

int main()
{   //Use these variables to test mapping seat availibilty into the seatingChart array
	int ROW = 14;
	int COLUMN = 29;
	
	//Set initial value of all seats to "Available" (#)
	for(int rows = 0; rows < x; rows++){
		for(int columns = 0; columns < y; columns++)
			seatingChart[rows][columns] = Available;}

	seatingChart[ROW][COLUMN] = Taken;

	//Main menu would call for Seating chart, displayChart input condition would go true (example: if menu = 4 , then run displayChart function)
	displayChart();
	return 0;
}
//displayChart function definition
void displayChart(){   
	
	//Seating chart array header/column numbers
	cout << "         1| 2| 3| 4| 5| 6| 7| 8| 9|10|11|12|13|14|15|16|17|18|19|20|21|22|23|24|25|26|27|28|29|30" << endl;
	cout << "         ----------------------------------------------------------------------------------------";

	//Double nested for loop generates 15 rows and 30 columns
	//Added the word Row at the beginning of each line within the seating chart array
	//std::setw(2) is used for y axis header alignment of the seating chart
	for(int row = 0; row < 15; row++){
		cout << endl;
		std::cout << "Row: " << std::setw(2) << row + 1;

		//Added 2 spaces into the array for each seat to help with seating availability alignment
		for(int column = 0; column < 30; column++){
			cout << "  " << seatingChart[row][column];}
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
}



//Get seat info from user (Asma)

void TicketsPurchased(char SeatingArray[ROWS][COLS])
{
	int NumOfSeats;
	int RowNum;
	int ColNum;

	cout << "How many seats would you like to purchase? ";
	cin >> userSeats;
	cout << "In which row would you like to sit? ";
	cin >> userRow;
	cout << "What seat number would you like to sit? ";
	cin >> userCol;
	if (NumOfSeats == 1)
	{
		seatingArray[RowNum][ColNum]

	}
}

void storeRowPrices() {
	//priceArray to temporarily store user declared values to later load into file
	double priceArray[15];

	//for loop to cycle through each row/array element while prompting user for price of each row
	for (int counter = 0; counter < 15; counter++) {
		cout << "Please enter the cost for a seat in row " << counter + 1 << ": $";
		cin >> priceArray[counter];
	}

	//define and open file for output, searches for/creates text file named "prices.txt"
	ofstream outputFile("prices.txt");

	//for loop to iterate through each array element and write to file with endline separating each entry
	for (int counter = 0; counter < 15; counter++) {
		outputFile << priceArray[counter] << endl;
	}

	//close outputFile
	outputFile.close();
}

void totalTicketSale(char seatingArray[30][15], int row, int col){
	
	double total = 0, priceArray[15];
	//define and open "prices.txt" as inputFile
	ifstream inputFile("prices.txt");

	//for fill array with pricing info from file
	for (int rowCounter = 0; rowCounter < 15; rowCounter++) {
			inputFile >> priceArray[rowCounter];
	}
	
	//increment through 2D array, every time a seat is shown as taken the price for that particular row is added to the running total of "total"
	for (int seatCounter = 0; seatCounter < 30; seatCounter++){
		for (int rowCounter = 0; rowCounter < 15; rowCounter++){
			if (seatingArray[seatCounter][rowCounter] == '*'){
				total += priceArray[rowCounter];
			}
		}
	}
	
	//close inputFile
	inputFile.close();

	cout << "The current total is $" << fixed << setprecision(2) << total << endl;
}


