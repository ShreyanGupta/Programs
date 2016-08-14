#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	string s;
	vector<long long> v;
	long long dis = 10000000000;
	cin >> n >> s;
	for(long long i=0; i<n; ++i){
		long long temp;
		cin >> temp;
		v.push_back(temp);
	}
	size_t temp = 0;
	while(true){
		temp = s.find("RL",temp);
		if(temp == string::npos) break;
		temp += 2;
		if(v[temp-1]-v[temp-2] < dis) dis = v[temp-1]-v[temp-2];
		// cout << temp << " " << v[temp-1] << " " << v[temp-2] << endl;
	}
	if(dis==10000000000) cout << "-1";
	else cout << dis/2;
	return 0;
}