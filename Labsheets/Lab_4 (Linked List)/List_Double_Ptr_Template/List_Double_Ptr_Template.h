
#ifndef List_Double_Ptr_Template_H
#define List_Double_Ptr_Template_H

#include<iostream>
#include "Iterator_Node_Template.h"
using namespace std;

template<class Type>
class List_Double_Ptr_Template
{
	typedef size_t size_type;	
	typedef const Iterator_Node<Type> const_Iterator;
	Node<Type> sentinel_head;
	Node<Type> sentinel_tail;	
	size_type List_size;
public:
	typedef Iterator_Node<Type> iterator;
	void push_back(const int& x );
	explicit List_Double_Ptr_Template() :sentinel_head(), sentinel_tail(), List_size(0){}
	explicit List_Double_Ptr_Template(size_type n, const int& value = 0) :sentinel_head(), sentinel_tail(), List_size(0)
	{
		while (n)
			{
				n--;
				this->push_back(value);
			}
	}
	explicit List_Double_Ptr_Template(typename const_Iterator first, typename const_Iterator last) :sentinel_head(), sentinel_tail(), List_size(0)
	{
		Iterator_Node temp = first;
		this->push_back(*temp);
		while (temp != last)
		{
			temp++;
			this->push_back(*temp);
		}		
	}
	List_Double_Ptr_Template(const List_Double_Ptr_Template<Type>& l) :sentinel_head(), sentinel_tail(), List_size(0)
	{
		iterator beg = l.begin();
		this->copy(beg);
	}
	virtual~List_Double_Ptr_Template(){ this->clear(); }
	void push_front(const int& );
	void pop_back();
	void pop_front();
	bool empty() const { return(List_size==0);}
	friend ostream& operator<<(ostream&,const List_Double_Ptr_Template<Type>&);
	size_type size() const {return List_size;}
	typename iterator begin() {return typename iterator(sentinel_head.get_next_ptr());}
	typename const_Iterator begin() const {return typename const_Iterator(sentinel_head.get_next_ptr());}
	typename iterator end() 
	{ 
		return typename iterator(&sentinel_tail);
	}
	const_Iterator end() const
	{
		return typename const_Iterator((Node<Type>* const) &sentinel_tail);
	}
	void clear();
	typename iterator insert(typename iterator position,const int& x);
	void copy(typename iterator& beg);
	void swap(List_Double_Ptr_Template<Type>& lst);
	iterator erase(iterator postion);
	iterator erase(iterator first,iterator last);
	void remove(const int& value);	
	void remove(iterator it, const int& value);
	void unique();
	void splice(iterator position, List_Double_Ptr_Template<Type>& x);
	void splice(iterator position, List_Double_Ptr_Template<Type>& x, iterator i);
	void splice(iterator position, List_Double_Ptr_Template<Type>& x, iterator first, iterator last);
	void reverse();
	void sort();
};
#include "List_Double_Ptr_Template.cpp"
#endif

