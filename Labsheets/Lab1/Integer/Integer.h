#ifndef INTEGER_H
#define INTEGER_H

#include<iostream>
//#include<stdio.h>
#include<stdlib.h>
#include<string>

using namespace std;

class Integer{
	int data;
public:
	Integer():data(0){}
	Integer(Integer &i1):data(i1.data){}
	Integer(int a):data(a){}
	Integer(string s);
	class Invalid_argument
	{
	};
	int get_data()
	{
		return data;
	}
	void set_data(int a)
	{ 
		data=a;
	}
	Integer operator+ (Integer &i1)
	{
		return Integer(data+=i1.data);
	}
	Integer operator- (Integer &i1)
	{
		return Integer(data-i1.data);
	}
	void operator= (Integer &i1)
	{
		data=i1.data;
	}
	bool operator> (Integer &i1)
	{
		if(data>i1.data)
			return true;
		else
			return false;
	}
	bool operator>= (Integer &i1)
	{
		if(data>=i1.data)
			return true;
		else
			return false;
	}
	bool operator< (Integer &i1)
	{
		if(data<i1.data)
			return true;
		else
			return false;
	}
	bool operator<= (Integer &i1)
	{
		if(data<=i1.data)
			return true;
		else
			return false;
	}
	Integer& operator++()
	{
		data++;
		return *this;
	}
	Integer operator++(int)
	{
		return(data++);
	}
	Integer operator--()
	{
		data--;
		return *this;
	}
	Integer operator--(int)
	{
		return(data--);
	}
	bool operator||(const Integer& i1)
	{
		return(data||i1.data);
	}
	bool operator&&(const Integer& i1)
	{
		return(data && i1.data);
	}
	bool operator!()
	{
		return(!data);
	}
	static int parse_int(string);
	string to_string();
	friend Integer operator* (const Integer &i1,const Integer &i2);
	friend Integer operator/ (const Integer &i1,const Integer &i2);
	friend ostream& operator<< (ostream &out, const Integer& i);
	friend istream& operator>> (istream &in, Integer& i); 
};

#endif