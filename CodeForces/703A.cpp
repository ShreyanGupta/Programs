#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	int m=0, c=0;
	cin >> n;
	for(int i=0; i<n; ++i){
		int t1, t2;
		cin >> t1 >> t2;
		if(t1 > t2) ++m;
		else if(t1 < t2) ++c;
	}
	if(m>c) cout << "Mishka";
	else if(m==c) cout << "Friendship is magic!^^";
	else cout << "Chris";
	return 0;
}