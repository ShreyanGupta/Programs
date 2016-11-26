#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <stack>
#include <climits>
using namespace std;

class K_Stacks{
	vector< pair<int, int> > v;	// val, ptr
	vector<int> ptr;
	int k;
public:
	K_Stacks(int k){
		v = vector< pair<int, int> >(100);
		for(int i=0; i<100; ++i) v[i] = make_pair(0, i+1);
		v[99].second = -1;
		ptr = vector<int>(k+1, -1);
		ptr[0] = 0;
		this->k = k;
	}
	void push(int val, int k){
		if(k>this->k) return;
		int curr_ptr = ptr[0];
		ptr[0] = v[curr_ptr].second;
		v[curr_ptr].first = val;
		v[curr_ptr].second = ptr[k];
		ptr[k] = curr_ptr;
	}
	int pop(int k){
		if(k>this->k) return INT_MIN;
		int curr_ptr = ptr[k];
		if(curr_ptr == -1) return INT_MIN;
		ptr[k] = v[curr_ptr].second;
		v[curr_ptr].second = ptr[0];
		ptr[0] = curr_ptr;
		return v[curr_ptr].first;
	}
};

class Min_Stack{
	list<int> l;
	list<int> min_list;
public:
	void push(int val){
		l.push_back(val);
		if(min_list.size() == 0) min_list.push_back(val);
		else if(min_list.back() >= val) min_list.push_back(val);
	}
	int pop(){
		if(l.size() == 0) return INT_MIN;
		if(l.back() == min_list.back()) min_list.pop_back();
		int temp = l.back();
		l.pop_back();
		return temp;
	}
	int min_elt(){
		if(min_list.size() == 0) return INT_MIN;
		else return min_list.back();
	}
};

class Set_Stack{
	list< list<int> > l;
	int capacity;
public:
	Set_Stack(int capacity){
		this->capacity = capacity;
	}
	void push(int val){
		if(l.size() == 0) l.push_back(list<int>());
		l.back().push_back(val);
		if(l.back().size() == capacity){
			l.push_back(list<int>());
		}
	}
	int pop(){
		if(l.size() == 0) return INT_MIN;
		int temp = l.back().back();
		l.back().pop_back();
		if(l.back().size() == 0) l.pop_back();
		return temp;
	}
	void print_stack(){
		cout << "printing stack" << endl;
		for(auto &i : l){
			for(auto &j : i) cout << j << " ";
			cout << endl;
		}
	}
};

class Stack_Queue{
	stack<int> s1;
	stack<int> s2;
public:
	void enqueue(int val){
		s1.push(val);
	}
	int dequeue(){
		if(s2.size() == 0){
			while(!s1.empty()){
				s2.push(s1.top());
				s1.pop();
			}
		}
		if(s2.size() == 0) return INT_MIN;
		int temp = s2.top();
		s2.pop();
		return temp;
	}
};

// void print_stacks(){
// 	for(auto &i : s1) cout << i << " "; cout << endl;
// 	for(auto &i : s2) cout << i << " "; cout << endl;
// 	for(auto &i : s3) cout << i << " "; cout << endl;
// 	cout << "---------------------------------" << endl;
// }

void recursion(int n, stack<int> &s1, stack<int> &s2, stack<int> &s3){
	if(n==0) return;
	recursion(n-1, s1, s3, s2);
	s3.push(s1.top());
	s1.pop();
	// cout << "elt " << n << str << endl;
	recursion(n-1, s2, s1, s3);
}

void q4_tower_of_hanoi(int n){
	stack<int> s1, s2, s3;
	for(int i=n; i>0; --i) s1.push(i);
	recursion(n, s1, s2, s3);
}

void insert_sort(int val, stack<int> &s){
	if(s.size() == 0) s.push(val);
	else if(val < s.top()) s.push(val);
	else{
		int temp = s.top();
		s.pop();
		insert_sort(val, s);
		s.push(temp);
	}
}

void sort_stack(stack<int> &s){
	if(s.size() == 0) return;
	int temp = s.top();
	s.pop();
	sort_stack(s);
	insert_sort(temp, s);
}

int main(int argc, char const *argv[])
{
	// q4_tower_of_hanoi(1);
	// cout << "------------" << endl;
	// q4_tower_of_hanoi(3);
	
	// stack<int> s;
	// for(int i=0; i<100; ++i) if(i%2 == 0) s.push(i); else s.push(2*i);
	// sort_stack(s);
	// while(s.size() != 0){
	// 	cout << s.top() << " ";
	// 	s.pop();
	// }
	
	// Stack_Queue q;
	// for(int i=0; i<10; ++i) q.enqueue(i);
	// for(int i=0; i<11; ++i) cout << q.dequeue() << " ";
	// cout << endl;
	// for(int i=0; i<50; ++i) q.enqueue(i);
	// for(int i=0; i<30; ++i) cout << q.dequeue() << " ";
	// cout << endl;
	// for(int i=0; i<30; ++i) q.enqueue(i);
	// for(int i=0; i<51; ++i) cout << q.dequeue() << " ";
	// cout << endl;

	// Set_Stack s(4);
	// for(int i=0; i<99; ++i) s.push(i);
	// s.print_stack();
	// for(int i=0; i<50; ++i) cout << s.pop() << " ";
	// cout << endl;
	// s.print_stack();
	// for(int i=0; i<30; ++i) s.push(i);
	// for(int i=0; i<80; ++i) cout << s.pop() << " ";
	// cout << endl;
	// s.print_stack();

	// Min_Stack s;
	// for(int i=49; i>=0; --i){
	// 	cout << s.min_elt() << " ";
	// 	if(i%2 == 0) s.push(i);
	// 	else s.push(2*i);
	// }
	// cout << endl;
	// for(int i=0; i<50; ++i){
	// 	cout << s.min_elt() << " ";
	// 	cout << s.pop() << " ";
	// }

	return 0;
}