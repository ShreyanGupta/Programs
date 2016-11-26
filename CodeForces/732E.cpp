#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[])
{
	int n, m;
	int c = 0, u = 0;
	cin >> n >> m;
	multimap<long long, int> p;
	for(int i=0; i<n; ++i){
		long long temp;
		cin >> temp;
		p.insert(make_pair(temp, i));
		// p[temp] = i;
	}
	vector< pair<long long, int> > s(m);
	vector<int> a(m, 0);
	vector<int> b(n, 0);
	for(int i=0; i<m; ++i){
		long long temp;
		cin >> temp;
		s[i] = make_pair(temp, i);
	}
	sort(s.begin(), s.end());

	// cout << "s ";
	// for(auto &i : s) cout << i.first << " "; cout << endl;

	for(int i=0; i<m; ++i){
		int z = 0;
		// printf("START %d\n", i);
		while(s[i].first != 0){
			// printf("s_i %d\n", s[i].first);
			auto temp = p.find(s[i].first);
			if(temp != p.end()){
				++c;
				a[s[i].second] = z;
				u += z;
				b[temp->second] = s[i].second+1;
				p.erase(temp);
				break;
			}
			++z;
			if(s[i].first == 1) s[i].first = 0;
			s[i].first = (s[i].first+1)/2;
		}
	}
	cout << c << " " << u << endl;
	for(auto &i : a) cout << i << " "; cout << endl;
	for(auto &i : b) cout << i << " "; cout << endl;
	return 0;
}