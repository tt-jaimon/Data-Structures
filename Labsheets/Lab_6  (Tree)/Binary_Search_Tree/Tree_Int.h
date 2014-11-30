#ifndef TREE_INT_H
#define TREE_INT_H

#include<iostream>
#include "Iterator_Node.h"
using std::ostream;
using std::cout;

class Tree_Int
{
	typedef size_t size_type;
	Node* root;
	size_type Tree_size;
	size_type Deletion_flag;
public:
	Tree_Int():root(NULL),Tree_size(0),Deletion_flag(0){}
	~Tree_Int(){this->clear();}
	bool empty(){return (Tree_size==0);}
	size_type size(){return Tree_size;}
	void Insert(int x);
	Node* get_root()const{ return root;}
	void inorder(Node *node_ptr,ostream& out = cout)const; 
	void inorder(ostream& out = cout)const;
	void preorder(Node *node_ptr,ostream& out = cout)const; 
	void preorder(ostream& out = cout)const;
	void postorder(Node *node_ptr,ostream& out = cout)const; 
	void postorder(ostream& out = cout)const;
	void levelorder(Node *node_ptr,ostream& out = cout)const; 
	void levelorder(ostream& out = cout)const;
	Node* Search(int key);
	Node* get_parent(Node* node);
	Node* get_parent(int x);
	bool is_left_child (Node* node);
	bool is_left_child (int value);
	bool is_right_child (Node* node);
	bool is_right_child (int value);
	bool is_root(Node* node){ return(this->get_root()==node);}
	bool is_root(int value)
	{
		Node* node;
		node=Search(value);
		return(this->get_root()==node);
	}
	bool has_two_siblings(Node* node);
	bool has_two_siblings(int value);
	bool is_leaf(int value);
	bool is_leaf(Node* node);
	bool has_only_one_siblings(int value);
	bool has_only_one_siblings(Node* node);
	Node* get_inorder_successor(Node *node); 
	Node* get_inorder_successor(int value);
	Node* get_inorder_predecessor(Node *node); 
	Node* get_inorder_predecessor(int value);
	bool delete_node(int value); 
	bool delete_node(Node* node); 
	void clear();
	void clear(Node* node);
};
#endif


