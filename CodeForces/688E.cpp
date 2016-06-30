#include <iostream>
#include <set>
#include <vector>
using namespace std;
vector< vector< set<int> > > v;
vector<int> values;

void union2(set<int> &a, set<int> &b, int x, set<int> &temp){
	temp = b;
	// temp.insert(x);
	for(auto it=a.begin(); it!=a.end(); ++it){
		temp.insert(*it);
		temp.insert(*it+x);
	}
	// return temp;
}

void print_set(set<int> x){
	for(auto it=x.begin(); it!=x.end(); ++it) cout << *it << " ";
	cout << endl;
}

set<int> &rec(int i, int j){
	if(!v[i][j].empty()) return v[i][j];
	if(i==0){
		if(values[0]==j){
			v[0][j].insert(j);
			v[0][j].insert(0);
		}
		if(j==0) v[0][0].insert(0);
	}else{
		int bla = j-values[i];
		if(bla>=0) union2(rec(i-1,bla), rec(i-1,j), values[i], v[i][j]);
		else v[i][j] = rec(i-1,j);
		if(j==0) v[i][0].insert(0);
	}
	// cout << i+1 << " " << j << " values: "; print_set(v[i][j]);
	return v[i][j];
}

int main(int argc, char const *argv[])
{
	int n, k, temp;
	cin >> n >> k;
	v = vector< vector<set<int> > >(n, vector<set<int> >(k+1, set<int>()));
	for(int i=0; i<n; ++i){
		cin >> temp;
		values.push_back(temp);
	}

	for(int i=0; i<n; ++i)
	for(int j=0; j<=k; ++j){
		if(i==0){
			if(values[0]==j){
				v[0][j].insert(j);
				v[0][j].insert(0);
			}
			if(j==0) v[0][0].insert(0);
		}else{
			int bla = j-values[i];
			// if(bla>0) v[i][j] = union1(add_elt(, values[i]), v[i-1][j]);
			if(bla>=0) union2(v[i-1][bla], v[i-1][j], values[i], v[i][j]);
			else v[i][j] = v[i-1][j];
			if(j==0) v[i][0].insert(0);
		}
		// cout << i+1 << " " << j << " values: "; print_set(v[i][j]);
	}
	// rec(n-1,k);

	cout << v[n-1][k].size() << endl;
	for(auto it=v[n-1][k].begin(); it!=v[n-1][k].end(); ++it) cout << *it << " ";
	cout << endl;
	return 0;
}