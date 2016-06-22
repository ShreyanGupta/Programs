#ifndef TEST_H
#define TEST_H

#include <string> 
 
class Test 
{ 
	public: 
		Test(std::string description); 
		~Test(); 
		void VerifyTrue(bool, std::string); 
		void VerifyFalse(bool, std::string); 
		bool isPassed(); 
		 
	private: 
		std::string description; 
		bool isPass; 
		void PrintPassFail(bool); 
}; 


#endif