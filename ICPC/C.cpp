#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int T;
	cin >> T;
	for(int t=0; t<T; ++t){
		int d;
		cin >> d;
		int x = d%9;
		cout << x+1 << endl;
	}
	return 0;
}