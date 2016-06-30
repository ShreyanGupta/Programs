#include <iostream>
// #include <algorithm>
// #include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	string v;
	cin >> v;
	cout << v;
	for(int i=v.length()-1; i>=0; --i) cout << v[i];
	return 0;
}