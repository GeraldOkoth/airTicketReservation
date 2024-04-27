//A program to automate Air ticket reservation.
#include <iostream>

using namespace std;

//function to display the seating chart.
void displaySeatChart()
{
	//Implement a 2D array to store seat number.
    int array[6][3] = {{1, 2, 3},{4, 5, 6},{7, 8, 9},{10, 11, 12},{13, 14, 15},{16, 17, 18}}; // Define a 3 by 3 array
    cout << "Seating Chart:" << endl << endl;
    // Print the array from seat 1 - 18
    for (int i = 0; i < 6; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                cout << array[i][j] << " ";
            }
            cout << endl << endl;
        }
}

//function to check whether all sits are occupied or not
bool allSeatsOccupied(char arr[6][3])
{
	int count = 0; //initialize count to 0.
	for(int i = 0; i < 6; i++)
        {
            for (int j = 1; j < 3; j++) //begin looping from the first index.
            {
                if(arr[i][j] == 'X')
                {
                    count++; //incrementing count.
                }
            }
        }
        if(count == 18)
            {
                cout <<"Sorry. All the seats are full. Please wait for the next flight that leaves in the next 3 hours." <<endl;
                return true;
            }
        return false;
}

//function to update seat status
void updateSeatStatus(char arr[6][3], int row, int col)
{
	cout <<"\nUpdated seat status." << endl;
	arr[row][col] = 'X';
}

//Check if the range of clients' input is in the range 1,1 to 6,18 is valid.
bool checkInput(char arr[6][3], string s)
{
        if (s.length() != 2 || s[0] < '1' || s[0] > '6' || s[1] < '1' || s[1] > '3')
    {
        cout << "Invalid seat number." << endl;
        return false;
    }

    int row = s[0] - '1';
    int col = s[1] - '1';

    if (arr[row][col] == 'X')
    {
        cout << "This seat has already been assigned." << endl;
        return false;
    }
    else
    {
        cout << "This seat is available for booking." << endl;
        updateSeatStatus(arr, row, col);
        return true;
    }
}

//Define the seats in the bussiness class
void bussinessClassSeats()
{
    int array[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    cout << "Business Class Seats:" << endl << endl;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cout << array[i][j] << " ";
        }
        cout << endl << endl;
    }
}

//Define the seats in the Economy class
void economyClassSeats()
{
    int array[3][3] = {{10, 11, 12}, {13, 14, 15}, {16, 17, 18}};
    cout << "Economy Class Seats:" << endl << endl;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cout << array[i][j] << " ";
        }
        cout << endl << endl;
    }
}

/*void airline(char arr[6][4])
{
	string s;
	while(true)
	{
	    //process the request & check according to
	    if(check(arr,s))
            {
                displaySeatChart(arr);
            }

        if(allSeatsOccupied(arr))
            {
                cout <<"sorry, all the seats are full. Please wait for the next flight that leaves in the next 3 hours." <<endl;
                break;
            }
    }*/
//Entry into the main function
int main()
{
    int selection, seat; //Declare two variables that stores clients' class selection and seat respectively.

    cout <<"\t\t\t\tAIRLINE SEAT RESERVATION\n";
    cout <<"\t\t\t\t========================\n\n";

    cout << "Capacity of seats available for booking: 18" <<endl <<endl;

    displaySeatChart();

	cout << endl;
    cout << "1. Please input 1 to reserve a seat in Business Class" <<endl;
    cout << "2. Please input 2 to reserve a seat in Economy Class" <<endl;
    cout << "3. Please input 3 to Exit" <<endl <<endl;

    cin >> selection; //Take in and stores clients' input.

	switch(selection) //Switch case statement to check what the clients' inputs and assign a class accordingly.
	{
	case 1:

        cout << "\nWelcome to Bussiness class" << endl;
	    cout << "You are about to book a seat in the Bussiness class." <<endl;
		cout << "Seats available for booking are (1 - 9), Please select a number between 1 - 9 and proceed: " <<endl <<endl;

        bussinessClassSeats();

		cin >> seat; //Store clients' selection of a number between 1 - 9.

		if(seat >=1 && seat <= 9)
		{
		    if(seat == seat)
            {
                cout << "\nDear customer, you have been assigned Seat Number: " << seat <<endl <<endl;
                cout << "Boarding pass" <<endl;
                cout << "=============" <<endl;
                cout << "\nClass: " << "Bussiness class" << endl;
                cout << "Seat no.: " << seat << endl;

            }
            else if (seat == 1 || seat == 2 || seat == 3 || seat == 4 || seat == 5 || seat == 6 || seat == 7 || seat == 8 || seat == 9)
            {
                cout << "The bussiness class is full, please book a seat in the economy class." <<endl;
            }
            else
                break;
		}
		else
			cout << "Invalid input, or the number of seat does not belong to the Bussiness class. Please try again!" << endl;
		break;
	case 2:

        cout << "\nWelcome to Economy class" << endl;
	    cout << "You are about to book a seat in the Economy class." <<endl;
		cout << "Seats available for booking are (10 - 18), Please select a number between 10 - 18 and proceed: " <<endl <<endl;

		economyClassSeats();

		cin >> seat; //Store clients' selection of a number between 10 - 18.

		if(seat >=10 && seat <= 18)
		{
		    if(seat == seat)
            {
               cout << "\nDear customer, you have been assigned Seat Number: " << seat <<endl <<endl;
               cout << "Boarding pass" <<endl;
               cout << "=============" <<endl;
               cout << "\nClass: " << "Economy class" << endl;
               cout << "Seat no.: " << seat << endl;
            }
            else if (seat == 10 || seat == 11 || seat == 12 || seat == 13 || seat == 14 || seat == 15 || seat == 16 || seat == 17 || seat == 18 || seat == 19)
            {
                cout << "The Economy class is full, please book a seat in the Bussiness class." <<endl;
            }
            else
                break;
		}
		else
			cout << "Invalid input, or the number of seat does not belong to the Economy class. Please try again!" << endl;
		break;
    case 3:
        exit(0);
    default: cout << "\nInvalid input! Please try again." <<endl <<endl;
	}
	//airline(arr); //airline function

	return 0;
}
