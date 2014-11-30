#ifndef ITERATOR_NODE_H
#define ITERATOR_NODE_H

#include <iostream>
#include "Node.h"
#include <cassert>

class Iterator_Node
{
	Node* node_ptr;
public:
	Iterator_Node(Node* ptr) :node_ptr(ptr){}
	Node* get_node_ptr(){ return node_ptr; }
	int& operator*()
	{
		assert(node_ptr != NULL);
		return node_ptr->data;
	}
	const int& operator*() const
	{
		assert(node_ptr != NULL);
		return node_ptr->data;
	}
	Node* operator->()
	{
		assert(node_ptr != NULL);
		return node_ptr;
	}
	const Node* operator->() const
	{
		assert(node_ptr != NULL);
		return node_ptr;
	}
	bool operator==(const Iterator_Node& i)
	{
		return(this->node_ptr == i.node_ptr);
	}
	bool operator!=(const Iterator_Node& i)
	{
		return !(*this == i);
	}
	Node& operator++()
	{
		node_ptr = node_ptr->get_next_ptr();
		return *node_ptr;
	}
	Node& operator++(int)
	{
		Node* temp = this->node_ptr;
		node_ptr = node_ptr->get_next_ptr();
		return *temp;
	}
	void operator=(const Iterator_Node& i){ node_ptr = i.node_ptr; }

};
#endif
	





