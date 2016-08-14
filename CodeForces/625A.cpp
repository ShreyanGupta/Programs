#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
	long long n, a, b, c;
	cin >> n >> a >> b >> c;
	if(b-c > a) cout << n/a;
	else{
		long long answer = 0;
		if(n<b){
			cout << n/a;
			return 0;
		}
		answer = (n-b)/(b-c);
		n = n - (answer*(b-c));
		if(n>=b){
			n-=(b-c);
			++answer;
		}
		if(a<b) answer += n/a;
		else answer += n/b;
		cout << answer;
	}
	return 0;
}