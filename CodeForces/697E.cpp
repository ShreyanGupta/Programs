#include <iostream>
using namespace std;

typedef long long ll;

int main(int argc, char const *argv[])
{
	bool is_even = false;
	const ll p_1 = 1000000006;
	const ll p = 1000000007;
	const ll two_inv = 500000004;
	const ll three_inv = 333333336;
	ll k, temp, a=1, answer=1;
	cin >> k;
	for(ll i=0; i<k; ++i){
		cin >> temp;
		if(temp%2==0) is_even = true;
		temp%=p_1;
		a*=temp;
		a%=p_1;
		// cout << "a is " << a << endl;
	}
	temp = 2;
	while(a!=0){
		if(a%2==1) answer*=temp;
		answer%=p;
		temp*=temp;
		temp%=p;
		a/=2;
		// cout << answer << " " << a << endl;
	}
	answer*=two_inv;
	answer%=p;
	if(is_even) cout << (((answer+1)*three_inv)%p);
	else cout << (((answer-1)*three_inv)%p);
	cout << "/" << (answer);
	return 0;
}