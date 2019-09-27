/*
 * functionstocomplete.cpp
 *
 *  Created on: Sep 10, 2017
 *      Author: keith
 *
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
	int num_occ;
};
//TODO add a global array of entry structs (global to this file)
track myTrack[MAX_WORDS];

//TODO add variable to keep track of next available slot in array
int nxt;
//TODO define all functions in header file
//zero out array that tracks words and their occurrences
void clearArray(){
//decided to use this again... It should work. Need to pass processToken first
	nxt = 0;
}
//how many unique words are in array?
int getArraySize(){
	return nxt;
}

//get data at a particular location
//return the word in array
std::string getArrayWordAt(int i){
	return myTrack[i].word;
}
//return the num_occ array
int getArrayWord_NumbOccur_At(int i){
	return myTrack[i].num_occ;
}

/*loop through whole file, one line at a time
 * call processLine on each line
 * returns false: myfstream is not open
 *         true: otherwise*/
bool processFile(std::fstream &myfstream){
	string line;
	if (!(myfstream.is_open())){
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
	stringstream ss(myString);
	string temptoken;
	while(getline(ss, temptoken, CHAR_TO_SEARCH_FOR)){
		processToken(temptoken);
	}
}

/*Keep track of how many times each token seen*/
void processToken(std::string &token) {

	string upper = token;
	strip_unwanted_chars(upper);
//	toUpper(upper);
	if (!(strip_unwanted_chars(upper))){
		return;
	}
	for(int i = 0; i < nxt; i++) {
		myTrack[nxt].num_occ = 0;
		string str = myTrack[i].word;
		toUpper(upper);
		toUpper(str);

		if(str == upper) {
			myTrack[i].num_occ++;
			return;
		}
	}
	if(token.length()!=0){
		myTrack[nxt] = track(); // adds word to new struct
		myTrack[nxt].num_occ = 1;
		myTrack[nxt].word = upper;
		nxt++;
	}
}
/*if you are debugging the file must be in the project parent directory
  in this case Project2 with the .project and .cProject files*/
bool openFile(std::fstream& myfile, const std::string& myFileName,
		std::ios_base::openmode mode) {
		myfile.open(myFileName);
		return myfile.is_open();

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
	ofstream myOutputfile;
	myOutputfile.open(outputfilename.c_str());
	if (!myOutputfile.is_open())
		return FAIL_FILE_DID_NOT_OPEN;
	if (nxt == 0){
		return FAIL_NO_ARRAY_DATA;
	}
	else{
		for (int i=0; i < nxt; i++){
			myOutputfile << myTrack[i].word << ' ' << myTrack[i].num_occ << '\n' << endl;
		}
	myOutputfile.close();
	return SUCCESS;
}
}
/*
 * Sort myEntryArray based on so enum value.
 * You must provide a solution that handles alphabetic sorting (A-Z)
 * The presence of the enum implies a switch statement based on its value
 */
void sortArray(constants::sortOrder so){
	switch (so){
		case NONE:{
			break;
		}
		case ASCENDING:{
			for(int i = 0; i < nxt - 1; i++){
				for (int j = i + 1; j < nxt; j++){
					string w1 = myTrack[i].word;
					string w2 = myTrack[j].word;
					if (w1 > w2){
						track temp = myTrack[i];
						myTrack[i] = myTrack[j];
						myTrack[j] = temp;
					}
				}
			}
			break;
		}
		case DESCENDING:{
			break;
		}
		case NUMBER_OCCURRENCES:{
			break;
		}
	}
}
//TODO look in utilities.h for useful functions, particularly strip_unwanted_chars!
