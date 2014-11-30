#include "List_Double_ptr_Int.h"
using std::cout;

void List_Double_Ptr_Int::push_back(const int& x)
{
	Node* node=new Node(x);
	if (this->size() == 0)
	{
		sentinel_tail.set_prev_ptr(node);
		node->set_prev_ptr(&sentinel_head);
		sentinel_head.set_next_ptr(node);
		node->set_next_ptr(&sentinel_tail);
		
	}
	else
	{
		Node* temp = sentinel_tail.get_prev_ptr();
		temp->set_next_ptr(node);
		node->set_prev_ptr(temp);
		node->set_next_ptr(&sentinel_tail);
		sentinel_tail.set_prev_ptr(node);
	}
	List_size++;	
}
void List_Double_Ptr_Int::push_front(const int& x)
{
	if (this->size()==0)
		push_back(x);
	else
	{
		Node* node = new Node(x);
		Node* temp = sentinel_head.get_next_ptr();
		sentinel_head.set_next_ptr(node);
		node->set_prev_ptr(&sentinel_head);
		node->set_next_ptr(temp);
		temp->set_prev_ptr(node);		
	}
	List_size++;
}
void List_Double_Ptr_Int::pop_back()
{
	if (empty()) return;
	else
	{
		if (this->size() == 1)
		{
			sentinel_head.set_next_ptr(NULL);
			sentinel_head.set_prev_ptr(NULL);
			sentinel_tail.set_next_ptr(NULL);
			sentinel_tail.set_prev_ptr(NULL);
		}
		else
		{
			Node*next = sentinel_tail.get_prev_ptr();
			Node*prev = next->get_prev_ptr();
			prev->set_next_ptr(&sentinel_tail);
			sentinel_tail.set_prev_ptr(prev);
			delete next;			
		}
		List_size--;
	}
}
void List_Double_Ptr_Int::pop_front()
{
	if (empty()) return;
	else
	{
		if (this->size()==1)
			pop_back();
		else
		{
			List_size--;
			Node* prev = sentinel_head.get_next_ptr();
			Node* next = prev->get_next_ptr();
			sentinel_head.set_next_ptr(next);
			next->set_prev_ptr(&sentinel_head);
			delete prev;
		}
	}
}
void List_Double_Ptr_Int::clear()
{
	while (!(empty()))
		pop_front();
}
ostream& operator<<(ostream& out, const List_Double_Ptr_Int& l)
{
	if (l.empty())
	{
		out << "\nsentinel_head";
		out << " <--sentinel_tail \n";
	}
	else
	{
		Iterator_Node temp = l.begin();
		out << "\nsentinel_head";
		while (temp != l.end())
		{
			out << " -> ";
			out << *temp;
			temp++;
		}
		out << " <--sentinel_tail \n";
	}
	return out;
}
List_Double_Ptr_Int::iterator List_Double_Ptr_Int::insert(List_Double_Ptr_Int::iterator position,const int& x)
{
	if(position==this->begin())
	{
		this->push_front(x);
		return this->begin();
	}
	else if(position==this->end())
	{
		this->push_back(x);
		return this->end();
	}
	else
	{
		Node* node = new Node(x);
		Node* next=sentinel_head.get_next_ptr();
		Node*prev=NULL;

		while(next!=position.get_node_ptr())
		{
			prev=next;
			next=next->get_next_ptr();
		}
		prev->set_next_ptr(node);
		node->set_prev_ptr(prev);
		node->set_next_ptr(next);
		next->set_prev_ptr(node);
		return List_Double_Ptr_Int::iterator(node);
		List_size++;
	}
	
}
List_Double_Ptr_Int::iterator List_Double_Ptr_Int::erase(List_Double_Ptr_Int::iterator position)
{
	if (position==this->begin())
	{
		pop_front();
		return this->begin();
	}
	else if (position==this->end())
	{
		pop_back();
		return this->end();
	}
	else
	{
		Node* next  = sentinel_head.get_next_ptr();
		Node* prev = NULL;
		while (next != position.get_node_ptr())
		{
			prev = next;
			next = next->get_next_ptr();
		}
		prev->set_next_ptr(next->get_next_ptr());
		(next->get_next_ptr())->set_prev_ptr(prev);
		delete next;
		--List_size;
		return iterator(prev->get_next_ptr());
	}
}
List_Double_Ptr_Int::iterator List_Double_Ptr_Int::erase(List_Double_Ptr_Int::iterator first, List_Double_Ptr_Int::iterator last)
{
	while (first!= last)
	{
		iterator temp(first.get_node_ptr());
		first++;		
		erase(temp);
	}
	return last;
}
void List_Double_Ptr_Int::copy(List_Double_Ptr_Int::iterator& beg)
{
	    this->clear();
		this->push_back(*beg);
		beg++;
		while (beg->get_next_ptr()->get_next_ptr()!=NULL )
		{
			this->push_back(*beg);
			beg++;
		}
}
void List_Double_Ptr_Int::swap(List_Double_Ptr_Int& lst)
{
	List_Double_Ptr_Int temp;
	temp.copy(lst.begin());
	lst.copy(this->begin());
	this->copy(temp.begin());
}
void List_Double_Ptr_Int::remove(const int& value)
{
	List_Double_Ptr_Int::iterator it(this->begin());
	while (it != this->end())
	{
		if (*it == value)
		{
			List_Double_Ptr_Int::iterator temp(this->begin());
			temp = it;
			if (it->get_next_ptr()!=NULL)
				it++;
			this->erase(temp);
		}
		else 
			it++;
	}
}
void List_Double_Ptr_Int::remove(List_Double_Ptr_Int::iterator it, const int& value)
{
	it++;
	while (it != this->end())
	{
		if (*it == value)
		{
			List_Double_Ptr_Int::iterator temp(this->begin());
			temp = it;
			if (it->get_next_ptr() != NULL)
				it++;
			this->erase(temp);
		}
		else
			it++;
	}
}
void List_Double_Ptr_Int::unique()
{
	List_Double_Ptr_Int::iterator it(this->begin());
	while (it != this->end())
	{
		this->remove(it,*it);
		if (it->get_next_ptr() == NULL)
			break;
		it++;
	}
}
void List_Double_Ptr_Int::splice(List_Double_Ptr_Int::iterator position, List_Double_Ptr_Int& x)
{
	while (!x.empty())
	{
		List_Double_Ptr_Int::iterator t(x.begin());
		this->insert(position, t->get_data());
		x.pop_front();
		List_size++;
	}
}
void List_Double_Ptr_Int::splice(List_Double_Ptr_Int::iterator position, List_Double_Ptr_Int& x, List_Double_Ptr_Int::iterator i)
{
	List_Double_Ptr_Int::iterator t(i);
	this->insert(position, t->get_data());
	x.erase(i);
	List_size++;
}
void List_Double_Ptr_Int::splice(List_Double_Ptr_Int::iterator position, List_Double_Ptr_Int& x, List_Double_Ptr_Int::iterator first, List_Double_Ptr_Int::iterator last)
{
	while (first != last)
	{
		List_Double_Ptr_Int::iterator t(first);
		this->insert(position, t->get_data());
		first++;
		x.erase(t);
		List_size++;
	}	
}
void List_Double_Ptr_Int::reverse()
{
	if (this->size()> 1)
	{
		Node* tail = sentinel_head.get_next_ptr();
		Node* prev = &sentinel_head;
		Node* cur = sentinel_head.get_next_ptr();
		Node* next = cur->get_next_ptr();
		while (next != &sentinel_tail)
		{
			cur->set_next_ptr(prev);
			prev->set_prev_ptr(cur);
			prev = cur;
			cur = next;
			next = cur->get_next_ptr();
		}
		cur->set_next_ptr(prev);
		prev->set_prev_ptr(cur);	
		cur->set_prev_ptr(&sentinel_head);
		sentinel_head.set_next_ptr(cur);
		tail->set_next_ptr(&sentinel_tail);
		sentinel_tail.set_prev_ptr(tail);
	}
}
void List_Double_Ptr_Int::sort()
{
	int sz = List_size;
	while (--sz)
	{
		Node* prev = &sentinel_head;
		Node* cur = sentinel_head.get_next_ptr();
		Node* next = cur->get_next_ptr();
		while (next != &sentinel_tail)
		{
			int flag = 0;
			if (cur->get_data() > next->get_data())
			{
				Node * temp;
				temp = next->get_next_ptr();
				prev->set_next_ptr(next);
				next->set_prev_ptr(prev);
				next->set_next_ptr(cur);
				cur->set_prev_ptr(next);
				cur->set_next_ptr(temp);
				temp->set_prev_ptr(cur);
				flag = 1;				
			}
			if (flag == 1)
				prev = next;
			else
				prev = cur;
			cur = prev->get_next_ptr();
			next = cur->get_next_ptr();
		}
		cur->set_next_ptr(&sentinel_tail);
		sentinel_tail.set_prev_ptr(cur);
	}
}