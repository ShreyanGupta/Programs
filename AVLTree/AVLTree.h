#ifndef AVLTree_h
#define AVLTree_h

template <typename K, typename D>
struct Node{
	int h;
	Node *leftTree;
	Node *rightTree;
	Node *parent;
	K key;
	const D *data;
	Node(const K&, const D*);
};

template <typename K, typename D>
class AVLTree{
private:
	Node<K,D> *root;
	void right_rotate(Node<K,D> *);
	void left_rotate(Node<K,D> *);
	void balance(Node<K,D> *);
	int height(Node<K,D> *);
	void set_height(Node<K,D> *);
	void rec_delete(Node<K,D> *);

public:
	AVLTree();
	~AVLTree();
	void insert(const K &, const D &); 
	bool remove(const K &);
	D & search(const K &);
	void print(Node<K,D> *);
	void print(){print(root);}
};


#include "AVLTree.hpp"

#endif