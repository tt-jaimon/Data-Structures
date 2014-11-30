#ifndef NODE_TEMPLATE_H
#define NODE_TEMPLATE_H

#include <iostream>
template<class Type>
class Node
{
	int data;
	Node<Type>* next;
	Node<Type>* prev;
public:
	Node():data(0),next(NULL),prev(NULL){}
	Node(int a):data(a),next(NULL),prev(NULL){}
	int get_data() const {return data;}
	Node<Type>* get_next_ptr() const {return next;}
	Node<Type>* get_prev_ptr() const { return prev;}
	void set_data(int d){ data=d;}
	void set_next_ptr(Node<Type>* ptr) { 	next = ptr;}
	void set_prev_ptr(Node<Type>* ptr) { prev = ptr; }
	friend class Iterator_Node<Type>;
};
#endif
