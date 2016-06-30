#include <iostream>
using namespace std;
typedef long long ll;

int main(int argc, char const *argv[])
{
	ll n;
	cin >> n;
	for(int i=0; i<=n/1234567; ++i){
		ll temp = n - i*1234567;
		for(int j=0; j<=temp/123456; ++j){
			if((temp - j*123456)%1234 == 0){
				cout<<"YES";
				return 0;
			}
		}
	}
	cout << "NO";
	return 0;
}