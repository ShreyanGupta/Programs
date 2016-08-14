#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int count=0;
	size_t f;
	string a, b;
	cin >> a >> b;
	while(true){
		f = a.find(b,f);
		if(f==string::npos) break;
		f += b.length();
		++count;
		// cout << f << endl;
	}
	cout << count;
	return 0;
}