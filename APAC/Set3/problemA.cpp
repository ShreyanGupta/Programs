#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
using namespace std;

void recursion(int n, int m, int diff, long long &count){
	// printf("%d %d %d %d\n", n, m, diff, count);
	if(n == 0 || m == 0){
		++count;
		return;
	}
	if(diff > 0) recursion(n, m-1, diff-1, count);
	recursion(n-1, m, diff+1, count);
}

long long fact(int n){
	if(n == 1) return 1;
	return n * fact(n-1);
}

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	for(int x=1; x<=t; ++x){
		int n,m;
		cin >> n >> m;
		long long count = 0;
		recursion(n,m,0,count);
		printf("Case #%d: ", x);
		cout << setprecision(9) << (1.0*count/fact(n+m)) << endl;
	}
	return 0;
}