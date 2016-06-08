#include <iostream>

using namespace std;

template <class T>
class Stack{
	private:
		class Node{
			public:
			Node *next;
			T data;
			Node(const T &d, Node *n){
				data = d+1;
				next = n;
			};
		};

		Node *top;

	public:
		Stack(){
			top = NULL;
		};

		void push(const T &d){
			Node *temp = new Node(d, top);
			top = temp;
		};

		T pop(){
			if(top==NULL) return NULL;
			Node *temp = top;
			top = top->next;
			T temp_data = temp->data;
			delete temp;
			return temp_data;
		};

		bool is_empty(){
			return (top==NULL);
		};

		T first(){
			if(top!=NULL) return top->data;
			else return NULL;
		};
};

int main(int argc, char const *argv[])
{
	Stack<int> s;
	int x = 5;
	s.push(x);
	s.push(2);
	cout<<s.pop()<<s.pop();
	cout<<"\n"<<x;
	return 0;
}