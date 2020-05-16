#pragma once
#include <iostream>
#include <iomanip>

using namespace std;

#define MAX_ARY_SIZE 15

class QuickSort {
	int* sortData;
	int maxSize;
	void medianLeft(int left, int right);
public:
	QuickSort(int* ary, int size)
	{
		maxSize = size;
		sortData = new int[maxSize];
		for (int i = 0; i < maxSize; i++)
		{
			sortData[i] = ary[i];
		}
	}

	void sort(int left, int right);

	void print() 
	{
		cout << "\nSorted array:\n";
		for (int i = 0; i < maxSize; i++)
			cout << setw(3) << sortData[i] << endl;
		cout << endl;
	}
};


//
//int main(void) {
////	Local Declarations
//	int i;
//
//	int ary[ MAX_ARY_SIZE] = { 89, 72, 3, 15, 21, 57, 61, 44, 19, 98, 5, 77, 39,
//			59, 61 }; // ary
//
////	Statements
//	cout << "Unsorted array: ";
//	for (i = 0; i < MAX_ARY_SIZE; i++)
//		cout << setw(3) << ary[i];
//
//	QuickSort qs(ary);
//	qs.sort(0, MAX_ARY_SIZE - 1);
//	qs.print();
//	return 0;
//}	// main

