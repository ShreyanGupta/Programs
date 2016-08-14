#include <iostream>
using namespace std;

template <typename T>
void my_memset(T *arr, int length){
	// int size = sizeof(T);
	// cout << "size " << size << endl;
	char *new_arr = reinterpret_cast<char*>(arr);
	for(long long i=0; i<length*sizeof(T); ++i){
		*new_arr = 0;
		++new_arr;
	}
}

int main(int argc, char const *argv[])
{
	int arr[5] = {1,2,5,7,8};
	// int *x = a;
	// my_memset(a, 5);
	// for(auto i : a) cout << i;
	// string b[5] = {"a", "b", "c", "d", "e"};
	// my_memset(b, 5);
	// for(auto i : b) cout << i;
	// cout << "YO" << sizeof(char*) << " " << sizeof(a);

	cout<<"First element of the array: "<<arr[0]+1 <<endl;
	cout<<"Address of the first element: "<<&arr[0]+1 <<endl;
	cout<<"Address of the array: "<<arr +1<<endl;
	cout<<"So what is this? "<<**(&arr +1)<<endl;
	cout<<"Size of array " <<sizeof(arr)<<endl; 
	return 0;
}