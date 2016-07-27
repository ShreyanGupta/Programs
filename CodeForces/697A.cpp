#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	long long t, s, x;
	cin >> t >> s >> x;
	bool yes = false;
	if((x-t)%s==0) yes = true;
	if((x-t-1)%s==0) yes = true;
	if(x==t+1) yes = false;
	if(x<t) yes=false;
	if(yes) cout << "YES";
	else cout << "NO"; 
	return 0;
}