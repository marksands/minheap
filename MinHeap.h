#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Heap.h"

using namespace std;

#ifndef MIN_HEAP_H
#define MIN_HEAP_H

template <class T>
class MinHeap : public Heap<T>
{
public:
	explicit MinHeap();
	
	bool isEmpty() const;
	int loadFromFile(string fileName);
	T removeMin();
	void empty();
	void insertValue(T value);
	
private:
	int size;
	vector<T> array;
	
	void Insert( const T& item );
	void Clear();
	void DeleteMin();
	
	void PercolateDown( int hole );
};

#include "MinHeap.cc"

#endif