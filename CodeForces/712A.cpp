#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	vector<long long> a(n+1), b(n);
	a[n+1] = 0;
	for(int i=0; i<n; ++i) cin >> a[i];
	for(int i=n-1; i>=0; --i){
		b[i] = a[i] + a[i+1];
	}
	for(int i=0; i<n; ++i) cout << b[i] << " ";
	return 0;
}