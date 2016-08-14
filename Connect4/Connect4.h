#ifndef CONNECT4_H
#define CONNECT4_H

#include <vector>
#include <utility>

typedef std::pair<float, int> Data;

class Connect4 {
	enum State {X, O, Empty};
	std::vector< std::vector<State> > v;
	int pointer [8];
	State current_player;
	void change_player();
	void remove_player(int);

	const int max_level = 5;
	Data minimax(int);
	Data weight(int);

public:
	Connect4();
	~Connect4();
	bool insert(int);
	void print();
};

#endif
