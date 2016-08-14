#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

bool sort_fn(std::pair<int, int> &p1, std::pair<int, int> &p2){
	// return (p1.first < p2.first);

	if(p1.first < p2.first) return true;
	else if(p1.first == p2.first){
		if(p1.second < p2.second) return true;
		else return false;
	}else return false;s
}

int main(int argc, char const *argv[])
{
	int n, x, y;
	std::cin >> n;
	std::vector< std::pair<int, int> > v;
	for(int i=0; i<n; ++i){
		std::cin >> x >> y;
		v.push_back(std::make_pair(x,y));
	}
	std::sort(v.begin(), v.end(), sort_fn);
	
	int x_temp = v[0].first;
	int index_start = 0;
	int index_end = 0;
	for(int i=0; i<=n/2; ++i){
		if(v[i].first == x_temp) ++index_end;
		else{
			std::reverse(v.begin()+index_start, v.begin()+index_end);
			index_start = i;
			index_end = i;
			x_temp = v[i].first;
		}
	}
	// for(auto i : v) std::cout << i.first << " " << i.second << std::endl;

	int x_avg = (v[0].first + v[n-1].first);
	bool possible = true;
	for(int i=0; i<n; ++i){
		if(!((v[i].first + v[n-1-i].first) == x_avg && (v[i].second == v[n-1-i].second))) 
			possible = false;
	}
	std::cout << (possible?"YES":"NO");
	return 0;
}