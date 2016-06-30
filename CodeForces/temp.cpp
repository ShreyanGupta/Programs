#include <iostream>
#include <vector>
#include <cstring>
#include <cstdint>
#include <set>
using namespace std;

int main(int argc, char const *argv[])
{
	set<int> *p = new set<int>();
	*p->insert(5);

	return 0;
}