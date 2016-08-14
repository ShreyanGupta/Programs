#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	long long n, k, temp;
	long long answer=0;
	long long partial_sum=0;
	vector<long long> v(1,1);
	cin >> n >> k;
	for(long long i=1; i<=n; ++i){
		cin >> temp;
		v.push_back(temp);
		partial_sum += temp;
	}

	vector<long long> cap(k+1);
	// vector<long long> partial_sum(k+1);
	// partial_sum[k] = 0;
	
	for(long long i=0; i<k; ++i){
		cin >> temp;
		cap[i] = temp;
		// partial_sum -= v[temp];
	}
	cap[k] = n+1;
	v[0] = v[n];
	// for(long long i=k-1; i>=0; --i){
	// 	partial_sum[i] = partial_sum[i+1] + v[cap[i]];
	// 	cout << partial_sum[i] << " ";
	// }
	for(long long i=1; i<n; ++i) answer += v[i]*v[i+1];
	answer += v[n]*v[1];
	// cout << "partial_sum " << partial_sum << endl;
	
	for(long long i=0; i<k; ++i){
		temp = 0;
		for(int j=0; j<i; ++j) if(cap[j]!=cap[i]+1) temp += v[cap[j]];
		answer -= temp*v[cap[i]];
		answer += (partial_sum - v[cap[i]] - v[(cap[i]+1)%n] - v[(cap[i]-1+n)%n]) * v[cap[i]];
		// if(cap[i+1]==cap[i]+1) answer += v[i]*partial_sum[i+2];
		// else answer += v[i]*partial_sum[i+1];
	}

	for(int i=0; i<k-1; ++i) if(cap[i]+1==cap[i+1]) answer += v[cap[i]]*v[cap[i]+1];
	if(cap[k-1]==n && cap[0]==1) answer += v[1]*v[n];


	// for(long long k : cap){
	// 	temp = sum - v[k] - v[(k+1)%n] - v[(k-1+n)%n];
	// 	// cout << "temp " << temp << " " << " vk " << v[k] << endl;
	// 	answer += temp*v[k];
	// }
	// // cout << "term 2 " << answer << endl;
	// temp = 0;
	// for(long long k1 : cap)
	// for(long long k2 : cap){
	// 	if(k1!=k2) temp += v[k1]*v[k2];
	// }
	// answer -= temp/2;
	cout << answer;
	return 0;
}
