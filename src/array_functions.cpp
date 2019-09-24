/*
 * functionstocomplete.cpp
 *
 *  Created on: Sep 10, 2017
 *      Author: keith
 */

//============================================================================
//	TODO add necessary includes here
//============================================================================
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <time.h>
#include "constants.h"
#include "utilities.h"
#include "array_functions.h"
//============================================================================
//	stuff you will need
//============================================================================
//TODO define a structure to track words and number of times they occur
using namespace std;
using namespace constants;

struct track
{
	string word;
	int number_occ;
};
//TODO add a global array of entry structs (global to this file)

//TODO add variable to keep track of next available slot in array
int next;
//TODO define all functions in header file
void clearArray(){

}

int getArraySize(){
	return 0;
}
std::string getArrayWordAt(int i){
	return " ";
}
int getArrayWord_NumbOccur_At(int i){
	return 0;
}
bool processFile(std::fstream &myfstream){
	return false;
}
void processLine(std::string &myString){

}
void processToken(std::string &token){

}
bool openFile(std::fstream& myfile, const std::string& myFileName,
		std::ios_base::openmode mode){

	myfile.open(myFileName.c_str());
	if (!myfile.is_open())
		return false;

	return true;
}
void closeFile(std::fstream& myfile){
	myfile.close();
}
int writeArraytoFile(const std::string &outputfilename){
	return 0;
}
void sortArray(constants::sortOrder so){

}

//TODO look in utilities.h for useful functions, particularly strip_unwanted_chars!
