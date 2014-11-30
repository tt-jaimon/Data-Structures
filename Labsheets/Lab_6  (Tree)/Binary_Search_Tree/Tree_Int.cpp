#include "Tree_Int.h"
#include<iostream>
#include<queue>
using std::ostream;
using std::cout;
using std::queue;
void Tree_Int::Insert(int x)
{
	Node* node=new Node(x);
	if(this->size()==0)
	{
		root=node;
		root->set_left_ptr(NULL);
		root->set_right_ptr(NULL);
		Tree_size++;
	}
	else
	{
		Tree_size++;
		int flag=0;
		Node* prev=NULL;
		Node* next=root;
		while(next!=NULL)
		{
			prev=next;
			if(x<next->get_data()){next=next->get_left();}
			else if(x>next->get_data()){next=next->get_right();}
			else{ flag=1;break;	}
		}
		if(flag==0)
		{
			if(x<prev->get_data())	prev->set_left_ptr(node);
			else prev->set_right_ptr(node);
		}
	}
}
void Tree_Int::inorder(Node *node_ptr,ostream& out)const
{
	if(node_ptr==NULL) return;
	inorder(node_ptr->get_left());
	out<<node_ptr->get_data();
	inorder(node_ptr->get_right());	
}
void Tree_Int::inorder(ostream& out)const
{
	this->inorder(this->get_root());
	out<<"\n";
}
void Tree_Int::preorder(Node *node_ptr,ostream& out)const
{
	if(node_ptr==NULL) return;
	out<<node_ptr->get_data();
	preorder(node_ptr->get_left());
	preorder(node_ptr->get_right());	
}
void Tree_Int::preorder(ostream& out)const
{
	this->preorder(this->get_root());
	out<<"\n";
}
void Tree_Int::postorder(Node *node_ptr,ostream& out)const
{
	if(node_ptr==NULL) return;
	postorder(node_ptr->get_left());
	postorder(node_ptr->get_right());	
	out<<node_ptr->get_data();
}
void Tree_Int::postorder(ostream& out)const
{
	this->postorder(this->get_root());
	out<<"\n";
}
void Tree_Int::levelorder(ostream& out)const
{
	this->levelorder(this->get_root());
	out<<"\n";
}
void Tree_Int::levelorder(Node* node_ptr,ostream& out)const
{
	queue<Node*> q;
	q.push(node_ptr);
	while(!q.empty())
	{
		Node* temp=q.front();
		if(temp->get_left()!=NULL)
			q.push(temp->get_left());
		if(temp->get_right()!=NULL)
			q.push(temp->get_right());
		cout<<temp->get_data();
		q.pop();
	}
}
Node* Tree_Int::Search(int key)
{
	Node* temp=this->get_root();
	while(temp!=NULL)
	{
		if(key<temp->get_data())
			temp=temp->get_left();
		else if(key>temp->get_data())
			temp=temp->get_right();
		else return temp;	
	}
	return NULL;
}
Node* Tree_Int::get_parent(Node* node)
{
	Node* prev=NULL;
	Node* next=this->get_root();
	while(next!=node)
	{
		prev=next;
		if(node->get_data()<next->get_data())
			next=next->get_left();
		else
			next=next->get_right();
	}
	return prev;
}
Node* Tree_Int::get_parent(int x)
{
	Node* temp=this->Search(x);
	if(temp==NULL)
		return NULL;
	else
		temp=this->get_parent(temp);
	return temp;
}
bool Tree_Int::is_left_child (Node* node)
{
	Node* temp;
	temp=this->get_parent(node);
	if (temp == NULL)
		return false;
	return (temp->get_left()==node);
}
bool Tree_Int::is_left_child (int value)
{
	Node* temp;
	temp=this->get_parent(value);
	if (temp == NULL)
		return false;
	return (temp->get_left()==temp);
}
bool Tree_Int::is_right_child (Node* node)
{
	Node* temp;
	temp=this->get_parent(node);
	if (temp == NULL)
		return false;
	return (temp->get_right()==node);
}
bool Tree_Int::is_right_child (int value)
{
	Node* temp;
	temp=this->get_parent(value);
	if (temp == NULL)
		return false;
	return (temp->get_right()==temp);
}
bool Tree_Int::has_two_siblings(Node* node)
{
	return(node->get_left()!=NULL&&node->get_right()!=NULL);
}
bool Tree_Int::has_two_siblings(int value)
{
	Node* node;
	node=Search(value);
	return(node->get_left()!=NULL&&node->get_right()!=NULL);
}
bool Tree_Int::has_only_one_siblings(Node* node)
{
	int flag=0;
	if (node->get_left() != NULL)
	{
		flag++;
	}
	if (node->get_right() != NULL)
	{
		flag++;
	}
	return (flag==1);
}
bool Tree_Int::has_only_one_siblings(int value)
{
	Node* node;
	node=Search(value);
	int flag=0;
	if (node->get_left() != NULL)
	{
		flag++;
	}
	if (node->get_right() != NULL)
	{
		flag++;
	}
	return (flag==1);
}
bool Tree_Int::is_leaf(Node* node)
{
	return(node->get_left()==NULL&&node->get_right()==NULL);		
}
bool Tree_Int::is_leaf(int value)
{
	Node* node;
	node=Search(value);
	return(node->get_left()==NULL&&node->get_right()==NULL);
}
Node* Tree_Int::get_inorder_successor(Node *node)
{
	if(node==NULL)
		return NULL;
	else
	{
		if(node->get_right()!=NULL)
		{
			Node* curr_node=node->get_right();
			while(curr_node->get_left()!=NULL)
			{
				curr_node=curr_node->get_left();
			}
			return curr_node;
		}
		else
		{
			Node* save_node=NULL;
			Node* curr_node=this->get_root();
			while(curr_node!=NULL)
			{
				if(node->get_data()<curr_node->get_data())
				{
					save_node=curr_node;
					curr_node=curr_node->get_left();
				}
				else if(node->get_data()>curr_node->get_data())
				{
					curr_node=curr_node->get_left();
				}
				else
					break;
			}
			return save_node;
		}
	}
}
Node* Tree_Int::get_inorder_successor(int value)
{
	Node* temp=Search(value);
	return (this->get_inorder_successor(temp));
}
Node* Tree_Int::get_inorder_predecessor(Node *node)
{
	if(node==NULL)
		return NULL;
	else
	{
		if(node->get_left()!=NULL)
		{
			Node* curr_node=node->get_left();
			while(curr_node->get_right()!=NULL)
			{
				curr_node=curr_node->get_right();
			}
			return curr_node;
		}
		else
		{
			Node* save_node=NULL;
			Node* curr_node=this->get_root();
			while(curr_node!=NULL)
			{
				if(node->get_data()<curr_node->get_data())
				{
					curr_node=curr_node->get_left();
				}
				else if(node->get_data()>curr_node->get_data())
				{
					save_node=curr_node;
					curr_node=curr_node->get_left();
				}
				else
					break;
			}
			return save_node;
		}
	}
}
Node* Tree_Int::get_inorder_predecessor(int value)
{
	Node* temp=Search(value);
	return (this->get_inorder_predecessor(temp));
}
bool Tree_Int::delete_node(int value)
{
	Node* node;
	node=Search(value);
	return (this->delete_node(node));
}
bool Tree_Int::delete_node(Node* node)
{
	if(node==NULL)
		return false;
	else
	{
		// if the node is a leaf node
		if(this->is_leaf(node))
		{
			if(node==this->get_root())
				root=NULL;
			else if(this->is_left_child(node))
			{
				Node* parent;
				parent=this->get_parent(node);
				parent->set_left_ptr(node->get_left());
			}
			else
			{
				Node* parent;
				parent=this->get_parent(node);
				parent->set_right_ptr(node->get_right());
			}
			delete node;
			Tree_size--;
			return true;
		}

		// if the node has only one siblings

		else if(this->has_only_one_siblings(node))
		{
			if(node->get_left()!=NULL)
			{
				if (this->is_left_child(node))
				{
					Node* parent;
					parent=this->get_parent(node);
					parent->set_left_ptr(node->get_left());
				}
				else if (this->is_right_child(node))
				{
					Node* parent;
					parent=this->get_parent(node);
					parent->set_right_ptr(node->get_right());
				}
				else
					root = node->get_left();
				delete node;
				Tree_size--;
				return true;
			}			
			else 
			{
				if(this->is_left_child(node))
				{
					Node* parent;
					parent=this->get_parent(node);
					parent->set_left_ptr(node->get_left());
				}
				else if(this->is_right_child(node))
				{
					Node* parent;
					parent=this->get_parent(node);
					parent->set_right_ptr(node->get_right());
				}
				else
					root=node->get_right();
				delete node;
				Tree_size--;
				return true;
			}
		}

		// if the node is has two child nodes

		else
		{
			Node* inorder_pre_or_succ =NULL;
			if(this->Deletion_flag==0)
			{
				this->Deletion_flag=1;
			    inorder_pre_or_succ=this->get_inorder_predecessor(node);
			}
			else if(this->Deletion_flag==1)
			{
				this->Deletion_flag=0;
				inorder_pre_or_succ=this->get_inorder_successor(node);
			}
			int temp= inorder_pre_or_succ->get_data();
			this->delete_node(inorder_pre_or_succ);
			node->set_data(temp);
			return true;
		}
	}
}
void Tree_Int::clear()
{
	while (this->size()!=0)
		this->clear(this->get_root());
}
void Tree_Int::clear(Node* node)
{
	assert(node != NULL);
	this->delete_node(node);
	
}

		





	






