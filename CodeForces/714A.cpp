#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	long long l1, r1, l2, r2, k;
	cin >> l1 >> r1 >> l2 >> r2 >> k;
	// fflush(stdout);
	long long l0 = max(l1,l2);
	long long r0 = min(r1,r2);
	if(l0 > r0){
		cout << "0";
	}
	else if(l0 <=k && k<= r0){
		cout << (r0-l0);
	}else{
		cout << (r0-l0+1);
	}
	return 0;
}