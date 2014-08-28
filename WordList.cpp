#include "WordList.h"

WordNode::WordNode()
{
	next= NULL;
}

WordNode::WordNode(char *word, int length, int lineNum) 
{
	next= NULL;	
	worddata = WordData(word,length,lineNum);

}

WordNode::~WordNode()
{
	delete next;
}

WordData & WordNode::getData() 
{
	return worddata;
}
void WordNode::setNext(WordNode * next)
{
	this->next = next;
}
WordNode * WordNode::getNext()
{
	return next;
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------

WordList::WordList(char * fname)
{
	size = 1;
	head=NULL;
	end =NULL;
	loadList(fname);

}


WordList::~WordList(){
	delete head;
}

void WordList::loadList(char* fname)
{
	char temp[30];
	char ch;
	int length=0;
	int lineNum =1;
	ifstream fin(fname);

	//Read the first word into the head node
	cout<<"Word Collection Source File: "<< fname<<endl;
	do{
		ch=fin.get();
		if(ch==' ')
		{   
			temp[length]='\0';
			head = new WordNode(temp,length+1,lineNum);
						
			end=head;
			length=0;
			break;
		}
		else
		{
		temp[length]=ch;
		length++;
		}
	}while(1);


	//Read the rest words
	
	do{
		
		ch=fin.get();
		if(ch =='\n')
			lineNum++;
		if(ch==' '||ch==';'|| ch=='\n' ) // Token judgement
		{
			temp[length]='\0';
			if(length!=0)
			wordsOperation(temp, length+1, lineNum);  // WordOperation
			length=0;
		}
		else if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')||(ch=='.'&&temp[length-1]=='i')||(temp[length-1]=='t'&&ch=='\'')) // not the token keep reading
		{
		temp[length]=ch;
		length++;
		}	
	}while(!fin.eof());
	temp[length]='\0';
	wordsOperation(temp, length+1, lineNum);// Handle the last word;
	
}
void WordList::wordsOperation( char * words, int length, int lineNum)
{
	WordNode *previous = NULL;
	WordNode * current = getPointer(words) ;
	//cout<<words<<endl;
	if(current== NULL) // Given words not exist in the list, Insert intto the List
	{
		current = head;
		int flag;

		do
		{
			flag =current->getData().compareWords(words);
			if(flag==-1) // Insert after previous, not the final position keep searching
			{
				previous = current;
				current = current->getNext();
				if(current==NULL)   // Insert in the end of the list;
				{
					//cout<<words<<endl;
					end = new WordNode(words, length ,lineNum);
					previous->setNext(end);
					
					break;
				}
			}
			else        //Insert before current;
			{
				if(current==head)  // Insert before Head
				{
					head = new WordNode(words, length ,lineNum);
					head->setNext(current);
					break;
				}
				else   //Insert befroe other nodes
				{
					WordNode *temp = new WordNode(words, length ,lineNum);
					temp->setNext(current);
					previous->setNext(temp);
					break;
				}

			}
			
		}while(1);

		size++;
	}
	else
	{
		current->getData().appendLineNum(lineNum);
		//cout<<"duplicated  "<< words<<endl;
		
	}

}

WordNode * WordList::getPointer( char* words)
{
	WordNode *current = head;
	int i=1;
	for(int i=0;i<size;i++)
	{
		if(current->getData().compareWords(words)==0)
			return current;
		current= current->getNext();
	}
	return NULL;
}
	
int  WordList::getSize() const
{
	return size;
}

void  WordList::printFormat() const
{
	char ch='A';
	WordNode * current =head;
	cout<<"============================="<<endl;
	cout<<left<<setw(1)<<"<"<<'A'<<">"<<endl;
	while(current!=NULL)
	{   
		
		if(ch==toupper(current->getData().getWord()[0]))
		{
		current->getData().print();
		current= current->getNext();
		}
		else
		{
			ch ++;
			cout<<left<<setw(1)<<"<"<<ch<<">"<<endl;
		}
		
	}
	if(ch!='Z')
		cout<<left<<setw(1)<<"<"<<++ch<<">"<<endl;
		cin.get();
}