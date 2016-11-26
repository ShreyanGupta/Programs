#include <iostream>
#include <climits>
using namespace std;

int job[105];
int dp[105][3];	// 0 rest, 1 gym 2 coding

int main(int argc, char const *argv[])
{
	int n, temp;
	cin >> n;
	for(int i=1; i<=n; ++i) cin >> job[i];

	for(int i=1; i<=n; ++i){
		switch(job[i]){
			case 0 : 
				dp[i][1] = INT_MAX/2;
				dp[i][2] = INT_MAX/2;
				temp = min(dp[i-1][0], dp[i-1][1]);
				dp[i][0] = min(temp, dp[i-1][2]) + 1;
				break;
			case 1 :
				dp[i][1] = INT_MAX/2;
				dp[i][2] = min(dp[i-1][0], dp[i-1][1]);
				dp[i][0] = min(dp[i][2], dp[i-1][2]) + 1;
				break;
			case 2 :
				dp[i][1] = min(dp[i-1][0], dp[i-1][2]);
				dp[i][2] = INT_MAX/2;
				dp[i][0] = min(dp[i][1], dp[i-1][1]) + 1;
				break;
			case 3 :
				dp[i][1] = min(dp[i-1][0], dp[i-1][2]);
				dp[i][2] = min(dp[i-1][0], dp[i-1][1]);
				dp[i][0] = min(dp[i][2], dp[i-1][2]) + 1;
				break;
		}
			// dp[i][1] = min(dp[i-1][0], dp[i-1][2]);
			// dp[i][2] = min(dp[i-1][0], dp[i-1][1]);
			// dp[i][0] = min(dp[i][2], dp[i-1][2]) + 1;
			// cout << i << " : " << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << endl;
	}
	temp = min(dp[n][0], dp[n][1]);
	cout << min(temp, dp[n][2]) << endl;
	return 0;
}