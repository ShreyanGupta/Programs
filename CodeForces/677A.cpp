#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n, h;
	int temp, count = 0;
	cin >> n >> h;
	for(int i=0; i<n; ++i){
		cin >> temp;
		if(temp>h) count+=2;
		else ++count;
	}
	cout << count;
	return 0;
}