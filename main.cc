//   File: main.cc
//   Name: Msark Sands
//   Date: 4/22/08
// Course: CS 340 - Data Structures and Algorithms
//   Desc: a MinHeap class that creats an object inheriting
//			an abstract Heap which loads data in from a file, then the user is
//			able to remove the min value, insert entry, clear the heap or quit the program
//
//  Other files required: MinHeap.h, Heap.h 
//------------------------------------------------------------------------------------------

#include <ctime>
#include <iostream>
#include <iomanip>
#include <string>

#include "Heap.h"
#include "Minheap.h"

using namespace std;

enum MenuOptions {LOAD = 1, CLEAR = 2, INSERT_ENTRY = 3, DELETE_MIN = 4, QUIT = 5};

int Menu();

void ReadFile( Heap<int>*& heap );
void Clear( Heap<int>*& heap );
void InsertEntry( Heap<int>*& heap );
void DeleteMin( Heap<int>*& heap );
void QuitProgram( Heap<int>*& heap );


#define GetUserInputAndCallFunction for( void (*menuTable[6])( Heap<int>*& ) = { NULL, &ReadFile, &Clear, &InsertEntry, &DeleteMin, &QuitProgram }; \
	 					  choice != 5; \
	 					  menuTable[ choice = Menu() ]( heap ) );
 
int main()
{
	int choice = 0;
	Heap<int> *heap = new MinHeap<int>;

	GetUserInputAndCallFunction;
	 					  
	return 0;
}

int Menu()
{
	int choice;

	cout << endl
		 << setw(3) << LOAD << ". Load file into Heap"
		 << endl
		 << setw(3) << CLEAR << ". Clear Heap"
		 << endl
		 << setw(3) << INSERT_ENTRY << ". Insert Entry"
		 << endl
		 << setw(3) << DELETE_MIN << ". Delete Min"
		 << endl
		 << setw(3) << QUIT << ". Quit"
		 << endl
		 << endl
		 << setw(3) << " " << "Enter choice: ";
	cin >> choice;
	cout << endl;
	
	return (choice);
}

void ReadFile( Heap<int>*& heap )
{
	string filename;
	cout << "Enter filename: ";
	cin >> filename;
	
	if ( heap->loadFromFile( filename ) == 1 )
		cerr << "File failed to load!";
	
	cout << endl;
}

void Clear( Heap<int>*& heap )
{
	cout << "Emptying heap..";
	heap->empty();
	cout << endl;
}

void InsertEntry( Heap<int>*& heap )
{
	int value;
	cout << "Enter data: ";
	cin >> value;
	
	heap->insertValue( value );

	cout << endl;
}

void DeleteMin( Heap<int>*& heap )
{
	int top = heap->removeMin();
	
	cout << top
		 << " removed from top of heap"
		 << endl;
}

void QuitProgram( Heap<int>*& heap )
{
	heap->empty();
	delete heap;
}