// stack by array
// header

#ifndef STACK_H
#define STACK_H

#include <iostream>

class Stack
{
	private:
		int top_index;
		int capacity;
		int* S_array;

	public:
		Stack();
		Stack(int);

		~Stack();

		int GetSize();
		int Top();
		int Peek();

		bool IsEmpty();
		bool IsFull();


		void Push(int);
		int Pop();
};

#endif