#include <iostream>
#include <map>
using namespace std;

int main(int argc, char const *argv[])
{
	string s;
	int m, n;
	std::map<int, int> map;
	int global_x=-1;
	int global_y=-1;
	// int global_counter=0;
	// int temp_x=-1;
	bool possible = true;
	cin >> n >> m;
	for(int i=0; i<n; ++i){
		cin >> s;
		int count_y = 0;
		int pos_x;
		for(int j=0; j<m; ++j){
			if(s[j]=='*'){
				++count_y;
				// ++global_counter;
				pos_x = j;
			}
		}
		if(count_y>1){
			if(global_y==-1) global_y = i;
			else possible = false;
		}else if(count_y==1){
			++map[pos_x];
		}
	}
	int i1, i2 = 0;
	int x1, x2;
	if(map.size()>2) possible = false;
	for(auto i : map){
		if(i1!=0){ 
			x2=i.first;
			i2=i.second;
			if(i1!=1 && i2!=1) possible=false;
		}
		if(i1==0){ 
			x1=i.first;
			i1=i.second;
		}
	}
	if(i1!=0){
		if(i2==0) global_x = x1;
		else if(i2==1) global_x = x1;
		else global_x = x2;
	}
	cout << (possible?"YES":"NO") << endl;
	if(global_x==-1) global_x=0;
	if(global_y==-1) global_y=0;
	if(possible) cout << global_y+1 << " " << global_x+1;
	return 0;
}