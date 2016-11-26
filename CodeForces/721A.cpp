#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	string s;
	cin >> n >> s;
	bool running = false;
	vector<int> v;
	for(int i=0; i<n; ++i){
		if(running){
			if(s[i] == 'B') ++v.back();
			else{
				running = false;
			}
		}else{
			if(s[i] == 'B'){
				running = true;
				v.push_back(1);
			}
		}
	}
	cout << v.size() << endl;
	for(auto &i : v) cout << i << " "; cout << endl;
	return 0;
}