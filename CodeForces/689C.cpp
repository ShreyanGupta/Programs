#include <iostream>
#include <queue>
using namespace std;

struct s{
	long long x;
	
};

int main(int argc, char const *argv[])
{
	priority_queue<int> q;
	q.push(2);
	q.push(2);
	cout << q.size();
	cout << q.top(); q.pop();
	cout << q.top(); q.pop(); 
	return 0;
}