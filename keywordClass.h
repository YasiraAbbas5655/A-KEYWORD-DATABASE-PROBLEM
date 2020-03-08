class info;
class DB;
class keyword;

class info
{
public:
	info(string name, int location){fileName = name;address=location;}
	info(){address = -1;}
	/*bool operator < (const info &i);*/
	//implement whatever else you need
private:
	string fileName;
	int address;      //contains position of the word in file

	friend ostream & operator << (ostream &strm, const info &i);

};

class keyword
{
public:
	keyword(){}
	keyword(string str) {word = str;}
	void addInfo(string fileName,int address){info i(fileName,address);infoList.add(i);}
	bool operator == (const keyword &k)
	{
		for (int i=0;word[i]!='\0';i++)
		{
			if (word[i]!=k.word[i])
			{
				return false;
			}
		}
		return true;
	}
	bool operator != (const keyword &k)
	{
		for (int i=0;word[i]!='\0';i++)
		{
			if (word[i]!=k.word[i])
			{
				return true;
			}
		}
		return false;
	}
	bool operator == (const string &str)
	{
	   for (int i=0;word[i]!='\0';i++)
		  {
			  if (word[i]!=str[i])
			  {
			    	return true;
			  }
		  } 
		return false;
	}
	bool operator != (const string &str)
	{
		for (int i=0;word[i]!='\0';i++)
		{
			if (word[i]!=str[i])
			{
				return true;
			}
		}
		return false;
	}
	/*bool operator < (const keyword &k)  ;*/
private:
	string word;
	myLinkedList<info> infoList;

	friend class DB;
	friend ostream & operator << (ostream &strm, const keyword &k);

};

class DB
{
public:	
	DB(){};
	bool add(string fileName);
	bool remove(string fileName)
	{
		
		list.remove(fileName);
	}
	void print();
private:
	myLinkedList<keyword> list;
};
