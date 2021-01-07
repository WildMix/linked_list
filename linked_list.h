#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H
#include <cstddef>
#include <iostream>


template <class T>
class linked_list{


	public:
	
		linked_list();
		
		~linked_list();
		
		void append(T);
		
		void pop(T);
		
		void print();

		bool empty();

		int getDim();
		
		T read(int);

		void write(T,int);
		
		T firstValue();
		
		T endValue();
		
		T next(int);
		
		T previous(int);

		void erase(int);
		
		

	
		
		

	private:

		struct Node{

			T data;
	
			Node * next;

		};
		
		int dim;
		
		Node *head;
		
		

};

template <class T>
linked_list<T>::linked_list()
{

	dim = 0;

}


template <class T>
linked_list<T>::~linked_list()
{

	int i;

	for (i = 1; i <= getDim();i++)
	
		erase(i);

}


template <class T>
int linked_list<T>::getDim()
{

	return dim;

}



template <class T>
void linked_list<T>::append(T value)
{

	Node *newNode = new Node;
	
	Node *last = head;
	
	newNode -> data = value;
	
	newNode -> next = NULL;
	
	if (empty())
	{
	
		head = newNode;
		
		dim ++;
		
		return;
	
	}
	
	while (last->next != NULL)
		
		last = last->next;
		
	last->next = newNode;		
	
	
	dim ++;
	
}

template <class T>
void linked_list<T>::pop(T value)
{

	Node *newNode = new Node;
	
	newNode -> data = value;
	
	newNode -> next = head;
	
	head = newNode;
	
	dim ++;

}
template <class T>
void linked_list<T>::print()
{

	int i = 1;
	
	
	if (empty())
	{
	
		std::cout << "\nerror: empty list\n";
	
		return;
	
	}
	
	for(i = 1;i <= getDim();i++)
	{
	
		std::cout << "\n" << read(i) << "\n";
	
	}
	
	std::cout << "\n";
	
}


template <class T>
T linked_list<T>::read(int p)
{

	Node *temp = head;
	
	int flag = 1;
	
	if (!empty())
	{
	
		if (p <= dim)
		{
			
			while (temp->next != NULL || flag <= getDim())
			{
			
				if (p == flag)
				
					return temp->data;
					
				temp = temp->next;
			
				flag++;
				
			}

			temp = temp->next;
			
			return temp->data;
			
		}
		
		std::cout << " error: position out of range\n lenght of the list : " << getDim() << "\n";

		return NULL;

	}
	
	std::cout << "\nerror: empty list\n";
	
	return NULL;

}

template <class T>
void linked_list<T>::write(T value,int position)
{

	
	Node *temp = head;
	
	int flag = 1;


	if (position > dim)
	{
	
		std::cout << " error: position out of range\n lenght of the list : " << getDim() << "\n";
	
		return;
		
	}
	
	while ( temp->next != NULL || flag <= getDim() )
	{
	
		if (position == flag)
		{
		
			temp->data = value;
			
			return;
			
		}
		
		temp = temp->next;
	
		flag ++;
		
	}
	
		dim ++;
}

template <class T>
T linked_list<T>::firstValue()
{

	if (!empty())
	
		return (head->data);
	
	std::cout << "\nerror: empty list\n";
	
	return NULL;
	
}

template <class T>
T linked_list<T>::endValue()
{

	if (!empty())
	
		return read(getDim());

		
		
	
	
	std::cout << "\nerror: empty list\n";
	
	return NULL;

}

template <class T>
T linked_list<T>::next(int position)
{

	if (!empty())
	{
		
		
		if (position >= dim)
		{
	
			std::cout << "\nerror: position out of range\n lenght of the list : " << getDim() << "\n";
	
			return -1;
		
		}
		
		return read(position + 1);
		
		
	}
	
	std::cout << "\nerror: empty list\n";
	
	return NULL;

}


template <class T>
T linked_list<T>::previous(int position)
{

	if (!empty())
	{
		
		
		if (position != 1)
		{
	
			int flag = 2;
			
			Node *temp = head;
			
			while (temp->next != NULL )
			{	
			
				
				if (position == flag)
				
					return (temp->data);
					
					
				temp = temp->next;
			
				flag ++;
			
			}
				
		
		}
		
		std::cout << "\nerror: head node have no previous node\n"; 
		
		return NULL;
		
		
		
	}
	
	std::cout << "\nerror: empty list\n";
	
	return NULL;


}



template <class T>
void linked_list<T>::erase(int position)
{

	if (!empty())
	{
	
		if (position <= dim)
		{
			
			Node *temp = head;
			

			int flag = 1;
				
			
			if (position == 1)
			{
				
				Node *newNode = temp->next;
				
				head = newNode;
				
				delete temp;
				
				dim --;
				
				return;
				
			}
				
			
			flag = 0;
			
			for (flag = 0; flag < position - 2; flag++)
			
				temp = temp->next;	// previous node of the node to erase
			
			Node *temp2 = temp->next;	// node to erase
			
			temp->next = temp2->next;	// the next of the previous one should be the next of the node to erase
			
			delete temp2;			// delete the node
			
			dim --;
			
			return;
			
		}
		
		std::cout << "\nerror: position out of range\n lenght of the list : " << getDim() << "\n";
		
		return;
	
	}
	
	std::cout << "\nerror: empty list\n";
	

}

template <class T>
bool linked_list<T>::empty()
{

	return (getDim() == 0);

}


#endif
