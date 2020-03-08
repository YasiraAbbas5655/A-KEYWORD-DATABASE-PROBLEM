#ifndef MYLINKEDLIST_H
#define MYLINKEDLIST_H

template <class type> class myLinkedList;


template <class type>
class myNode
{
public:
	myNode(type val){data = val;next=nullptr;}
private:
	type data;
	myNode<type> *next;
	friend class myLinkedList<type>;
};


template <class type>
class myLinkedList
{

private:
	class myIterator
	{
		myNode<type> *nodePtr;
	public:
		myIterator(){nodePtr = nullptr;}
		myIterator(myNode<type>* n){nodePtr = n;}
		const myIterator & operator ++()
		{
			if (nodePtr==nullptr)
			{
				return *this;
			}
			nodePtr=nodePtr->next;
			return *this;
		}
		const myIterator  operator++(int) 
		{
			int i=0;
			while (i!=Num_of_it)
			{
				nodePtr=nodePtr->next;
			}
			return *this;
		}
		bool operator  ==(const myIterator &it)
		{
			if (nodePtr==it.nodePtr)
			{
				return true;
			}
			return false;
		}
		bool operator  !=(const myIterator &it)
		{
			if (nodePtr!=it.nodePtr)
			{
				return true;
			}
			return false;
		}
		const myIterator & operator = (myNode<type> *n)
		{
			nodePtr=n;
			return *this;
		}
		type* operator ->()
		{
			return nodePtr;
		}
		type& operator*  ()
		{
			
			return nodePtr->data;
		}

	};

public:
	typedef myIterator iter;

	myLinkedList(){head = nullptr;}
	/*~myLinkedList();*/
	void remove(type val);
	void print();	
	iter begin(){iter it(head);return it;};
	iter end()  
	{
		iter it=begin();
		iter previous;
		while (it != nullptr)
		{
			/*previous = it;*/
			++it;
		}
		return it;
	}
	iter find(type val);
	iter add(type val);

private:	
	myNode<type> *head;
	iter addToHead(type val);
};


template <class type>
typename myLinkedList<type>::iter myLinkedList<type>::addToHead(type val)
{
	iter it;
	myNode<type>* temp = new myNode<type>(val);
	head = temp;
	it=head;
	return it;
}

template <class type>
typename myLinkedList<type>::iter myLinkedList<type>::add(type val)
{
	iter it;
	if (head == nullptr)
		{
			it=addToHead(val);
		}
		else {
			myNode<type>* current = head;
			while (current->next != nullptr)
			{
				current = current->next;
			}
			myNode<type>* temp = new myNode<type>(val);
			current->next = temp;
		}
		it=head;
		return it;
}


template <class type>
void myLinkedList<type>::remove(type val)
{
	if (head->data == val)
		{
			delete head;
			head = nullptr;
		}
		else {
			myNode<type>* curr = head;
			myNode<type>* previous = nullptr;
			while (curr->data != val)
			{
				previous = curr;
				curr = curr->next;
			}
			previous->next = curr->next;
			delete curr;
		}
}

template <class type>
typename myLinkedList<type>::iter myLinkedList<type>::find(type val)
{
		iter i=begin();
 		while (*i != val )
		{
			++i;
			if (i==end())
			{
				return nullptr;

			}
		}
		
		return i;
}

template <class type>
void myLinkedList<type>::print()
{
	myNode<type>* curr = head;
		while (curr != nullptr)
		{
			cout << curr->data;
			curr = curr->next;
		}
}

//implement all other methods like destructor etc.

#endif
