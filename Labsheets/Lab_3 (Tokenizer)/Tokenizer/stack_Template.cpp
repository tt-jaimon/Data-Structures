#include "Stack_Template.h"
#include "Exceptions.h"

template<class Type>
void Stack_Template<Type>::push(const value_type& s)
{
	if(top_of_stack==stack_size-1)
		throw overflow_exception();
	data[++top_of_stack]=s;
}
template<class Type>
void Stack_Template<Type>::pop()
{
	if(top_of_stack==-1)
		throw underflow_exception("Underflow");
	top_of_stack--;
}
template<class Type>
void Stack_Template<Type>::clear()
{
	while(!empty())
		pop();
}

template<class Type>
ostream& operator<< (ostream& out,const Stack_Template<Type>& s)
{
	if(s.size()==0)
		out<<"\nStack is Empty\n";
	else
	{
		out<<"\n+-----+\n";
		for(typename Stack_Template<Type>::size_type i= s.size()-1;i!=UINT_MAX;i--)
		{		
			out<<"|"<<setw(5)<<s.data[i]<<"|";
			out<<((i==s.size()-1)?" <--Top of Stack":"");
		    out<<"\n+-----+\n";
		}
	}
	return out;
}
