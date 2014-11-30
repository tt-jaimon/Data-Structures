#include "List_Int.h"
using std::cout;

void List_Int::push_back(const int& x)
{
	Node* node=new Node(x);
	List_size++; 
	if(head==NULL)
	{
		head=tail=node;
	}
	else
	{
		tail->set_next_ptr(node);
		tail=node;
	}
}
void List_Int::push_front(const int& x)
{
	List_size++;
	if(head==NULL)
		push_back(x);
	else
	{
		Node* node=new Node(x);
		node->set_next_ptr(head);
		head=node;
	}
}
void List_Int::pop_back()
{
	if(empty()) return;
	else
	{
		List_size--;
		if(head==tail)
			head=tail=NULL;
		else
		{
			Node*temp=head;
			while(temp->get_next_ptr()!=tail)
			{
				temp=temp->get_next_ptr();
			}
			delete tail;
			tail=temp;
		}
	}
}
void List_Int::pop_front()
{
	if(empty()) return;
	else
	{
		if(head==tail)
			pop_back();
		else
		{
			List_size--;
			Node* temp=head;
			head=head->get_next_ptr();
			delete temp;
		}
	}
}
void List_Int::clear()
{
	while(!(empty()))
		pop_front();
}
ostream& operator<<(ostream& out, const List_Int& l)
{
	Iterator_Node temp=l.begin();
	out<<"\nHead";
	while(temp!=l.end())
	{ 
		out<<" -> ";
		out<<*temp;
		temp++;
	}
	out<<" <--tail \n";
	return out;
}
List_Int::iterator List_Int::insert(List_Int::iterator position,const int& x)
{
	Node* temp=new Node(x);
	List_size++;

	if(position==this->begin())
	{
		temp->set_next_ptr(head);
		head=temp;
	}
	else if(position==this->end())
	{
		tail->set_next_ptr(temp);
		tail=temp;
	}
	else
	{
		Node* next=head;
		Node*prev=NULL;

		while(next!=position.get_node_ptr())
		{
			prev=next;
			next=next->get_next_ptr();
		}
		prev->set_next_ptr(temp);
		temp->set_next_ptr(next);
	}
	return List_Int::iterator(temp);
}
List_Int::iterator List_Int::erase(List_Int::iterator position)
{
	if (position.get_node_ptr() == head)
	{
		pop_front();
		return this->begin();
	}
	else if (position.get_node_ptr() == tail)
	{
		pop_back();
		return this->end();
	}
	else
	{
		Node* next  = head;
		Node* prev = NULL;
		while (next != position.get_node_ptr())
		{
			prev = next;
			next = next->get_next_ptr();
		}
		prev->set_next_ptr(next->get_next_ptr());
		delete next;
		--List_size;
		return iterator(prev->get_next_ptr());
	}
}
List_Int::iterator List_Int::erase(List_Int::iterator first, List_Int::iterator last)
{
	while (first!= last)
	{
		iterator temp(first.get_node_ptr());
		first++;		
		erase(temp);
	}
	return last;
}
void List_Int::copy(List_Int::iterator& beg)
{
	    this->clear();
		head=NULL;
		this->push_back(*beg);
		beg++;
		while (beg != NULL)
		{
			this->push_back(*beg);
			beg++;
		}
}
void List_Int::swap(List_Int& lst)
{
	List_Int temp;
	temp.copy(lst.begin());
	lst.copy(this->begin());
	this->copy(temp.begin());
}
void List_Int::remove(const int& value)
{
	List_Int::iterator it(this->begin());
	while (it != this->end())
	{
		if (*it == value)
		{
			List_Int::iterator temp(this->begin());
			temp = it;
			if (it->get_next_ptr()!=NULL)
				it++;
			this->erase(temp);
		}
		else 
			it++;
	}
}
void List_Int::remove(List_Int::iterator it, const int& value)
{
	it++;
	while (it != this->end())
	{
		if (*it == value)
		{
			List_Int::iterator temp(this->begin());
			temp = it;
			if (it->get_next_ptr() != NULL)
				it++;
			this->erase(temp);
		}
		else
			it++;
	}
}
void List_Int::unique()
{
	List_Int::iterator it(this->begin());
	while (it != this->end())
	{
		this->remove(it,*it);
		if (it->get_next_ptr() == NULL)
			break;
		it++;
	}
}
void List_Int::splice(List_Int::iterator position, List_Int& x)
{
	while (!x.empty())
	{
		List_Int::iterator t(x.begin());
		this->insert(position, t->get_data());
		x.pop_front();
		List_size++;
	}
}
void List_Int::splice(List_Int::iterator position, List_Int& x, List_Int::iterator i)
{
	List_Int::iterator t(i);
	this->insert(position, t->get_data());
	x.erase(i);
	List_size++;
}
void List_Int::splice(List_Int::iterator position, List_Int& x, List_Int::iterator first, List_Int::iterator last)
{
	while (first != last)
	{
		List_Int::iterator t(first);
		this->insert(position, t->get_data());
		first++;
		x.erase(t);
		List_size++;
	}	
}
