#include <fstream>
#include <iostream>
#include <string>

using namespace std;

#include "myLinkedList.h"
#include "keywordClass.h"

//fill it
ostream & operator << (ostream &strm, const keyword &k)
{
	for(int i=0;k.word[i]!='\0';i++)
	{
		strm<<k.word[i];
	}
	cout<<"->";
	keyword k2=k;
    k2.infoList.print();
	cout<<endl;
	
	return strm;
}
//fill it
ostream & operator << (ostream &strm, const info &i)
{
	strm<<i.fileName<<"keyword.txt";
	strm<<i.address;
	return strm;
}



bool DB::add(string fileName)
{
		string wordRead;
	
	ifstream strm(fileName);
	long int pos = 0;
	if (strm.is_open())
		pos = strm.tellg();
		strm >> wordRead;
		
		keyword k1(wordRead);
		k1.addInfo(fileName,pos);
		list.add(k1);
		myLinkedList<keyword>::iter myIter;
	    myIter = list.begin();
	{	while (!strm.eof())
		{
			pos = 0;
			pos = strm.tellg();
			strm >> wordRead;
			
			myIter=list.find(wordRead);
			if (myIter==nullptr)
			{
				keyword k1(wordRead);
				k1.addInfo(fileName,pos);
				list.add(k1);

			}
			else
			{
				keyword temp=*myIter;
				temp.addInfo(fileName,pos);
				*myIter=temp;
			}
			
			 //convert the word to small case first
			//now add code to insert the word read in the linked list object of this class
			//you need the myIter to check whether the word is already in the list or not
			//if the word is in the list then add the keyword's info to the already existing list
			//if the word is not in the list then insert it in the keyword list and insert its corresponding info
		}
	}
	return true;
}

void DB::print()
{
	myLinkedList<keyword>::iter itKeywords;
	myLinkedList<info>::iter itInfo;

	for (itKeywords=list.begin();itKeywords!=list.end();++itKeywords)
	{
		cout<<*itKeywords;
	}
}

void main()
{

	DB db;
	db.add("try1");
	db.print();

	system("pause");
	
}