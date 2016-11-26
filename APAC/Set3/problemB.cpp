#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	for(int x=1; x<=t; ++x){
		int r,c;
		cin >> r >> c;
		int a = r/3;
		int b = c/3;
		int count = a*b*6;
		int m = r%3;
		int n = c%3;
		switch(m){
			case 0 :{
				if(n == 1) count += 2*a;
				else if(n == 2) count += 4*a;
				break;
			}
			case 1 : {
				count += 2*b;
				if(n == 1) count += (2*a + 1);
				else if(n == 2) count += (4*a + 2);
				break;
			}
			case 2 : {
				count += 4*b;
				if(n == 1) count += (2*a + 2);
				else if(n == 2) count += (4*a + 3);
				break;
			}
		}
		if(a == 0 && b == 0) count += 1;
		// int count = 0;
		// int p, q, r;
		// switch(c%3){
		// 	case 0 : {
		// 		p = q = r = c/3;
		// 		break;
		// 	}
		// 	case 1 : {
		// 		p = q = c/3 + 1;
		// 		r = c/3;
		// 		break;
		// 	}
		// 	case 2 : {
		// 		p = c/3 + 2;
		// 		q = r = c/3 + 1;
		// 	}
		// }
		// for(int i=0; i<z; ++i){
		// 	switch(i%3){
		// 		case 0 : count += p; break;
		// 		case 1 : count += q; break;
		// 		case 2 : count += r; break;
		// 	}
		// }
		printf("Case #%d: ", x);
		cout << count << endl;
	}
	return 0;
}