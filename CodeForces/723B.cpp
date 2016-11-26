#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	string s;
	cin >> n >> s;
	bool par = false;
	bool running = false;
	int longest = 0;
	int current = 0;
	int count = 0;
	// for(int i=0; i<n; ++i){
	// 	switch(s[i]){
	// 		case '_' :{
	// 			if(par && running) ++count;
	// 			if(!par && running) longest = max(longest, current);
	// 			current = 0;
	// 			running = false;
	// 			break;
	// 		}
	// 		case '(' :{
	// 			if(par && running) ++count;
	// 			if(!par && running) longest = max(longest, current); 
	// 			current = 0;
	// 			par = true;
	// 			running = false;
	// 			break;
	// 		}
	// 		case ')' :{
	// 			if(par && running) ++count;
	// 			if(!par && running) longest = max(longest, current); 
	// 			current = 0;
	// 			par = false;
	// 			running = false;
	// 			break;
	// 		}
	// 		default  :{
	// 			if(!running) running = true;
	// 			++current;
	// 			break;
	// 		}
	// 	}
	// }

	s += "_";

	for(int i=0; i<n+1; ++i){
		if(running){
			if(s[i] != '(' && s[i] != ')' && s[i] != '_'){
				++current;
			}else{
				running = false;
				if(par) ++count;
				else if(!par) longest = max(longest, current);
				current = 0;
				if(s[i] == '(') par = true;
				else if(s[i] == ')') par = false;
			}
		}else{
			if(s[i] != '(' && s[i] != ')' && s[i] != '_'){
				++current;
				running = true;
			}else if(s[i] == '(') par = true;
			else if(s[i] == ')') par = false;
		}
	}
	printf("%d %d\n",longest, count);
	return 0;
}