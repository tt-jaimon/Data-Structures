#ifndef ITERATOR_NODE_TEMPLATE_H
#define ITERATOR_NODE_TEMPLATE_H

#include <iostream>
#include "Node_Template.h"
#include <cassert>

template<class Type>
class Iterator_Node
{
	Node<Type>* node_ptr;
public:
	Iterator_Node(Node<Type>* ptr) :node_ptr(ptr){}
	Node<Type>* get_node_ptr(){ return node_ptr; }
	int& operator*()
	{
		assert(this->node_ptr != NULL);
		assert(this->node_ptr->get_next_ptr() != NULL);
		return node_ptr->data;
	}
	const int& operator*() const
	{
		assert(this->node_ptr != NULL);
		assert(this->node_ptr->get_next_ptr() != NULL);
		return node_ptr->data;
	}
	Node<Type>* operator->()
	{
		assert(this->node_ptr != NULL);
		assert(this->node_ptr->get_next_ptr() != NULL);
		return node_ptr;
	}
	const Node<Type>* operator->() const
	{
		assert(this->node_ptr != NULL);
		assert(this->node_ptr->get_next_ptr() != NULL);
		return node_ptr;
	}
	bool operator==(const Iterator_Node<Type>& i)
	{
		return(this->node_ptr == i.node_ptr);
	}
	bool operator!=(const Iterator_Node<Type>& i)
	{
		return !(*this == i);
	}
	Node<Type>& operator++()
	{
		assert(node_ptr != NULL);
		assert(node_ptr->get_next_ptr() != NULL);
		node_ptr = node_ptr->get_next_ptr();
		return *node_ptr;
	}
	Node<Type>& operator++(int)
	{
		assert(node_ptr != NULL);
		assert(node_ptr->get_next_ptr() != NULL);
		Node<int>* temp = this->node_ptr;
		node_ptr = node_ptr->get_next_ptr();
		return *temp;
	}
	Node<Type>& operator--()
	{
		assert(node_ptr != NULL);
		assert(node_ptr->get_prev_ptr() != NULL);
		node_ptr = node_ptr->get_prev_ptr();
		return (*node_ptr);
	}
	Node<Type>& operator--(int)
	{
		assert(node_ptr != NULL);
		assert(node_ptr->get_prev_ptr() != NULL);
		Node<int>* temp = node_ptr;
		node_ptr = node_ptr->get_prev_ptr();
		return (*temp);
	}
	void operator=(const Iterator_Node<Type>& i){ node_ptr = i.node_ptr; }
};

#endif
	





