#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	long long b, d, s;
	cin >> b >> d >> s;

	long long m = max(max(b,d),s);
	long long ans;
	// start before breakfast
	// start before dinner
	// start before supper

	if(b == d && d == s) ans = 0;
	else if(m == b){
		if(m == d) ans = (m-s-1);
		else if(m == s) ans = (m-d-1);
		else ans = (m-d-1) + (m-s-1);
	}else{
		// m != b
		if(d == m){
			if(s == m) ans = (m-b-1);
			else ans = (m-b-1) + (m-s-1);
		}else ans = (m-b-1) + (m-d-1);
	}
	cout << ans << endl;
	return 0;
}