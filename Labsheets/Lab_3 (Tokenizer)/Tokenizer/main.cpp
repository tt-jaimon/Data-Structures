#include "Tokenizer_Template.h"
#include "Stack_Template.h"

int main()
{
	Stack_Template< Token_Template<int> >stk;
	Tokenizer_Template<int> tokenizer(cin);
	bool err_flag=false;

	while(1)
	{
		cout<<"\nEnter Expression >>";
		cout.flush();
		Token_Template <int> curr_Token =tokenizer.get_Token();
		while(curr_Token.get_type()!=EOL)
		{
			if(curr_Token.get_type()==LPAREN)
			{
				stk.push(curr_Token);				
			}
			else if(curr_Token.get_type()==RPAREN)
			{
				if(stk.empty())
				{
					cerr<<"\n Unmatched Right Paranthesis\n";
					err_flag=true;
					cin.ignore(1000,'\n');
					break;
				}
				else
				{
					stk.pop();
				}
			}
			else if(curr_Token.get_type()==UNKNOWN)
			{
				cerr<<"\nPARSE ERROR \n";
				err_flag=true;
				break;
			}
			curr_Token=tokenizer.get_Token();
		}
		if(!err_flag)
		{
			((stk.empty())?cout<<"\nLPAREN AND RPAREN MATCHED\n":cerr<<"\nUnmatched LPAREN");
			cout<<endl;		
		}
		err_flag=false;
		tokenizer.clear();
		stk.clear();
		
	}
	return 0;
}
