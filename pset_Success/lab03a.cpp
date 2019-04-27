// C++ for C Coders & Data Structures
// Lecture note by idebtor@gmail.com
/*
* lab02.cpp  & lab02a.cpp
* This brute force version of Selection Sort that takes O(n^2).
*
* Compilation:
*   g++ lab02.cpp -o lab02
*   g++ lab02a.cpp -o lab02a
*
* Lab: (1) Improve the following code in C first. Name the file as lab02a.cpp
*      (2) Then recode it in C++. Name the file as lab02b.cpp
*
*	1. Understand the following C code.
*   - #if
*		- const
*		- rand()
*		- % operator
*  2. Use dynamic allocation for the array
*		- Add assert after malloc()
*		- Add free()
*  3. NMN principle - no magic number
*     DRY principle - don't repeat yourself
*/

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <cassert>

using namespace std;

void selectionSort(int *list, int n) {
	int i, j, min, temp;
	for (i = 0; i < n - 1; i++) {
		min = i;
		for (j = i + 1; j < n; j++)
			if (list[j] < list[min])
				min = j;
		// Swap min found with the first one of unsorted
		temp = list[i];
		list[i] = list[min];
		list[min] = temp;
	}
}

void showList(int* list,int N){
	for (int i = 0; i < N; i++)
    printf("%d ", list[i]);
  printf("\n");
}

#if 1
int main() {
	//int list[] = { 3, 4, 1, 7, 9, 6, 5, 2, 8, 0 };
	//const int N = sizeof(list)/sizeof(int);
	//int *list = NULL;
	int N;
	cin >> N;
	//list = (int*)malloc(sizeof(int*)*N);
	int *list = new int[N];
	assert(list!=NULL);
	for(int i=0;i<N;i++) list[i]=rand()%100;

	printf("UNSORTED: \n");
  showList(list,N);

	selectionSort(list, N);

	printf("SORTED: \n");
  showList(list,N);

	// system("pause");
  printf("Happy Coding~~\n");
	//free(list);l
	delete[] list;
}
#endif
