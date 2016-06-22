#include <cstring>
#include <iostream>
#include <string>
#include <cstdlib>
#include <time.h>

using namespace std;
long long int a;

void recursion(int i, int left){
	if(i==1)	++a;
	else{
		for(int x=0;x<=left/i;++x){
			recursion((i-1),left-i*x);
		}
	}
}

int main(int argc, char const *argv[])
{
	//srand(time(NULL));
	for(int i=0;i<10;++i) cout<<rand()%100<<"\n";


	return 0;
}

