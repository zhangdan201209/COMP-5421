#include "IntList.h"

//Default Constructor
IntList::IntList()
{
	
	size = 0;
	capacity = 12;
	ptr = new int[capacity];

}
//Constructor overloading
IntList::IntList(int lineNumber)
{	
	size = 10;
	capacity = 12;
	ptr = new int[capacity];
	
	ptr[0]= lineNumber;
}
//Copy Constructor
IntList::IntList(const IntList & src)
{
	ptr = NULL;
	*this = src;
	
}
//Operator assigment =
IntList &IntList::operator=(const IntList &src) 
{
	delete [] ptr;
	capacity = src.getCapacity();
	ptr = new int[capacity]; 
	size = 0;
	for(int i=0;i<src.getSize()-1;i++)
	{	
		append(src.getPointer()[i]);	
	}
	return *this;
}
//Destructor
IntList::~IntList()
{
	delete [] ptr;
}
// Check position valid
bool IntList::isValid(int position) const

{
	if(position>=0&&position<=capacity)
		return true;
	else
		 return false;

}
bool IntList::isEmpty () const
{
	if(!size)
		return true;
	else
		return false;
}

bool IntList::isExist ( int element) const
{
	for(int i=0;i<size;i++)
	{
		if(ptr[i] == element)
			return true;
	}
	
	return false;
}

void IntList::append(int element)
{   
	if(!isExist(element))
	{
	  ptr[size]=element;
	  size++;
	}
	
}

int IntList::getElement (int position) const	
{
	if(isValid(position)){
		return ptr[position];
	}
	else 
		return -1 ;//  ERROR '-1':position is not valid
}

bool IntList::setElement( int element, int position)
{
	if(isValid(position)){	
	  ptr[position]= element;
	  return true;
	}
	else
		return false;
}

int IntList::getSize() const
{
	return size;
}

int IntList::getCapacity() const
{
	return capacity;
}

const int * IntList::getPointer() const
{
	return ptr;
}