#include <iostream>
#include <vector>
#include <cstring>
#include <cstdint>
#include <set>
using namespace std;

int main(int argc, char const *argv[])
{
	for(long long i=2; i<=1000000007; ++i){
		if((3*i)%1000000007 == 1) cout << i << endl;
	}
	return 0;
}