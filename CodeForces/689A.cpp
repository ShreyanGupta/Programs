#include <iostream>
using namespace std;

int n;
string s;

bool find(char x){
	for(int i=0; i<n; ++i){
		if(s[i]==x) return true;
	}
	return false;
}

int main(int argc, char const *argv[])
{
	cin >> n;
	cin >> s;
	bool up=false, down=false, left=false, right=false;
	if(find('1')){
		up = true;
		left = true;
	}
	if(find('2')){
		up = true;
	}
	if(find('3')){
		up = true;
		right = true;
	}
	if(find('4')){
		left = true;
	}
	if(find('6')){
		right = true;
	}
	if(find('7')){
		down = true;
		left = true;
	}
	if(find('0')){
		down = true;
		left = true;
		right = true;
	}
	if(find('9')){
		down = true;
		right = true;
	}
	if(up&&down&&left&&right) cout << "YES";
	else cout << "NO";
	return 0;
}