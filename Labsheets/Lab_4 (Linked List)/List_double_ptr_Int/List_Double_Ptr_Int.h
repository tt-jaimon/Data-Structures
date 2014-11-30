
#ifndef List_Double_Ptr_Int_H
#define List_Double_Ptr_Int_H

#include<iostream>
#include "Iterator_Node.h"
using namespace std;

class List_Double_Ptr_Int
{
	typedef size_t size_type;	
	typedef const Iterator_Node const_Iterator;
	Node sentinel_head;
	Node sentinel_tail;	
	size_type List_size;
public:
	typedef Iterator_Node iterator;
	void push_back(const int& x );
	explicit List_Double_Ptr_Int () :sentinel_head(), sentinel_tail(), List_size(0){}
	explicit List_Double_Ptr_Int(size_type n, const int& value = 0) :sentinel_head(), sentinel_tail(), List_size(0)
	{
		while (n)
			{
				n--;
				this->push_back(value);
			}
	}
	explicit List_Double_Ptr_Int(const_Iterator first, const_Iterator last) :sentinel_head(), sentinel_tail(), List_size(0)
	{
		Iterator_Node temp = first;
		this->push_back(*temp);
		while (temp != last)
		{
			temp++;
			this->push_back(*temp);
		}		
	}
	List_Double_Ptr_Int(const List_Double_Ptr_Int& l) :sentinel_head(), sentinel_tail(), List_size(0)
	{
		iterator beg = l.begin();
		this->copy(beg);
	}
	virtual~List_Double_Ptr_Int(){ this->clear(); }
	void push_front(const int& );
	void pop_back();
	void pop_front();
	bool empty() const { return(List_size==0);}
	friend ostream& operator<<(ostream&,const List_Double_Ptr_Int&);
	size_type size() const {return List_size;}
	iterator begin() {return iterator(sentinel_head.get_next_ptr());}
	const_Iterator begin() const {return const_Iterator(sentinel_head.get_next_ptr());}
	iterator end() 
	{ 
		return iterator(&sentinel_tail);
	}
	const_Iterator end() const
	{
		return const_Iterator((Node* const) &sentinel_tail);
	}
	void clear();
	iterator insert(iterator position,const int& x);
	void copy(iterator& beg);
	void swap(List_Double_Ptr_Int& lst);
	iterator erase(iterator postion);
	iterator erase(iterator first,iterator last);
	void remove(const int& value);	
	void remove(iterator it, const int& value);
	void unique();
	void splice(iterator position, List_Double_Ptr_Int& x);
	void splice(iterator position, List_Double_Ptr_Int& x, iterator i);
	void splice(iterator position, List_Double_Ptr_Int& x, iterator first, iterator last);
	void reverse();
	void sort();
};
#endif

