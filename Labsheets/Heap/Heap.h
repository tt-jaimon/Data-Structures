#pragma once
#include<vector>
#include<ostream>
using std::vector;

class Max_Heap{
private:
	vector<int> data;
	size_t heap_size;
	void heapify_down(size_t index);
	void heapify_up(size_t index);
public:
	Max_Heap(vector<int> v);
	void push_heap(int value);
	void pop_heap();
	void clear();
	void make_heap();
	size_t size(){ return heap_size; }
	bool empty(){ return heap_size == 0; }
	void levelorder_traversal();
	void heapsort();
};
