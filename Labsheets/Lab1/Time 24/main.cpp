#include "CarParking.h"

int main()
{
	try{
		CarParking a;
		a.read();
		a.write();
		return 0;
	}
	catch(CarParking::EntryWrong)
	{
		cout<<"\nError: Entry time is wrong.\n";
	}
	catch(CarParking::ExitWrong)
	{
		cout<<"\nError: Exit time is wrong.\n";
	}
	catch(CarParking::ExitLess)
	{
		cout<<"\nError: Exit time cannot be less than entry time. \n";
	}

}
