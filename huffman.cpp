#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node{
	Node *parent;
	bool leaf;
	char letter;
	Node *left_child;
	Node *right_child;
	float prob;
	Node(char letter, float prob){
		left_child = NULL;
		right_child = NULL;
		leaf = true;
		this->letter = letter;
		this->prob = prob;
		parent = NULL;
	}
	Node(Node *left_child, Node *right_child){
		this->left_child = left_child;
		this->right_child = right_child;
		leaf = false;
		prob = left_child->prob + right_child->prob;
		left_child->parent = this;
		right_child->parent = this;
		parent = NULL;
	}
	void print_tree(){
		bool null_before = false;
		queue< Node* > q;
		q.push(this);
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
				if(!temp->leaf) cout << temp->prob << " ";
				else cout << temp->prob << temp->letter << " ";
				if(temp->left_child != NULL) q.push(temp->left_child);
				if(temp->right_child != NULL) q.push(temp->right_child);
				null_before = false;
			}
		}
	}
};

class comp{
public:
	bool operator()(const Node *n1, const Node *n2){
		return(n1->prob >= n2->prob);
	}
};

int main(int argc, char const *argv[])
{
	int n;
	char letter;
	float prob;
	priority_queue<Node*, vector<Node*>, comp> q;
	cin >> n;
	for(int i=0; i<n; ++i){
		cin >> letter >> prob;
		q.push(new Node(letter, prob));
	}
	while(q.size()!=1){
		Node *n1 = q.top();
		q.pop();
		Node *n2 = q.top();
		q.pop();
		q.push(new Node(n1,n2));
	}
	q.top()->print_tree();
	return 0;
}