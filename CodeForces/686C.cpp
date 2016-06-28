#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
typedef long long ll;
using namespace std;

bool a[7], x7, y7;
ll c = 0;
int *t1, *t2, *x, *y;
int xx, yy;

void print(){
	for(int i=xx-1; i>=0; --i) cout << t1[i]; cout << "   ";
	for(int i=yy-1; i>=0; --i) cout << t2[i]; cout << "\n";
	// ++c;
}

bool check_x(int pos){
	if(x7) return true;
	if(pos==-1) return false;
	if(t1[pos]<x[pos]) return true;
	else if(t1[pos]==x[pos]) return check_x(pos-1);
	else return false;
	// for(int i=xx-1; i>=0; --i) if(t1[i]>x[i]) return false;
	// return true;
}

bool check_y(int pos){
	if(y7) return true;
	if(pos==-1) return false;
	if(t2[pos]<y[pos]) return true;
	else if(t2[pos]==y[pos]) return check_y(pos-1);
	else return false;
	// for(int i=yy-1; i>=0; --i) if(t2[i]>y[i]) return false;
	// return true;
}

void recursion(int pos1, int pos2){
	if(pos1==-1){
		if(!check_x(xx-1)) return;
		if(pos2==-1){
			if(!check_y(yy-1)) return;
			++c;
			// print();
		}else{
			for(int i=0; i<7; ++i){
				if(a[i]) continue;
				else{
					t2[pos2] = i;
					a[i] = true;
					recursion(pos1, pos2-1);
					a[i] = false;
				}
			}
		}
	}else{
		for(int i=0; i<7; ++i){
			if(a[i]) continue;
			else{
				t1[pos1] = i;
				a[i] = true;
				recursion(pos1-1, pos2);
				a[i] = false; 
			}
		}
	}

	// if(start==size){
	// 	for(int i=0; i<size; ++i) cout << num[i];
	// 	cout << "\n";
	// 	++c;
	// }else for(int i=0; i<7; ++i){
	// 	if(a[i]) continue;
	// 	else{
	// 		num[start] = i;
	// 		a[i] = true;
	// 		recursion(start+1);
	// 		a[i] = false;
	// 	}
	// }
}

int main(int argc, char const *argv[])
{
	x7 = y7 = true;
	ll n, m;
	cin >> n >> m;
	xx = ceil( log(n) / log(7) );
	yy = ceil( log(m) / log(7) );
	if(n==1) xx=1;
	if(m==1) yy=1;

	// cout << "xx " << xx << "\n";
	// cout << "yy " << yy << endl;
	x = new int[xx];
	y = new int[yy];
	t1 = new int[xx];
	t2 = new int[yy];

	int *ptr = x;
	while(n!=0){
		*ptr = n%7;
		n /= 7;
		++ptr;
	}
	ptr = y;
	while(m!=0){
		*ptr = m%7;
		m /= 7;
		++ptr;
	}
	for(int i=xx-1; i>=0; --i) x7 = x7 && (x[i]==0); 
		// cout << x[i]; cout << "\n";
	for(int i=yy-1; i>=0; --i) y7 = y7 && (y[i]==0); 
		// cout << y[i]; cout << "\n";
	for(int i=0; i<7; ++i) a[i] = false;
	recursion(xx-1,yy-1);
	cout << c;
	return 0;
}