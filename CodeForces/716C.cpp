#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	printf("2\n");
	for(long long i=2; i<=n; ++i){
		long long x = (i*(i+1)*(i+1)-i+1);
		cout << x << endl;
	}
	return 0;
}