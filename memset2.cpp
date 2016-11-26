#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int m, n;
	cin >> m >> n;
	int **arr = new int*[m];
	for(int i=0; i<m; ++i){
		arr[i] = new int[n];
		memset(arr[i], 0, n * sizeof(int));
	}
	for(int i=0; i<m; ++i){
		for(int j=0; j<n; ++j) cout << arr[i][j] << " ";
		cout << endl;
	}
	for(int i=0; i<m; ++i) delete[] arr[i];
	delete[] arr;
	return 0;
}