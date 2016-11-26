#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

struct node{
	long long t_left = -1;
	int next = -1;
	int n_len = 0;
	vector< pair<int,long long> > path;
};

vector< node > v;
int n,m;
long long t;

int search(int x, long long t_left, int len){
	if(t_left < 0) return -1;
	if(x == n) return len;
	
	if(len <= v[x].n_len && t_left < v[x].t_left) return -1;

	int best = -1;
	for(auto &i : v[x].path){
		int temp = search(i.first, t_left - i.second, len+1);
		if(best < temp){
			best = temp;
			v[x].next = i.first;
		}
	}
	v[x].n_len = len;
	v[x].t_left = t_left;

	return best;
}

int main(int argc, char const *argv[])
{
	cin >> n >> m >> t;
	v = vector< node >(n+1);
	for(int i=0; i<m; ++i){
		int x,y;
		long long temp;
		cin >> x >> y >> temp;
		v[x].path.push_back(make_pair(y,temp));
	}
	cout << search(1,t,1) << endl;
	int c = 1;
	while(c != n){
		cout << c << " ";
		c = v[c].next;
	}
	cout << n << endl;
	return 0;
}