#include <iostream>
#include <vector>
using namespace std;

struct data{
	vector<int> children;
	double start_time;
	int tree_size;
	int parent;
};
vector<data> d;

int calc_size(int x){
	int temp = 1;
	for(auto i : d[x].children){
		temp += calc_size(i);
	}
	d[x].tree_size = temp;
	return temp;
}

void calc_exp(int x){
	double temp = d[d[x].parent].start_time + 0.5 - d[x].tree_size/2.0 + (d[d[x].parent].tree_size)/2.0;
	// for(auto i : d[d[x].parent].children){
	// 	temp += d[i].tree_size/2.0;
	// 	// calc_exp(i);
	// }
	d[x].start_time = temp;
	for(auto i: d[x].children) calc_exp(i);
}

int main(int argc, char const *argv[])
{
	int n, p;
	cin >> n;
	d = vector<data>(n+1);
	for(int i=2; i<=n; ++i){
		cin >> p;
		d[p].children.push_back(i);
		d[i].parent = p;
	}
	d[1].parent = 0;
	d[0].start_time = 0;
	d[0].children.push_back(1);
	calc_size(0);
	// for(auto i : d) cout << i.tree_size << " ";

	calc_exp(1);
	for(int i=1; i<=n; ++i) cout << d[i].start_time << " ";
	return 0;
}