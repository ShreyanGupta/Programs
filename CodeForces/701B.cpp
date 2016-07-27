#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	long long count, x_done=0, y_done=0;
	// map<long long> x_map, y_map;

	long long n, m, x, y;
	cin >> n >> m;

	vector<bool> vx(n+1, false);
	vector<bool> vy(n+1, false);
	count = n*n;

	for(long long i=0; i<m; ++i){
		cin >> x >> y;
		if(vx[x]==false){
			count -= (n - y_done);

			// for(long long yy=1; yy<=n; ++yy){
			// 	if(vy[yy]==false) --count;
			// }
			vx[x] = true;
			x_done += 1;
		}
		if(vy[y]==false){
			count -= (n - x_done);
			// for(long long xx=1; xx<=n; ++xx){
			// 	if(vx[xx]==false) --count;
			// }
			vy[y] = true;
			y_done += 1;
		}
		cout << count << " ";
	}
	// for(long long x=1; x<=n; ++x){
	// 	if(x_map.find(x)==x_map.end()) continue;
	// 	for(long long y=1; y<=n; ++y){
	// 		if(y_map.find(y)==y_map.end()) continue;
	// 		++count;
	// 	}
	// }
	// cout << count;
	return 0;
}