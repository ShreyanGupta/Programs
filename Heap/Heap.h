#ifndef HEAP_H
#define HEAP_H

#include <vector>

template <typename E>
class Heap{
private:
	int index;
	std::vector<E> v;
	void heapify_up(int);
	void heapify_down();
	void swap(int, int);
public:
	Heap();
	~Heap();
	void insert(const E&);
	E &find_min();
	E &extract_min();
	void print();
};

#include "Heap.hpp"

#endif
