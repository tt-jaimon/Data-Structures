#ifndef QUEUE_ARRAY_H
#define QUEUE_ARRAY_H

using namespace std;
#include<iostream>

class Queue_Array
{
	static const size_t queue_size = 5;
	typedef size_t size_type;
	typedef int value_type;
	value_type data[queue_size];
	size_type Queue_Size;
	int front_queue;
	int back_queue;	
public:	
	Queue_Array() :front_queue(-1), back_queue(-1), Queue_Size(0){}
	bool empty() const{ return(Queue_Size == 0); }
	void push(const int& x); 
	void pop();
	size_type size() const{ return Queue_Size; }
	value_type& front(){ return data[front_queue];}
	const value_type& front() const { return data[front_queue]; }
	value_type& back() { return data[back_queue]; }
	const value_type& back() const{ return data[back_queue]; }
	friend ostream& operator<<(ostream& out, const Queue_Array& s);
};

#endif