#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	long long m;
	int n, q;
	cin >> n;
	vector<int> v(n);
	for(int i=0; i<n; ++i) cin >> v[i];	
	std::sort(v.begin(), v.end());
	cin >> q;
	for(int i=0; i<q; ++i){
		cin >> m;
		auto t = std::upper_bound(v.begin(), v.end(), m);
		cout << (t-v.begin()) << endl;
	}

	return 0;
}