#include <iostream>
#include <vector>
using namespace std;

struct node{
	int baap;
	int child1, child2;
	long long int edge;
	long long int a;
	bool is_leaf;
	node(int a){
		baap = -1;
		child1 = -1;
		child2 = -1;
		is_leaf = true;
		edge = 0;
		this->a = a;
	}
};

int main(int argc, char const *argv[])
{
	int n;
	long long int temp, pi, ci;
	cin >> n;
	std::vector<node> v;
	v.push_back(node(0));
	for(int i=0; i<n; ++i){
		cin >> temp;
		v.push_back(node(temp));
	}
	for(int i=1; i<n; ++i){
		// i+1 and pi with ci
		cin >> pi >> ci;
		v[i+1].baap = pi;
		v[i+1].edge = ci;
		if(v[pi].child1 == -1) v[pi].child1 = i+1; else v[pi].child2 = i+1;
		v[pi].is_leaf = false;
	}
	for(int i=1; i<=n; ++i) cout << v[i].a << " " << v[i].child1 << " " << v[i].child2 << " " << (v[i].is_leaf?"true":"false") << " " << v[i].edge << "\n";
	return 0;
}