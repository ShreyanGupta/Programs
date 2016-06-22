// int main yahaan
#include "Stack.h"

int main()
{
	Stack s1 = Stack();
	std::cout << "Top of s1 " << s1.Top() << std::endl;
	std::cout << "Size of s1 " << s1.GetSize() << std::endl;
	s1.Push(1);
	s1.Push(2);
	s1.Push(3);
	s1.Push(4);
	s1.Push(5);
	s1.Push(6);
	std::cout << "Top of s1 " << s1.Top() << std::endl;
	std::cout << "Size of s1 " << s1.GetSize() << std::endl;
	int lastTop = s1.Pop();
	std::cout << "After Pop, Top of s1 " << s1.Top() << std::endl;
	std::cout << "After Pop, Peek of s1 " << s1.Peek() << std::endl;
	std::cout << "Size of s1 " << s1.GetSize() << std::endl;

	Stack s2 = Stack(11);
	std::cout << "Top of s2 " << s2.Top() << std::endl;
	std::cout << "Size of s2 " << s2.GetSize() << std::endl;

	s2.Push(17);
	std::cout << "Top of s2 " << s2.Top() << std::endl;
	std::cout << "Size of s2 " << s2.GetSize() << std::endl;

	int lastTop2 = s2.Pop();
	std::cout << "After Pop, Top of s2 " << s2.Top() << std::endl;
	std::cout << "After Pop, Peek of s2 " << s2.Peek() << std::endl;
	std::cout << "Size of s2 " << s2.GetSize() << std::endl;
		
	return 0;
}