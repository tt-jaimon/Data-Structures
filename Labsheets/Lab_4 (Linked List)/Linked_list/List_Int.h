
#ifndef LIST_INT_H
#define LIST_INT_H

#include<iostream>
#include "Iterator_Node.h"
using namespace std;

class List_Int
{
	typedef size_t size_type;	
	typedef const Iterator_Node const_Iterator;
	Node* head;
	Node* tail;
	size_type List_size;
public:
	typedef Iterator_Node iterator;
	void push_back(const int& );
	explicit List_Int():head(NULL),tail(NULL),List_size(0){}
	explicit List_Int(size_type n, const int& value = 0)
	{
		List_size=0;
		if (n == 0)
		{
			head = tail = NULL;
			List_size = 0;
		}
		else
		{
			head=NULL;
			while (n)
			{
				n--;
				this->push_back(value);
			}
		}
	}
	explicit List_Int(const_Iterator first, const_Iterator last)
	{
		List_size=0;
		Iterator_Node temp = first;
		head=NULL;
		this->push_back(*temp);
		while (temp != last)
		{
			temp++;
			this->push_back(*temp);
		}		
	}
	List_Int(const List_Int& l)
	{
		List_size = 0;
		iterator beg = l.begin();
		this->copy(beg);
	}
	void push_front(const int& );
	void pop_back();
	void pop_front();
	bool empty() const { return(List_size==0);}
	friend ostream& operator<<(ostream&,const List_Int&);
	size_type size() const {return List_size;}
	iterator begin() {return iterator(head);}
	const_Iterator begin() const {return const_Iterator(head);}
	iterator end() 
	{ 
		if(tail==NULL) return NULL;
		return iterator(tail->get_next_ptr());
	}
	const_Iterator end() const
	{
		if(tail==NULL) return NULL;
		return const_Iterator(tail->get_next_ptr());
	}
	void clear();
	iterator insert(iterator position,const int& x);
	void copy(iterator& beg);
	void swap(List_Int& lst);
	iterator erase(iterator postion);
	iterator erase(iterator first,iterator last);
	void remove(const int& value);	
	void remove(iterator it, const int& value);
	void unique();
	void splice(iterator position, List_Int& x);
	void splice(iterator position, List_Int& x, iterator i);
	void splice(iterator position, List_Int& x, iterator first, iterator last);
};
#endif
