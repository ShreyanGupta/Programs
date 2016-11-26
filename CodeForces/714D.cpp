#include <iostream>
#include <cstdio>

using namespace std;

long long n;

void query1(long long &fix, long long &x1, long long &x2){
	long long mid = (x1+x2)/2;
	if(x1==mid) return;
	// printf("? %lld %lld 0 0\n", x1, x2);
	// cout << "? " << fix << " " << mid << " " << n << " " << n << "\n";
	printf("? %lld %lld %lld %lld \n",fix,1,mid,n);
	fflush(stdout);
	int response;
	cin >> response;
	if(response == 2) query1(fix, x1, x2=mid);
	else query1(fix, x1=mid, x2);
}

void query2(long long &x1, long long &x2, long long &fix){
	long long mid = (x1+x2)/2;
	// cout << "!!!!" << x1 << " " << mid << " " << x2 << endl;
	if(x1==mid) return;
	// printf("? %lld %lld 0 0\n", x1, x2);
	// cout << "? " << mid << " " << fix << " " << n << " " << n << "\n";
	printf("? %lld %lld %lld %lld \n",mid,1,fix,n);
	fflush(stdout);
	int response;
	cin >> response;
	if(response == 2) query2(x1=mid, x2, fix);
	else query2(x1, x2=mid, fix);
}

void query3(long long &fix, long long &x1, long long &x2){
	long long mid = (x1+x2)/2;
	if(x1==mid) return;
	// printf("? %lld %lld 0 0\n", x1, x2);
	// cout << "? 0 0 " << fix << " " << mid << "\n";
	printf("? %lld %lld %lld %lld \n",1,fix,n,mid);
	fflush(stdout);
	int response;
	cin >> response;
	if(response == 2) query3(fix, x1, x2=mid);
	else query3(fix, x1=mid, x2);
}

void query4(long long &x1, long long &x2, long long &fix){
	long long mid = (x1+x2)/2;
	// cout << "!!!!" << x1 << " " << mid << " " << x2 << endl;
	if(x1==mid) return;
	// printf("? %lld %lld 0 0\n", x1, x2);
	// cout << "? 0 0 " << mid << " " << fix << "\n";
	printf("? %lld %lld %lld %lld \n",1,mid,n,fix);
	fflush(stdout);
	int response;
	cin >> response;
	if(response == 2) query4(x1=mid, x2, fix);
	else query4(x1, x2=mid, fix);
}

void query_n(long long &x1, long long &x2, long long &fix){
	long long mid = (x1+x2)/2;
	// cout << "!!!!" << x1 << " " << mid << " " << x2 << endl;
	if(x1==mid) return;
	// cout << "? " << mid << " " << fix << " 0 0\n";
	printf("? %lld %lld %lld %lld \n",mid,1,fix,n);
	fflush(stdout);
	int response;
	cin >> response;
	if(response == 0) query_n(x1, x2=mid, fix);
	else query_n(x1=mid, x2, fix);
}

void query_m(long long &fix, long long &x1, long long &x2){
	long long mid = (x1+x2)/2;
	if(x1==mid) return;
	// printf("? %lld %lld 0 0\n", x1, x2);
	// cout << "? " << fix << " " << mid << " 0 0\n";
	printf("? %lld %lld %lld %lld \n",fix,1,mid,n);
	fflush(stdout);
	int response;
	cin >> response;
	if(response == 1) query_m(fix, x1, x2=mid);
	else query_m(fix, x1=mid, x2);
}

void query_x(long long &x1, long long &x2, long long &fix){
	long long mid = (x1+x2)/2;
	// cout << "!!!!" << x1 << " " << mid << " " << x2 << endl;
	if(x1==mid) return;
	// cout << "? 0 0 " << mid << " " << fix << "\n";
	printf("? %lld %lld %lld %lld \n",1,mid,n,fix);
	fflush(stdout);
	int response;
	cin >> response;
	if(response == 0) query_x(x1, x2=mid, fix);
	else query_x(x1=mid, x2, fix);
}

void query_y(long long &fix, long long &x1, long long &x2){
	long long mid = (x1+x2)/2;
	if(x1==mid) return;
	// printf("? %lld %lld 0 0\n", x1, x2);
	// cout << "? 0 0 " << fix << " " << mid << "\n";
	printf("? %lld %lld %lld %lld \n",1,fix,n,mid);
	fflush(stdout);
	int response;
	cin >> response;
	if(response == 1) query_y(fix, x1, x2=mid);
	else query_y(fix, x1=mid, x2);
}

int main(int argc, char const *argv[])
{
	// long long n;
	cin >> n;
	long long left=1, temp=1, right=n, up=n, down=1;
	query1(left, temp, right);
	temp = right;
	query2(left, temp, right);
	temp = 1;
	query3(down, temp, up);
	temp = up;
	query4(down, temp, up);
	long long right_2=right, left_2=left;
	temp = right;
	query_n(left_2, temp, right);
	temp = left;
	query_m(left, temp, right_2);

	long long down_2=down, up_2=up;
	temp = up;
	query_x(down_2, temp, up);
	temp = down;
	query_y(down, temp, up_2);

	cout << left << " " << right << endl;
	cout << left_2 << " " << right_2 << endl;
	cout << down << " " << up << endl;
	cout << down_2 << " " << up_2 << endl;

	printf("! %lld %lld %lld %lld %lld %lld %lld %lld \n",left,down,);
	return 0;
}