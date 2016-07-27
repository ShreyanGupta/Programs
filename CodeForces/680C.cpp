#include <fstream>
#include <iostream>
using namespace std;
int n;
bool one = false;
bool two = false;
bool sq = false;

void query(int x){
	cout << x << endl;
	fflush(stdout);
	string response;
	cin >> response;
	// cout << "RESP " << response;
	if(response.compare("yes")==0){
		// cout << "BLA BLA";
		if(one) two = true;
		else one = true;
	}
}

void query2(int x){
	cout << x << endl;
	fflush(stdout);
	string response;
	cin >> response;
	if(response.compare("yes")==0) sq=true;
}

int main(int argc, char const *argv[])
{
	query(2);
	query(3);
	query(5);
	query(7);
	query(11);
	query(13);
	query(17);
	query(19);
	query(23);
	query(29);
	query(31);
	query(37);
	query(41);
	query(43);
	query(47);
	if(two) cout << "composite" << endl;
	else{
		query2(4);
		query2(9);
		query2(25);
		query2(49);
		if(sq) cout << "composite" << endl;
		else cout << "prime" << endl;
	}
	return 0;
}