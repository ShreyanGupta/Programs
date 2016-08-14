#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	cout << "I ";
	for(int i=0; i<n-1; ++i){
		if(i%2 == 0) cout << "hate that I ";
		else cout << "love that I ";
	}
	if(((n-1)%2) == 0) cout << "hate it";
	else cout << "love it";
	return 0;
}