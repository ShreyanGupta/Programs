#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	long long answer = -1;
	double x = 0.202056903159594285399738161511449990764986292340498881792;
	long long m;
	cin >> m;
	vector<long long> cube;
	long long i=2;
	long long upper_limit = (double)m/x;
	while(true){
		long long temp = i*i*i;
		if(temp > upper_limit) break;
		cube.push_back(temp);
		++i;
	}
	cube.push_back(i*i*i);
	// for(auto &i : cube) cout << i << " "; cout << endl;
	cout << "upper limit " << upper_limit << endl;
	for(auto i = upper_limit - cube.size() - 100; i<upper_limit; ++i){
		long long temp = 0;
		for(auto &j : cube) temp += i/j;
		cout << i << " " << temp << endl;
		// if(temp == m) cout << "FOUND!!! " << i;
		if(temp == m){
			answer = i;
			break;
		}
	}
	for(int i=1; i<200; ++i){
		if((i/8 + i/27 + i/64 + i/125) == m){
			answer = i;
			break;
		}
	}
	cout << answer << endl;
	return 0;
}