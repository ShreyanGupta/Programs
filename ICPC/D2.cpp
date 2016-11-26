#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

long long p = 1000000007;

int main(int argc, char const *argv[])
{
	int T;
	cin >> T;
	for(int t=0; t<T; ++t){
		int n;
		cin >> n;
		vector<int> v(n);
		long long tot = 1;

		for(int i=0; i<n; ++i) cin >> v[i];
		sort(v.begin(), v.end());

		unordered_map<int, long long> m;
		m[v[0]] = 1;
		
		for(int k=1; k<n; ++k){
			long long val = 1;
			for(int j=1; j<=sqrt(v[k]); ++j){
				if(v[k]%j != 0) continue;
				val += m[j];
				val %= p;
				if(v[k] != j*j){
					val += m[v[k]/j];
					val %= p;
				}
			}
			m[v[k]] = val;
			tot += val;
			tot %= p;
		}
		cout << tot << endl;
	}
	return 0;
}