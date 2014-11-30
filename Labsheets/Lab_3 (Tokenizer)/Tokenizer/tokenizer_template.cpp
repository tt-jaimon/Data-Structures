#include "Tokenizer_Template.h"

template<class Type>
Token_Template<Type> Tokenizer_Template<Type>::get_Token()
{
	char ch;
	Type value;
	while(in.get(ch)&&((ch==' ')||(ch=='\t')));
	if(in.good())
	{
		switch(ch)
		{
			case '^':return EXP;
			case '/':return DIV;
			case '*':return MULT;
			case '+':return PLUS;
			case '-':return MINUS;
			case '(':return LPAREN;
			case ')':return RPAREN;
			case '\n':return EOL; 
			default:
				    in.putback(ch);
					if(in>>value)
					{
						return (Token_Template<Type>(VALUE,value));
					}
					else
					{
						cin.clear();
						cin.ignore(1000,'\n');
						return UNKNOWN ;
					}
		}
	}
	return EOL;
}






	