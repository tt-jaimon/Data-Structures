#ifndef TOKEN_TEMPLATE_H
#define TOKEN_TEMPLATE_H
#include<iostream>
#include<string>
using std::cout;
using std::cin;
using std::cerr;

enum Token_Type
{
	EOL,     /* End of Line. */
	VALUE,   /* Value. */
	LPAREN,  /* Left parenthesis. */
	RPAREN,	 /* Right parenthesis. */
	PLUS,    /* Addition. */
	MINUS,   /* Subtraction. */
	DIV,	 /* Division. */
	MULT,    /* Multiplication. */
	EXP,     /* Exponentiation. */
	UNKNOWN  /* Unknown token. */
};
template<class Type>
class Token_Template
{
	Token_Type token_type;
	Type       token_value;
public:
	Token_Template(Token_Type tt=EOL,const Type& val=0):token_type(tt),token_value(val){}
	Token_Type   get_type() const { return token_type;}
	const Type& get_value() const { return token_value;}
};
#endif



