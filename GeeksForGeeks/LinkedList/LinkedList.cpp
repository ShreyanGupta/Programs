#include "LinkedList.h"
#include <iostream>
#include <limits.h>
#include <cstddef>
using namespace std;


LinkedList::LinkedList(){
	s = 0;
	head = NULL;
}

LinkedList::~LinkedList(){
	Node *temp = head;
	while(temp != NULL){
		Node *to_delete = temp;
		temp = temp->next;
		delete to_delete;
	}
}

void LinkedList::insert(int k){
	Node *temp = new Node(k, head);
	head = temp;
	++s;
}

bool LinkedList::delete_elt(int k){
	Node *temp = head;
	if(temp == NULL) return false;
	if(temp->data == k){
		head = temp->next;
		delete temp;
		--s;
		return true;
	}
	while(temp->next != NULL){
		if(temp->next->data == k){
			Node *to_delete = temp->next;
			temp->next = temp->next->next;
			delete to_delete;
			--s;
			return true;
		}
		temp = temp->next;
	}
	return false;
}

bool LinkedList::delete_at_pos(int pos){
	Node *temp = head;
	if(pos==0){
		if(head==NULL) return false;
		else{
			head = temp->next;
			delete temp;
			--s;
			return true;
		}
	}
	--pos;
	if(head == NULL) return false;
	while(pos !=0 && temp->next!=NULL){
		temp = temp->next;
		--pos;
	}
	if(pos==0 && temp->next != NULL){
		Node *to_delete = temp->next;
		temp->next = temp->next->next;
		delete to_delete;
		--s;
		return true;
	}else return false;
}

int LinkedList::size(){return s;}

int LinkedList::element_at_head(){
	if(head == NULL) return INT_MIN;
	else return head->data;
}

int LinkedList::element_at_pos(int pos){
	Node *temp = head;
	while(pos!=0 && temp!=NULL){
		--pos;
		temp = temp->next;
	}
	if(pos==0 && temp!=NULL) return temp->data;
	else return INT_MIN;
}

bool LinkedList::swap(int x, int y){
	if(x==y) return false;
	if(head == NULL) return false;
	Node *temp = head;
	Node *x_node = NULL;
	Node *y_node = NULL;
	Node *pre_x_node = NULL;
	Node *pre_y_node = NULL;
	if(head->data == x) x_node = head;
	if(head->data == y) y_node = head;
	while(temp->next != NULL){
		if(temp->next->data == x){
			x_node = temp->next;
			pre_x_node = temp;
		}
		if(temp->next->data == y){
			y_node = temp->next;
			pre_y_node = temp;
		}
		temp = temp->next;
	}
	if(x_node == NULL || y_node == NULL) return false;
	
	if(pre_x_node == NULL) head = y_node;
	else pre_x_node->next = y_node;
	if(pre_y_node == NULL) head = x_node;
	else pre_y_node->next = x_node;
	
	temp = x_node->next;
	x_node->next = y_node->next;
	y_node->next = temp;

	return true;
}

void LinkedList::reverse(){
	if(head == NULL || head->next == NULL) return;
	Node *temp = NULL;
	Node *curr = head->next;
	Node *pre = head;
	pre->next = NULL;
	while(curr != NULL){
		temp = curr->next;
		curr->next = pre;
		pre = curr;
		curr = temp;
	}
	head = pre;
}

LinkedList merge_list(LinkedList &l1, LinkedList &l2){
	LinkedList result;
	int pos1=0, pos2=0;
	while(pos1 < l1.size() && pos2 < l2.size()){
		if(l1.element_at_pos(pos1) < l2.element_at_pos(pos2)){
			result.insert(l1.element_at_pos(pos1));
			++pos1;
		}else{
			result.insert(l2.element_at_pos(pos2));
			++pos2;
		}
	}
	if(pos1 == l1.size()){
		while(pos2 < l2.size()){
			result.insert(l2.element_at_pos(pos2));
			++pos2;
		}
	}
	if(pos2 == l2.size()){
		while(pos1 < l1.size()){
			result.insert(l1.element_at_pos(pos1));
			++pos1;
		}
	}
	result.reverse();
	return result;
}

LinkedList merge_sort(LinkedList l){
	if(l.size()==0 || l.size()==1) return l;
	LinkedList l1, l2;
	int mid = l.size()/2;
	cout << "mid = " << mid << endl;
	for(int i=0; i<l.size(); ++i){
		if(i<mid) l1.insert(l.element_at_pos(i));
		else l2.insert(l.element_at_pos(i));
	}
	LinkedList l1_sort = merge_sort(l1);
	cout << "l1 sorted size " << l1_sort.size() << endl;
	LinkedList l2_sort = merge_sort(l2);
	cout << "l2 sorted size " << l2_sort.size() << endl;
	LinkedList merged = merge_list(l1_sort, l2_sort);
	cout << "merged size " << merged.size() << endl;
	return merged;
}


