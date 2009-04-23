#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Heap.h"

using namespace std;

template <class T>
MinHeap<T>::MinHeap() : size( 0 )
{
	array.resize(1);
}

template <class T>
bool MinHeap<T>::isEmpty() const
{
	return ( size <= 0 );
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
	if ( isEmpty() ) {
		cerr << "Underflow Exception!"
			 << endl;
		exit(1);
	}	
	
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
	
	for(; hole * 2 <= size; hole = child) {
		child = hole * 2;
		
		if ( child != size && array[child+1] < array[child] )
			child++;
		
		if ( array[child] < temp )
			array[hole] = array[child];
		else
			break;
		
	}
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