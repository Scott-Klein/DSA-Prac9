#include "heap.h"

void swap(int* heap, int  x1, int  x2)
{
	//	Local Declarations 
	int  temp;

	//	Statements 
	temp = heap[x1];
	heap[x1] = heap[x2];
	heap[x2] = temp;

	return;
}	// swap 

void reheapDown(int* heap, int  current, int  heapLast)
{
	//	Local Declarations 
	int parent;
	int lftChild;
	int rgtChild;
	int maxChild;

	//	Statements 
	parent = current;
	lftChild = (current * 2) + 1;
	rgtChild = lftChild + 1;

	if (lftChild <= heapLast)
	{
		// There is at least one child 
		if (lftChild == heapLast)
			// Only a left child 
			maxChild = lftChild;
		else
			// Determine which is child is larger			
			if (heap[lftChild] > heap[rgtChild])
				maxChild = lftChild;
			else
				maxChild = rgtChild;

		// Now determine if parent > children 
		if (heap[parent] < heap[maxChild])
		{
			// parent < children 
			swap(heap, parent, maxChild);
			reheapDown(heap, maxChild, heapLast);
		} // if there is at least one child 
		else
			// At leaf 
			return;
	} // lftChild <= 1 

	return;
}	// reheapDown 

void reheapUp(int* heap, int   heapLast)
{
	//	Prototype Declarations 
	void swap(int* heap, int x1, int x2);

	/*	Local Declarations */
	int parent;
	int child;

	//	Statements 
	if (heapLast != 0)
	{
		// if not at root of heap 
		parent = (heapLast - 1) / 2;
		child = heapLast;
		if (heap[child] > heap[parent])
		{
			// child is greater than parent 
			swap(heap, child, parent);
			reheapUp(heap, parent);
		} // if 
	} // last != 0 
	return;
}	// reheapUp 

void heapSort(int  list[], int  last)
{
	//	Local Definitions 
	int sorted;
	int holdData;
	int walker;

	//	Statements 
		// Create heap 
	for (walker = 1; walker <= last; walker++)
		reheapUp(list, walker);

	//	Heap created. Now sort it. 
	sorted = last;
	while (sorted > 0)
	{
		holdData = list[0];
		list[0] = list[sorted];
		list[sorted] = holdData;
		sorted--;
		reheapDown(list, 0, sorted);
	} // while	
	return;
}	// heapSort 
