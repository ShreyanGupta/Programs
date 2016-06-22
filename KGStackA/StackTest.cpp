#include "StackTest.h"

bool AllTests()
{
	Test AllTests("Combined Tests");
	AllTests.VerifyTrue(StackInitTests(),"Initialisation Tests");
	AllTests.VerifyTrue(StackPushTests(),"Stack Pushing Tests");
	AllTests.VerifyTrue(StackPopTests(),"Stack Popping Tests");
	AllTests.VerifyTrue(RandomTests(),"Random Tests");
	return AllTests.isPassed();
}

bool StackInitTests()
{
	Test t("Stack init tests");
	Stack s(5);
	t.VerifyTrue(s.IsEmpty()==false,"Stack should not be empty");
	t.VerifyTrue(s.Top()==5,"Top of stack should be 5");
	t.VerifyTrue(s.Peek()==-1,"Peek does not exist and should return default value");
	t.VerifyTrue(s.IsFull()==false,"Stack should not be full");

	Stack s1();
	t.VerifyTrue(s.IsEmpty()==true,"Stack should be empty");
	t.VerifyTrue(s.Top()==-1,"Top should return default value");
	t.VerifyTrue(s.Peek()==-1,"Peek does not exist and should return default value");
	t.VerifyTrue(s.IsFull()==false,"Stack should not be full");
	return t.isPassed();
}

bool StackPushTests()
{
	Test t("Stack Pushing tests");
	Stack s;
	for (int i=0;i<10000; i++)
	{
		s.Push(i);
		t.VerifyTrue(s.Top()==i,"Top should be i");
		t.VerifyTrue(s.GetSize()==i+1,"Size should be i+1");
		t.VerifyTrue(s.Peek()==i-1,"Peeked value should be  i-1");
		t.VerifyTrue(s.IsEmpty()==false,"Stack should not be empty");
	}
	return t.isPassed();
}

bool StackPopTests()
{
	Test t("Stack Popping tests");
	Stack s;
	for (int i=0; i<10000; i++)
	{
		s.Push(i);
	}
	for (int i=0; i<9999;i++)
	{
		t.VerifyTrue(s.Pop()==10000-1-i, "Popped value should be 10k -1 -i");
		t.VerifyTrue(s.GetSize()==10000-1-i,"Size should be 10k-1-i");
		t.VerifyTrue(s.Peek()==10000-3-i, "Peek should be 10k-3-i");
		t.VerifyTrue(s.Top()==10000-2-i,"Top should be 10k-2-i");
	}
	s.Pop();
	for (int i=0; i<100000; i++)
	{
		t.VerifyTrue(s.Pop()==-1, "Default Value should be returned");
		t.VerifyTrue(s.GetSize()==0, "Size should be 0");
	}
	return t.isPassed();
}

bool RandomTests()
{
	Test t("Stack Random tests");
	Stack s;
	for (int i=0; i<100000; i++)
	{
		s.Push(2*i);
		t.VerifyTrue(s.Top()==2*i,"Top element should be 2*i");
		t.VerifyTrue(s.Peek()==-1,"Peeked element should be default");
		t.VerifyTrue(s.GetSize()==1,"Size should be i+1");
		t.VerifyTrue(s.Pop()==2*i,"Popped element should be 2*i");
		t.VerifyTrue(s.Top()==-1,"Top should now be default");
	}
	t.VerifyTrue(s.GetSize()==0,"Size should be 0");
	return t.isPassed();
}

int main()
{
	return AllTests();
}