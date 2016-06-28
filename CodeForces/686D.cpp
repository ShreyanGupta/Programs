#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
typedef long long ll;
using namespace std;

struct node{
	int baap;
	vector<int> children;
	int size_subtree;
	int size_connected;
	int solution = -1;
};

vector<node> v;

inline int mx(int a, int b){return a>b?a:b;}

int max(vector<int> x){
	int m=0;
	for(auto &i : x) if(v[i].size_subtree > m) m=v[i].size_subtree;
	return m;
}
int sum(vector<int> x){
	int m=0;
	for(auto &i : x) m += v[i].size_subtree;
	return m;
}

void print_children(vector<int> x){
	for(auto &i : x) cout << i << " ";
}

void print(int i){
	cout << i << " children "; 
	// print_children(v[i].children);
	cout << "\tsubtree size " << v[i].size_subtree << " max break " << v[i].size_connected;
	cout << "\tsolution " << v[i].solution;
	cout << "\n";
}

void dfs(int x){
	for(auto &i : v[x].children){
		dfs(i);
	}
	v[x].size_subtree = sum(v[x].children) + 1;
	v[x].size_connected = max(v[x].children);
	// print(x);
}

int calc_sol(int x){
	if(v[x].solution!=-1) return v[x].solution;
	int x_size = v[x].size_subtree;
	int lim = x_size/2;
	if(v[x].size_connected <= lim){
		v[x].solution = x;
		// print(x);
		return x;
	}
	for(auto &temp : v[x].children){
		// if(x_size-v[temp].size_subtree > lim) continue;
		int temp_sol = calc_sol(temp);
		while(temp_sol != x){
			if(mx(x_size-v[temp_sol].size_subtree, v[temp_sol].size_connected)<=lim){
				v[x].solution = temp_sol;
				// print(x);
				return temp_sol;
			}
			temp_sol = v[temp_sol].baap;
		}
	}
	// print(x);
}

int bfs(int x){
	int x_size = v[x].size_subtree;
	int lim = x_size/2;
	queue<int> q;
	q.push(x);
	while(q.size()!=0){
		int temp = q.front();
		q.pop();
		if(mx(x_size-v[temp].size_subtree, v[temp].size_connected)<=lim) return temp;
		else for(auto &i : v[temp].children){
			q.push(i);
		}
	}
}

int main(int argc, char const *argv[])
{
	int n, q, temp;
	cin >> n >> q;
	v = vector<node>(n+1);
	for(int i=2; i<=n; ++i){
		cin >> temp;
		v[i].baap = temp;
		v[temp].children.push_back(i);
	}
	dfs(1);
	for(int i=0; i<q; ++i){
		cin >> temp;
		cout << calc_sol(temp) << "\n";
		// cout << "Node value for "<<temp<<" is "<<calc_sol(temp)<<"\n";
	}
	// calc_sol(1);
	// for(int i=1; i<=n; ++i){
	// 	print(i);
	// }
	return 0;
}