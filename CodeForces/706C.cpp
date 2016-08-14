#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct data{
	string r;
	string s;
	long long v;
	long long opt1, opt2;
};

int main(int argc, char const *argv[])
{
	long long max_l = 100000000000001;
	int n;
	long long xx;
	string temp;
	cin >> n;
	vector<long long> v(n+1), opt1(n+1), opt2(n+1);
	vector<string> r(n+1), s(n+1);
	for(int i=1; i<=n; ++i){ 
		cin >> xx;
		v[i] = xx;
	}
	for(int i=1; i<=n; ++i){ 
		cin >> temp;
		r[i] = temp;
		s[i] = temp;
		reverse(s[i].begin(), s[i].end());
		// d[i].is_less = (d[i].r.compare(d[i].s) == -1);
		// cout << d[i].s;
	}
	opt1[1] = 0;
	opt2[1] = v[1];
	for(int i=2; i<=n; ++i){
		
		if(r[i].compare(r[i-1])>0) opt1[i] = opt1[i-1];
		else opt1[i] = max_l;
		if(r[i].compare(s[i-1])>0){
			if(opt2[i-1] < opt1[i]) opt1[i] = opt2[i-1];
		}

		if(s[i].compare(r[i-1])>0) opt2[i] = opt1[i-1];
		else opt2[i] = max_l;
		if(s[i].compare(s[i-1])>0){
			if(opt2[i-1] < opt2[i]) opt2[i] = opt2[i-1];
		}
		opt2[i] += v[i];
		// cout << d[i].opt1 << " " << d[i].opt2 << endl;
	}
	long long ans = (opt1[n] < opt2[n] ? opt1[n] : opt2[n]) ;
	// long long ans = (d[n].opt1 < d[n].opt2 ? d[n].opt1 : d[n].opt2);
	if(ans >= max_l) cout << -1;
	else cout << ans;
	return 0;
}