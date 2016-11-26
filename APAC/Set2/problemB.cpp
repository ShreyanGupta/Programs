#include <iostream>
#include <vector>
using namespace std;

long count(vector< vector<bool> > &v, int r, int c){
	long num=0;
	if(r==0 || c==0) return 0;
	// if(d>r || d>c) return 0;
	for(int i=0; i<r; ++i){
		for(int j=0; j<c; ++j){
			if(!v[i][j]) ++num;
			v[i][j] = v[i][j] || v[i+1][j] || v[i][j+1] || v[i+1][j+1];
		}
	}
	// for(int i=0; i<r-1; ++i){
	// 	for(int j=0; j<c-1; ++j){
			
	// 	}
	// }
	return num + count(v, r-1, c-1);
}

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	for(int x=1; x<=t; ++x){
		int r, c, k;
		scanf("%d %d %d", &r, &c, &k);
		vector< vector<bool> > v(r+1, vector<bool>(c+1, false));
		for(int i=0; i<k; ++i){
			int p, q;
			cin >> p >> q;
			v[p][q] = true;
		}
		printf("Case #%d: %ld\n", x, count(v, r, c));
	}
	return 0;
}