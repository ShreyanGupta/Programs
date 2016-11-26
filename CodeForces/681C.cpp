#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;
typedef long ll;

// inline bool fun(int x, int y){return x>y;}

// template <typename T>
// void print(vector<T> x){
// 	for(auto &temp : x) cout << temp << "\n";
// }

int main(int argc, char const *argv[])
{
	string cmd;
	ll val;
	int n;
	priority_queue<ll, vector<long long>, std::greater<long long> > x;
	// vector<ll> v;
	vector<string> message(5000000);
	int z=0;
	
	// v.push_back(10); push_heap(v.begin(), v.end(), fun);
	// v.push_back(20); push_heap(v.begin(), v.end(), fun);
	// v.push_back(30); push_heap(v.begin(), v.end(), fun);
	// for(auto &temp : v) cout << temp << " ";
	// cout << endl;

	cin >> n;
	for(int i=0; i<n; ++i){
		cin >> cmd;
		// if(cmd.compare("removeMin")!=0) cin >> val;

		if(cmd.compare("insert")==0){
			cin >> val;
			x.push(val);
			message[z++] = ("insert "+to_string(val));
		}else if(cmd.compare("getMin")==0){
			cin >> val;
			bool flag = false;
			while(!flag){
				if(x.empty()){
					message[z++] = ("insert "+to_string(val));
					x.push(val);
					flag = true;
				}else if(x.top() < val){
					message[z++] = ("removeMin");
					x.pop();
				}else flag = true;
			}
			if(x.top() != val){
				message[z++] = ("insert "+to_string(val));
				x.push(val);
			}
			message[z++] = ("getMin "+to_string(val));
		}else{
			if(x.empty()){
				x.push(0);
				message[z++] = ("insert 0");
			}
			message[z++] = ("removeMin");
			x.pop();
		}
	}
	cout << z << "\n";
	for(ll i=0; i<z; ++i) cout << message[i] << endl;
	return 0;
}