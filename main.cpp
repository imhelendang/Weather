/*
 * main.cpp
 *
 *  Created on: Jan 27, 2021
 *      Author: Jade Tran
 */
/***************************************************************************
* AUTHOR : Ngoc Dang Tran;
* STUDENT ID : 1197865;
* ASSIGNMENT #2 : Weather
* CLASS : CS1B;
* SECTION : MW: 9:30am - 11:50am;
* DUE DATE : 12/15/2020;
****************************************************************************/

//This program uses a two-dimensional array to
//store the highest and lowest temperatures of each month of the year. The
//program should output the average high, average low, and the highest and
//lowest temperatures for the year. Your program must consist of the
//following methods:
//getData: This function reads and stores data in the two-dimensional array.
//averageHigh: This method calculates and returns the average high
//    temperature for the year.
//averageLow: This function calculates and returns the average low temperature
//    for the year.
//indexHighTemp: This function returns the index of the highest high
//    temperature in the array.
//indexLowestTemp: This function returns the index of the lowest temperature
//    in the array.
//(These functions must all have appropriate parameters.)
//****************************************************************************


#include "function.h"

int main()
{

	//Months of the year
	char MONTHS[12][10] = { "January", "February", "March", "April", "May",
					"June", "July", "August", "September", "October",
					"November", "December" } ;


	//data table
	int listTemp[ROW][COL], i, j;
	string usedIn, usedOut;
	char months[10];

	//Open ofstream file -- OFile.txt
	ofstream outFile;
	outFile.open("output.txt");
	//Open data.txt
	ifstream inFile;
	inFile.open("data.txt");

	if (!inFile)
	{
		cout << "Cannot open the input file." << endl;
		return 1;
	}


//****************************************************************************
//Progressing
//Example Run:
//
//January:
//
//-- Enter High: 53.5
//
//-- Enter Low: 39.1
//
//.....
//
//Yearly Statistics:
//
//Average Hi: ###.##°
//
//Average Low: ###.##°
//
//Highest Temperature: ###.##° Month: July
//
//Lowest Temperature: ###.##°  Month: January
//
//****************************************************************************

	classHeader();
	printClassHeader(outFile, "Weather", 'A', 2);		//OUT class header to the output.txt

	cout << left;
	cout << "Weather statistics:" << endl;

	cout << "The statistics will be displayed as the month along side with the high temperature and the low temperature of that month!\n";
	cout << "At the end the program will calculate the average high temperature and average low temperature to the decided output file.\n\n";
	cout << "The program also output the highest temperature with the name of the month!\n\n";
	cout << "Please choose the file to read in the data e.g input.txt: ";
	cin >> usedIn;
	cout << "Please choose the file to output the data e.g output.txt: ";
	cin >> usedOut;

//****************************************************************************
	//Read the data from picked input file
	getData(inFile, outFile, listTemp, MONTHS);
//****************************************************************************


//****************************************************************************
	//Write the data from the array to the output.txt
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			strcpy(months, MONTHS[i]);
			outFile << left;

			switch(j)
			{
			case 0:
				outFile << "Month: " << months << endl;
				outFile << "\t\tHi:  " << setw(6) << right << listTemp[i][j] << "\u2109" << endl;
			break;
			case 1:
				outFile << "\t\tLow: " << setw(6) << right << listTemp[i][j] << "\u2109" << endl << endl;
			break;

			}
		}
	}
//****************************************************************************


//****************************************************************************
//Recall the functions to calculate and output the average high temperature, average low temperature
//	highest temperature with the month, and lowest temperature with the month(s)
	outFile << left;
	averageHigh(outFile, listTemp);
	averageLow(outFile, listTemp);
	indexHighTemp(outFile, listTemp, MONTHS);
	indexLowTemp(outFile, listTemp, MONTHS);
//****************************************************************************


	//Close data.txt and output.txt
	outFile.close();
	inFile.close();

	cout << endl << endl;

	//Close the program
	cout << "All calculations and progress had done successfully!\n\n";
	cout << "Thanks for using the program!";

	return 0;

}
