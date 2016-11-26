#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// long long del_count = 0;

// struct data{
// 	bool is_calc;
// 	long long node_num;	//num
// 	// long long node_val;	//val
// 	long long margin;
// };

// struct node{
// 	long long baap;			//num
// 	long long child1, child2;	//num
// 	long long edge;	//val
// 	long long a;	//val
// 	bool is_leaf;
// 	data d;
// 	node(long long a, long long i){
// 		baap = -1;
// 		child1 = -1;
// 		child2 = -1;
// 		is_leaf = true;
// 		edge = 0;
// 		this->a = a;
// 		d.node_num = i;
// 		d.margin = a;
// 		d.is_calc = false;
// 	}
// };

// std::vector<node> v;
// data null_wala;

// void delete_node(long long x){
// 	if(x==-1) return;
// 	++del_count;
// 	// cout << "Deleted node " << x << " with value " << v[x].a << "\n";
// 	delete_node(v[x].child1);
// 	delete_node(v[x].child2);
// }

// data get_data(long long x){
// 	if(x==-1) return null_wala;
// 	if(v[x].d.is_calc) return v[x].d;
// 	v[x].d.margin = v[x].a;
// 	v[x].d.node_num = x;
// 	data d1 = get_data(v[x].child1);
// 	data d2 = get_data(v[x].child2);
// 	long long margin1 = d1.margin - v[v[x].child1].edge;
// 	long long margin2 = d2.margin - v[v[x].child2].edge;
// 	while(margin1<0){ 
// 		if(v[v[d1.node_num].baap].child1 == d1.node_num) v[v[d1.node_num].baap].child1 = -1;
// 		else v[v[d1.node_num].baap].child2 = -1;
// 		delete_node(d1.node_num);
// 		// cout << "done deleting\n";
// 		long long temp = v[d1.node_num].baap;
// 		while(temp != x){
// 			v[temp].d.is_calc = false;
// 			temp = v[temp].baap;
// 		}
// 		d1 = get_data(v[x].child1);
// 		margin1 = d1.margin - v[v[x].child1].edge;
// 	}
// 	if(margin1<=v[x].d.margin){
// 		v[x].d.margin = margin1;
// 		v[x].d.node_num = d1.node_num;
// 	}
// 	while(margin2<0){
// 		if(v[v[d2.node_num].baap].child1 == d2.node_num) v[v[d2.node_num].baap].child1 = -1;
// 		else v[v[d2.node_num].baap].child2 = -1;
// 		delete_node(d2.node_num);
// 		long long temp = v[d2.node_num].baap;
// 		while(temp != x){
// 			v[temp].d.is_calc = false;
// 			temp = v[temp].baap;
// 		}
// 		d2 = get_data(v[x].child2);
// 		margin2 = d2.margin - v[v[x].child2].edge;
// 	}
// 	if(margin2<=v[x].d.margin){
// 		v[x].d.margin = margin2;
// 		v[x].d.node_num = d2.node_num;
// 	}
// 	v[x].d.is_calc = true;
// 	// cout << "Node num " <<x<< " with val " <<v[x].a<< " has margin " <<v[x].d.margin << " with node num " << v[x].d.node_num << "\n";
// 	return v[x].d;
// }

// int main(int argc, char const *argv[])
// {
// 	null_wala.is_calc = true;
// 	null_wala.node_num = -1;
// 	null_wala.margin = //2000000000;
// 	9223372036854775807;
// 	long long n;
// 	long long temp, pi, ci;
// 	cin >> n;
// 	v.push_back(node(0,0));
// 	for(long long i=0; i<n; ++i){
// 		cin >> temp;
// 		v.push_back(node(temp,i+1));
// 	}
// 	for(long long i=1; i<n; ++i){
// 		// i+1 and pi with ci
// 		cin >> pi >> ci;
// 		v[i+1].baap = pi;
// 		v[i+1].edge = ci;
// 		if(v[pi].child1 == -1) v[pi].child1 = i+1; else v[pi].child2 = i+1;
// 		v[pi].is_leaf = false;
// 	}
// 	// for(long long i=1; i<=n; ++i) cout << i << " " << v[i].a << " " << v[i].child1 << " " << v[i].child2 << " " << (v[i].is_leaf?"true":"false") << " " << v[i].edge << "\n";
	
// 	get_data(1);

// 	cout << del_count;

// 	return 0;
// }

struct node{
	long long a;
	vector<int> children;
	int parent = 0;
	long long c = 0;
	long long max_dist = 0;
};

vector<node> v;
int del_count = 0;

void delete_node(int n){
	// cout << "deleting " << n << endl;
	for(auto &i : v[n].children) delete_node(i);
	++del_count;
}

void dfs(int n){
	v[n].max_dist = max(v[v[n].parent].max_dist + v[n].c, (long long)0);
	// cout << "max dist " << n << " " << v[n].max_dist << endl;
	if(v[n].max_dist > v[n].a){ 
		// cout << n << " " << v[n].max_dist << " " << v[n].a << endl;
		delete_node(n);
	}
	else for(auto &i : v[n].children) dfs(i);
}

void print_tree(int n){
	// cout << "node " << n << " parent " << v[n].parent << " a " << v[n].a << " max dist " << v[n].max_dist << endl;
	for(auto &i : v[n].children) print_tree(i);
}

int main(int argc, char const *argv[])
{
	int n, p, c;
	cin >> n;
	v = vector<node>(n+1);
	for(int i=1; i<=n; ++i) cin >> v[i].a;
	for(int i=2; i<=n; ++i){
		cin >> p >> c;
		v[i].parent = p;
		v[p].children.push_back(i);
		v[i].c = c; 
	}
	print_tree(1);
	dfs(1);
	cout << del_count << endl;
	return 0;
}
