#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include<iostream>
#include<stdexcept>
#include<string>

class overflow_exception:public exception{	
		string message;
	public:	
		overflow_exception():message("Stack Overflow"){}
		overflow_exception(const string& msg):message(msg){}
		virtual const char* what() const throw()
		{
			return message.c_str();	
		}
	};

class underflow_exception:public runtime_error{
public:
	underflow_exception(const string& msg):runtime_error(msg){}
};
#endif


