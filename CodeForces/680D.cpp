#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

vector<int> min_conf;
ll min_val=7;

int main(int argc, char const *argv[])
{
	ll m;
	cin >> m;
	if(m<8){
		cout << m << " " << m << endl;
		return 0;
	}
	min_conf.push_back(0);
	min_conf.push_back(7);
	
	ll cube_high=8, cube_low;
	int i=2;
	while(true){
		++i;
		cube_low = cube_high;
		cube_high = i*i*i;
		
		ll diff = cube_high - min_val;
		int next = diff/cube_low;
		ll temp = min_val + next*cube_low;
		if(temp > m) break;
		min_conf.push_back(next);
		min_val = temp;
		cout << i-1 << " " << min_val << " " << next << " " << diff << endl;
	}
	cout << min_val << endl;
	for(auto i : min_conf) cout << i << " ";
	return 0;
}