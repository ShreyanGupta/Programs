#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, m;
	cin >> n >> m;
	vector<long long> a(n);
	vector< vector<int> > indices(m+1);
	for(int i=0; i<n; ++i){
		long long temp;
		cin >> temp;
		a[i] = temp;
		if(temp>m) indices[0].push_back(i);
		else indices[m].push_back(i);
	}
	int avg = n/m;
	int high = n%m;
	int low = m - high;
	int count = 0;

	

	while(indices[0].size() != 0){
		for(int i=1; i<m; ++i){
			cout << i << endl;
			printf("!!! %d size %d, 0 size %d\n", i, indices[i].size(), indices[0].size());
			while(indices[i].size() < avg){
				if(indices[0].size() == 0) break;
				printf("i size %d, 0 size %d\n", indices[i].size(), indices[0].size());
				indices[i].push_back(indices[0].back());
				a[indices[0].back()] = i;
				indices[0].pop_back();
			}
			if(indices[i].size() == avg) --low;
			if(indices[i].size() == avg+1) --high;
		}
	}
	for(auto &i : a) cout << i << " ";
	// for(int i=1; i<=m; ++i){
	// 	if(indices[i])
	// }
	return 0;
}