#include <iostream>
#include <algorithm>
using namespace std;

void mergesort(int *a, int *b){
	int *mid = a + (b-a)/2;
	mergesort(a, mid);
	mergesort(mid+1, b);
	int *x = new int[mid-a+1];
	int *y = new int[b-mid];
	copy(a, mid, x);
	copy(mid+1, b, y);
	
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int *arr = new int[n];

	mergesort(arr, arr+n-1);

	delete[] arr;
	return 0;
}