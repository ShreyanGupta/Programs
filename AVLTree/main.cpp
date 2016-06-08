#include "AVLTree.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	AVLTree<int, string> tree;
	tree.insert(0,"a");
	tree.insert(2,"b");
	tree.insert(4,"c");
	tree.insert(6,"d");
	tree.insert(8,"e");
	tree.insert(10,"f");
	tree.insert(5,"cc");
	tree.print();

	try{
		AVLTree<int, int> tree2;
		for(int i=0; i<10000; ++i){
			tree2.insert(i,i+1);
		}
		tree2.print();
	}catch(const char *e){
		cout<<e;
	}
	

	return 0;
}