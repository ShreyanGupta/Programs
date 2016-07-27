#include <iostream>
#include <map>
#include <set>
using namespace std;

int main(int argc, char const *argv[])
{
	map<char, set<int> > m;
	int n;
	int size;
	string s;
	cin >> n >> s;
	size = 2*n;
	for(int i=0; i<n; ++i){
		m[s[i]].insert(i);
	}
	for(int i=0; i<n; ++i){
		int end = i;
		for(auto j=m.begin(); j!=m.end(); ++j){
			if(end-i+1 > size) break;
			if(j->first == s[i]) continue;
			auto next = (j->second).upper_bound(i);
			if(next == (j->second).end()) end=10*n;
			else{
				if(end < *next) end = *next;
			}
		}
		if(end-i+1 < size) size = end-i+1;
	}
	cout << size;
	return 0;
}