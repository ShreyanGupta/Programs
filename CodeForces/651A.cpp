#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int a, b;
	int count = 0;
	scanf("%d %d", &a, &b);
	if(a==1 && b==1){
		cout << 0;
		return 0;
	}
	while(a>0 && b>0){
		if(a==1 || a==2){
			++a;
			b-=2;
			++count;
		}else if(b==1 || b==2){
			++b;
			a-=2;
			++count;
		}else{
			++a;
			b-=2;
			++count;
		}
	}
	cout << count;
	return 0;
}