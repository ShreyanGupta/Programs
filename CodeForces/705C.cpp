#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, qq, type, x, t, temp;
	int current_t = 0;
	int current_unread = 0;
	cin >> n >> qq;
	vector< pair<int, int> > v(n+1);	// read, unread
	queue<int> q;
	for(int i=0; i<=n; ++i) v[i] = make_pair(0,0);
	for(int i=0; i<qq; ++i){
		cin >> type;
		if(type==1){
			cin >> x;
			++current_unread;
			++v[x].second;
			q.push(x);
			cout << current_unread << endl;
		}else if(type==2){
			cin >> x;
			current_unread -= v[x].second;
			v[x].first += v[x].second;
			v[x].second = 0;
			cout << current_unread << endl;
		}else{
			cin >> t;
			if(t <= current_t) cout << current_unread << endl;
			else{
				for(int i=current_t; i<t; ++i){
					temp = q.front(); q.pop();
					if(v[temp].first == 0){
						--v[temp].second;
						--current_unread;
					}else --v[temp].first;
				}
				current_t = t;
				cout << current_unread << endl;
			}
		}
	}
	return 0;
}