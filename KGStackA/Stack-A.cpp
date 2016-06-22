// Stack implementation

#include "Stack.h"

Stack::Stack()
{
	top_index = 0;
	capacity = 6;
	S_array = new int[capacity];
}

Stack::Stack(int t)
{
	top_index = 1;
	capacity = 6;
	S_array = new int[capacity];
	S_array[0] = t;
}

Stack::~Stack()
{
	// something
	delete S_array;
}

int Stack::GetSize()
{
	return top_index;
}

int Stack::Top()
{
	if (top_index > 0)
	{
		return S_array[top_index - 1];
	}
	else
		return -1;
}

int Stack::Peek()
{
	if (top_index > 1)
		return S_array[top_index - 2];
	else
		return -1;
}

bool Stack::IsEmpty()
{
	return (top_index == 0);
}

bool Stack::IsFull()
{
	return (top_index == capacity);
}

void Stack::Push(int pushthis)
{
	if (IsFull())
	{
		int* new_array = new int[capacity*2];
		for (int x = 0; x < capacity; x ++)
			new_array[x] = S_array[x];
		for (int x = capacity; x < 2*capacity; x++)
		{
			new_array[x] = 0;
		}
		delete S_array;	
		capacity *= 2;
		std::cout << "Doubling array size to " << capacity << std::endl;
		S_array = new_array;
		// puraana array??
		S_array[top_index] = pushthis;
		top_index += 1;
	}
	else
	{
		S_array[top_index] = pushthis;
		top_index += 1;
	}
}

int Stack::Pop()
{
	if (IsEmpty())
	{
		// bhaad mein jao
		return -1;
	}
	else
	{
		int rthis = S_array[top_index-1];
		top_index -= 1;
		return rthis;
	}
}