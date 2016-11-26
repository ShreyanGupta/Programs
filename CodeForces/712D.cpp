#include <iostream>

using namespace std;

const long long p = 1000000007;

long long val[2][404005];
int a, b, k, t;
bool temp = true;

inline int f(int val){
	// if(val+202002 > 404004) cout << "KATTA " << (202002+val) << endl;
	return val + 202002;
}

int main(int argc, char const *argv[])
{
	cin >> a >> b >> k >> t;
	int delta = b-a;
	val[0][f(0)] = 1;
	for(int i=1; i<=2*t; ++i){
		for(int j = -i*k; j <= i*k; ++j){
			// val[i][f(i,j)] = 0;
			// for(int l = -k; l <= k; ++l)
			// val[i][f(i,j)] +=val[i-1][f(i-1,j+l)]; // = summation val[i-1][delta-k] to val[i-1][delta+k]
			// val[i][f(i,j)] %= p;

			val[temp][f(j)] = (val[temp][f(j-1)] + val[!temp][f(j+k)] - val[!temp][f(j-1-k)] + p)%p;
			// val[temp][f(j)] %= p;
			// cout << i << " " << j << " : " << val[temp][f(j)] << endl;
		}
		temp = !temp;
		// cout << "Done " << i << endl;
	}
	if(delta > 2*t*k){
		cout << "0\n";
		return 0;
	}
	long long sum = 0;
	for(int j=delta+1; j<=2*t*k; ++j){
		sum += val[0][f(j)];
		sum %= p;
	}
	cout << sum << endl;
	return 0;
}