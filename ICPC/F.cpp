#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int T;
	cin >> T;
	for(int t=0; t<T; ++t){
		int n, m, d, D;
		cin >> n >> m >> d >> D;
		int l = m/n;
		int k = m%n;
		if(l < d || l > D){
			cout << "-1\n";
		}
		else if(k > 0 && l+1 > D){
			cout << "-1\n";
		}
		else{
			for(int i=0; i<k; ++i){
				for(int j=0; j<l+1; ++j){
					cout << (i+1) << " " << ((i+j)%n + 1) << endl;
				}
			}
			for(int i=k; i<n; ++i){
				for(int j=0; j<l; ++j){
					cout << (i+1) << " " << ((i+j)%n + 1) << endl;
				}
			}
		}
	}
	return 0;
}

