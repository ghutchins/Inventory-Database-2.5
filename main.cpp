/**  
*  @file    main.cpp
*  @author  Georgina Hutchins (hutcgb12)
*  @date    04/03/2014  
*  @version 2.5  
*
*  @brief CSC 112, Lab 9, Inventory Database
*
*  @section DESCRIPTION
*
*  This program maintains a company's inventory database
*  where each product has a unique ID number. The program
*  sorts entries, removes duplicates, adds or deletes 
*  specified ID numbers. In version 2.5, the program
*  manages the database files in a dynamically sized
*  array using the 10% and 20% rule.
*
*  @bug No known bugs
*
*/



#include <iostream>
#include <fstream>
#include <cstdlib>
#include "database.h"
using namespace std;



int main(int argc, char* argv[])
{
	int max = 20;		///< Physical size of database
	int* list = new (nothrow) int[max] ;///< Dynamic database array
	int value;		///< ID number values in the database
	int n = 0;		///< Number of entries in the array (logical size)
	char action;		///< Letter indicating action-code from file
	int loc;		///< Location of a deletion from the database
	int x;			///< Variable to store return position of search function
	
	if(argc < 4)
	{
		cerr << "Usage: " << argv[0] << " inventory update final" << '\n';
		cout << "Error, please enter three valid file names" << '\n';	
		return 1;
	}

	string inFileName = argv[1];
	fstream inFile(inFileName.c_str(), ios :: in);

	while(inFile >> value)
	{
		if((x = search(value, list, n) == -1))
			storeValue(value, list, n, max, x);
		
	}

	inFile.close();

	cout << "Reading " << inFileName << '\n';
	cout << "Database has " << n << " ID numbers, array physical size is " << max << " (" << sizeof(int)*n << " bytes)" << '\n';
	cout << "-----------------------------------------------------------------------" << '\n';

	string upFileName = argv[2];
	fstream upFile(upFileName.c_str(), ios :: in);
	

	while(upFile >> action >> value) 
	{
		if(action == 'a' || action == 'A')
		{
			if((x = search(value, list, n) == -1))
				storeValue(value, list, n, max, x);
		}
		else if(action == 'd' || action == 'D')
		{
			loc = search(value, list, n);
			if(loc != -1)
				deleteValue(loc, list, n, max);
	
		}

	}
	
	cout << "Reading " << upFileName << '\n';
	cout << "Updated database" << '\n';
	cout << "Database has " << n << " ID numbers, array physical size is " << max << " (" << sizeof(int)*n << " bytes)" << '\n';
	cout << "-----------------------------------------------------------------------" << '\n';

	writeFile(value, list, n, argv);



	return 0;

}


