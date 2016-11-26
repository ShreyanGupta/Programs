#include <iostream>
#include <set>
#include <vector>
#include <utility>
using namespace std;
typedef pair< vector<long long>, vector<long long> > odd_even;
typedef pair<long long, vector<long long> > Pair;

struct node{
	int begin;
	int end;
	long long val;
	vector<long long> arr;
};

vector<long long> a;
vector<node> v;
int n, m, l, r;

void merge(vector< long long > &a, vector< long long > &b, vector< long long > &c, long long &val){
	c = vector< long long >();
	auto ptr1 = a.begin();
	auto ptr2 = b.begin();
	// auto ptr3 = c.begin();
	while(ptr1 != a.end() && ptr2 != b.end()){
		if(*ptr1 == *ptr2){ 
			// cout << "Xored" << *ptr1 << endl;
			val ^= *ptr1;
			// c.push_back(make_pair(ptr1->first, ptr1->second + ptr2->second));
			++ptr1;	++ptr2;
		}else if(*ptr1 < *ptr2){
			c.push_back(*ptr1);
			++ptr1;
		}else{
			c.push_back(*ptr2);
			++ptr2;
		}
	}
	while(ptr1 != a.end()){
		c.push_back(*ptr1);
		++ptr1;
	}
	while(ptr2 != b.end()){
		c.push_back(*ptr2);
		++ptr2;
	}
	// copy(ptr1, a.end(), ptr3);
	// copy(ptr2, b.end(), ptr3);
}

// long long merge(vector<long long> &a, vector<long long> &b){
// 	long long ans = 0;
// 	auto ptr1 = a.begin();
// 	auto ptr2 = b.begin();
// 	while(ptr1 != a.end() && ptr2 != b.end()){
// 		if(*ptr1 == *ptr2){
// 			ans ^= *ptr1;
// 			++ptr1;	++ptr2;
// 		}else if(*ptr1 < *ptr2) ++ptr1;
// 		else ++ptr2;
// 	}
// 	return ans;
// }

void make_node(int num){
	if(v[num].begin == v[num].end){
		v[num].arr.push_back(a[v[num].begin]);
		// v[num].val = a[v[num].begin];
		v[num].val = 0;
	}else{
		int mid = (v[num].begin + v[num].end)/2;
		v[2*num].begin = v[num].begin;
		v[2*num].end = mid;
		make_node(2*num);
		v[2*num+1].begin = mid+1;
		v[2*num+1].end = v[num].end;
		make_node(2*num+1);
		v[num].val = v[2*num].val ^ v[2*num+1].val;
		merge(v[2*num].arr, v[2*num+1].arr, v[num].arr, v[num].val);
	}
}

void print_node(int num){
	cout << v[num].begin << " " << v[num].end << " val: " << v[num].val << " arr: ";
	for(auto &i : v[num].arr) cout << i << " ";	cout << endl;
	if(v[num].begin != v[num].end){
		print_node(2*num);
		print_node(2*num + 1);
	}
}

Pair query(int l, int r, int num){
	Pair temp;
	if(v[num].end < l || r < v[num].begin){ 
		temp.first = 0;
		temp.second = vector< long long >();
	}
	else if(l <= v[num].begin && v[num].end <= r){ 
		temp.first = v[num].val;
		temp.second = v[num].arr;
	}
	else{
		auto x1 = query(l, r, 2*num);
		auto x2 = query(l, r, 2*num+1);
		temp.first = x1.first ^ x2.first;
		merge(x1.second, x2.second, temp.second, temp.first);
		x1.second.clear();
		x2.second.clear();
	}
	cout << "begin: " << v[num].begin << " end: " << v[num].end << " value: " << temp.first << " array: ";
	for(auto &i : temp.second) cout << i << " "; cout << endl;
	return temp;
}

int main(int argc, char const *argv[])
{
	long long temp;
	cin >> n;
	a = vector<long long>(n+1);
	v = vector<node>(2*n+1);
	for(int i=1; i<=n; ++i) cin >> a[i];
	v[1].begin = 1;
	v[1].end = n;
	make_node(1);
	print_node(1);
	// cout << query(4,7,1);
	cin >> m;
	for(int i=0; i<m; ++i){
		cin >> l >> r;
		cout << query(l,r,1).first << endl;
	}
	return 0;
}