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
#include <climits>
using namespace std;

void q1_remove_duplicates(list<int> &l){
	cout << "q1 remove duplicates" << endl;
	for(auto &i : l) cout << i << " "; cout << endl;

	unordered_set<int> s;
	auto it = l.begin();
	while(it != l.end()){
		if(s.find(*it) == s.end()){
			s.insert(*it);
			++it;
		}else{
			it = l.erase(it);
		}
	}

	for(auto &i : l) cout << i << " "; cout << endl;
}

int q2_nth_last(list<int> l, int n){
	auto it = l.begin();
	for(int i=0; i<n; ++i){
		if(it == l.end()) return INT_MIN;
		++it;
	}
	auto it2 = l.begin();
	while(it != l.end()){
		++it;
		++it2;
	}
	return *it2;
}

list<int> q4_sum(list<int> l1, list<int> l2){
	auto it1 = l1.begin();
	auto it2 = l2.begin();
	int temp = 0;
	list<int> l3;
	while(it1 != l1.end() && it2 != l2.end()){
		temp = temp + *it1 + *it2;
		l3.push_front(temp%10);
		temp/=10;
		++it1;
		++it2;
	}
	if(it1 == l1.end()){
		while(it2 != l2.end()){
			temp += *it2;
			l3.push_front(temp%10);
			temp/=10;
			++it2;
		}
	}
	if(it2 == l2.end()){
		while(it1 != l1.end()){
			temp += *it1;
			l3.push_front(temp%10);
			temp/=10;
			++it1;
		}
	}
	if(temp != 0) l3.push_front(temp);
	for(auto &i : l1) cout << i; cout << endl;
	for(auto &i : l2) cout << i; cout << endl;
	for(auto &i : l3) cout << i; cout << endl;
	return l3;
}

int q5_loop_wala_ptr(list<int> l){
	auto p1 = l.begin();
	auto p2 = l.begin();
	while(p1 != p2){
		++p1;
		++p2; ++p1;
	}
	auto p0 = l.begin();
	while(p1 != p0){
		++p1;
		++p0;
	}
	return *p0;
}

int main(int argc, char const *argv[])
{
	list<int> l1;
	q1_remove_duplicates(l1);
	for(int i=0; i<100; ++i) l1.push_back(i%7);
	q1_remove_duplicates(l1);
	
	list<int> l2;
	for(int i=50; i>0; --i) l2.push_back(i);
	cout << q2_nth_last(l2, 6) << " " <<q2_nth_last(l2, 49) << " " << q2_nth_last(l2, 50) << " " << q2_nth_last(l2, 51) << endl;

	list<int> l4_1, l4_2;
	l4_1.push_back(5); l4_1.push_back(1); l4_1.push_back(3);
	l4_2.push_back(9); l4_2.push_back(8); l4_2.push_back(7);
	q4_sum(l4_1, l4_2);
	l4_2.push_back(9);
	q4_sum(l4_1, l4_2);

	return 0;
}