#ifndef INTLIST_H
#define INTLIST_H
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

class IntList{

private:
	int * ptr ;			// A pointer to a dynamically allocated array of integer elements
	int size;			// current number of element in the list;
	int capacity;		//total size of the IntList;


	
	

public:
	IntList();
	IntList(int lineNumber);
	IntList(const IntList & src);  
	IntList &operator=(const IntList &src) ;
	~IntList();

	bool isValid(int position) const;  // Determine whether the position is valid
	bool isEmpty () const;				// Determine whether the list is empty
	bool isExist ( int element) const;	// Determine  whether a given element exist in the list
	void append(int element);			//Append an element to the end of the list
	int  getElement (int position) const; // Get an element at a specified position
	bool setElement( int element, int position); // Set an element at a specified position
	int getSize() const;				
	int getCapacity() const;
	const int * getPointer() const;    // Get a read-only pointer to the underly array

};

#endif