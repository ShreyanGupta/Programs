#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
typedef pair<int,int> P;

vector< vector<int> > v;
int n, m, p, temp;

struct data{
	int a;
};

void dfs_4(int i, int j, int x){
	vector< vector<bool> > visited(n+1, vector<bool>(m+1, false));
	queue<P> search;
	search.push(P(i,j));
	visited[i][j] = true;
	while(!search.empty()){
		P temp = search.front(); search.pop();
		if(visited[temp.first][temp.second]) continue;
		if(v[temp.first][temp.second]==x)
	}
}

int main(int argc, char const *argv[])
{
	cin >> n >> m >> p;
	v = vector< vector<int> >(n+1, vector<int>(m+1));
	for(int i=1; i<=n; ++i)
	for(int j=1; j<=m; ++j){
		cin >> temp;
		v[i][j] = temp;
	}
	return 0;
}