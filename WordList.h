#ifndef WORDLIST_H
#define WORDLIST_H
#include "WordData.h"
class WordNode{
private:
	WordData worddata; // A WordData object
	WordNode *next;   // A pointer to a WordNode object;

public:
	WordNode();
	WordNode(char *word, int length, int lineNum)  ; // Constructor with word and line number constructor
	~WordNode();
	WordData & getData() ;
	WordNode * getNext() ;
	void setNext(WordNode * next);
};

class WordList{

private:
	WordNode * head; // A pointer to the first node of the list
	WordNode * end;   // A pointer to the last node of the list
	int size;          // The size of the list;
	

	void loadList(char* fname);  // Load this list using the words in the input text file
	WordNode * getPointer( char* words);  //Get a pointer to the node whose word data objects strores a given words
	void wordsOperation( char * words,int length, int linenNum); //Reflect how to operate with the meeting words;

public:
	
	WordList(char * fname);
	~WordList();
	void printFormat() const;  //Formatted print the list
	int getSize() const;            // Get the size of the list


};

#endif