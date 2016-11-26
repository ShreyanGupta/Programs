#include <iostream>
#include <vector>
#include <tuple>
#include <utility>
#include <climits>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef tuple <int, int, int> tup;

struct tuphash {
public:
  template <typename T, typename U, typename W>
  std::size_t operator()(const std::tuple<T, U, W> &x) const
  {
    return std::hash<T>()(get<0>(x)) ^ std::hash<U>()(get<1>(x)) ^ std::hash<U>()(get<2>(x));
  }
};

unordered_map<tup, ll, tuphash> mapx;
vector<int> c;
vector< vector<ll> > p;
int n, m, k;

ll opt(int i, int k_left, int last_colour){
	if(i==n+1){ 
		if(k_left != 0) return LLONG_MAX/200;
		return 0;
	}
	if(k_left == -1) return LLONG_MAX/200;

	auto val = mapx.find(make_tuple(i, k_left, last_colour));
	if(val != mapx.end()) return val->second;
	// cout << "opt " << i << " " << k_left << " " << last_colour << endl;
	
	ll min = LLONG_MAX;
	if(c[i] != 0){
		if(c[i]==last_colour) min = opt(i+1, k_left, c[i]);
		else min = opt(i+1, k_left-1, c[i]);
	}else{
		ll temp;
		// ll min = LLONG_MAX;
		// vector<ll> temp(m+1);
		for(int j=1; j<=m; ++j){
			if(j==last_colour) temp = opt(i+1, k_left, j) + p[i][j];
			else temp = opt(i+1, k_left-1, j) + p[i][j];
			if(temp < min) min = temp;
			// cout << temp;
		}
		//yahaan
	}
	mapx[make_tuple(i, k_left, last_colour)] =  min;
	return min;
}

int main(int argc, char const *argv[])
{
	cin >> n >> m >> k;
	c = vector<int>(n+1);
	p = vector< vector<ll> >(n+1, vector<ll>(m+1));
	for(int i=1; i<=n; ++i) cin >> c[i];
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j) cin >> p[i][j];
	}
	ll answer = opt(1, k, -1);
	if(answer > 1000000000000) cout << "-1";
	else cout << answer;
	// auto xyz = make_tuple(1,2,3);
	
	return 0;
}