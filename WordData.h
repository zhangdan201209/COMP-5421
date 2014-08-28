#ifndef WORDDATA_H
#define WORDDATA_H
#include "IntList.h"

class WordData{

private :
	char * ptr;   // A pointer to a dynamically allocated array to store a specified word
	int length;   // length of the dynamically array
	int frequency; // frequency count of the word
	IntList intlist; // IntList object storing a list of line numbers associated with the word

public :
	WordData();
	WordData(char* word, int length, int lineNum);
	WordData(WordData & worddata);
	WordData &operator=(WordData &worddata) ;
	~WordData();


	void appendLineNum(int lineNumber); //Append the element to the end of the list
	int getFrequency() const;           //Get frequency count
	int getLength() const;				//Get the length of the memory
	const char * getWord() const;		// Get a read-only pointer to the stored word
	const IntList& getList() const;		// Get a read-only reference to the IntList object
	int compareWords(char * words) const; // Determine the relationship with the given word and stored word
	void print() const;					//print the word together with its frequency count and list of line number

};

#endif