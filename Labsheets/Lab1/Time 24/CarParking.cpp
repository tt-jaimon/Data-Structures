#include "CarParking.h"

void CarParking::read()
{
	cout<<"\nEnter the entry and exit times:\n";
	Entry_Time.read_time();
	Exit_Time.read_time();
	Exception_check();
	Duration=Entry_Time.duration(Exit_Time);
	Parking_rate=(Duration.get_hour()*60.0+Duration.get_minute())*10.0/60.0;
}
void CarParking::Exception_check()
{
	if(Entry_Time.get_hour()<0||Entry_Time.get_hour()>=24)
		throw EntryWrong();
	if(Exit_Time.get_hour()<0||Exit_Time.get_hour()>=24)
		throw ExitWrong();
	if(Entry_Time.get_hour()>Exit_Time.get_hour())
		throw ExitLess();
	if(Entry_Time.get_hour()==Exit_Time.get_hour()&&Entry_Time.get_minute()>Exit_Time.get_minute())
		throw ExitLess();
}

void CarParking::write()
{
	cout<<"\n---------------------------";
	cout<<"\nReceipt";
	cout<<"\n----------------------------";
	cout<<"\nCar enters at:";
	Entry_Time.write_time();
	cout<<"\nCar exits at :";
	Exit_Time.write_time();
	cout<<"\nParking time :"<<Duration.get_hour()<<" hrs"<<Duration.get_minute()<<" mins";
	cout<<"\nRate :Rs. 10/hour";
	cout<<"\n----------------------------";
	cout<<"\nTotal Cost : Rs. "<<Parking_rate;
	cout<<"\n---------------------------- ";
}
