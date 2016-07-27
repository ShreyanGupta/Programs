#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

int main(int argc, char const *argv[])
{
	ll n,h,k;
	ll sec=0, current=0, temp;
	cin >> n >> h >> k;
	for(ll i=0; i<n; ++i){
		cin >> temp;
		// while(current+temp > h){
		// 	current-=k;
		// 	++sec;
		// 	if(current<0) current=0;
		// }
		ll x = ceil((current+temp-h)*1.0/k);
		if(x<0) x=0;
		sec += x;
		current -= x*k;
		if(current<0) current=0;
		current+=temp;
		// cout << current << " " << sec << " " << x << endl;
	}
	// while(current>0){
	// 	current-=k;
	// 	++sec;
	// }
	sec += ceil(1.0*current/k);
	cout << sec;
	return 0;
}