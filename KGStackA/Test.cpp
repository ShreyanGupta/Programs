#include "Test.h"
#include <iostream>

Test::Test(std::string description)
{
	this->description = description;
	isPass=true;
}

Test::~Test()
{
	PrintPassFail(isPass);
	std::cerr << description << "\n";
}

void Test::VerifyTrue(bool x, std::string t)
{
	if (!x)
	{
		PrintPassFail(x);
		std::cerr << t <<"\n";
		isPass=false;
	}
}

void Test::PrintPassFail(bool x)
{
	if (!x)
	{
		std::cerr << "FAIL : ";
	}
	else
	{
		std::cerr << "PASS : ";
	}
}

bool Test::isPassed()
{
	return isPass;
}
