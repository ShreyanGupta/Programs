Referrence::

// dynamic array initialization
int *a = new int[n];

// random number generator
int random_num = rand()%n;

#include <algorithm>
auto ptr = std::find(v.begin(), v.end(), val);	// returns iterator to element else v.end()
std::sort(v.begin(), v.end(), function)	;		// sorts using function comparator
std::reverse(v.begin(), v.end());				// reverses
auto ptr = std::lower_bound(v.begin(), v.end(), val, func);// 1st element just greater than val (including val)
bool find = std::binary_search(v.begin(), v.end(), val, func);

std::pair<int, int> p = make_pair(a,b);

#include <queue>
q.empty();
q.size();
q.front();
q.back();
q.pop();

std::priority_queue<int> p;
p.top();
p.push(int);
p.pop();

#include <stack>
stack<int> s;
s.push(int);
s.pop();
s.top();
s.size();


#include <map>
std::map<key, value> map;
map.insert(key, val);
map.erase(key);
auto val = map[key];
auto ptr = map.lower_bound(key);
auto ptr = map.find(key);

std::multimap<key, val> multimap;
multimap.find(key);		// returns one element
multimap.erase(key);	// delets all elements with key = k
multimap.count(key);	// no. of elements with that key
auto equal_range = multimap.equal_range(key); 	// pair<iterator, iterator> of range
for(auto it = range.first; it!=range.second; ++it){}
DOES NOT HAVE multimap[key];

#include <set>
Same as map
Same as multimap

#include <stack>
stack<int> s;
s.top();
s.push(int);
s.pop();
s.size();

#include <unordered_map>
unordered_map<key, val> u_map;
begin, end, [], find, count (0 or 1)
insert, erase

unordered_multimap<key, val> u_multimap;
begin, end, find, count
insert, erase, equal_range

#include <unordered set>
same as unordered_map
same as unordered_multimap

#include <vector>
pataa hai

