// #include <iostream>
// #include <vector>
// #include <cstring>
// #include <cstdint>
// using namespace std;

// string a;
// string b;
// int bla;
// vector< vector< vector< vector<int> > > > v;

// // struct data{
// // 	int i, j;
// // 	int curr_len;
// // 	int len;
// // };

// inline int max(int x, int y){
// 	return x>y?x:y;
// }
// inline int max(int x, int y, int z){
// 	if(x>y &&  x>z) return x;
// 	else if(y>z) return y;
// 	else return z;
// }

// // int get_data(int i, int j, int x, bool running){
// // 	if(i==-1) return 0;
// // 	if(j==-1) return 0;
// // 	if(vv[i][j][x][running?1:0] != -1) return vv[i][j][x][running?1:0];
// // 	++bla;
// // 	if(running){
// // 		if(a[i]==b[j]) (vv[i][j][x][running?1:0] = get_data(i-1, j-1, x, true) + 1);
// // 		else{
// // 			// cout << "End run on "<<i<<" "<<j<<"\n";
// // 			vv[i][j][x][running?1:0] = max(get_data(i-1, j, x, false), get_data(i, j-1, x, false));
// // 		}
// // 	}else{
// // 		if(x==0) return 0;
// // 		if(a[i]==b[j]) (vv[i][j][x][running?1:0] = max(
// // 					get_data(i-1,j-1,x-1,true)+1, 
// // 					get_data(i-1,j,x,false), 
// // 					get_data(i,j-1,x,false)
// // 					));
// // 		else (vv[i][j][x][running?1:0] = max(get_data(i-1,j,x,false),get_data(i,j-1,x,false)));
// // 	}
// // 	// cout << "call to " <<i+1<< " "<<j+1<< " "<<x<<(running?" true":" false")<< " with value "<< vv[i][j][x][running?1:0] <<" and "<< v[i][j][x][running?1:0] << "\n";
// // 	return vv[i][j][x][running?1:0];
// // }

// int main(int argc, char const *argv[])
// {
// 	int n;
// 	int m;
// 	int xx;

// 	cin >> n >> m >> xx;
// 	cin >> a >> b;

// 	// n = a.length();
// 	// m = b.length();
// 	v = vector< vector< vector< vector<int> > > > (
// 		n, vector< vector< vector<int> > >(
// 			m, vector< vector<int> >(
// 				xx+1, vector<int> (
// 					2, -1
// 					)
// 				)
// 			)
// 		);

// 	for(int x=0; x<=xx; ++x){
// 		for(int i=0; i<n; ++i){
// 			for(int j=0; j<m; ++j){
// 				if(i==0 && j==0){
// 					if(a[i]==b[j]) v[i][j][x][1] = 1; //running
// 					else v[i][j][x][1] = 0;

// 					if(x==0) v[i][j][x][0] = 0;
// 					else if(a[i]==b[j]) v[i][j][x][0] = 1;
// 					else v[i][j][x][0] = 0;
// 				}else if(j==0){
// 					if(a[i]==b[j]) v[i][j][x][1] = 1; //running
// 					else v[i][j][x][1] = v[i-1][j][x][0];

// 					if(x==0) v[i][j][x][0] = 0;
// 					else if(a[i]==b[j]) v[i][j][x][0] = max(1, v[i-1][j][x][0]);
// 					else v[i][j][x][0] = v[i-1][j][x][0];	
// 				}else if(i==0){
// 					if(a[i]==b[j]) v[i][j][x][1] = 1; //running
// 					else v[i][j][x][1] = v[i][j-1][x][0];

// 					if(x==0) v[i][j][x][0] = 0;
// 					else if(a[i]==b[j]) v[i][j][x][0] = max(1, v[i][j-1][x][0]);
// 					else v[i][j][x][0] = v[i][j-1][x][0];						
// 				}else{
// 					if(a[i]==b[j]) v[i][j][x][1] = v[i-1][j-1][x][1] +1; //running
// 					else v[i][j][x][1] = max(v[i-1][j][x][0], v[i][j-1][x][0]);

// 					if(x==0) v[i][j][x][0] = 0;
// 					else if(a[i]==b[j]) v[i][j][x][0] = max(v[i-1][j-1][x-1][1]+1, v[i-1][j][x][0], v[i][j-1][x][0]);
// 					else v[i][j][x][0] = max(v[i-1][j][x][0], v[i][j-1][x][0]);					
// 				}
// 				// cout<<"call to " << i+1<<" "<<j+1<<" "<<x<<" true with value " << v[i][j][x][0] <<"\n";
// 				// cout<<"call to " << i+1<<" "<<j+1<<" "<<x<<" false with value " << v[i][j][x][1] <<"\n";

// 			}
// 		}
// 	}

// 	// cout << "Values of array are "<<n<<" "<<m<<" "<<x<<"\n";
// 	// cout << "The answer is " << get_data(n-1,m-1,x,false) << "\n";
// 	// cout << "number of calls " << bla << "\n";

// 	cout << v[n-1][m-1][xx][0];

// 	// cout << get_data(n-1,m-1,xx,false);
// 	// cout << "\n" << sizeof(int);

// 	// for(int k=0; k<x; ++k){
// 	// 	for(int i=0; i<n; ++i){
// 	// 		for(int j=0; j<m; ++j)
// 	// 		cout<<(v[i][j][k][0]==-1);
// 	// 		cout<<"\n";
// 	// 	}
// 	// 	cout<<"\n";
// 	// }
// 	return 0;
// }
#include <iostream>
#include <algorithm>
using namespace std;

int n, m, k, dp[1002][1002][12][2];
string a, b;

int max(int a, int b){
	return (a>b?a:b);
}

int main(int argc, char const *argv[])
{
	cin >> n >> m >> k;
	cin >> a >> b;
	for(int i=0; i<1002; ++i){
		dp[i][0][1][0] = 0;
		dp[i][0][1][1] = 0;
		dp[0][i][1][0] = 0;
		dp[0][i][1][1] = 0;
	}
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=m; ++j)
			for(int x=1; x<=k; ++x){
				dp[i][j][x][0] = max(dp[i-1][j][x][0], dp[i][j-1][x][0]);
				dp[i][j][x][1] = max(dp[i-1][j][x-1][0], dp[i][j-1][x-1][0]);
				if(a[i-1] == b[j-1]){
					// cout << "here";
					dp[i][j][x][1] = dp[i-1][j-1][x][1] + 1;
					dp[i][j][x][0] = max(dp[i][j][x][0], dp[i][j][x][1]);
				}
				// cout << i << j << x << " " << dp[i][j][x][0] << " " << dp[i][j][x][1] << endl;
			}
	cout << dp[n][m][k][0];
	return 0;
}



