#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	for(int x=1; x<=t; ++x){
		int n;
		cin >> n;
		vector< pair<int,int> > s(n), t(n);
		for(int i=0; i<n; ++i){
			int a, d;
			cin >> a >> d;
			s[i] = make_pair(a,d);
			t[i] = make_pair(d,a);
		}
	}
	return 0;
}