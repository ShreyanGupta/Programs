#include "Test.h"
#include <iostream>
#include <stack>
#include <vector>
#include <queue>

string infix_to_postfix(string);
void recursion_sort(stack<int> &);
void stock(vector<int> &, vector<int> &);

// class Stack_queue_wala
// {
// 	queue<int> q;
// public:
// 	void push(int);
// 	int pop();
// };

// void Stack_queue_wala::push(int p){
// 	q.push(p);
// }

// int Stack_queue_wala::pop(){
// 	if(q.size() == 0) return INT_MIN;
// 	for(int i=0; i<q.size()-1; ++i){
// 		q.push(q.front());
// 		q.pop();
// 	}
// 	int temp = q.front();
// 	q.pop();
// 	return temp;
// }


class K_Stack
{
	vector<int> indices;
	vector< pair<int, int> > v;	// ptr, val
public:
	void push(int k, int val){
		int temp = indices[0];
		v[temp].second = val;
		indices[0] = v[temp].first;
		v[temp].first = indices[k];
		indices[k] = temp;
		// cout << "Next free " << indices[0] << " current k " << indices[k] << " index pointer for k " << v[indices[k]].first << endl;
	}
	int pop(int k){
		int temp = indices[k];
		if(temp == -1) return INT_MIN;
		indices[k] = v[temp].first;
		v[temp].first = indices[0];
		indices[0] = temp;
		return v[temp].second;
	}
	K_Stack(int k){
		v = vector< pair<int, int> >(100);
		for(int i=0; i<100; ++i){
			v[i] = make_pair(i+1, 0);
		}
		indices = vector<int>(k+1, -1);
		indices[0] = 0;
	}
	~K_Stack(){}
	
};


void test_all();
bool test_infix_to_postfix();
bool test_recursion_sort();
bool test_stock();
bool test_k_stack();

void test_all(){
	Test t("Testing stack");
	t.verify_true(test_infix_to_postfix(), "Infix to postfix failed");
	t.verify_true(test_recursion_sort(), "recursion sort failed");
	t.verify_true(test_stock(), "stock failed");
	t.verify_true(test_k_stack(), "::k stack test failed");
}

bool test_infix_to_postfix(){
	string ans;
	cout << (ans = infix_to_postfix("a+b")) << endl;
	if(ans.compare("ab+") != 0) return false;
	cout << (ans = infix_to_postfix("a+b*c")) << endl;
	if(ans.compare("abc*+") != 0) return false;
	cout << (ans = infix_to_postfix("x-(a+b)*c")) << endl;
	if(ans.compare("xab+c*-") != 0) return false;
	cout << (ans = infix_to_postfix("(x+(a+b*c)^d)+e")) << endl;
	if(ans.compare("xabc*+d^+e+") != 0) return false;
	// cout << (ans = infix_to_postfix("a+b")) << endl;
	// if(ans.compare("ab+") != 0) return false;
	return true;
}

bool test_recursion_sort(){
	stack<int> s;
	for(int i=0; i<100; i+=2) s.push(i);
	for(int i=1; i<100; i+=2) s.push(i);
	recursion_sort(s);
	for(int i=99; i>=0; --i){
		if(s.top() != i) return false;
		s.pop();
	} 
	return true;
}

bool test_stock(){
	cout << "Testing stock" << endl;
	vector<int> v;
	v.push_back(100);
	v.push_back(80);
	v.push_back(60);
	v.push_back(70);
	v.push_back(60);
	v.push_back(75);
	v.push_back(85);
	vector<int> w(7);
	stock(v,w);
	for(auto &i : w) cout << i << " "; cout << endl;
	if(w[0] != 1) return false;
	if(w[1] != 1) return false;
	if(w[2] != 1) return false;
	if(w[3] != 2) return false;
	if(w[4] != 1) return false;
	if(w[5] != 4) return false;
	if(w[6] != 6) return false;
	return true;
}

bool test_k_stack(){
	cout << "Testing k stack " << endl;
	K_Stack s(4);
	for(int i=0; i<10; ++i) s.push(1, i);
	for(int i=0; i<10; ++i) cout << s.pop(1) << " ";
	for(int i=0; i<50; ++i){
		s.push(i, (i%4)+1);
	}
	for(int i=0; i<50/4; ++i){
		if((cout << s.pop(1)) != 4*i);
	}
	cout << endl;
	for(int i=0; i<50; ++i) s.push(2, i);
	// while((cout << s.pop(2)) >= 0);
}

int main(int argc, char const *argv[])
{
	test_all();
	return 0;
}