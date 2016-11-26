#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

vector <long long> g, g2;

long long get_answer(ll n, ll m){
	vector<int> g(n+1);
	vector<int> g2(n+1);
	vector<int> combi(n+1);
	int fact = 1;
	for(int i=1; i<=n; ++i){
		fact *= i;
		fact %= m;
		combi *= (n-i-1);
		combi /= i;
		g[i] = 
	}
}


int main(int argc, char const *argv[])
{
	ifstream fin ("test.in");
	ofstream fout ("output");

	int t0;
	long long n, l1, r1, a, b, c1, c2, m;
	fin >> t0;
	for(int t=1; t<=t0; ++t){
		fout << "Case #" << t << ": ";
	}
	return 0;
}