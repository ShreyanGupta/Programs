#ifndef TEST_H
#define TEST_H

#include <iostream>
using namespace std;

class Test
{
	string message;
	bool pass;
public:
	Test(string);
	~Test();
	void verify_true(bool, string);
	void verify_false(bool, string);
	// bool is_passed();
};

#endif