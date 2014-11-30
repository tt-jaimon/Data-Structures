#include <iostream>
#include "queue_array.h"

int main()
{
	Queue_Array q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	q.push(6);
	cout << q;
	q.pop();
	q.pop(); q.pop(); q.pop(); q.pop(); q.pop(); q.pop(); q.pop();
	cout << q;
	cout << "bbbb";
	return 0;
}