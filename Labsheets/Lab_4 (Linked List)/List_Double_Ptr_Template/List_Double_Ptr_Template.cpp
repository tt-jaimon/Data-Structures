#include "List_Double_Ptr_Template.h"
using std::cout;

template<class Type>
void List_Double_Ptr_Template<Type>::push_back(const int& x)
{
	Node<Type>* node=new Node(x);
	if (this->size() == 0)
	{
		sentinel_tail.set_prev_ptr(node);
		node->set_prev_ptr(&sentinel_head);
		sentinel_head.set_next_ptr(node);
		node->set_next_ptr(&sentinel_tail);
		
	}
	else
	{
		Node<Type>* temp = sentinel_tail.get_prev_ptr();
		temp->set_next_ptr(node);
		node->set_prev_ptr(temp);
		node->set_next_ptr(&sentinel_tail);
		sentinel_tail.set_prev_ptr(node);
	}
	List_size++;	
}
template<class Type>
void List_Double_Ptr_Template<Type>::push_front(const int& x)
{
	if (this->size()==0)
		push_back(x);
	else
	{
		Node<Type>* node = new Node(x);
		Node<Type>* temp = sentinel_head.get_next_ptr();
		sentinel_head.set_next_ptr(node);
		node->set_prev_ptr(&sentinel_head);
		node->set_next_ptr(temp);
		temp->set_prev_ptr(node);		
	}
	List_size++;
}
template<class Type>
void List_Double_Ptr_Template<Type>::pop_back()
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
			Node<Type>*next = sentinel_tail.get_prev_ptr();
			Node<Type>*prev = next->get_prev_ptr();
			prev->set_next_ptr(&sentinel_tail);
			sentinel_tail.set_prev_ptr(prev);
			delete next;			
		}
		List_size--;
	}
}
template<class Type>
void List_Double_Ptr_Template<Type>::pop_front()
{
	if (empty()) return;
	else
	{
		if (this->size()==1)
			pop_back();
		else
		{
			List_size--;
			Node<Type>* prev = sentinel_head.get_next_ptr();
			Node<Type>* next = prev->get_next_ptr();
			sentinel_head.set_next_ptr(next);
			next->set_prev_ptr(&sentinel_head);
			delete prev;
		}
	}
}
template<class Type>
void List_Double_Ptr_Template<Type>::clear()
{
	while (!(empty()))
		pop_front();
}
template<class Type>
ostream& operator<<(ostream& out, const List_Double_Ptr_Template<Type>& l)
{
	if (l.empty())
	{
		out << "\nsentinel_head";
		out << " <--sentinel_tail \n";
	}
	else
	{
		Iterator_Node<Type> temp = l.begin();
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
template<class Type>
 typename List_Double_Ptr_Template<Type>::iterator List_Double_Ptr_Template<Type>::insert(typename List_Double_Ptr_Template<Type>::iterator position,const int& x)
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
		Node<Type>* node = new Node(x);
		Node<Type>* next=sentinel_head.get_next_ptr();
		Node<Type>*prev=NULL;
		while(next!=position.get_node_ptr())
		{
			prev=next;
			next=next->get_next_ptr();
		}
		prev->set_next_ptr(node);
		node->set_prev_ptr(prev);
		node->set_next_ptr(next);
		next->set_prev_ptr(node);
		return typename List_Double_Ptr_Template<Type>::iterator(node);
		List_size++;
	}	
}
template<class Type>
typename List_Double_Ptr_Template<Type>::iterator List_Double_Ptr_Template<Type>::erase(typename List_Double_Ptr_Template<Type>::iterator position)
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
		Node<Type>* next  = sentinel_head.get_next_ptr();
		Node<Type>* prev = NULL;
		while (next != position.get_node_ptr())
		{
			prev = next;
			next = next->get_next_ptr();
		}
		prev->set_next_ptr(next->get_next_ptr());
		(next->get_next_ptr())->set_prev_ptr(prev);
		delete next;
		--List_size;
		return typename List_Double_Ptr_Template<Type>::iterator(prev->get_next_ptr());
	}
}
template<class Type>
typename List_Double_Ptr_Template<Type>::iterator List_Double_Ptr_Template<Type>::erase(typename List_Double_Ptr_Template<Type>::iterator first,typename List_Double_Ptr_Template<Type>::iterator last)
{
	while (first!= last)
	{
		typename List_Double_Ptr_Template<Type>::iterator temp(first.get_node_ptr());
		first++;		
		erase(temp);
	}
	return last;
}
template<class Type>
void List_Double_Ptr_Template<Type>::copy(typename List_Double_Ptr_Template<Type>::iterator& beg)
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
template<class Type>
void List_Double_Ptr_Template<Type>::swap(List_Double_Ptr_Template<Type>& lst)
{
	List_Double_Ptr_Template<Type> temp;
	temp.copy(lst.begin());
	lst.copy(this->begin());
	this->copy(temp.begin());
}
template<class Type>
void List_Double_Ptr_Template<Type>::remove(const int& value)
{
	typename List_Double_Ptr_Template<Type>::iterator it(this->begin());
	while (it != this->end())
	{
		if (*it == value)
		{
			typename List_Double_Ptr_Template<Type>::iterator temp(this->begin());
			temp = it;
			if (it->get_next_ptr()!=NULL)
				it++;
			this->erase(temp);
		}
		else 
			it++;
	}
}
template<class Type>
void List_Double_Ptr_Template<Type>::remove(typename List_Double_Ptr_Template<Type>::iterator it, const int& value)
{
	it++;
	while (it != this->end())
	{
		if (*it == value)
		{
			typename List_Double_Ptr_Template<Type>::iterator temp(this->begin());
			temp = it;
			if (it->get_next_ptr() != NULL)
				it++;
			this->erase(temp);
		}
		else
			it++;
	}
}
template<class Type>
void List_Double_Ptr_Template<Type>::unique()
{
	typename List_Double_Ptr_Template<Type>::iterator it(this->begin());
	while (it != this->end())
	{
		this->remove(it,*it);
		if (it->get_next_ptr() == NULL)
			break;
		it++;
	}
}
template<class Type>
void List_Double_Ptr_Template<Type>::splice(typename List_Double_Ptr_Template<Type>::iterator position, List_Double_Ptr_Template<Type>& x)
{
	while (!x.empty())
	{
		typename List_Double_Ptr_Template<Type>::iterator t(x.begin());
		this->insert(position, t->get_data());
		x.pop_front();
		List_size++;
	}
}
template<class Type>
void List_Double_Ptr_Template<Type>::splice(typename List_Double_Ptr_Template<Type>::iterator position, List_Double_Ptr_Template<Type>& x, typename List_Double_Ptr_Template<Type>::iterator i)
{
	typename List_Double_Ptr_Template<Type>::iterator t(i);
	this->insert(position, t->get_data());
	x.erase(i);
	List_size++;
}
template<class Type>
void List_Double_Ptr_Template<Type>::splice(typename List_Double_Ptr_Template<Type>::iterator position, List_Double_Ptr_Template<Type>& x,typename List_Double_Ptr_Template<Type>::iterator first, List_Double_Ptr_Template<Type>::iterator last)
{
	while (first != last)
	{
		typename List_Double_Ptr_Template<Type>::iterator t(first);
		this->insert(position, t->get_data());
		first++;
		x.erase(t);
		List_size++;
	}	
}
template<class Type>
void List_Double_Ptr_Template<Type>::reverse()
{
	if (this->size()> 1)
	{
		Node<Type>* tail = sentinel_head.get_next_ptr();
		Node<Type>* prev = &sentinel_head;
		Node<Type>* cur = sentinel_head.get_next_ptr();
		Node<Type>* next = cur->get_next_ptr();
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
template<class Type>
void List_Double_Ptr_Template<Type>::sort()
{
	int sz = List_size;
	while (--sz)
	{
		Node<Type>* prev = &sentinel_head;
		Node<Type>* cur = sentinel_head.get_next_ptr();
		Node<Type>* next = cur->get_next_ptr();
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