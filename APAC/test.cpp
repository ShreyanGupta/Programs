#include <iostream>
#include <fstream>
#include <unordered_set>

using namespace std;

void put_num(long long num, unordered_set<long long> &m){
	while(num != 0){
		m.insert(num%10);
		num/=10;
	}
}

long long my_pow(long long i, long long expo){
	long long temp = i;
	long long ans = 1;
	while(expo != 0){
		if(expo%2 == 1) ans *= temp;
		cout << ans << endl;
		ans %= 1000000007;
		temp *= temp;
		temp %= 1000000007;
		expo/=2;
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	cout << my_pow(2, 1000);
	return 0;
}