#include <iostream>
#include <algorithm>
#include <vector>
typedef long long ll;
using namespace std;

inline bool fun(int i, int j){return i>j;}

int main(int argc, char const *argv[])
{
	int n, temp;
	cin >> n;
	vector<int> v;
	for(int i=0; i<n; ++i){
		cin >> temp;
		v.push_back(temp);
		// sort1.push_back(temp);
	}

	// sort(sort1.begin(), sort1.end(), fun);
	// for(int i=0; i<n; ++i) cout << sort1[i]; 
	// cout << "\n";

	for(int i=0; i<n-1; ++i)
	for(int j=0; j<n-1; ++j){
		if(v[j]>v[j+1]){
			cout << j+1 << " " << j+2 << "\n";
			temp = v[j];
			v[j] = v[j+1];
			v[j+1] = temp;
		}
	}
	// for(int i=0; i<n; ++i) cout << v[i];
	return 0;
}