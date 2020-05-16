#include "quick.h"

void QuickSort::sort(int left, int right) {

	int sortLeft;
	int sortRight;
	int pivot;
	int hold;

	{
		medianLeft(left, right);
		pivot = sortData[left];
		sortLeft = left + 1;
		sortRight = right;

		while (sortLeft <= sortRight) {
			// Find key on left that belongs on right
			while (sortData[sortLeft] < pivot)
				sortLeft++;
			// Find key on right that belongs on left
			while (sortData[sortRight] >= pivot)
				sortRight--;
			if (sortLeft <= sortRight) {
				hold = sortData[sortLeft];
				sortData[sortLeft] = sortData[sortRight];
				sortData[sortRight] = hold;
				sortLeft++;
				sortRight--;
			} /* if */
		} // while
		// Prepare for next phase
		sortData[left] = sortData[sortLeft - 1];
		sortData[sortLeft - 1] = pivot;
		if (left < sortRight)
			sort(left, sortRight - 1);
		if (sortLeft < right)
			sort(sortLeft, right);
	}

	return;
}	// end quickSort 

void QuickSort::medianLeft(int left, int right) {
	//	Local Definitions 
	int mid;
	mid = (left + right) / 2;
	if (sortData[left] > sortData[mid]) {
		swap(sortData[left], sortData[mid]);
	} // if
	if (sortData[left] > sortData[right]) {
		swap(sortData[left], sortData[right]);
	} // if
	if (sortData[mid] > sortData[right]) {
		swap(sortData[right], sortData[mid]);
	} // if
	// Median is in middle. Exchange with left.
	swap(sortData[left], sortData[mid]);

	return;
}	// medianLeft 