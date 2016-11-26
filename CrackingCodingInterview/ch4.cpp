#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <unordered_map>
#include <vector>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <stack>
#include <climits>
using namespace std;

struct Node{
	Node *left_child;
	Node *right_child;
	Node *parent;
	int data;
	Node(int data, Node *parent){
		this->data = data;
		this->parent = parent;
		this->left_child = NULL;
		this->right_child = NULL;
	}
};

class Binary_Tree{
	Node *root;
public:
	Binary_Tree(){
		root = NULL;
	}
	~Binary_Tree(){

	}
	void insert(int val, Node *curr_node = NULL){
		if(root == NULL){
			root = new Node(val, NULL);
			return;
		}
		if(curr_node == NULL){ 
			insert(val, root);
			return;
		}
		if(val > curr_node->data){
			if(curr_node->right_child == NULL){
				curr_node->right_child = new Node(val, curr_node);
			}else insert(val, curr_node->right_child);
		}else if(val < curr_node->data){
			if(curr_node->left_child == NULL){
				curr_node->left_child = new Node(val, curr_node);
			}else insert(val, curr_node->left_child);
		}
	}
	Node *get_root(){
		return root;
	}
	void print_tree(){
		bool null_before = false;
		queue< Node* > q;
		q.push(root);
		q.push(NULL);
		while(q.size() != 0){
			Node *temp = q.front();
			q.pop();
			if(temp == NULL){ 
				if(null_before) return;
				cout << endl;
				q.push(NULL);
				null_before = true;
			}
			else{
				cout << temp->data << " ";
				if(temp->left_child != NULL) q.push(temp->left_child);
				if(temp->right_child != NULL) q.push(temp->right_child);
				null_before = false;
			}
		}
	}
};

int q1_is_balanced(Node *node){
	if(node == NULL) return 0;
	int temp1 = q1_is_balanced(node->left_child);
	int temp2 = q1_is_balanced(node->right_child);
	if(temp1 == -1 || temp2 == -1) return -1;
	if(abs(temp1-temp2) <= 1) return (max(temp1, temp2)+1);
	else return -1;
}

void q3_create_bst(vector<int> &arr, int start, int end, Binary_Tree &tree){
	if(start == end){ 
		tree.insert(arr[start]);
		return;
	}
	if(start > end) return;
	int mid = (start+end)/2;
	tree.insert(arr[mid]);
	q3_create_bst(arr, start, mid-1, tree);
	q3_create_bst(arr, mid+1, end, tree);
}

// void q4_level_i_list(Node *n, vector< list<int> > &v){
// 	if(n==NULL) return;
// 	bool null_before = false;
// 	queue<Node*> q;
// 	q.push(n);
// 	v.push_back(list<int>());
// 	while(q.size() != 0){
// 		Node *temp = q.front();
// 		q.pop();
// 		if(temp == NULL){
// 			if(null_before) return;
// 			null_before = true;
// 			v.push_back(list<int>());
// 			q.push(NULL);
// 		}else{
// 			v[v.size()-1].push_back(temp->data);
// 			if(temp->left_child != NULL) q.push(temp->left_child);
// 			if(temp->right_child != NULL) q.push(temp->right_child);
// 			null_before = false;
// 		}
// 	}
// }

void q4_level_i_list(Node *n, vector< list<Node*> > &v){
	if(n == NULL) return;
	int x=0;
	v.push_back(list<Node*>());
	v[0].push_back(n);
	while(true){
		if(v[x].size() == 0){ 
			v.pop_back();
			return;
		}
		++x;
		v.push_back(list<Node*>());
		for(auto &i : v[x-1]){
			if(i->left_child != NULL) v[x].push_back(i->left_child);
			if(i->right_child != NULL) v[x].push_back(i->right_child);
		}
	}
}

Node *q5_in_order_successor(Node *n){
	Node *temp = n;
	if(n->right_child == NULL){
		Node *temp2 = temp->parent;
		while(temp2 != NULL && temp != temp2->left_child){
			temp = temp->parent;
			temp2 = temp2->parent;
		}
		temp = temp2;
	}else{
		temp = temp->right_child;
		while(temp->left_child != NULL) temp = temp->left_child;
	}
	return temp;
}

int main(int argc, char const *argv[])
{
	Binary_Tree tree;
	// tree.insert(5);
	// tree.insert(2);
	// tree.insert(1);
	vector<int> v;
	for(int i=0; i<64; ++i) v.push_back(i);
	q3_create_bst(v, 0, v.size()-1, tree);
	tree.print_tree();

	vector< list<Node*> > x;
	q4_level_i_list(tree.get_root(), x);
	for(int i=0; i<x.size()-1; ++i){
		cout << "Level " << i;
		for(auto &j : x[i]) cout << " " << j->data << ":" << q5_in_order_successor(j)->data << " ";
		cout << endl;
	}
	return 0;
}