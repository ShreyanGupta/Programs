#include <iostream>
using namespace std;

bool all_one(string x){
	for(int i=0; i<x.length(); ++i) if(x[i]=='0') return false;
	return true;
}

int main(int argc, char const *argv[])
{
	int n, d;
	int max=0;
	int current=0;
	string x;
	cin >> n >> d;
	for(int i=0 ; i<d; ++i){
		cin >> x;
		// bool temp = ;
		// cout << (all_one(x)?"true\n":"false\n");
		if(all_one(x)) current = 0;
		else{
			++current;
			if(max<current) max = current;
		}
	}
	cout << max;
	return 0;
}