#include <cstring>
#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>
#include <list>

using namespace std;
long long int a;

void recursion(int i, int left){
	if(i==1)	++a;
	else{
		for(int x=0;x<=left/i;++x){
			recursion((i-1),left-i*x);
		}
	}
}

int main(int argc, char const *argv[])
{
	// string s, temp;
	// int curr_pos = 0;
	// cin >> s;
	// auto ptr = ++s.begin();
	// while(ptr != s.end()){
	// 	// cout << *ptr << endl;
	// 	if(*ptr == 'v'){
	// 		++ptr;
	// 		temp = "";
	// 		while(*ptr != '-' && ptr != s.end()){
	// 			// cout << temp << endl;
	// 			temp.push_back(*ptr);
	// 			++ptr;
	// 		}
	// 		cout << stoi(temp) << endl;
	// 	}else ++ptr;
	// }

	list<char> l;
	l.push_back('a');
	l.push_back('b');
	l.push_back('c');
	auto it = l.begin();
	for(int i=0; i<1000; ++i){
		cout << (int)*it << " ";
		++it;
	}

	return 0;
}

