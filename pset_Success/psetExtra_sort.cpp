// C++ for C Coders & Data Structures
// Lecture note by idebtor@gmail.com
/*
* This brute force version of Selection Sort that takes O(n^2).
*
*  Lab - Using C++, rewrite lab02a.cpp and name the file as lab03.cpp.
*		- <iostream>, <cstdlib>, <cmath>, <cassert>
*		- using namespace std
*		- cin, cout, endl
*		- use new and delete operators instead of malloc() and free()
*/

#include <iostream>
#include <cmath>
#include <cassert>
#include <ctime>
#include <cstdlib>
#include "sort.h"
using namespace std;
#define FN 4

#if 1
int main() {

	void (*sort[])(int * list, int n, int (*comp)(int,int)) = {bubbleSort,selectionSort,insertionSort,quickSort};
	int (*comp[])(int,int) = {up,dn};
	string sortName[FN]={"bubbleSort","selectionSort","insertionSort","quickSort"};
	string compName[]={"Up","Dn"};
	clock_t start,end;
	srand(time(NULL));

	/*
	int list[] = { 3, 4, 1, 7, 9, 6, 5, 2, 8, 0 };
	const int N = sizeof(list) / sizeof(list[0]);
	*/

	int N;
	cout << "Enter a number of samples to sort: ";
	cin >> N;

	// int *list = (int *)malloc(N * sizeof(int));
	int *list = new int[N];
	assert(list != NULL);

	for(int i=0;i<FN;i++){
		//make random numbers
		for (int i = 0; i < N; i++)
			list[i] = rand() % N;


		cout << "-----"<<sortName[i] << " Test" <<"-----"<< endl;

		cout << "NOTsorted: " << endl;
		printList(list, N);

		for(int j=0;j<2;j++){

			start = clock();
			sort[i](list, N,comp[j]);
			end = clock();

			cout << compName[j]<<"sorted: " << endl;
			printList(list, N);
			cout << "\tDuration: " << (end - start) / (double)CLOCKS_PER_SEC << " seconds\n";

		}

		cout<<endl;
		cout<<endl;
	}
	delete[] list;
	cout << "Happy Coding~~\n";
}
#endif
