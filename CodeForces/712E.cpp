#include <iostream>
#include <vector>
using namespace std;

// vector<double> prob;
typedef pair<double, double> dd;

struct Node{
	double a=0.5,b=0.5;
	int left;
	int right;
};

vector<Node> v;

void init(int l, int r, int x){
	v[x].left = l;
	v[x].right = r;
	if(l!=r){
		int mid = (l+r)/2;
		init(l,mid,2*x);
		init(mid+1,r,2*x+1);
	}
}

void set_prob(int n, int val, double prob){
	if(val > v[n].right || val < v[n].left) return;
	if(v[n].right == v[n].left){
		v[n].a = prob;
		v[n].b = (1-prob);
		// cout << "Val set " << v[n].right << " " << prob << endl;
		return;
	}
	set_prob(2*n, val, prob);
	set_prob(2*n+1, val, prob);
	v[n].a = v[2*n].a * v[2*n+1].a / (1 - (1 - v[2*n].b)*(1 - v[2*n+1].a));
	v[n].b = v[2*n].b * v[2*n+1].b / (1 - (1 - v[2*n].b)*(1 - v[2*n+1].a));
}

pair<double, double> search(int n, int l, int r){
	if(v[n].right < l || r < v[n].left) return make_pair(1,1);
	if(l <= v[n].left && v[n].right <= r) return make_pair(v[n].a, v[n].b);
	auto p1 = search(2*n, l, r);
	auto p2 = search(2*n+1, l, r);
	double denom = 1 - (1 - p2.first)*(1 - p1.second);
	return make_pair(p1.first*p2.first/denom, p1.second*p2.second/denom);
}

void show_prob(int n){
	if(v[n].left == v[n].right){
		cout << "Base " << v[n].left << " " << v[n].a << " " << v[n].b <<  endl;
		return;
	}
	show_prob(2*n);
	show_prob(2*n+1);
	cout << v[n].left << " " << v[n].right << " " << v[n].a << " " << v[n].b << endl;
}

int main(int argc, char const *argv[])
{
	// int n, q, type, temp, l, r;
	// long long a, b;
	// scanf("%d %d", &n, &q);
	// prob = vector<double>(n+1);
	// for(int i=1; i<=n; ++i){
	// 	cin >> a >> b;
	// 	prob[i] = 1.0*a/b;
	// }
	// for(int i=0; i<q; ++i){
	// 	cin >> type;
	// 	if(type==1){
	// 		cin >> temp >> a >> b;
	// 		prob[temp] = 1.0*a/b;
	// 	}else{
	// 		cin >> l >> r;
	// 		double x = prob[r];
	// 		for(int j=r-1; j>=l; --j){
	// 			x = prob[j]*x/(1-prob[j]*(1-x));
	// 		}
	// 		cout << x << endl;
	// 	}
	// }
	// return 0;

	int n, q, type, temp, l, r;
	long long a, b;
	scanf("%d %d", &n, &q);
	v = vector<Node>(4*n+2);
	init(1,n,1);
	for(int i=1; i<=n; ++i){
		cin >> a >> b;
		set_prob(1, i, 1.0*a/b);
	}
	// show_prob(1);
	for(int i=0; i<q; ++i){
		cin >> type;
		if(type==1){
			cin >> temp >> a >> b;
			// prob[temp] = 1.0*a/b;
			set_prob(1, temp, 1.0*a/b);
		}else{
			cin >> l >> r;
			cout << search(1, l, r).first << endl;
		}
	}
}