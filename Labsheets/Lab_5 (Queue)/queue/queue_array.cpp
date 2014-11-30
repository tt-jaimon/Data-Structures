#include "queue_array.h"
#include<iomanip>

void Queue_Array::push(const int& x)
{
	if (this->size() == queue_size)
		cout<<" overflow";
	else
	{
		if (front_queue == -1)
			front_queue = back_queue = 0;
		else if (back_queue == queue_size)
			back_queue = 0;
		else
			back_queue++;
		data[back_queue] = x;
		Queue_Size++;
	}
}
void Queue_Array::pop()
{
	if (this->size() == 0)
		cout<<"underflow";
	else
	{
		if (front_queue == back_queue)
			front_queue = back_queue = -1;
		else if (front_queue = queue_size)
			front_queue = 0;
		else
			front_queue++;
		Queue_Size--;
	}
}
ostream& operator<<(ostream& out, const Queue_Array& s)
{
	if (s.size() == 0)
		out << "\nQueue is Empty\n";
	else
	{
		out << "\n+-----+\n";
		for (Queue_Array::size_type i =s.front_queue; ; i++)
		{
			out << "|" << setw(5) << s.data[i] << "|";
			out << ((i == s.front_queue) ? " <--Top of Queue" : "");
			out << "\n+-----+\n";
			if (i == s.back_queue)
				break;
			if (i == s.queue_size)
				i = 0;
		}
	}
	return out;
}
