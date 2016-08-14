#include <iostream>
using namespace std;

string s;
string answer;
int start, end;
bool possible = true;

void subtract_1(int n){
	while(s[n] == '0'){
		s[n] = '9';
		--n;
		// cout << s[n];
	}
	--s[n];
	// if(n<=start) possible = false;
}

void append_answer(char x, bool carry){
	int n = x-48;
	if(carry) n+=10;
	if(carry) answer = "9"+answer+to_string(n-9);
	else answer = to_string(n)+answer+"0";
}

void fun(int start, int end, bool carry){
	// cout << " begin " << start << " " << end << " " << carry << " end ";
	if(start==end){
		// cout << s[start];
		switch(s[start]){
			case '0' : if(!carry) answer="0"; else answer="5"; break;
			case '2' : if(!carry) answer="1"; else answer="6"; break;
			case '4' : if(!carry) answer="2"; else answer="7"; break;
			case '6' : if(!carry) answer="3"; else answer="8"; break;
			case '8' : if(!carry) answer="4"; else answer="9"; break;
			default : possible = false;
		}
		return;
	}else if(start>end){
		// cout << "hello world";
		return;
	}
	if((carry && s[end]=='9')/*||(!carry && s[end]=='0')*/){
		possible = false;
		return;
	}
	if(carry) subtract_1(end-1);
	if(s[start]==s[end]){
		// cout << "s=e" << endl;
		// if(carry) cout << "1" << s[end] << " "; else cout << s[end] << " ";
		
		fun(start+1, end-1, false);
		append_answer(s[end], carry);
	}else if(s[start]==s[end]+1){
		// cout << "s=e+1" << endl;
		// if(carry) cout << "1" << s[end] << " "; else cout << s[end] << " ";
		// if(carry) subtract_1(end-1);
		fun(start+1, end-1, true);
		append_answer(s[end], carry);
	}else{
		// cout << "KATTA!";
		possible = false;
	}
}

int main(int argc, char const *argv[])
{
	cin >> s;
	if(s.compare("1")==0){
		cout << "0";
		return 0;
	}
	int n = s.length();
	fun(0, n-1, false);
	// if(answer[0]=='0') possible=false;
	if(possible){
		cout << answer;
		return 0;
	}
	if(s[0]=='1'){
		possible = true;
		fun(1, n-1, true);
	}
	// if(answer[0]=='0') possible=false;
	cout << (possible?answer:"0");

	return 0;
}