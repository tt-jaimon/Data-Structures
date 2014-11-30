#ifndef STACK_TEMPLATE_H
#define STACK_TEMPLATE_H

#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

template<class Type>
class Stack_Template
{
	typedef size_t size_type;
	typedef Type value_type;

	static const int stack_size=10;
	value_type data[stack_size];
	int top_of_stack;
public:
	Stack_Template():top_of_stack(-1){}
	bool empty() const
	{
		return (top_of_stack==-1);
	}
	size_type size() const
	{
		return size_type(top_of_stack+1);
	}
	value_type& top()
	{
		return data[top_of_stack];
	}
	const value_type& top()const
	{
		return data[top_of_stack];
	}
	void push(const value_type& s);
	void pop();
	void clear();
	friend ostream& operator<< <Type>(ostream& out,const Stack_Template<Type>& s);
};

#include "Stack_Template.cpp"

#endif

	





    
