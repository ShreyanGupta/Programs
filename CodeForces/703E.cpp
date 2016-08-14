#include <iostream>
#include <vector>
#include <map>

using namespace std;
typedef long long ll;

struct data{
	vector<int> arr;
	ll sum = 0;
};

int main(int argc, char const *argv[])
{
	int n;
	ll k;
	cin >> n >> k;
	vector<ll> v(n+1);
	// map<ll, data> m1, m2;
	// auto *p = &m1;
	// auto *q = &m2;
	for(int i=1; i<=n; ++i)	cin >> (v[i]);

	for(int i=1; i<=n-1; ++i){
		map<ll, data> map;
	}

	return 0;
}