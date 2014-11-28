#include "Integer.h"
int main()
{
	try
	{
		Integer a,a1(10),a3,a4("123");
		Integer a2(a1); 
		cout<<"\nConstructors\n ";
		cout<<"\nDefault             -a    : "<<a;
		cout<<"\nOne argumented      -a1   : "<<a1;	
		cout<<"\nCopy Constructor    -a2   : "<<a2;
		cout<<"\nString constructor  -a4   : "<<a4;
		cout<<"\n\nOperations \n";
		a3=a1;
		cout<<"\n   a3=a1: "<<a3;
		a=a1+a2;
		cout<<"\n a=a1+a2: "<<a;
		a3=a-a2;
		cout<<"\n a3=a-a2: "<<a;
		cout<<"\n a3 : "<<a3;
		if(a>a3)
		{
			cout<<"\n a>a3\n";
			cout<<"\n a3-- : "<<a3--;
			cout<<"\n --a3 : "<<--a3;
			cout<<"\n ++a3 : "<<++a3;
			cout<<"\n a3++ : "<<a3++;
			cout<<"\n a3   : "<<a3<<"\n";
		}
		cout<<"  a4  : "<<a4<<"\n";		
		Integer i1(-4), i2(10);
		cout << "i1: " << i1 << endl;
		cout << "OR : It is " << ((i1 || i2) ? "true" : "false") << endl;
		cout << "AND : It is " << ((i1 && i2 ) ? "true" : "false") << endl;
		cout << "NOT : It is " << ((! i1) ? "true" : "false") << endl;
		cout<<"\n>>";
		cin>>a3;
		cout<<" \n a3 : "<<a3<<"\n";
		string a5=a4.to_string();
		cout<<"a5=a4.to_string() : "<<a5<<"\n";		
	}
	catch(Integer::Invalid_argument)
	{
		cout<<"\nInvalid Argument \n";
	}
	return 0;
}