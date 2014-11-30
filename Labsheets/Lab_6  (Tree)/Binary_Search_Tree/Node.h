#ifndef NODE_H
#define NODE_H

#include <iostream>

class Node
{
	int data;
	Node* left;
	Node* right;
public:
	Node():data(0),left(NULL),right(NULL){}
	Node(int a):data(a),left(NULL),right(NULL){}
	int get_data() const {return data;}
	Node* get_left() const {return left;}
	Node* get_right() const { return right;}
	void set_data(int d){ data=d;}
	void set_left_ptr(Node* ptr) { 	left = ptr;}
	void set_right_ptr(Node* ptr) { right = ptr; }
	friend class Iterator_Node;
};

#endif
