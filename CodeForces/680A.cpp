#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int a[5];
	int temp;
	cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4];
	int sum = a[0] + a[1] + a[2] + a[3] + a[4];
	int min = sum;
	for(int i=0; i<5; ++i){
		for(int j=i+1; j<5; ++j){
			if(a[i]==a[j]){
				temp = sum - a[i] -a[j];
				if(temp < min) min = temp;
				for(int k=j+1; k<5; ++k){
					if(a[i]==a[k]){
						temp = sum - 3*a[i];
						if(temp < min) min = temp;
					}
				}
			}

		}
	}
	cout << min;
	return 0;
}