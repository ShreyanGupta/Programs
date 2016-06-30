#include <iostream>
#include <vector>
using namespace std;
bool is_possible = true;
vector<int> list;

struct node{
	int baap = -1;
	vector<int> children;
	int gift_to = -1;
};
vector<node> v;

void print(vector<int> v){
	for(auto &i : v) cout << i << " ";
}

void print(vector<node> v){
	for(int i=1; i<v.size(); ++i){
		cout << i << " gift to " << v[i].gift_to << " baap " << v[i].baap << " children ";
		print(v[i].children);
		cout << endl;
	}
}

void get_list(int x){
	for(auto &i : v[x].children) get_list(i);
	if(v[x].gift_to == x) list.push_back(x);
}

int main(int argc, char const *argv[])
{
	int n, m;
	int p, q, a;
	cin >> n >> m;
	v = vector<node>(n+1);
	for(int i=0; i<m; ++i){
		cin >> p >> q;
		// cout << "p "<<p<<" q "<<q<<endl;
		v[p].children.push_back(q);
		v[q].baap = p;
	}
	// cout<<endl; print(v);

	for(int i=1; i<=n; ++i){
		cin >> a;
		int temp = i;
		while(temp != a){
			if(v[temp].gift_to == -1) v[temp].gift_to = a;
			else if(v[temp].gift_to != a) is_possible = false;
			temp = v[temp].baap;
			// cout << "loop\n";
		}
		if(v[a].gift_to == -1) v[a].gift_to = a;
		else if(v[a].gift_to != a) is_possible = false;
	}
	// cout << (is_possible?"is possible : true\n":"is possible : false\n");
	// print(v);
	if(is_possible)
	for(int i=1; i<=n; ++i){
		if(v[i].baap==-1) get_list(i);
	}
	// cout << "list is "; print(list);
	if(is_possible){
		cout << list.size() << endl;
		for(auto &i : list) cout << i <<endl;
	}else cout << -1;
	return 0;
}