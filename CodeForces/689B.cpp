#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(int argc, char const *argv[])
{
	int n = 0;
	int temp = 0;
	cin >> n;
	// vector< vector<int> > v(n+1, vector<int>());
	vector<int> m(n+1, 200001);
	vector<int> x(n+1, 0);
	for(int i=1; i<=n; ++i){
		cin >> temp;
		// v[temp].push_back(i);
		x[i] = temp;
	}
	// for(int i=1; i<=n; ++i){
	// 	cout << i << "ke liye ";
	// 	for(auto &j : v[i]) cout << j << " ";
	// 	cout << endl;
	// }
	
	// m[1] = 0;	cout << "0 ";
	// temp = 0;
	// for(int i=2; i<=n; ++i){
	// 	temp = m[i-1] + 1;
	// 	for(auto &j : v[i]){
	// 		// cout << " testing " << m[j]+1; 
	// 		if(j!=i && temp > m[j]+1) temp = m[j]+1;
	// 	}
	// 	m[i] = temp;
	// 	cout << temp << " ";
	// }

	queue<int> q;
	q.push(1);
	m[1] = 0;
	while(q.size()!=0){
		int temp = q.front();
		q.pop();
		// cout << temp << " with val " << m[temp] << endl;
		if(m[temp-1] > m[temp]+1)
		{ 
			m[temp-1] = m[temp]+1;
			q.push(temp-1);
		}
		if(temp!=n)
		{
			if(m[temp+1] > m[temp]+1)
			{
				m[temp+1] = m[temp]+1;
				q.push(temp+1);
			}
		}
		if(m[x[temp]] > m[temp]+1)
		{
			m[x[temp]] = m[temp]+1;
			q.push(x[temp]);
		}
	}
	for(int i=1; i<=n; ++i) cout << m[i] << " ";
	return 0;
}