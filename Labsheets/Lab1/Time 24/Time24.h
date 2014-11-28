#ifndef TIME24_H
#define TIME24_H

#include<iostream>
#include<cstdio>
#include<string>

using namespace std;

class Time24
{
	int hour;
	int minute;
	string separator;
	void normalize_time( );
	class Range{};
public:
	Time24( ):hour(0),minute(0),separator(":"){}
	Time24(int h, int m ):hour(h),minute(m),separator(":"){}
	Time24(const Time24& t):hour(t.hour),minute(t.minute),separator(t.separator){}
	int get_hour( )const
	{
		return hour;
	}
	int get_minute( ) const
	{
		return minute;
	}
	void read_time( );
	void write_time( );
	Time24 duration(const Time24 &t);
	void add_time(int m);
};
#endif