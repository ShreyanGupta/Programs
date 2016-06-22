#include "Heap.h"

int main(int argc, char const *argv[])
{
	Heap<int> h;
	h.insert(6);
	h.insert(5);
	h.insert(4);
	h.insert(3);
	h.insert(2);
	h.insert(1);
	h.print();
	// std::cout << "sweg2";
	h.extract_min();
	h.print();
	return 0;
}