#include <iostream>
typedef long long ll;
using namespace std;

int get_char(int x){
	int count = 0;
	// cout << x << " ";
	for(int i=0; i<6; ++i){
		if(x%2==0) ++count;
		x/=2;
	}
	return count;
}

int main(int argc, char const *argv[])
{
	ll x=0, temp=3, answer=1;
	const ll bla = 1000000007;
	string s;
	cin >> s;
	for(int i=0; i<s.length(); ++i){
		int temp = s[i];
		if(temp>=97) x += get_char(temp-61);
		else if(temp==95) x += get_char(63);
		else if(temp>=65) x += get_char(temp-55);
		else if(temp>=48) x += get_char(temp-48);
		else x += get_char(62);
	}
	// cout << endl << x << endl;
	while(x!=0){
		if(x%2==1) answer = (temp*answer)%bla;
		temp = (temp*temp)%bla;
		x/=2;
	}
	cout << answer;
	return 0;
}