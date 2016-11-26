#include <iostream>
#include <map>
#include <set>
using namespace std;

map<char, int> m;
set<char> l;

int main(int argc, char const *argv[])
{
	string s;
	cin >> s;
	s += "#";
	if(s.size()<26){
		printf("-1\n");
		return 0;
	}
	auto ptr1 = s.begin();
	auto ptr2 = s.begin();
	int unassigned=0;
	int assigned=0;
	for(char i='A'; i<='Z'; ++i) l.insert(i);
	for(int i=0; i<26; ++i){
		if(*ptr2 == '?'){
			++unassigned;
		}else{
			if(m[*ptr2] == 0){ 
				l.erase(*ptr2);
			}
			++m[*ptr2];
		}
		++ptr2;
	}
	while(ptr2 != s.end()){
		printf("%c %c %d %d ", *ptr1, *ptr2, l.size()-unassigned, unassigned);
		for(auto i : l) cout << i; cout << endl;
		if(l.size()-unassigned==0){
			// printf("?????????????????????????\n");
			for( ;ptr1 != ptr2; ++ptr1){
				if(*ptr1 == '?'){
					char c = *l.begin();
					// printf("%c", c);
					*ptr1 = c;
					l.erase(c);
				}
				// else printf("%c", *ptr1);
			}
			for(auto &i : s) if(i=='?') i = 'A';
			cout << s.substr(0,s.size()-1) << endl;
			return 0;
		}
		if(*ptr1 == '?') --unassigned;
		else{
			--m[*ptr1];
			if(m[*ptr1] == 0) l.insert(*ptr1);
		}
		++ptr1;
		++ptr2;
		if(*ptr2 == '?'){
			++unassigned;
		}else{
			if(m[*ptr2] == 0){ 
				l.erase(*ptr2);
			}
			++m[*ptr2];
		}
	}
	printf("-1\n");
	return 0;
}