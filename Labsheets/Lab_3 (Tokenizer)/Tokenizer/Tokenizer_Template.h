#ifndef TOKENIZER_TEMPLATE_H
#define TOKENIZER_TEMPLATE_H

#include "Token_Template.h"
#include<iostream>
#include<stdio.h>
#include<string>

using std::cout;
using std::cin;
using std::istream;

template<class Type>
class Tokenizer_Template
{
	istream& in;
public:
	Tokenizer_Template(istream& is):in(is){}
	Token_Template<Type> get_Token();
	void clear(){ in.clear();}
};
#include "Tokenizer_Template.cpp"

#endif
