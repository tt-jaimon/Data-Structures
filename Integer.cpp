#include "Integer.h"

using namespace std;

int Integer::parse_int(string s)
{
	int temp=atoi(s.c_str());
	int sz=s.size();
	int t=1;
	while(sz!=1)
	{
		t*=10;
		sz--;
	}
	if(temp>=t)
		return temp;
	else
		throw Invalid_argument();
	return temp;
}



string Integer::to_string()
	{
		int temp=data;
		int t=0;
	    string s;
		while(temp!=0)
		{
			t=t*10+temp%10;
			temp/=10;
		}
		while(t!=0)
		{
			s+=static_cast<char>(t%10+'0');
			t/=10;

		}
		return s;
	}
Integer operator* (const Integer &i1,const Integer &i2)
{
	return(Integer(i1.data*i2.data));
}
Integer operator/ (const Integer &i1,const Integer &i2)
{
	return(Integer(i1.data/i2.data));
}

ostream& operator<< (ostream &out,const Integer& i)
{
	out<<i.data;
	return out;
}
istream& operator>> (istream &in, Integer& i)
{
	in>>i.data;
	return in;
}
Integer::Integer(string s)
{
	data=parse_int(s);
}




		

	 

