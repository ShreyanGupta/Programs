#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	vector<bool> c;
	int n, a, temp, count=0;
	cin >> a >> n;
	c.push_back(false);
	for(int i=1; i<=a; ++i){
		cin >> temp;
		if(temp==1) c.push_back(true);
		else c.push_back(false);
	}
	if(c[n]) ++count;
	if(n <= a/2){
		for(int i=1; i<=n-1; ++i){
			// cout << n+i << " " << n-i <<endl;
			if(c[n+i] && c[n-i]) count+=2;
		}
		for(int i=2*n; i<=a; ++i)
		if(c[i]) ++count;
	}else{
		for(int i=1; i<=a-n; ++i){
			// cout << n+i << " " << n-i <<endl;
			if(c[n+i] && c[n-i]) count+=2;
		}
		for(int i=1; i<2*n-a; ++i)
		if(c[i]) ++count;
	}
	cout << count;
	return 0;
}