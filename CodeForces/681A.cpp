#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	bool good = false;
	int n, r1, r2;
	string name;
	cin >> n;
	for(int i=0; i<n; ++i){
		cin >> name >> r1 >> r2;
		if(r1>=2400 && r2>r1) good = true;
	}
	cout << (good?"YES":"NO");
	return 0;
}