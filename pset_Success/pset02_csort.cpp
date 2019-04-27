// csort.cpp
// This is a sample code that runs okay, has a bad coding style.
// Reference: Fundamentals of Data Structures by Horowitz, Sahni
//
// When you compile the following code in Visual Studio, you may
// get the warning about scanf() or others. Then enter an addtional
// compiler option /wd4996 in the following:
// Project Properties -> C/C++ -> Command Line -> Additonal Options

/*
On my honour, I pledge that I have neither received nor provided improper assistance
in the completion of this assignment.
signed : 신지영 Section:03 Student Number:21800409
*/


#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

//#define MAX_SIZE 101
#define SWAP(x, y, t)  ((t) = (x), (x) = (y), (y) = (t))

void sort(int[], int);
void printArray(int list[],int n);

int main(void) {
	int n;
	int* list;
	cout << "Enter the number of samples: " << endl;
	cin >> n;

	list = new int[n];

/*
	if (n < 1 || n > MAX_SIZE) {
		cerr << "Improper value of n" << endl;
		exit(1);
	}
	*/

	cout << "UnSorted array:" << endl;
	printArray(list,n);
	printf("\n");

	sort(list, n);

	cout << "Sorted array:" << endl;
	printArray(list,n);
	printf("\n");

	delete[] list;

	return 0;
}

void sort(int list[], int n) {
	int i, j, min, temp;
	for (i = 0; i < n - 1; i++) {
		min = i;
		for (j = i + 1; j < n; j++)
			if (list[j] < list[min])
				min = j;
		SWAP(list[i], list[min], temp);
	}
}


void printArray(int list[],int n){
	for (int i = 0; i < n; i++) {       // randomly generate numbers
		list[i] = rand() % 1000;
		cout << list[i] << " ";
	}
}
