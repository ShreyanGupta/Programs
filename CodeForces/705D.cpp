#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int n, s, e;
	cin >> n >> s >> e;
	vector<long long> x(n+1), a(n+1), b(n+1), c(n+1), d(n+1);
	for(int i=1; i<=n; ++i) cin >> x[i];
	for(int i=1; i<=n; ++i) cin >> a[i];
	for(int i=1; i<=n; ++i) cin >> b[i];
	for(int i=1; i<=n; ++i) cin >> c[i];
	for(int i=1; i<=n; ++i) cin >> d[i];
	return 0;
}