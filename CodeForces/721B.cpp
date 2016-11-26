#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, k;
	cin >> n >> k;
	map<int,int> m;
	vector<int> v(n);
	for(int i=0; i<n; ++i){
		string temp;
		cin >> temp;
		++m[temp.size()];
		v[i] = temp.size();
	}
	v.push_back(10000);
	sort(v.begin(), v.end());
	int ans_len;
	string ans;
	cin >> ans;
	int i = 0;
	while(v[i] < ans.size()){
		++i;
	}
	++i;
	cout << (i + 5*(int)((i-1)/k));
	while(v[i] <= ans.size()){
		++i;
	}
	cout << " " << (i + 5*(int)((i-1)/k));
	return 0;
}