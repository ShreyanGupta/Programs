#include <iostream>
#include <map>
using namespace std;
typedef long long ll;

map<ll, ll> m;

ll calc_cost(ll u, ll v){
	ll temp = 0;
	while(u!=v){
		if(u>v){
			temp += m[u];
			u/=2;
		}else{
			temp += m[v];
			v/=2;
		}
	}
	return temp;
}

void add_cost(ll u, ll v, ll w){
	while(u!=v){
		if(u>v){
			m[u]+=w;
			u/=2;
		}else{
			m[v]+=w;
			v/=2;
		}
	}
}

int main(int argc, char const *argv[])
{
	int q, p;
	cin >> q;
	long long u, v, w;
	for(int i=0; i<q; ++i){
		cin >> p;
		if(p==1){ 
			cin >> u >> v >> w;
			add_cost(u,v,w);
		}else{
			cin >> u >> v;
			cout << calc_cost(u,v) << endl;
		}
	}
	return 0;
}