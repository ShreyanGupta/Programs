#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

const double r = 1.618033988749894848;
const double r3 = 4.23606797749978969640;


int main(int argc, char const *argv[])
{
	// int x, y, count=0;
	// cin >> x >> y;
	// int c = x;
	// int b = ceil(x/r);
	// int a = ceil(b/r);
	// // cout << a << " " << b << " " << c << endl;
	// if(b <= y){
	// 	cout << "3";
	// 	return 0;
	// }
	// count = 2;
	// while(a>y){
	// 	++count;
	// 	int temp = c;
	// 	c = b;
	// 	b = a;
	// 	a = ceil(temp/r3);
	// 	if(a+b < c+1){ 
	// 		++a;
	// 		// cout << "ERROR!!!!\n";
	// 	}
	// 	// cout << a << " " << b << " " << c << endl;
	// }
	// count +=2;
	// cout << count;

	int x, y, count=0;
	scanf("%d %d", &x, &y);
	int a=y, b=y, c=y;
	while(c < x){
		++count;
		a=b;
		b=c;
		c=a+b-1;
		// cout << a << " " << b << " " << c << endl;
	}
	cout << (count+2) << endl;
	return 0;
}