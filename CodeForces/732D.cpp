#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char const *argv[])
{
	int n, m;
	cin >> n >> m;
	vector<int> d(n);
	for(int i=0; i<n; ++i) cin >> d[i];
	vector<int> a(m+1);
	for(int i=1; i<=m; ++i) cin >> a[m];

	return 0;
}