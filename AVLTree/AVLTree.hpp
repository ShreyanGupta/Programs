#ifndef AVLTree_hpp
#define AVLTree_hpp

#include <cstddef>
#include <iostream>

using namespace std;

template <typename K, typename D>
Node<K,D>::Node(const K &k, const D *d){
	key = k;
	data = d;
	leftTree = NULL;
	rightTree = NULL;
	parent = NULL;
	h = 0;
}

// Constructor
template <typename K, typename D>
AVLTree<K,D>::AVLTree(){
	root = NULL;
}

// Destructor
template <typename K, typename D>
AVLTree<K,D>::~AVLTree(){
	rec_delete(root);
}

// recursive delete used in destructor
template <typename K, typename D>
void AVLTree<K,D>::rec_delete(Node<K,D> *temp){
	if(temp==NULL) return;
	rec_delete(temp->leftTree);
	rec_delete(temp->rightTree);
	delete temp;
}

// right rotate
template <typename K, typename D>
void AVLTree<K,D>::right_rotate(Node<K,D> *x){
	//cout<<"right rotate "<<*x->data<<"\n";
	Node<K,D> *y = x->leftTree;
	Node<K,D> *b = y->rightTree;
	if(x->parent==NULL){
		root = y;
	}else{
		if(x->parent->rightTree==x) x->parent->rightTree = y;
		else x->parent->leftTree = y;
	}
	x->leftTree = b;
	y->rightTree = x;
	if(b!=NULL) b->parent = x;
	y->parent = x->parent;
	x->parent = y;
	set_height(x);
	set_height(y);
}

// left rotate
template <typename K, typename D>
void AVLTree<K,D>::left_rotate(Node<K,D> *x){
	//cout<<"left rotate "<<*x->data<<"\n";
	Node<K,D> *y = x->rightTree;
	Node<K,D> *b = y->leftTree;
	if(x->parent==NULL){
		root = y;
	}else{
		if(x->parent->rightTree==x) x->parent->rightTree = y;
		else x->parent->leftTree = y;
	}
	x->rightTree = b;
	y->leftTree = x;
	if(b!=NULL) b->parent = x;
	y->parent = x->parent;
	x->parent = y;
	set_height(x);
	set_height(y);
}


// insert element
template <typename K, typename D>
void AVLTree<K,D>::insert(const K &k, const D &d){
	//cout<<"Insert "<<k<<" "<<d<<"\n";
	Node<K,D> *new_node = new Node<K,D>(k, &d);
	if(root==NULL){
		root = new_node;
		return;
	}
	Node<K,D> *temp = root;
	while(true){
		if(k < temp->key){
			if(temp->leftTree==NULL){
				temp->leftTree = new_node;
				new_node->parent = temp;
				balance(new_node);
				return;
			}
			else temp = temp->leftTree;
		}else if(k > temp->key){
			if(temp->rightTree==NULL){
				temp->rightTree = new_node;
				new_node->parent = temp;
				balance(new_node);
				return;
			}
			else temp = temp->rightTree;
		}else{
			delete new_node;
			throw "Duplicate key1";
			// RAISE Exception of duplicate key
		}
	}


	// Node<K,D> *curr_node = NULL;
	// Node<K,D> *next_node = root;
	// while(next_node!=NULL){
	// 	curr_node = next_node;
	// 	if(k < *curr_node->key){
	// 		next_node = curr_node->leftTree;
	// 	}else if(k > *curr_node->key){
	// 		next_node = curr_node->rightTree;
	// 	}else{
	// 		delete new_node;
	// 		throw "Duplicate key1";
	// 		// RAISE Exception of duplicate key
	// 	}
	// }
	// if(k < *curr_node->key){
	// 	curr_node->leftTree = new_node;
	// 	new_node->parent = curr_node;
	// }else if(k > *curr_node->key){
	// 	curr_node->rightTree = new_node;
	// 	new_node->parent = curr_node;
	// }else{
	// 	delete new_node;
	// 	throw "Duplicate key2";
	// 	// RAISE Exception of duplicate key
	// }
	// balance(new_node);
}

// search for element
template <typename K, typename D>
D & AVLTree<K,D>::search(const K &k){
	Node<K,D> *temp = root;
	while(temp!=NULL){
		if(k < temp->key) 		temp = temp->leftTree;
		else if(k > temp->key)	temp = temp->rightTree;
		else return const_cast<D&>(*temp->data);
	}
	throw "key not found";
}

// remove element
template <typename K, typename D>
bool AVLTree<K,D>::remove(const K &k){
	bool dir;
	Node<K,D> *temp = root;
	while(temp!=NULL){
		if(k < temp->key){
			temp = temp->leftTree;
			dir = false;
		}else if(k > temp->key){
			temp = temp->rightTree;
			dir = true;
		}else break;
	}
	if(temp==NULL) return false;
	Node<K,D> *temp2 = temp->rightTree;
	if(temp2==NULL){
		Node<K,D> *a = temp->leftTree;
		if(dir) temp->parent->rightTree = a;
		else temp->parent->leftTree = a;
		if(a!=NULL) a->parent = temp->parent;
		balance(temp->parent);
		delete temp;
		return true;
	}
	while(temp2->leftTree!=NULL){
		temp2 = temp2->leftTree;
		dir = false;
	}
	temp->key = temp2->key;
	temp->data = temp2->data;
	{	
		Node<K,D> *a = temp2->rightTree;
		if(dir) temp2->parent->rightTree = a;
		else temp2->parent->leftTree = a;
		if(a!=NULL) a->parent = temp2->parent;
		balance(temp2->parent);
		delete temp2;
		return true;
	}
}

//balance
template <typename K, typename D>
void AVLTree<K,D>::balance(Node<K,D> *temp){
	//Node<K,D> *temp = node;
	while(temp!=NULL){
		int left_h = height(temp->leftTree);
		int right_h = height(temp->rightTree);
		if(left_h - right_h == 2){
			if(height(temp->leftTree->leftTree)<height(temp->leftTree->rightTree)) 
				left_rotate(temp->leftTree);
			right_rotate(temp);
		}else if(right_h - left_h == 2){
			if(height(temp->rightTree->rightTree)<height(temp->rightTree->leftTree))
				right_rotate(temp->rightTree);
			left_rotate(temp);
		}
		set_height(temp);
		temp = temp->parent;
	}
}

// get height
template <typename K, typename D>
inline int AVLTree<K,D>::height(Node<K,D> *node){
	if(node==NULL) return -1;
	return node->h;
}

// set height
template <typename K, typename D>
inline void AVLTree<K,D>::set_height(Node<K,D> *node){
	int x = height(node->leftTree);
	int y = height(node->rightTree);
	node->h = (x>y?x:y) + 1;
	//cout<<*node->data<<" height "<<node->h<<"\n";
}

// print
template <typename K, typename D>
void AVLTree<K,D>::print(Node<K,D> *node){
	if(node==NULL) return;
	print(node->leftTree);
	cout<<node->key<<" "<<*node->data<<" "<<node->h<<'\n';
	print(node->rightTree);
}

#endif