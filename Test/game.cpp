#include <iostream>
#include <ctime>

using namespace std;

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	int n = rand()%100 +1;
	int temp, random;
	int count = 0;
	while(temp != n){
		++count;
		cin >> temp;
		random = rand()%4;
		if(temp == n) cout << "Congrats you won in " << count << " number of moves!\n";
		else if(temp < n){
			if(random == 0) cout << "Go lower!\n";
			else cout << "GO higher!\n";
		}
		else{
			if(random == 0) cout << "GO higher!\n";
			else cout << "Go lower!\n";
		}
	}
	return 0;
}