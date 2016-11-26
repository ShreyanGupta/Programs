#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[])
{
	string s;
	cin >> s;
	int l=0, r=0, u=0, d=0, count=0;
	for(auto i : s){
		++count;
		switch(i){
			case 'L' : ++l; break;
			case 'R' : ++r; break;
			case 'U' : ++u; break;
			case 'D' : ++d; break;
		}
	}
	if(count%2 == 1){
		cout << "-1";
		return 0;
	}
	int a1 = abs(l-r);
	int a2 = abs(u-d);
	cout << ((a1 + a2)/2);
	return 0;
}