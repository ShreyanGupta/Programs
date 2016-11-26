#include <iostream>
#include <map>
#include <unordered_set>
#include <vector>
#include <stack>
using namespace std;

struct node{
	vector<string> children;
};

void parse(string s, map<string, node> &m){
	auto ptr = s.begin();
	string var;
	while(*ptr != '='){
		var += *ptr;
		++ptr;
	}
	while(*ptr != '(') ++ptr;
	++ptr;
	// cout << var << " : ";
	m[var];
	while(ptr != s.end() && *ptr != ')'){
		string temp;
		while(*ptr != ',' && *ptr != ')'){
			temp += *ptr;
			++ptr;
		}
		if(temp.compare("") != 0) m[var].children.push_back(temp);
		++ptr;
		// cout << temp << " ";
	}
	// cout << endl;
}

bool dfs(string var, map<string, node> &m, map<string, bool> &visited, unordered_set<string> &current){
	// cout << "AT " << var << endl;
	current.insert(var);
	visited[var] = true;
	if(m.find(var) == m.end()){ 
		// cout << "NOT FOUND " << var << endl;
		return false;
	}
	for(auto &i : m[var].children){
		if(current.find(i) != current.end()) return false;
		if(visited[i]) continue;
		if(!dfs(i, m, visited, current)) return false;
	}
	current.erase(var);
	return true;
}

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	for(int x=1; x<=t; ++x){
		int n;
		cin >> n;
		map<string, node> m;
		map<string, bool> visited;
		for(int i=0; i<n; ++i){
			string s;
			cin >> s;
			parse(s,m);
		}
		bool possible = true;
		for(auto &i : m){
			// cout << "START " << i.first << endl;
			if(visited[i.first]) continue;
			unordered_set<string> current;
			if(!dfs(i.first, m, visited, current)) possible = false;
		}
		printf("Case #%d: %s\n", x,(possible?"GOOD":"BAD"));
	}
	return 0;
}