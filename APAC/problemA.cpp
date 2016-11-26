#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char const *argv[])
{
	ifstream fin ("A-large.in");
	ofstream fout ("output");

	long long t0, x, y, temp;
	fin >> t0;
	for(long long t=1; t<=t0; ++t){
		fout << "Case #" << t << ": ";
		fin >> x >> y;
		temp = (x>y?y:x);
		fout << temp*(temp+1)/2;
		fout << endl;
	}
	return 0;
}