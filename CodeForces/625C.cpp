#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, k;
	cin >> n >> k;
	cout << (n*n*(k-1) + n + n*(n-1)*(n-k+1)/2) << endl;
	for(int i=0; i<n; ++i){
		for(int j=1; j<k; ++j) cout << (i*(k-1)+j) << " ";
		for(int j=0; j<=n-k; ++j) cout << (n*(k-1)+i*(n-k+1)+j+1) << " ";
		// cout << (n*(k-1)+i+1) << " ";
		// for(int j=1; j<=n-k; ++j) cout << (n*k+(n-k)*i+j) << " ";
		cout << endl;
	}
	return 0;
}