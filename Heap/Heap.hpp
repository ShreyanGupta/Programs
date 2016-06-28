 #ifndef HEAP_HPP
#define HEAP_HPP

#include <iostream>
#include "Heap.h"

template <typename E>
void Heap<E>::heapify_up(int x){
	int temp = x;
	while(temp!=0){
		if(v[temp/2]>v[temp]) swap(temp, temp/2);
		temp/=2;
	}
}

template <typename E>
void Heap<E>::heapify_down(){
	int temp=0;
	while(true){
		if(2*temp==index){
			if(v[temp]>v[2*temp]) swap(temp, 2*temp);
			return;
		}
		if(2*temp+1>index) return;
		if(v[2*temp] <= v[2*temp+1] && v[temp] > v[2*temp]){
			swap(2*temp, temp);
			temp*=2;
		}
		else if(v[2*temp+1] <= v[2*temp] && v[temp] > v[2*temp+1]){
			swap(2*temp+1, temp);
			temp = 2*temp+1;
		}
	}
}

template <typename E>
inline void Heap<E>::swap(int x, int y){
	E temp = v[x];
	v[x] = v[y];
	v[y] = temp;
}

template <typename E>
Heap<E>::Heap(){
	index = -1;
}

template <typename E>
Heap<E>::~Heap(){
	// delete v;
}

template <typename E>
void Heap<E>::insert(const E &data){
	v.push_back(data);
	heapify_up(++index);
}

template <typename E>
E &Heap<E>::find_min(){
	if(index==-1) throw "Empty heap";
	return const_cast<E&>(v[0]);
}

template <typename E>
E &Heap<E>::extract_min(){
	if(index==-1) throw "Empty heap";
	// std::cout << "sweg1";	
	E return_elt = v[0];
	v[0] = v[index--];
	// std::cout << "sweg";
	heapify_down();
	return const_cast<E&>(return_elt);
}

template <typename E>
void Heap<E>::print(){
	int x = 2;
	for(int i=0; i<=index; ++i){
		std::cout << v[i] << " ";
		if(i==x-2){
			std::cout << "\n";
			x*=2;
		}
	}
	std::cout << "\n";
	std::cout << "Index is " << index << "\n";
}

#endif
