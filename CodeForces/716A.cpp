#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, count=0;
	long long c, previous;
	cin >> n >> c;
	for(int i=0; i<n; ++i){
		long long temp;
		cin >> temp;
		if(temp-previous > c) count = 0;
		previous = temp;
		++count;
	}
	printf("%d\n", count);
	return 0;
}