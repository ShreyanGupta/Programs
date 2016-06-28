#include <iostream>
using namespace std;

typedef long long ll;

int main(int argc, char const *argv[])
{
	ll depressed = 0;
	ll n, x, temp;
	cin >> n >> x;
	char s;
	for(ll i=0; i<n; ++i){
		cin >> s >> temp;
		if(s=='+') x += temp;
		else{
			if(temp > x) ++depressed;
			else x -= temp;
		}
	}
	cout << x << "  " << depressed;
	return 0;
}