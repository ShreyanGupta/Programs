#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, k;
	double l, v1, v2;
	cin >> n >> l >> v1 >> v2 >> k;
	l /= v1;
	v2 /= v1;

	int n_not = ceil(1.0*n/k);
	double delta = 2*(n_not - 1)/(v2 + 1);
	double t = l/v2 + delta*l*(v2-1)/(delta+1)/v2;
	cout << setprecision(15) << t;

	return 0;
}