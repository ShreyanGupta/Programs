#include <iostream>
#include <vector>

using namespace std;

class hashmap{
	const int arr_size = 11;
	int hash(string);
	std::vector< std::vector<string> > v;
	int elt;
public:
	hashmap();
	void insert(string);
	bool find(string);
	int size();
	void print();
};

int hashmap::hash(string s){
	unsigned int x = 1;
	unsigned int val = 0;
	for(auto i : s){
		x*=7;
		val += x*i;
	}
	return (val%arr_size);
}

hashmap::hashmap(){
	v = std::vector< std::vector<string> >(arr_size);
	elt = 0;
}

void hashmap::insert(string s){
	int val = hash(s);
	cout << val;
	v[val].push_back(s);
	++elt;
}

bool hashmap::find(string s){
	int val = hash(s);
	for(auto &i : v[val]){
		if(s.compare(i)==0) return true;
	}
	return false;
}

inline int hashmap::size(){
	return elt;
}

void hashmap::print(){
	for(auto &i : v){
		for(auto &j : i) cout << j << " ";
		cout << endl;
	}
}

int main(int argc, char const *argv[])
{
	hashmap h;
	int n;
	std::cin >> n;
	string temp;
	for(int i=0; i<n; ++i){
		std::cin >> temp;
		h.insert(temp);
	}
	h.print();
	return 0;
}