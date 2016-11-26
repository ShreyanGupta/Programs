#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct node{
	int begin;
	int end;
	long long max;
	long long min;
};

vector<node> v;
vector<long long> a,b;

void make_node(int num){
	if(v[num].begin == v[num].end){
		v[num].max = a[v[num].begin];
		v[num].min = b[v[num].begin];
		return;
	}
	int mid = (v[num].begin + v[num].end)/2;
	v[2*num].begin = v[num].begin;
	v[2*num].end = mid;
	make_node(2*num);
	v[2*num+1].begin = mid+1;
	v[2*num+1].end = v[num].end;
	make_node(2*num+1);
	v[num].max = max(v[2*num].max, v[2*num+1].max);
	v[num].min = min(v[2*num].min, v[2*num+1].min);
}

void print_node(int num){
	cout << v[num].begin << " " << v[num].end << " min: " << v[num].min << " max: " << v[num].max << endl;
	if(v[num].begin != v[num].end){
		print_node(2*num);
		print_node(2*num + 1);
	}
}

long long query_min(int l, int r, int num){
	
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	v = vector<node>(2*n+1);
	a = vector<long long>(n+1);
	b = vector<long long>(n+1);
	for(int i=1; i<=n; ++i) cin >> a[i];
	for(int i=1; i<=n; ++i) cin >> b[i];
	v[1].begin = 1;
	v[1].end = n;
	make_node(1);
	print_node(1);
	return 0;
}