#ifndef MIN_HEAP_H
#define MIN_HEAP_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Heap.h"

using namespace std;


template <class T>
class MinHeap : public Heap<T>
{
public:
	explicit MinHeap( int capacity = 100 );
	explicit MinHeap( const vector<T>& items );
	
	bool IsEmpty() const;
	//const T& FindMin() const;
		
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
	void DeleteMin( T& item );
	
	void BuildMinHeap();
	void PercolateDown( int hole );
};

template <class T>
MinHeap<T>::MinHeap( int capacity ) : array( capacity ), size( capacity )
{
	BuildMinHeap();
}
	
template <class T>
MinHeap<T>::MinHeap( const vector<T> &items ) : array( items.size() + 10 ), size( items.size() )
{
	for ( int i = 0; i < items.size(); i++ )
		array[ i + 1 ] = items[ i ];
	
	BuildMinHeap();
}

template <class T>
bool MinHeap<T>::IsEmpty() const
{
	return ( size <= 0 );
}
	
template <class T>
void MinHeap<T>::BuildMinHeap()
{
	for ( int i = size / 2; i > 0; i-- )
		PercolateDown( i );
}

template <class T>
void MinHeap<T>::Insert( const T& item )
{
	if ( size == array.size() - 1 )
		array.resize( array.size() * 2 );
	
	int hole;
	for( hole = ++size; hole > 1 && item < array[ hole / 2 ]; hole /= 2 )
		array[ hole ] = array[ hole / 2 ];
	
	array[ hole ] = item;
}

template <class T>
void MinHeap<T>::Clear()
{
	array.clear();
	size = 0;
}

template <class T>
void MinHeap<T>::DeleteMin()
{
	if ( IsEmpty() )
		//throw UnderflowException();
	
	array[1] = array[ size-- ];
	PercolateDown( 1 );
}

template <class T>
void MinHeap<T>::DeleteMin( T& item )
{
	if ( IsEmpty() )
		//throw UnderflowException();
	
	item = array[1];
	
	array[1] = array[ size-- ];
	PercolateDown( 1 );
}

template <class T>
T MinHeap<T>::removeMin()
{
	T temp = array[1];
	DeleteMin();
	
	return (temp);
}

template <class T>
void MinHeap<T>::empty()
{
	Clear();
}

template <class T>
void MinHeap<T>::insertValue(T value)
{
	Insert( value );
}

template <class T>
void MinHeap<T>::PercolateDown( int hole )
{
	int child;
	T temp = array[hole];
	
	do {
		child = hole * 2;
		
		if ( child != size && array[child+1] < array[child] )
			child++;
		
		if ( array[child] < temp )
			array[hole] = array[child];

		hole = child;
		
	} while ( (array[child] > temp) || (hole * 2 <= size) );
	
	array[hole] = temp;
}

template <class T>
int MinHeap<T>::loadFromFile(string fileName)
{
	ifstream fin;
	fin.open( fileName.c_str() );
	
	int result = fin.fail() ? 1 : 0;
	T temp;
	
	while ( !fin.eof() )
	{
		fin >> temp;
		insertValue( temp );
	}
	
	return result;	
}

#endif