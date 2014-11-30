#ifndef NODE_H
#define NODE_H

#include <iostream>

class Node
{
	int data;
	Node* next;
	Node* prev;
public:
	Node():data(0),next(NULL),prev(NULL){}
	Node(int a):data(a),next(NULL),prev(NULL){}
	int get_data() const {return data;}
	Node* get_next_ptr() const {return next;}
	Node* get_prev_ptr() const { return prev;}
	void set_data(int d){ data=d;}
	void set_next_ptr(Node* ptr) { 	next = ptr;}
	void set_prev_ptr(Node* ptr) { prev = ptr; }
	friend class Iterator_Node;
};

#endif
