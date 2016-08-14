#include "test.h"
#include "LinkedList.h"
#include <limits.h>

void test_all();
bool test_init();
bool test_insert();
bool test_delete();
bool test_swap();
// bool test_delete_at_pos();
bool test_reverse();
bool test_merge();
bool test_mergesort();

void test_all(){
	Test t("Testing Linked List");
	t.verify_true(test_init(), "Initialization test fail");
	t.verify_true(test_insert(), "insert test fail");
	t.verify_true(test_delete(), "delete test fail");
	// t.verify_true(test_delete_at_pos(), "delete at position test fail");
	// t.verify_true(test_size(), "size test fail");
	t.verify_true(test_swap(), "swap test failed");
	t.verify_true(test_reverse(), "reverse test failed");
	t.verify_true(test_merge(), "merge test failed");
	t.verify_true(test_mergesort(), "merge sort test failed");
}

bool test_init(){
	LinkedList l;
	if(l.size() != 0) return false;
	if(l.element_at_head() != INT_MIN) return false;
	if(l.element_at_pos(0) != INT_MIN) return false;
	return true;
}

bool test_insert(){
	LinkedList l;
	for(int i=0; i<100; ++i){
		// cout << "Testing i=" << i << endl;
		l.insert(i);
		if(l.size() != i+1) return false;
		if(l.element_at_head() != i) return false;
		// cout << "Hello";
		for(int j=0; j<=i+1; ++j){
			if(j==i+1){
				if(l.element_at_pos(j) != INT_MIN) return false;	
			}else{
				if(l.element_at_pos(j) != i-j) return false;
			}
		}
	}
	return true;
}

bool test_delete(){
	LinkedList l;
	for(int i=99; i>=0; --i) l.insert(i);
	if(l.delete_elt(100)==true) return false;
	if(l.size() != 100) return false;
	for(int i=50; i<100; ++i){
		if(l.delete_elt(i) == false) return false;
		if(l.size() != 150-i-1) return false;
		if(l.element_at_head() != 0) return false;
	}
	for(int i=0; i<50; ++i) if(l.element_at_pos(i) != i) return false;
	return true;
}

bool test_swap(){
	LinkedList l;
	int k;
	for(int i=0; i<100; ++i) l.insert(i);
	for(int i=0; i<100; i+=2) l.swap(i, i+1);
	for(int i=0; i<100; ++i){ 
		if(i%2==0) k = 99-i-1;
		else k = 99-i+1;
		if(l.element_at_pos(i) != k) return false;
	}
	return true;
}

bool test_reverse(){
	LinkedList l;
	for(int i=0; i<100; ++i) l.insert(i);
	l.reverse();
	// for(int i=0; i<100; ++i) cout << l.element_at_pos(i) << " ";
	for(int i=0; i<100; ++i) if(l.element_at_pos(i) != i) return false;
	return true;
}

bool test_merge(){
	LinkedList l1, l2;
	for(int i=98; i>=0; i-=2) l1.insert(i);
	for(int i=99; i>=0; i-=2) l2.insert(i);
	LinkedList l3 = merge_list(l1, l2);
	for(int i=0; i<100; ++i) if(l3.element_at_pos(i) != i) return false;
	
	LinkedList m1, m2;
	LinkedList m3 = merge_list(m1,m2);
	if(m3.size()!=0) return false;
	m2.insert(1);
	LinkedList m4 = merge_list(m1,m2);
	// for(int i=0; i<3; ++i) cout << m4.element_at_pos(i) << " ";
	if(m4.size()!=1) return false;
	

	return true;
}

bool test_mergesort(){
	cout << "testing merge_sort" << endl;
	LinkedList l;
	// if(merge_sort(l).size() != 0) return false;
	for(int i=0; i<100; i+=2) l.insert(i);
	for(int i=1; i<100; i+=2) l.insert(i);
	cout << "inserted elements" << endl;
	LinkedList sorted = merge_sort(l);
	for(int i=0; i<100; ++i) if(sorted.element_at_pos(i) != i) return false;
	return true;
}

int main(int argc, char const *argv[])
{
	test_all();
	return 0;
}