#include "Stack_Int.h"
#include "Exceptions.h"

int main()
{
	string msg;
	int a;
	Stack_Int s;
	do{
		try
		{
			cout<<">>";
			cin>>msg;
			if(msg=="push")
			{ 
				cin>>a;
				s.push(a);
			}
			else if(msg=="pop")
				s.pop();
			else if(msg=="print")
				cout<<s;
			else if(msg=="exit")
				break;
			else
				cout<<"\nInvalid Argument\n"; 
		}
		catch(const overflow_exception e)
		{
			cout<<e.what()<<"\n";
		}
		catch(const underflow_exception e)
		{
			cout<<"\nUnderlow Catch\n";
		}
	}while(msg!="exit");
	return 0;

}
	








