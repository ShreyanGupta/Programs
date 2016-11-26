#include <stack>
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int get_precd(char a){
	switch(a){
		case ')' : return 6;
		case '+' : return 1;
		case '-' : return 2;
		case '*' : return 3;
		case '/' : return 4;
		case '^' : return 5;
		case '(' : return 0;
		default : return -1;
	}
}

char get_op(int i){
	switch(i){
		case 1 : return '+';
		case 2 : return '-';
		case 3 : return '*';
		case 4 : return '/';
		case 5 : return '^';
		default : return '#';
	}
}

string infix_to_postfix(string str){
	string answer;
	stack<int> s;
	s.push(-20);
	for(int i=0; i<str.length(); ++i){
		int op = get_precd(str[i]);
		if(op == -1) answer.push_back(str[i]);
		else{
			if(op == 6){
				while(s.top() != 0){
					// cout << s.top() << " " << answer << endl;
					answer.push_back(get_op(s.top()));
					s.pop();
				}
				s.pop();
			}else if(op == 0){
				s.push(op);
			}else{
				while(s.top() > op){
					answer.push_back(get_op(s.top()));
					s.pop();
				}
				s.push(op);
			}
		}
	}
	while(s.top() != -20){
		answer.push_back(get_op(s.top()));
		s.pop();
	}
	return answer;
}

void insert(int &elt, stack<int> &s){
	if(s.size() == 0){
		s.push(elt);
		return;
	}
	if(elt < s.top()){
		int temp = s.top();
		s.pop();
		insert(elt, s);
		s.push(temp);
	}else{
		s.push(elt);
	}
}

void recursion_sort(stack<int> &s){
	if(s.empty()) return;
	int temp = s.top();
	s.pop();
	recursion_sort(s);
	insert(temp, s);
}

void stock(vector<int> &data, vector<int> &span){
	stack< pair<int, int> > s;	// index, val
	for(int i=0; i<data.size(); ++i){
		while(s.size()!=0 && s.top().second <= data[i]){
			s.pop();
		}
		if(s.empty()) span[i] = i+1;
		else span[i] = i - s.top().first;
		s.push(make_pair(i,data[i]));
	}
}





