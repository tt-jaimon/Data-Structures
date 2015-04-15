#include "Heap.h"
#include<cassert>
#include<iostream>

void Max_Heap::heapify_down(size_t index)
{
	assert(index <= heap_size);
	size_t left = index << 1;
	size_t right = (index << 1) + 1;
	size_t largest = index;
	if (left <= heap_size&&data[left] > data[largest])
		largest = left;
	if (right <= heap_size&&data[right] > data[largest])
		largest = right;
	if (largest != index)
	{
		int temp = data[largest];
		data[largest] = data[index];
		data[index] = temp;
		heapify_down(largest);
	}
	return;
}
void Max_Heap::heapify_up(size_t index)
{
	assert(index <= heap_size);
	size_t parent = index >> 1;
	if (data[parent] < data[index])
	{
		int temp = data[parent];
		data[parent] = data[index];
		data[index] = temp;
		heapify_up(parent);
	}
	return;
}
void Max_Heap::levelorder_traversal()
{
	for (size_t i = 1; i <= heap_size; i++)
			std::cout << data[i] << " ";
	std::cout << "\n";
}
Max_Heap::Max_Heap(vector<int> v)
{
	assert(v.size()>0);
	data.push_back(0);
	for (vector<int>::iterator itr = v.begin(); itr != v.end(); itr++)
		data.push_back(*itr);
	heap_size = v.size();
	make_heap();
}
void Max_Heap::make_heap()
{
	if (heap_size <= 1)	return;
	for (size_t i = heap_size / 2; i >= 1; i--)
		heapify_down(i);
}
void Max_Heap::push_heap(int value)
{
	if (heap_size == 0)
		data.push_back(0);
	heap_size++;
	data.push_back(value);
	heapify_up(heap_size);
}
void Max_Heap::clear()
{
	for (size_t i = 0; i < data.size(); i++)
		data.pop_back();
	heap_size = 0;
}
void Max_Heap::pop_heap()
{
	assert(!empty());
	if (heap_size == 1)
		this->clear();
	else
	{
		data[1] = data[heap_size];
		heap_size--;
		data.pop_back();
		heapify_down(1);
	}
}
void Max_Heap::heapsort()
{
	size_t size = heap_size;
	while (heap_size > 1)
	{
		int temp = data[heap_size];
		data[heap_size] = data[1];
		data[1] = temp;
		heap_size--;
		heapify_down(1);
	}
	heap_size = size;
}