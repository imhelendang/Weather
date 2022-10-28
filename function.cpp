/*
 * function.cpp
 *
 *  Created on: Jan 27, 2021
 *      Author: Jade Tran
 */
/**********************************************************
* AUTHOR : Ngoc Dang Tran;
* STUDENT ID : 1197865;
* ASSIGNMENT #8 : Weather
* CLASS : CS1B;
* SECTION : MW: 9:30am-11:50am;
* DUE DATE : 01/27/2021;
**********************************************************/

#ifndef FUNCTION_CPP_
#define FUNCTION_CPP_

#include "function.h"

void classHeader()			//This function print class heading to the console
{
	/********************************************************
	*CONSTANTS
	* ----------------------------------------------------
	* USED FOR CLASS HEADING –ALL WILL BE OUTPUT
	* ----------------------------------------------------
	* PROGRAMMER : Programmer's Name
	* CLASS : Student's Course
	* SECTION : Class Days and Times
	* ASSIGNMENT_NUM : Assignment Number (specific to this tab)
	* ASSIGNMENT_NAME : Title of the Assignment
	********************************************************/

	// OUTPUT - Class Heading
	const char PROGRAMMER[30] = "Ngoc Dang Tran";
	const char CLASS[5] = "CS1A";
	const char SECTION[25] = "MW: 5:00p - 7:20p";
	const int ASSIGNMENT_NUM = 8;
	const char ASSIGNMENT_NAME[20] = "Functions and Files";

	cout << left;
	cout << "**************************************************";
	cout << "\n* PROGRAMMED BY : " << PROGRAMMER;
	cout << "\n* " << setw(14) << "CLASS" << ": " << CLASS;
	cout << "\n* " << setw(14) << "SECTION" << ": " << SECTION;
	cout << "\n* ASSIGNMENT #" << ASSIGNMENT_NUM << " : " << ASSIGNMENT_NAME;
	cout << "\n**************************************************\n\n";
	cout << right;

	return;
}

//PRINT class header to the ofstream file by using passing reference
void printClassHeader(ofstream& outFile, string asName, char asType, int asNum)
{
	// OUTPUT - Class Heading
	outFile << left;
	outFile << "**************************************************\n";
	outFile << "*  PROGRAMMED BY : Ngoc Dang Tran";
	outFile << "\n*  " << setw(14) << "STUDENT ID" << ": 1197865";
	outFile << "\n*  " << setw(14) << "CLASS" << ": CS1B –-> MW - 9:30-11:50am";
	outFile << "\n*  " ;
	if (toupper(asType) == 'L')
	{
		outFile << "LAB #" << setw(9);
	}
	else
	{
		outFile << "ASSIGNMENT #" <<setw(2);
	}
	outFile << asNum << ": " << asName;
	outFile <<"\n**************************************************\n\n";
	outFile << right;


}


//This function reads and store data in the two dimensional array
//The data are being stored according to the parameters
//Postcondition: the function will receive the data and store data in the two dimensional array
void getData(ifstream& inFile, ofstream& outFile, int listTemp[ROW][COL], char MONTHS[][10])
{
	int i;		//number of row
	int j;		//number of column

		for (i = 0; i < ROW; i++)
		{
			for (j = 0; j < COL; j++)
			{
				inFile >> listTemp[i][j];
			}
		}

	return;
}


//This function calculates and returns the average high temperature for the year.
//The data will be calculated according to the parameters
//Precondition: received data from text file
//Postcondition: calculate in Fahrenheit degree
//				 This function calculate and return the average high temperature in degree in the output.txt
double averageHigh(ofstream& outFile, int listTemp[ROW][COL])
{
	int sum = 0;
	float aveHigh = 0.00;

		//set up the number formatting
		outFile << left;
		outFile << fixed << showpoint << right << setprecision(2);
		outFile << left;


		for (int i = 0; i < ROW; i++)
		{
			sum = sum + listTemp[i][0];
		}

	aveHigh =  static_cast<float>(sum)/ROW; 		//Average high temperature = the sum of high temperature divides 12 months of a year

	outFile << "Average high for the year: " << aveHigh << "\u2109" << endl << endl;


	return aveHigh;
}

//This function calculates and returns the average low temperature for the year.
//The data will be calculated accroding to the parameters
//Precondition: received data from text file
//Postcondition: calculate in Fahrenheit degree
//				 This function calculate and return the average low temperature in degree in the output.txt
double averageLow(ofstream& outFile, int listTemp[ROW][COL])
{
	int sum;
	float aveLow = 0.00;

		//set up the number formatting
		outFile << left;
		outFile << fixed << showpoint << right << setprecision(2);
		outFile << left;

		sum = 0;
		for (int i = 0; i < ROW; i++)
		{
			sum += listTemp[i][1];
		}


	aveLow = static_cast<float>(sum)/ROW; 		//Average high temperature = the sum of high temperature divides 12 months of a year

	outFile << "Average low for the year:  " << aveLow << "\u2109" << endl << endl;


	return aveLow;
}

//This function returns the index of the highest in high temperature column.
//The data will be calculated according to the parameters
//Precondition: received data from text file
//Postcondition: calculate and determine the index of high temperature in the array
//				 index is an integer
//				 temperature in Fahrenheit degree with the degree sign ('\370')
void indexHighTemp(ofstream& outFile, int listTemp[ROW][COL], char MONTHS[][10])
{
	int highestIndex;
	char highMonth[10];
	highestIndex = listTemp[0][0]; 		//Assuming that the first element of the column is the highest

	//find highest in the "high" column


		for (int i = 1; i < ROW; i++)
		{
			if (listTemp[i][0] > highestIndex)
			{
				highestIndex = listTemp[i][0];
				strcpy(highMonth, MONTHS[i]);
			}
		}

	outFile << "Highest Temperature: " << highestIndex << "\u2109" << "\t\tMonth: " << highMonth << endl;

	return;
}

//This function returns the index of the lowest in low temperature column.
//The data will be calculated according to the parameters
//Precondition: received data from text file
//Postcondition: calculate and determine the index of low temperature in the array
//				 index is an integer
//				 temperature in Fahrenheit degree with the degree sign ('\370')
void indexLowTemp(ofstream& outFile, int listTemp[ROW][COL], char MONTHS[][10])
{
	int lowestIndex = 0;
	char lowMonth[10];
	char lowMonth2[10];


		//find highest in the "low" column
		for (int i = 0; i < ROW; i++)
		{
			if (listTemp[i][1] - lowestIndex == listTemp[i][1])
			{
				lowestIndex = listTemp[i][1];
				strcpy(lowMonth, MONTHS[i]);
			}
			else
			{
				if (listTemp[i][1] <= lowestIndex)
				{
					strcpy(lowMonth2, MONTHS[i]);
				}
			}
		}

	outFile << "Lowest Temperature:  " << lowestIndex << "\u2109" << "\t\tMonth(s): " << lowMonth << " and " << lowMonth2 << endl;


	return;
}



#endif /* FUNCTION_CPP_ */
