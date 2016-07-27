#include <iostream>
#include <string>
using namespace std;

int main(int argc, char const *argv[])
{
	string s;
	cin >> s;
	int a = stoi(s.substr(0, s.find(".")));
	string d = s.substr(s.find(".")+1, s.find("e")-2);
	if(d.compare("0")==0) d = "";
	int b = stoi(s.substr(s.find("e")+1));
	// cout << a << endl << d << endl << b << endl;
	if(a==0){
		if(d.compare("")==0) cout << "0";
		else cout << s.substr(0,s.find("e"));
		return 0;
	}
	if(d.length()<=b){
		int temp = d.length();
		for(int i=0; i<b-temp; ++i) d.push_back('0');
		cout << a << d;
		return 0;
	}else{
		cout << a << d.substr(0,b) << "." << d.substr(b);
	}
	return 0;
}