#include <iostream>
#include <vector>
#include <map>
using namespace std;

int n,m,k;
const bool land = true;
const bool water = false;

void search(int x, int y, vector< vector<bool> > &explored, vector< vector<bool> > &v, vector< pair<int, int> > &lake){
	if(explored[x][y]) return;
	if(v[x][y] == land) return;

	lake.push_back(make_pair(x,y));
	explored[x][y] = true;
	if(y!=m+1) search(x, y+1, explored, v, lake);
	if(x!=n+1) search(x+1, y, explored, v, lake);
	if(y!=0) search(x, y-1, explored, v, lake);
	if(x!=0) search(x-1, y, explored, v, lake);
}

int main(int argc, char const *argv[])
{
	cin >> n >> m >> k;
	vector< vector<bool> > v(n+2, vector<bool>(m+2,water));
	for(int i=0; i<n; ++i){
		string s;
		cin >> s;
		for(int j=0; j<m; ++j){
			if(s[j] == '*') v[i+1][j+1] = land;
		}
	}
	vector< vector<bool> > explored(n+2, vector<bool>(m+2,false));
	vector< pair<int,int> > ocean;
	search(0,0,explored,v,ocean);

	multimap<int, vector< pair<int,int> > > lake_list;

	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			if(!explored[i][j]){
				vector< pair<int,int> > lake;
				search(i,j,explored,v,lake);
				if(lake.size() != 0)
				lake_list.insert(make_pair(lake.size(), lake));
			}
		}
	}
	// for(auto &itr : lake_list){
	// 	printf("Lake size %d\n", itr.first);
	// 	for(auto &i : itr.second) printf("%d %d\n",i.first, i.second); 
	// }

	int count = 0;
	auto itr = lake_list.begin();
	for(int i=k; i<lake_list.size(); ++i){
		count += itr->first;
		for(auto &j : itr->second){
			v[j.first][j.second] = land;
		}
		++itr;
	}
	cout << count << endl;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			if(v[i][j] == land) cout << "*";
			else cout << ".";
		}
		cout << endl;
	}
	return 0;
}