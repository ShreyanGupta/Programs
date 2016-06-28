#include <iostream>
#include <vector>
#include <cstring>
#include <cstdint>
using namespace std;

string a;
string b;
int16_t bla;
vector< vector< vector< vector<int16_t> > > > v,vv;

// struct data{
// 	int16_t i, j;
// 	int16_t curr_len;
// 	int16_t len;
// };

inline int16_t max(int16_t x, int16_t y){
	return x>y?x:y;
}
inline int16_t max(int16_t x, int16_t y, int16_t z){
	if(x>y &&  x>z) return x;
	else if(y>z) return y;
	else return z;
}

int16_t get_data(int16_t i, int16_t j, int16_t x, bool running){
	if(i==-1) return 0;
	if(j==-1) return 0;
	if(vv[i][j][x][running?0:1] != -1) return vv[i][j][x][running?0:1];
	++bla;
	if(running){
		if(a[i]==b[j]) (vv[i][j][x][running?0:1] = get_data(i-1, j-1, x, true) + 1);
		else{
			// cout << "End run on "<<i<<" "<<j<<"\n";
			vv[i][j][x][running?0:1] = max(get_data(i-1, j, x, false), get_data(i, j-1, x, false));
		}
	}else{
		if(x==0) return 0;
		if(a[i]==b[j]) (vv[i][j][x][running?0:1] = max(
					get_data(i-1,j-1,x-1,true)+1, 
					get_data(i-1,j,x,false), 
					get_data(i,j-1,x,false)
					));
		else (vv[i][j][x][running?0:1] = max(get_data(i-1,j,x,false),get_data(i,j-1,x,false)));
	}
	if(vv[i][j][x][running?0:1] != v[i][j][x][running?1:0])
	cout << "1. call to " <<i+1<< " "<<j+1<< " "<<x<<(running?" true":" false")<< " with value "<< 
			vv[i][j][x][running?0:1] << " and " << v[i][j][x][running?1:0] << "\n";
	return vv[i][j][x][running?0:1];
}

int main(int argc, char const *argv[])
{
	int16_t n;
	int16_t m;
	int16_t x = 4;

	cin >> n >> m >> x;
	cin >> a >> b;

	// n = a.length();
	// m = b.length();
	v = vv = vector< vector< vector< vector<int16_t> > > > (
		n, vector< vector< vector<int16_t> > >(
			m, vector< vector<int16_t> >(
				x+1, vector<int16_t> (
					2, -1
					)
				)
			)
		);

	// cout << "Values of array are "<<n<<" "<<m<<" "<<x<<"\n";
	// cout << "The answer is " << get_data(n-1,m-1,x,false) << "\n";
	// cout << "number of calls " << bla << "\n";

	for(int xx=0; xx<=x; ++xx){
		for(int i=0; i<n; ++i){
			for(int j=0; j<m; ++j){
				if(i==0 && j==0){
					if(a[i]==b[j]) v[i][j][xx][1] = 1; //running
					else v[i][j][xx][1] = 0;

					v[i][j][xx][0] = 0;
				}else if(j==0){
					if(a[i]==b[j]) v[i][j][xx][1] = 1; //running
					else v[i][j][xx][1] = v[i-1][j][xx][0];

					if(x==0) v[i][j][xx][0] = 0;
					else v[i][j][xx][0] = v[i-1][j][xx][0];	
				}else if(i==0){
					if(a[i]==b[j]) v[i][j][xx][1] = 1; //running
					else v[i][j][xx][1] = v[i][j-1][xx][0];

					if(x==0) v[i][j][xx][0] = 0;
					else v[i][j][xx][0] = v[i][j-1][xx][0];						
				}else{
					if(a[i]==b[j]) v[i][j][xx][1] = v[i-1][j-1][xx][1] +1; //running
					else v[i][j][xx][1] = max(v[i-1][j][xx][0], v[i][j-1][xx][0]);

					if(xx==0) v[i][j][xx][0] = 0;
					else if(a[i]==b[j]) v[i][j][xx][0] = max(v[i-1][j-1][xx-1][1]+1, v[i-1][j][xx][0], v[i][j-1][xx][0]);
					else v[i][j][xx][0] = max(v[i-1][j][xx][0], v[i][j-1][xx][0]);					
				}
				// cout<<"2. call to " << i+1<<" "<<j+1<<" "<<xx<<" true with value " << v[i][j][xx][0] <<"\n";
				// cout<<"2. call to " << i+1<<" "<<j+1<<" "<<xx<<" false with value " << v[i][j][xx][1] <<"\n";

			}
		}
	}

	cout << get_data(n-1,m-1,x,false);
	cout << v[n-1][m-1][x][0] << "\n";
	// cout << "\n" << sizeof(int16_t);

	// for(int16_t k=0; k<x; ++k){
	// 	for(int16_t i=0; i<n; ++i){
	// 		for(int16_t j=0; j<m; ++j)
	// 		cout<<(v[i][j][k][1]==-1);
	// 		cout<<"\n";
	// 	}
	// 	cout<<"\n";
	// }
	return 0;
}