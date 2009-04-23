#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <string>

using namespace std;

template <class T>
class Heap
{
public:
	virtual ~Heap() { }
	
	virtual void insertValue(T value) = 0;
	virtual T removeMin() = 0;
	virtual void empty() = 0;
	virtual bool isEmpty() const = 0;
	virtual int loadFromFile(string fileName) = 0; // return number of items inserted	
};

#endif