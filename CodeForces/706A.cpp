#include <iostream>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
	int a, b, n, x, y, v;
	double t_min = 100000000000000000;
	cin >> a >> b >> n;
	for(int i=0; i<n; ++i){
		cin >> x >> y >> v;
		double t = sqrt((x-a)*(x-a) + (y-b)*(y-b))/v;
		if(t < t_min) t_min = t;
	}
	cout.precision(17);
	cout << t_min;

	return 0;
}