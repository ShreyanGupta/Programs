#include "Connect4.h"

#include <iostream>

inline void Connect4::change_player(){
	if(current_player==X) current_player=O;
	else current_player=X;
}

inline void Connect4::remove_player(int i){
	v[--pointer[i]][i] = Empty;
	change_player();
}

// incomplete
Data Connect4::minimax(int level){
	std::vector<Data> v;
	// Data v[8];
	for(int i=1; i<=7; ++i){
		if(!insert(i)) continue;
		else{
			if(level==max_level) v.push_back(weight(i));
			else v.push_back(minimax(level+1));
			remove_player(i);
		}
	}
	// dhange se return kar
	Data temp = v[0];
	for(Data &i : v){
		if(level%2==0){
			if(temp.first > i.first)
			temp = i;
		}else{
			if(temp.first < i.first)
			temp = i;
		}
	}
	return temp;
}

Data Connect4::weight(int i){
	return std::make_pair(1.0, i);
}

Connect4::Connect4(){
	v = std::vector< std::vector<State> >(7, std::vector<State>(8, Empty) );
	for(int i=0;i<8;++i) pointer[i] = 1;
	current_player = X;
}

Connect4::~Connect4(){
}

bool Connect4::insert(int i){
	if(pointer[i]==7) return false;
	v[pointer[i]++][i] = current_player;
	change_player();
	return true;
}

void Connect4::print(){
	std::cout << "1|2|3|4|5|6|7|\n";
	for(int i=6;i>0; --i){
		for(int j=1; j<=7; ++j){
			switch(v[i][j]){
				case X : std::cout << "X|"; break;
				case O : std::cout << "O|"; break;
				case Empty : std::cout << " |"; break;
			}
		}
		std::cout << std::endl;
	}
}
