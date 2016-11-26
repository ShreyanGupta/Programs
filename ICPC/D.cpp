#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <unordered_map>

using namespace std;

unsigned long long p = 1000000007;
typedef unsigned long long ull;

pair<bool,int> bin_s(vector<int>& v,unordered_map<int,int>& mp, int k, int j)
{
	// int s = 0; int e = k-1;
	// int mid = 0; bool done = false;
	// while(s<=e)
	// {
	// 	mid = (s+e)/2;

	// 	if (v[mid] > j)
	// 	{
	// 		e = mid-1;
	// 	}
	// 	else if (v[mid] < j)
	// 	{
	// 		s = mid+1;
	// 	}
	// 	else
	// 	{
	// 		done = true;
	// 		break;
	// 	}
	// }

	bool done = false;

	if (mp.find(j) == mp.end())
	{
		return make_pair(false,0);
	}
	else
	{
		int index = mp[j];

		if (index <= k-1)
		{
			return make_pair(true,index);
		}
		else
		{
			return make_pair(false,index);
		}
	}

	// return make_pair(done,mid);
}

int main(int argc, char const *argv[])
{
	int t;

	cin>>t;

	for (int i = 0; i < t; ++i)
	{
		int n;
		cin>>n;

		vector<int> v;
		unordered_map<int,int> mp;

		for (int j = 0; j < n; ++j)
		{
			int a;
			cin>>a;
			v.push_back(a);
			mp[a] = j;
		}

		vector<ull> set_num;
		
		if(n == 0)
		{
			cout<<0<<endl;
			break;
		}

		sort(v.begin(),v.end());

		// for(int j = 0; j<v.size(); j++)
		// {
		// 	cout<<v[j];
		// }

		// cout<<endl;

		set_num.push_back(1);

		for(int k = 1; k<n; k++)
		{
			ull total = 1;

			for(int j = 1; j<=sqrt(v[k])+1; j++)
			{
				// int index = binary_search(v.begin(),v.begin()+i-1,j);

				if (v[k] % j == 0)
				{
					pair<bool,int> pr = bin_s(v,mp,k,j);
					
					if (pr.first)
					{
						total = (total+set_num[pr.second]) % p;
					}

					if (v[k] != j*j && (v[k]/j) > (sqrt(v[k])+1) )
					{
						pair<bool,int> pr = bin_s(v,mp,k,v[k]/j);
					
						if (pr.first)
						{
							total = (total+set_num[pr.second]) % p;
						}
					}
				}
			}

			// cout<<"total: "<<total<<endl;
			set_num.push_back(total);
		}
		
		ull tot = 0;

		for(int j = 0; j<set_num.size(); j++)
		{
			tot = (tot+set_num[j])%p;
		}

		cout<<tot<<endl;
	}

	return 0;
}





4 1s -> 1 11/11
3 1s -> 1 01/11
2 1s -> 2 00/11 vs 01/10
1 1s -> 1 00/10
0 1s -> 1 00/00



