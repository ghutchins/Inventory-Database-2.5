/**  
*  @file    database.h
*  @author  Georgina Hutchins (hutcgb12)
*  @date    04/03/2014  
*  @version 2.5  
*
*  @brief CSC 112, Lab 9, Inventory Database
*
*  @section DESCRIPTION
*
*  The database.h header file contains the function declarations
*  or prototypes that can be utilized in a program that 
*  maintains a company's inventory database.
*
*  @bug No known bugs
*
*/


#ifndef DATABASE_H
#define DATABASE_H
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;


int search(int& value, int* list, int n);


void storeValue(int& value, int*& list, int& n, int& max, int x);


void deleteValue(int loc, int*& list, int& n, int& max);


void writeFile(int value, int* list, int n, char* argv[]);


#endif






