#include <iostream>
#include <map>

using namespace std;

map<int, int> m;

int get_encoding(long long x){
	int ans = 0;
	long long p = 1;
	while(x != 0){
		if(x%2 == 1) ans+=p;
		// ans*=2;
		x/=10;
		p*=2;
	}
	// cout << ans;
	return ans;
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	for(int i=0; i<n; ++i){
		char c;
		long long x;
		cin >> c >> x;
		switch(c){
			case '+' : ++m[get_encoding(x)]; break;
			case '-' : --m[get_encoding(x)]; break;
			case '?' : cout << m[get_encoding(x)] << endl; break;
		}
	}
	// get_encoding(n);
	return 0;
}