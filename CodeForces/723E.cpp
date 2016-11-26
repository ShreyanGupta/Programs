#include <iostream>
#include <vector>
#include <set>
using namespace std;

struct node{
	bool possible = true;
	set<int> nbr;
};

void remove_path(vector<node> &v, vector<int> &path, vector< pair<int, int> > &directed_roads){
	int index = 0;
	while(path[index] != path.back()) ++index;
	if(index == path.size() - 1){
		v[path[0]].possible = false;
		v[path.back()].possible = false;
		for(int i=0; i<path.size()-1; ++i){
			// printf("Erase %d -> %d\n", path[i], path[i+1]);
			v[path[i]].nbr.erase(path[i+1]);
			directed_roads.push_back(make_pair(path[i], path[i+1]));
		}
		// printf("End\n");
		for(int i=path.size()-1; i>=1; --i){
			// printf("Erase %d -> %d\n", path[i], path[i-1]);
			v[path[i]].nbr.erase(path[i-1]);
		}
	}else{
		for(int i=index; i<path.size()-1; ++i){
			directed_roads.push_back(make_pair(path[i], path[i+1]));
			v[path[i]].nbr.erase(path[i+1]);
			v[path[i+1]].nbr.erase(path[i]);
		}
	}
}

bool find_loop(int x, int prev, vector<node> &v, vector<bool> &explored, vector<int> &loop){
	loop.push_back(x);
	if(explored[x]) return true;
	explored[x] = true;
	for(int i : v[x].nbr){
		if(i == prev) continue;
		if(find_loop(i,x,v,explored,loop)){
			return true;
		}
	}
	loop.pop_back();
	return false;
}

void find_path(int x, int prev, vector<node> &v, vector<int> &path){
	path.push_back(x);
	for(int i : v[x].nbr){
		if(i == prev) continue;
		find_path(i,x,v,path);
		break;
	}
}

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	for(int tt=0; tt<t; ++tt){
		// printf("START CASE %d\n", tt);
		int n,m;
		cin >> n >> m;
		vector<node> v(n+1);
		vector< pair<int, int> > directed_roads;
		for(int i=0; i<m; ++i){
			int x,y;
			cin >> x >> y;
			v[x].nbr.insert(y);
			v[y].nbr.insert(x);
		}
		for(int i=1; i<=n; ++i){
			bool loop = true;
			while(loop){
				vector<int> path;
				vector<bool> explored(n+1,false);
				loop = find_loop(i,-1,v,explored,path);
				// cout << "Node "<<i<<" Loop : "; for(int i : path) cout << i << " "; cout << endl;
				if(loop) remove_path(v,path,directed_roads);
			}
		}
		bool has_path = true;
		while(has_path){
			has_path = false;
			for(int i=1; i<=n; ++i){
				if(v[i].nbr.size() % 2 == 1){
					vector<int> path;
					find_path(i,-1,v,path);
					// cout << "Node "<<i<<" Path : "; for(int i : path) cout << i << " "; cout << endl;
					remove_path(v,path,directed_roads);
					has_path = true;
				}
			}
		}


		// while(v[i].nbr.size() != 0){
		// }
		int count = 0;
		for(int i=1; i<=n; ++i){
			if(v[i].possible) ++count;
		}
		printf("%d\n", count);
		for(auto &i : directed_roads) printf("%d %d\n", i.first, i.second);
		// printf("END CASE %d\n", tt);
	}
	return 0;
}