/*
* Compilation:
* > g++ -c nowic.cpp -o nowic.o
* > ar rcs libnowic.a nowic.o
*/

#include<iostream>

using namespace std;

void printList(int *list, int n) {
	for (int i = 0; i < n; i++)
		cout << list[i] << " ";
	cout << endl;
}

void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}

int up(int a,int b){ return a-b; }
int dn(int a,int b){ return b-a; }

void bubbleSort(int *list, int n,int (*fn)(int,int)=up) {
	int i, j, temp;

	for (i = 0; i < n - 1; i++) {
		// last i elements are already in place
		for (j = 0; j < n - i - 1; j++)
			if (fn(list[j], list[j + 1])>0) {
				swap(&list[j],&list[j+1]);
			}
	}
}

void selectionSort(int *list, int n,int (*fn)(int,int)=up) {
	int i, j, min, temp;
	for (i = 0; i < n - 1; i++) {
		min = i;
		for (j = i + 1; j < n; j++)
			if ((fn(list[min], list[j])>0))
				min = j;
		// Swap min found with the first one of unsorted
		swap(&list[i],&list[min]);
	}
}

void insertionSort(int *list, int n,int (*fn)(int,int)=up) {
	int i, j, key;

	for (i = 1; i < n; i++) {
		key = list[i];
		j = i - 1;
		// move elements of list[0..i-1], that are greater than key,
		// to one position ahead of their current position
		while (j >= 0 && fn(list[j], key)>0) {
			list[j + 1] = list[j];
			j = j - 1;
		}
		list[j + 1] = key;
	}
}

int partition(int list[], int lo, int hi,int (*fn)(int,int)=up) {
	int x = list[hi];  // pivot
	int i = (lo - 1);  // Index of smaller element

	for (int j = lo; j <= hi - 1; j++) {
		// If current element is smaller than or equal to pivot
		if (fn(list[j], x)<=0) {
			i++;    // increment index of smaller element
			swap(&list[i], &list[j]);  // Swap current element with index
		}
	}
	swap(&list[i + 1], &list[hi]);
	return (i + 1);
}

// QuickSort helper function for recursive operation
// list[]: array to be sorted, lo: Starting index, h: Ending index
// N is added only for debugging or DPRINT
void _quickSort(int *list, int lo, int hi, int N,int (*fn)(int,int)=up) {
	if (lo < hi) 	{
		int pi = partition(list, lo, hi,fn); // Partitioning index
		_quickSort(list, lo, pi - 1, N,fn);
		_quickSort(list, pi + 1, hi, N,fn);
	}
}

void quickSort(int *a, int n,int (*fn)(int,int)=up) {
	_quickSort(a, 0, n - 1, n,fn);  // the last argument n is added only for DPRINT()
}
