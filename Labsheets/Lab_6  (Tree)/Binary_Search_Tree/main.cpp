#include<iostream>
#include "Tree_Int.h"
using namespace std;
int main()
{
	Tree_Int t;
	t.Insert(4);
	t.Insert(2);
	t.Insert(1);
	t.Insert(3);
	t.Insert(6);
	t.Insert(5);
	t.Insert(7);
	t.Insert(8);
	t.inorder();
	t.preorder();
	t.postorder();
	t.levelorder();
	Node* test=t.get_inorder_successor(6);
	cout<<"\nsucessor :"<<test->get_data()<<"\n";
	Node* test1=t.get_inorder_predecessor(6);
	cout<<"\npredecessor: "<<test1->get_data()<<"\n";
	Node* temp;
	temp=t.Search(6);
	if(temp==NULL)
		cout<<"No such element";
	else
		cout<<temp->get_data(); 
	cout<<"\n";
	temp=t.get_parent(7);
	if(temp==NULL)
		cout<<"No such element";
	else
		cout<<temp->get_data(); 
	cout<<"\n";
	t.delete_node(3);
	t.inorder();
	cout<<t.size();
	t.inorder();
	t.clear();
	t.Insert(8);
	t.inorder();
	Tree_Int t1;
	t1.Insert(4);
	t1.Insert(3);
	t1.Insert(7);
	t1.Insert(8);
	t1.delete_node(4);
	t1.delete_node(3);
	t1.inorder();
	return 0;
}

