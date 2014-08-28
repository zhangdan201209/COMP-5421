#include "WordData.h"

//Default constructor
WordData::WordData()
{
	ptr = NULL;

}
//Constructor overloading
WordData::WordData(char* word, int length, int lineNum)
{
	
	ptr = new char[length];
	strcpy(ptr,word);
	this->length =length;
	frequency=1;
	
	intlist = IntList(lineNum);
	

}
//Copy constructor
WordData::WordData(WordData & worddata)
{
	ptr =NULL;
	*this = worddata;

}
//Assignment operator define
WordData &WordData::operator=(WordData &worddata) 
{
	delete []ptr;
	length = worddata.getLength();

	ptr = new char[length];
	strcpy(ptr,worddata.getWord());
	frequency=worddata.getFrequency();
	intlist = worddata.getList();
	
	return *this;
}
//Destructor
WordData::~WordData()
{
	delete[] ptr;
	// cout<<"DELETE DATA"<<endl;
}

void WordData::appendLineNum(int lineNumber)
{
	frequency++;
	intlist.append(lineNumber);

}


int WordData::getFrequency() const
{
	return frequency;
}
int WordData::getLength() const
{
	return length;
}
const char * WordData::getWord() const
{
	return ptr;
}

const IntList& WordData::getList() const
{
	return intlist;
}

int WordData::compareWords(char * words) const
{
	char *src = ptr;
	char *dst = words;
	  while(*src && *dst)
    {
        char c_local=*src, c_in=*dst;
        if(c_local>='A' && c_local<='Z')
            c_local +=32;
        if(c_in>='A' && c_in<='Z')
            c_in +=32;
        if(c_local==c_in )
        {
            ++src;
            ++dst;
        }
        else
        {
            if(c_local>c_in)
                return 1;
            else
                return -1;
        }
    }
    if(*src==*dst)
        return 0;         // Indicate equal 
    else if(*src)
        return 1;         //Indicate dst is null, insert dst befor src
    else
        return -1;		  //Indicate src is null, insert dst after src	
}

void WordData::print() const
{
	//Print the word
	cout<<setw(12)<<right<<ptr<<setw(3)<<"("<< setw(1)<<frequency<<")";
	//Print the frequency and related line number
	for(int i=0;i< intlist.getSize();i++)
	{
		cout<<setw(3)<<intlist.getElement(i);
	}
	cout<<endl;

}
