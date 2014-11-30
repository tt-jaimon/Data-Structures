#include "Stack_int.h"
#include "Exceptions.h"


void Stack_Int::push(const value_type& s)
{
	if(top_of_stack==stack_size-1)
		throw overflow_exception();
	data[++top_of_stack]=s;
}
void Stack_Int::pop()
{
	if(top_of_stack==-1)
		throw underflow_exception("Underflow");
	top_of_stack--;
}
ostream& operator<<(ostream& out,const Stack_Int& s)
{
	if(s.size()==0)
		out<<"\nStack is Empty\n";
	else
	{
		out<<"\n+-----+\n";
		for(Stack_Int::size_type i= s.size()-1;i!=UINT_MAX;i--)
		{		
			out<<"|"<<setw(5)<<s.data[i]<<"|";
			out<<((i==s.size()-1)?" <--Top of Stack":"");
		    out<<"\n+-----+\n";
		}
	}
	return out;
}
