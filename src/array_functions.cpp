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
#include <array>
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
track myTrack[constants::MAX_WORDS];

//TODO add variable to keep track of next available slot in array
int next;
//TODO define all functions in header file
//zero out array that tracks words and their occurrences
void clearArray(){
	char testName[MAX_WORDS];
	std::fill(std::begin(testName), std::end(testName), '\0');
}
//how many unique words are in array
int getArraySize(){
	//I need to get rid of the bad chars here!
	int size = 0;
	int count =0;
	for (int i = 0; (unsigned)i < sizeof(myTrack); i++){
		size =+ 1;
		}
	return size;
	while(!end(myTrack)){
		count += 1;
		return count;
	}
}

//get data at a particular location
std::string getArrayWordAt(int i){
	return "";
}
int getArrayWord_NumbOccur_At(int i){
	return 0;
}

/*loop through whole file, one line at a time
 * call processLine on each line
 * returns false: myfstream is not open
 *         true: otherwise*/
bool processFile(std::fstream &myfstream){
	string line;
	if (!myfstream.is_open()){
		return false;
	}
	while(!(myfstream.eof())){
		getline(myfstream, line);
		processLine(line);
	}
	return true;
}

/*take 1 line and extract all the tokens from it
feed each token to processToken for recording*/
void processLine(std::string &myString){
	strip_unwanted_chars(myString);
	stringstream ss(myString);
	string tempToken;

	while(getline(ss, tempToken, CHAR_TO_SEARCH_FOR)){
		processToken(tempToken);
	}


}

/*Keep track of how many times each token seen*/
void processToken(std::string &token){

}

/*if you are debugging the file must be in the project parent directory
  in this case Project2 with the .project and .cProject files*/
bool openFile(std::fstream& myfile, const std::string& myFileName,
		std::ios_base::openmode mode) {

	myfile.open(myFileName.c_str());
	if (!(myfile.is_open())){
		return false;
	}
	return true;
}

/*if myfile is open then close it*/
void closeFile(std::fstream& myfile){
	if (myfile.is_open()){
		myfile.close();
	}
}

/* serializes all content in myEntryArray to file outputfilename
 * returns  FAIL_FILE_DID_NOT_OPEN if cannot open outputfilename
 * 			FAIL_NO_ARRAY_DATA if there are 0 entries in myEntryArray
 * 			SUCCESS if all data is written and outputfilename closes OK
 * */
int writeArraytoFile(const std::string &outputfilename){
//	ofstream myOutputfile;
//	myOutputfile.open(outputfilename.c_str());
//	if (!myOutputfile.is_open())
//			return false;
//	myOutputfile << myTrack;
//	myOutputfile.close();
	return 0;
}

/*
 * Sort myEntryArray based on so enum value.
 * You must provide a solution that handles alphabetic sorting (A-Z)
 * The presence of the enum implies a switch statement based on its value
 */
void sortArray(constants::sortOrder so){

}

//TODO look in utilities.h for useful functions, particularly strip_unwanted_chars!
