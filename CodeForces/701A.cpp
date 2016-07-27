#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, temp;
	cin >> n;
	int count = 0;
	vector<int> v;
	v.push_back(-1);
	for(int i=0; i<n; ++i){
		cin >> temp;
		count += temp;
		v.push_back(temp);
	}
	int avg = 2*count/n;
	// cout << "avg = " << avg << endl;

	for(int i=1; i<=n; ++i){
		if(v[i]==-1) continue;
		cout << i << " ";
		for(int j=i+1; j<=n; ++j){
			if(v[i]+v[j]==avg){
				cout << j << endl;
				v[j]=-1;
				break;
			}
		}
	}
	return 0;
}