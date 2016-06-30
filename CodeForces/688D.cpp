#include <iostream>
#include <vector>
using namespace std;

// struct data{
// 	int p;
// 	int x;
// 	bool done;
// 	data(int p, int x){
// 		this->p = p;
// 		this->x = x;
// 		done = false;
// 	}
// };

vector<int> prime;
vector<int> factor2;
// vector<data> factor;
int n, k;
// int possible = true;

bool is_prime(int x){
	// cout << "Checking prime ";
	for(int i=0; i<prime.size(); ++i){
		int temp = prime[i];
		// cout << temp << " ";
		if(x%temp==0) return false;
		if(temp*temp > x)return true;
	}
	return true;
}

// void print_factors(){
// 	cout << k << " = ";
// 	for(auto &i : factor) cout << i.p << ".." << i.x << " done " << (i.done?"Yes":"No") << " | ";
// 	cout << endl;
// }

int main(int argc, char const *argv[])
{
	int temp, temp2, x=1;
	cin >> n >> k;

	temp = k;
	prime.push_back(2);
	while(temp%2==0){
		x*=2;
		temp/=2;
	}
	// if(x!=1) factor.push_back(data(2,x));
	if(x!=1) factor2.push_back(x);
	for(int i=3; i<=temp; i+=2){
		if(is_prime(i)){
			prime.push_back(i);
			x=1;
			while(temp%i==0){
				x*=i;
				temp/=i;
			}
			// if(x!=1) factor.push_back(data(i,x));
			if(x!=1) factor2.push_back(x);
		}
	}
	// print_factors();
	
	// for(auto &i : prime) cout << i << " "; cout << endl;
	// for(auto &i : factor2) cout << i << " "; cout << endl;

	for(int i=0; i<n; ++i){
		cin >> temp;
		for(int i=factor2.size()-1; i>=0; --i){
			temp2 = factor2[i];
			if(temp < temp2) continue;
			else if(temp % temp2 == 0){
				factor2.erase(factor2.begin()+i);
			}
			// if(temp % factor[i].x == 0){
			// 	factor.erase(factor.begin()+i);
			// }
		}
		// for(auto &i : factor){
		// 	if(!i.done){
		// 		if(temp%i.x == 0) i.done = true;
		// 	}
		// }
	}
	// for(auto &i : factor2) possible = possible && i.done;

	// print_factors();
	// cout << (possible?"Yes":"No");
	if(factor2.size()==0) cout << "Yes";
	else cout << "No";
	return 0;
}