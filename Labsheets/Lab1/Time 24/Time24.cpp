#include "Time24.h"
void Time24::normalize_time()
{
	if(minute>=60)
	{
		while(minute>=60)
		{
			hour++;
			minute-=60;
		}
	}
	if(hour>=24)
	{
		while(hour<24)
			hour-=24;
	}
	if(minute<0)
		{
			while(minute<0)
			{
				hour--;
				minute+=60;
			}
		}
	if(hour<0)
		while(hour<0)
			hour+=24;
}

void Time24::read_time()
{
	string temp,th,tm;
	cout<<"\n>>";
	cin>>temp;
	int flag=0;
	for(size_t i=0;i<temp.size();i++)
	{
		if(temp[i]==':')
			flag++;
		else{
			if(flag==0)
				th+=temp[i];
			if(flag==1)
				tm+=temp[i];
		}
	}
	hour=atoi(th.c_str());
	minute=atoi(tm.c_str());
	normalize_time();
}
void Time24::write_time()
{
	cout<<hour<<separator<<minute;
}

Time24 Time24::duration(const Time24 &t)
{
	int th,tm;
	if(t.hour<hour)
	{
		throw Range();
	}
	if(t.hour==hour&&t.minute<minute)
	{
		throw Range();
	}
	else
	{
		th=t.hour-hour;
		tm=t.minute-minute;		
	}
	Time24 temp(th,tm);
	temp.normalize_time();
	return temp;
}
void Time24::add_time(int m)
{
	minute+=m;
	normalize_time();
}




	