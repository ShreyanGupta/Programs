#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

long long my_pow(long long i, long long expo, long long k){
	long long temp = i;
	long long ans = 1;
	while(expo != 0){
		if(expo%2 == 1) ans *= temp;
		ans %= k;
		temp *= temp;
		temp %= k;
		expo/=2;
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	ifstream fin ("B-small-attempt2.in");
	ofstream fout ("output");

	int t0;
	long long a,b,n,k;
	fin >> t0;
	for(int t=1; t<=t0; ++t){
		long long count = 0;
		fout << "Case #" << t << ": ";
		fin >> a >> b >> n >> k;
		for(int i=1; i<=n; ++i){
			for(int j=1; j<=n; ++j){
				if(i==j) continue;
				long long temp1;
				if((my_pow(i,a,k) + my_pow(j,b,k))%k == 0) ++count;
			}
		}
		fout << count%1000000007 << endl;
	}
	return 0;
}