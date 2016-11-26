#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	int x1, x2, x3;
	cin >> x1 >> x2 >> x3;
	int m = 10000;
	for(int i=1; i<=100; ++i){
		int temp = abs(x1-i) + abs(x2-i) + abs(x3-i);
		m = min(m, temp);
	}
	cout << m;
	return 0;
}