#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	string s;
	bool done = false;
	cin >> n;
	vector<string> v(n);
	for(int i=0; i<n; ++i){
		cin >> s;
		if(!done){
			if(s[0] == 'O' && s[1] == 'O'){
				done = true;
				s[0] = s[1] = '+';
			}else if(s[3] == 'O' && s[4] == 'O'){
				done = true;
				s[3] = s[4] = '+';
			}
		}
		v[i] = s;
	}
	if(done){
		cout << "YES\n";
		for(auto &i : v) cout << i << endl;
	}else cout << "NO\n";
	
	return 0;
}