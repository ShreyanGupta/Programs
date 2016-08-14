#include "Test.h"
#include <iostream>
using namespace std;

Test::Test(string message){
	cout << message << endl;
	pass = true;
}

Test::~Test(){
	cout << "End test with " << (pass?"pass":"fail") << endl;
}

void Test::verify_true(bool a, string message){
	if(!a){
		cout << message << endl;
		pass = false;
	}
}

void Test::verify_false(bool a, string message){
	if(a){
		cout << message << endl;
		pass = false;
	}
}

// inline bool is_passed(){return pass;}