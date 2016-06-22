#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	long long int n;
	long long int x;
	cin >> n;
 	std::vector<long long int> v;
 	for(long long int i=0; i<n; ++i){ 
 		cin >> x;
 		v.push_back(x);
 	}	
 	std::sort(v.begin(), v.end());
 	// for(long long int i=0; i<n; ++i)
 	// cout << v[i] << " ";
 	x=1;
 	for(long long int i=0; i<n; ++i){
 		if(v[i]>=x) ++x;
 	}
 	cout << x;
	return 0;
}