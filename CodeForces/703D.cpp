#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	long long temp;
	int n, m, l, r;
	cin >> n;
	std::vector<long long> v(n+1);
	for(int i=1; i<=n; ++i){
		cin >> temp;
		v[i] = temp;
	}
	cin >> m;
	for(int i=0; i<m; ++i){
		cin >> l >> r;
		// cout << "map mein: ";
		set<long long> s;
		long long xored_all=0, xored_some=0;
		for(int j=l; j<=r; ++j){
			xored_all ^= v[j];
			if(s.find(v[j])==s.end()){
				// cout << v[j] << " ";
				s.insert(v[j]);
				xored_some ^= v[j];
			}
		}
		// cout << "answer ";
		cout << (xored_some ^ xored_all) << endl;
	}
	return 0;
}