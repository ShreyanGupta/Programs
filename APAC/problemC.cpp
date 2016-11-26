#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

void fun(long long left, long long right){
	while(v[i].second < right){
		.
	}
}

int main(int argc, char const *argv[])
{
	ifstream fin ("test.in");
	ofstream fout ("output");

	int t0;
	long long n, l1, r1, a, b, c1, c2, m;
	fin >> t0;
	for(int t=1; t<=t0; ++t){
		fout << "Case #" << t << ": ";
		fin >> n >> l1 >> r1 >> a >> b >> c1 >> c2 >> m;
		long long x=l1, y=r1;
		long long x2, y2;
		vector< pair<ll, ll> > v;
		for(int i=1; i<=n; ++i){
			v.push_back(make_pair(min(x,y), max(x,y)));
			x2 = (a*x + b*y + c1)%m;
			y2 = (a*y + b*x + c2)%m;
			x = x2;
			y = y2;
		}
		sort(v.begin(), v.end());
		long long start = v[0].first;
		long long max_end = 0;
		for(int i=0; i<v.size(); ++i){
			if(v[i].second <= max_end) continue;
			if(max_end < v[i].first){

			}else{
				// ??
			}
		}
	}
	return 0;
}