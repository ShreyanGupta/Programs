#include <iostream>
#include <vector>
using namespace std;

int uni_num;
int dis;

struct node{
	vector<int> adj;
	bool is_uni = false;
	bool visited;
};
vector<node> v;

void reset(){
	uni_num = -1;
	dis = 0;
	for(auto i : v) i.visited = false;
}

void bfs(int x, int d){
	if(v[x].is_uni){
		if(d > dis){
			dis = d;
			uni_num = x;
		}
	}
	for(auto i : v[x].adj){
		bfs(i, d+1);
	}
}

int main(int argc, char const *argv[])
{
	int n, k, x, y;
	cin >> n >> k;
	v = vector<node>(n+1);
	for(int i=1; i<=2*k; ++i){
		cin >> x;
		v[x].is_uni = true;
	}
	for(int i=1; i<n; ++i){
		cin >> x >> y;
		v[x].adj.push_back(y);
		v[y].adj.push_back(x);
	}
	
	for(int i=1; i<=n; ++i){
		if(!v[i].is_uni) continue;
		reset();
		bfs(i,0);
	}
	return 0;
}