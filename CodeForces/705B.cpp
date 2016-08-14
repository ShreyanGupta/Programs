#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	long long temp;
	cin >> n;
	bool current = false;
	for(int i=0; i<n; ++i){
		cin >> temp;
		if(temp%2 == 0) current = !current;
		cout << (current?"1\n":"2\n");
	}
	return 0;
}