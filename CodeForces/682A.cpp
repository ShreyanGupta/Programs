#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	long long int a;
	long long int b;
	cin >> a >> b;
	long long int x = a%5;
	long long int y = b%5;
	long long int p = a/5;
	long long int q = b/5;
	long long int a0 = x==0?p:p;
	long long int a1 = x>0?p+1:p;
	long long int a2 = x>1?p+1:p;
	long long int a3 = x>2?p+1:p;
	long long int a4 = x>3?p+1:p;

	long long int b0 = y==0?q:q;
	long long int b1 = y>0?q+1:q;
	long long int b2 = y>1?q+1:q;
	long long int b3 = y>2?q+1:q;
	long long int b4 = y>3?q+1:q;
	// cout << a0<<a1<<a2<<a3<<a4;
	long long int bla = (a0*b0 + a1*b4 + a2*b3 + a3*b2 + a4*b1);
	cout<<bla;
	return 0;
}