/*
 * function.h
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

#ifndef FUNCTION_H_
#define FUNCTION_H_

#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
using namespace std;

const int ROW = 12;
const int COL = 2;


void classHeader();
//This function print class heading to the console

void printClassHeader(ofstream& outFile, string asName, char asType, int asNum);
//PRINT class header to the ofstream file by using passing reference

void getData(ifstream& inFile, ofstream& outFile, int listTemp[ROW][COL], char MONTHS[][10]);
//This function reads and store data in the two dimensional array

double averageHigh(ofstream& outFile, int listTemp[ROW][COL]);
//This function calculates and returns the average high temperature for the year.

double averageLow(ofstream& outFile, int listTemp[ROW][COL]);
//This function calculates and returns the average low temperature for the year.

void indexHighTemp(ofstream& outFile, int listTemp[ROW][COL], char MONTHS[][10]);
//This function returns the index of the highest high temperature in the array.

void indexLowTemp(ofstream& outFile, int listTemp[ROW][COL], char MONTHS[][10]);
//This function returns the index of the lowest low temperature in the array.


#endif /* FUNCTION_H_ */
