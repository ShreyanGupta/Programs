// #include <iostream>
// #include <map>
// using namespace std;

// int main(int argc, char const *argv[])
// {
// 	string s;
// 	int m, n;
// 	std::map<int, int> map;
// 	int global_x=-1;
// 	int global_y=-1;
// 	// int global_counter=0;
// 	// int temp_x=-1;
// 	bool possible = true;
// 	cin >> n >> m;
// 	for(int i=0; i<n; ++i){
// 		cin >> s;
// 		int count_y = 0;
// 		int pos_x;
// 		for(int j=0; j<m; ++j){
// 			if(s[j]=='*'){
// 				++count_y;
// 				// ++global_counter;
// 				pos_x = j;
// 			}
// 		}
// 		if(count_y>1){
// 			if(global_y==-1) global_y = i;
// 			else possible = false;
// 		}else if(count_y==1){
// 			++map[pos_x];
// 		}
// 	}
// 	int i1, i2 = 0;
// 	int x1, x2;
// 	if(map.size()>2) possible = false;
// 	for(auto i : map){
// 		if(i1!=0){ 
// 			x2=i.first;
// 			i2=i.second;
// 			if(i1!=1 && i2!=1) possible=false;
// 		}
// 		if(i1==0){ 
// 			x1=i.first;
// 			i1=i.second;
// 		}
// 	}
// 	if(i1!=0){
// 		if(i2==0) global_x = x1;
// 		else if(i2==1) global_x = x1;
// 		else global_x = x2;
// 	}
// 	cout << (possible?"YES":"NO") << endl;
// 	if(global_x==-1) global_x=0;
// 	if(global_y==-1) global_y=0;
// 	if(possible) cout << global_y+1 << " " << global_x+1;
// 	return 0;
// }

#include <iostream>
using namespace std;

int n;
string v[1001];
int main(int argc, char const *argv[])
{
	cin >> n;
	int row_status = 0;
	int col_status = 0;
	int row[3] = {-1,-1,-1};
	int col[3] = {-1,-1,-1};
	bool possible = true;
	for(int i=1; i<=n; ++i){
		cin >> v[i];
		for(int j=1; j<=m; ++j){
			if(v[i][j] == '*'){
				switch(row_status){
					case 0 :
						row[0] = i;
						row_status = 1;
						break;
					case 1 :
						if(i == row[0]){
							row[2] = i;
							row_status = 3;
						}else{
							row[1] = i;
							row_status = 2;
						}
						break;
					case 2 :
						if(i == row[0] || i == row[1]){
							row[2] = i;
							row_status = 3;
						}else possible = false;
						break;
					case 3 :
						if(i != row[2]) possible = false;
				}
				switch(col_status){
					case 0 :
						col[0] = j;
						col_status = 1;
						break;
					case 1 :
						if(j == col[0]){
							col[2] = j;
							col_status = 3;
						}else{
							col[1] = j;
							col_status = 2;
						}
						break;
					case 2 :
						if(j == col[0] || j == col[1]){
							col[2] = j;
							col_status = 3;
						}else possible = false;
						break;
					case 3 :
						if(j != col[2]) possible = false;
				}
			}
		}
	}
	// bool one_row = true;
	// if(row_status == 2) one_row = false;
	// if(row_status == 3 && row[1] != -1) one_row = false;

	// bool one_col = true;
	// if(col_status == 2) one_col = false;
	// if(col_status == 3 && col[1] != -1) one_col = false;

	switch(row_status){
		case 0 : {
			switch(col_status){
				case 0 :{
					cout << "YES\n0 0\n";
					break;
				}
			}
			break;
		}
		case 1 : {
			switch(col_status){
				case 1 :{
					cout << "YES\n" << row[0] << " " << col[0] << endl;
					break;
				}
				case 2 :{
					
					break;
				}
				case 3 :{
					break;
				}
			}
			break;
		}
		case 2 : {
			switch(col_status){
				case 0 :{
					break;
				}
				case 1 :{
					break;
				}
				case 2 :{
					break;
				}
				case 3 :{
					break;
				}
			}
			break;
		}
		case 3 : {
			switch(col_status){
				case 0 :{
					break;
				}
				case 1 :{
					break;
				}
				case 2 :{
					break;
				}
				case 3 :{
					break;
				}
			}
			break;
		}
	}

	return 0;
}