#include <iostream>
using namespace std;

const int n = 15;
bool done[n];
int x[n];
int y[n];

inline void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void quicksort(int *start, int *end){
	int size = end - start;
	// cout << *start << " " << *end << " " << size << endl;
	if(size==1){
		if(*start > *end) swap(start, end);
		return;
	}
	int *s = start, *e = end;
	int *pivot = end;
	while(start!=end){
		if(*start < *pivot) ++start;
		else{ 
			swap(start, end);
			--end;
		}
	}
	if(*start < *pivot) ++start;
	swap(start, pivot);
	if(start-1 > s)	quicksort(s,start-1);
	if(start+1 < e) quicksort(start+1,e);
}

void fill(int k){
	if(k==n){
		for(int i=0; i<n; ++i) y[i] = x[i];
		quicksort(y,y+n-1);
		for(int i=0; i<n; ++i) cout << y[i] << " ";
		cout << endl;
	}
	for(int i=0; i<n; ++i){
		if(done[i]) continue;
		x[k] = i;
		done[i] = true;
		fill(k+1);
		done[i] = false;
	}
}

int main(int argc, char const *argv[])
{
	for(int i=0; i<n; ++i) done[i] = false;
	fill(0);
	return 0;
}