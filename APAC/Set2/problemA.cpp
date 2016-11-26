#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
using namespace std;

double backtrack(int x, int y, int s, vector< vector<double> > &v, vector< vector<double> > &w, int r, int c){
	if(x < 0 || x == r) return 0;
	if(y < 0 || y == c) return 0;
	if(s==0) return 0;
	double temp = v[x][y];
	v[x][y] *= (1-w[x][y]);
	double c1 = backtrack(x+1, y, s-1, v, w, r, c);
	double c2 = backtrack(x-1, y, s-1, v, w, r, c);
	double c3 = backtrack(x, y+1, s-1, v, w, r, c);
	double c4 = backtrack(x, y-1, s-1, v, w, r, c);
	double m = c1;
	m = max(m, c2);
	m = max(m, c3);
	m = max(m, c4);
	v[x][y] = temp;
	return m+temp;
}

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	for(int x=1; x<=t; ++x){
		int r, c, rs, cs, s;
		double p, q;
		scanf("%d %d %d %d %d", &r, &c, &rs, &cs, &s);
		cin >> p >> q;
		vector< vector<double> > v(r, vector<double>(c));
		vector< vector<double> > w(r, vector<double>(c));
		for(int i=0; i<r; ++i){
			for(int j=0; j<c; ++j){
				char z;
				cin >> z;
				v[i][j] = (z=='A'?p:q);
				w[i][j] = (z=='A'?p:q);
			}
		}
		double c1 = backtrack(rs+1, cs, s, v, w, r, c);
		double c2 = backtrack(rs-1, cs, s, v, w, r, c);
		double c3 = backtrack(rs, cs+1, s, v, w, r, c);
		double c4 = backtrack(rs, cs-1, s, v, w, r, c);
		double m = c1;
		m = max(m, c2);
		m = max(m, c3);
		m = max(m, c4);
		printf("Case #%d: ", x);
		cout << setprecision(9) << m << endl;
	}
	return 0;
}