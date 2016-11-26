#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, k;
	cin >> n >> k;
	vector<int> v(n+1);
	v[0] = k;
	for(int i=1; i<=n; ++i) cin >> v[i];
	int extra = 0;
	for(int i=1; i<=n; ++i){
		int r = v[i] + v[i-1];
		if(r < k){
			extra += (k-r);
			v[i] += (k-r);
		}
	}
	cout << extra << endl;
	for(int i=1; i<=n; ++i) cout << v[i] << " ";
	cout << endl;
	return 0;
}