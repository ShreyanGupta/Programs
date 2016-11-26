#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main(int argc, char const *argv[])
{
	int n;
	int x=-1,y=-1;
	bool possible = true;
	ll temp, global_sum = -1;
	cin >> n;
	vector< vector <ll> > v(n, vector<ll>(n));
	for(int i=0; i<n; ++i){
		ll sum = 0;
		for(int j=0; j<n; ++j){
			cin >> temp;
			v[i][j] = temp;
			sum += temp;
			if(temp == 0){
				x = i;
				y = j;
			}
		}
		if(global_sum == -1){
			if(i != x) global_sum = sum;
		}else{
			if(i != x){
				if(sum != global_sum) possible = false;
			}
		}
	}
	for(int j=0; j<n; ++j){
		ll sum = 0;
		for(int i=0; i<n; ++i) sum += v[i][j];
		if(j == y){ 
			v[x][y] = global_sum - sum;
			if(v[x][y] < 1) possible = false;
		}
		else{
			if(sum != global_sum) possible = false;
		}
	}
	ll sum = 0;
	for(int j=0; j<n; ++j) sum += v[x][j];
	if(sum != global_sum) possible = false;
	sum = 0;
	for(int i=0; i<n; ++i) sum += v[i][i];
	if(sum != global_sum) possible = false;
	sum = 0;
	for(int i=0; i<n; ++i) sum += v[i][n-i-1];
	if(sum != global_sum) possible = false;

	if(n==1){
		cout << "1";
		return 0;
	}
	if(possible){
		cout << v[x][y];
	}else cout << "-1";
	return 0;
}