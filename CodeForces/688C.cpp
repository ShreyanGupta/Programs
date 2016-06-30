#include <iostream>
#include <vector>
using namespace std;

bool is_possible = true;
int c0 = 0;
int c1 = 0;

struct vertex{
	vector<int> list;
	int color = -1;
};
vector<vertex> v;

void set_color(int x, int c){
	if(v[x].color == c) return;
	else if(v[x].color == -1){
		v[x].color = c;
		c==1? ++c1: ++c0;
		for(auto &i : v[x].list) set_color(i, c==1?0:1);
	}else is_possible = false;
}

void print(){
	cout << "Possible? " << (is_possible?"true\n":"false\n");
	cout << "Color 0 " << c0 << " Color 1 " << c1 << endl;
	for(int i=1; i<v.size(); ++i){
		cout << i << " color " << v[i].color << " vertex list ";
		for(auto &j : v[i].list) cout << j << " ";
		cout << endl;
	}
	cout << endl;
}

int main(int argc, char const *argv[])
{
	int n, m;
	int u, w;
	cin >> n >> m;
	v = vector<vertex>(n+1);
	for(int i=0; i<m; ++i){
		cin >> u >> w;
		v[u].list.push_back(w);
		v[w].list.push_back(u);
	}
	// print();
	for (int i=1; i<=n; ++i){
		if(v[i].color==-1) set_color(i, 1);
	}
	// print();
	if(is_possible){
		cout << c0 << endl;
		for(int i=0; i<=n; ++i) if(v[i].color==0) cout << i << " ";
		cout << endl << c1 << endl;
		for(int i=0; i<=n; ++i) if(v[i].color==1) cout << i << " ";
	}else cout << -1;
	return 0;
}