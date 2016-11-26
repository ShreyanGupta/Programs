#include <iostream>
#include <vector>
#include <multimap>
#include <algorithm>
using namespace std;

struct node{
	int index;
	vector< pair<int, long long> > nbr;
	long long min=100000000000000;
	long long max=100000000000000;
};

vector<node> v;
vector<bool> visited;
int n, m, l, s, t;

void set_min(){
	v[s].min = 0;
	multimap<long long, int> m;
	for(int i=0; i<n; ++i) m.insert(v[i].min, i);
	for(auto &i : m){
		for(auto &j : v[i.second].nbr){
			// update min for index j.first
			int index = j.first;
			long long new_min = min(v[index].min, v[i.first].min+j.second);
			v[index].min = new_min;
			auto range = m.equal_range(v[index].min);
			for(auto ptr=range.first; ptr!=range.second; ++ptr){
				if(ptr.second == index){
					m.insert(new_min, index);
				}
			}
		}
	}
}


int main(int argc, char const *argv[])
{
	scanf("%d %d %d %d %d", &n, &m, &l, &s, &t);
	v = vector<node>(n);
	visited = vector<bool>(n, false);
	for(int i=0; i<n; ++i) v[i].index = i;
	for(int i=0; i<m; ++i){
		int u, vv;
		long long w;
		cin >> u >> vv >> w;
		v[u].nbr.push_back(make_pair(vv,w));
		v[vv].nbr.push_back(make_pair(u,w));
	}
	set_min();
	return 0;
}