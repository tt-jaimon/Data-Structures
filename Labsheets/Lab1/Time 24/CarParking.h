#ifndef CARPARKING_H
#define CARPARKING_H
#include "Time24.h"

class CarParking
{
	class ExitLess{};
	class ExitWrong{};
	class EntryWrong{};
	Time24 Entry_Time;
	Time24 Exit_Time;
	double Rate;
	Time24 Duration;
	double Parking_rate;
public:
	CarParking():Rate(10.0),Parking_rate(0){}
	void read();
	void write();
	void Exception_check();
};
#endif

