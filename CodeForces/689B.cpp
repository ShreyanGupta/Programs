#include <iostream>
#include <vector>
#include <queue>
#include <cassert>
using namespace std;

vector<int> m;
vector<int> x;
int main()
{
	int n = 0;
	int temp = 0;
	cin >> n;
	// vector< vector<int> > v(n+1, vector<int>());

    m.assign(n+2, 200001);
    x.assign(n+1, 0);
	//vector<int> m(n+1, 200001);
	//vector<int> x(n+1, 0);
	for(int i=1; i<=n; ++i){
		cin >> temp;
		x[i] = temp;
	}

	queue<int> q;
	q.push(1);
	m[0] = -1;
	m[1] = 0;
	m[n+1] = -1;
	while(q.size()!=0){
		int temp = q.front();
		q.pop();
		// cout << temp << " with val " << m[temp] << endl;
		if(m[temp-1] > m[temp]+1)
		{
			m[temp-1] = m[temp]+1;
			// cout << "Pushed " << (temp-1) << endl;
			q.push(temp-1);
		}
		if(m[temp+1] > m[temp]+1)
		{
			m[temp+1] = m[temp]+1;
			// cout << "Pushed " << (temp+1) << endl;
			q.push(temp+1);
		}
		if(m[x[temp]] > m[temp]+1)
		{
			m[x[temp]] = m[temp]+1;
			// cout << "Pushed " << (x[temp]) << endl;
			q.push(x[temp]);
		}
	}
	for(int i=1; i<=n; ++i) cout << m[i] << " ";
	return 0;
}
