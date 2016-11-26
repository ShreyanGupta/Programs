#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class comp{
public:
	bool operator()(const pair<long long, int> &p1, const pair<long long, int> &p2){
		return p1.first > p2.first;
	}
};

int main(int argc, char const *argv[])
{
	int n,k;
	long long x, minimum = 1000000001;
	int min_index;
	cin >> n >> k >> x;
	vector<long long> v(n);
	vector<bool> sign(n);
	bool negative;
	for(int i=0; i<n; ++i){
		long long temp;
		cin >> temp;
		if(minimum > abs(temp)){
			minimum = abs(temp);
			min_index = i;
		}
		v[i] = temp;
		sign[i] = (temp > 0);
	}
	int negative_count = 0;
	for(auto i : sign) if(!i) ++negative_count;
	negative = (negative_count % 2 == 1);

	if(!negative){
		while(k>0 && minimum >= 0){
			minimum -= x;
			--k;
		}
		v[min_index] = (sign[min_index]?1:-1)*minimum;
		sign[min_index] = (v[min_index] > 0);
	}

	// for(auto &i : v) cout << i << " "; cout << endl;
	// for(auto i : sign) cout << i << " "; cout << endl;
	// cout << k << endl;

	priority_queue< pair<long long, int>, vector< pair<long long, int> >, comp > q;
	for(int i=0; i<n; ++i) q.push(make_pair(abs(v[i]),i));
	for(int i=0; i<k; ++i){
		auto temp = q.top(); q.pop();
		temp.first += x;
		q.push(temp);
	}
	while(!q.empty()){
		auto temp = q.top(); q.pop();
		v[temp.second] = (sign[temp.second]?1:-1)*temp.first;
	}

	for(auto &i : v) cout << i << " "; cout << endl;

	return 0;
}