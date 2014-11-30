#ifndef NODE_H
#define NODE_H

//#include "Iterator_Node.h"
#include <iostream>

class Node
{
	int data;
	Node* next;
public:
	Node():data(0),next(NULL){}
	Node(int a):data(a),next(NULL){}
	int get_data() const {return data;}
	Node* get_next_ptr() const {return next;}
	void set_data(int d){ data=d;}
	void set_next_ptr(Node* ptr) {next=ptr;}
	friend class Iterator_Node;
};

#endif
