#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct Node{
	int data;
	Node *next;
	Node(int data, Node *next){
		this->data = data;
		this->next = next;
	}
};

class LinkedList
{
	int s;
	Node *head;
public:
	LinkedList();
	~LinkedList();
	void insert(int);
	bool delete_elt(int);
	bool delete_at_pos(int);
	int size();
	int element_at_head();
	int element_at_pos(int);
	bool swap(int, int);
	void reverse();
};

LinkedList merge_list(LinkedList &, LinkedList &);
LinkedList merge_sort(LinkedList);

#endif