#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<pair<long long, int> > v;

// void check2(){
// 	// bool possible = false;
// 	if(v[0].second == 1 || v[1].second == 1) cout << "YES";
// 	else if(v[1].first == 2*v[0].first) cout << "YES";
// 	else cout << "NO";
// }

// void check3(){
// 	bool b = false;
// 	if(v[0].second == 1){
// 		if(v[1].first + v[0].first == v[2].first || v[1].first + v[0].first == v[2].first - v[0].first){ 
// 			b = true;
// 			// cout << "YES";
// 			// return;
// 		}
// 	}
// 	if(v[1].second == 1){
// 		cout << ":(";
// 		if(v[0].first + v[1].first == v[2].first - v[1].first || v[0].first + v[1].first == v[2].first){ 
// 			b = true;
// 			// cout << "YES";
// 			// return;
// 		}
// 	}else if(v[0].first +v[1].first == v[1].first && v[2].first - v[1].first == v[1].first){
// 		b = true;
// 		// cout << "YES";
// 	}
// 	if(b) cout << "YES";
// 	else cout << "NO";
// }

// void check4(){
// 	cout << "NO";
// 	return;
// 	if(v[0].second == 1){
// 		if(v[1].first + v[0].first == v[2].first && v[3].first - v[0].first == v[2].first){
// 			cout << "YES";
// 			// return;
// 		}
// 	}
// 	else if(v[1].second == 1){
// 		if(v[0].first + v[1].first == v[2].first && v[3].first - v[1].first == v[2].first){
// 			cout << "YES";
// 			// return;
// 		}
// 	}
// 	else cout << "NO";
// }

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	// vector<long long> v(n+1);
	map<long long, int> m;
	for(int i=0; i<n; ++i){ 
		long long temp;
		cin >> temp;
		++m[temp];
	}
	if(m.size() > 3){
		// cout << m.size();
		cout << "NO";
		return 0;
	}
	for(auto &i : m){
		v.push_back(i);
		// cout << i.first << " " << i.second << endl;
	}
	switch(v.size()){
		case 1 : cout << "YES"; break;
		case 2 : cout << "YES"; break;
		case 3 : if(v[0].first + v[2].first == 2*v[1].first) cout << "YES";
					else cout << "NO";
					break;
	}
	return 0;
}