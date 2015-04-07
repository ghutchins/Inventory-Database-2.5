/**  
*  @file    database.cpp
*  @author  Georgina Hutchins (hutcgb12)
*  @date    04/03/2014  
*  @version 2.5  
*
*  @brief CSC 112, Lab 9, Inventory Database
*
*  @section DESCRIPTION
*
*  database.cpp is the source file that contains the function
*  defintions that can be utitlized in a program that maintains
*  a company's inventory database.
*
*  @bug No known bugs
*
*/



#include "database.h"
using namespace std;



/**
*  @brief search is a function that searches the database to
*  ensure that all the values are in the array and are unique
*
*
*  @param value is a variable for each ID number read 
*  @param list is the database array of product ID numbers
*  @param n is the logical size of the array 
*
*  @return the location of the value in the array
*/
int search(int& value, int* list, int n)
{
	for(int i = 0; i < n; i++)
	{
		if(value == list[i])
			return i;
	}
	
	return -1;

}



/**
*  @brief storeValue is a function that stores the unique ID
*  values in ascending order in the array and allocates a new 
*  array with 10% more elements if the current array is full
*
*  @param value is an ID number in the database
*  @param list is the database array of product ID numbers
*  @param n is the logical size of the array
*  @param max is the physical size of the array
*
*  @return void
*/
void storeValue(int& value, int*& list, int& n, int& max, int x)
{	
	if(n == max)
	{
		max += int(max * (0.1 + 0.5));
		int* tempList = new (nothrow) int[max]; ///< Temporary array to resize database array

		if(!tempList)
			exit(1);

		for(int i = 0; i < x; i++)
		{
			tempList[i] = list[i];
		}

		tempList[x] = value;

		for(int i = (x + 1); i < n; i++)
			tempList[i] = list[i + 1];

		if(list)
			delete[] list;

		list = tempList;
		
	}
	
	else
	{
		int i;		///< Counter variable

		for(i = (n - 1); (i >= 0) && (value < list[i]); i--)
			list[i + 1] = list[i];

		list[i + 1] = value;
		
	}

	n++;

}



/**
*  @brief deleteValue is a function that deletes specified
*  values in the database array and if no more than 50% of the
*  actual array is used, it will reallocate such that only 20%
*  of the elements are empty
*
*  @param loc is the location of the deletion
*  @param list is the database array of product ID numbers
*  @param n is the logical size of the array
*  @param max is the physical size of the array
*
*  @return void
*/
void deleteValue(int loc, int*& list, int& n, int& max)
{
	if(max > 20 && max > (n * 1.5))
	{
		int i;		///< Counter variable
		max = int(n * (1.2 + 0.5));
		int* tempList = new (nothrow) int[max]; ///< Temporary array for deleting from dynamic list

		if((tempList == 0))
			exit(1);

		for(i = 0; i < loc; i++)
			tempList[i] = list[i];

		for(i = loc; i < (n - 1); i++)
			tempList[i] = list[i + 1];

		n--;

		if(list)
			delete[] list;

		list = tempList;
	}			
	
	else
	{
		if(loc < n)
		{
			for(int i =  loc; i < (n - 1); i++)
				list[i] = list[i + 1];
			
			n--;
		}
	}

}



/**
*  @brief writeFile is a function that writes the updated
*  database information from the array into a new file to
*  print to the screen
*
*  @param value is an ID number in the database
*  @param list is the database array of product ID numbers
*  @param n is the logical size of the array
*  @param argv is the command line argument from user
*
*  @return void
*/
void writeFile(int value, int* list, int n, char* argv[])
{
	string dataFileName = argv[3];
	fstream dataFile(dataFileName.c_str(), ios :: out);
	
	for(int i = 0; i < n; i++)
	{
		dataFile << list[i]; 
		dataFile << endl;
	}

	dataFile.close();

	cout << "Output written to " << dataFileName << '\n';

}



