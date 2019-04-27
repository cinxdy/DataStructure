/*
* Lecture Note by idebtor@gmail.com
*
* This program is written to run the sort algorithms.
* It takes the number of data samples to sort from the user.
* Then, the int array is created and filled with random numbers.
* User may selection one of sort functions to be used. Then
* execution time and its output is displayed.
*
* History:
* 02/10/19:		Created in C++
*
* Before Compilation, you must have some files (static library and
* include file) ready as shown below:
*   src/selection.cpp, bubble.cpp ...
*   include/nowic.h
*	lib/libnowic.a        (nowic.lib for Visual Studio)
* Compilation:
*	g++ selection.cpp insertion.cpp quicksort.cpp bubble.cpp sortDriver2.cpp -I../../include -L../../lib -lnowic -o sort
*/

/*
On my honour, I pledge that I have neither received nor provided improper assistance
in the completion of this assignment.
signed : 신지영 Section:03 Student Number:21800409
*/


#include <cstdlib>
#include <ctime>
#include <cassert>
#include <iostream>
#include <iomanip>
#include "nowic.h"

using namespace std;

void bubbleSort(int *list, int n);
void insertionSort(int *list, int n);
void quickSort(int *list, int n);
void selectionSort(int *list, int n);

void printList(int *list, int n, int max_print, int per_line);
void randomize(int list[], int n);

const int STARTING_SAMPLES = 100;
void sortProfiling(void (*sortFunc)(int *, int),int *list,int n, int starting_samples = STARTING_SAMPLES);


// Randomize: shuffle the sequence
// For every sample, starting from the first element in the list,
// it is swapped with the element randomly selected by the index
// generated by a 'real' (not pseudo) random number out of from
// 0 to N - 1.
// Hint: Refer to rand() and srand() function document.
void randomize(int list[], int n) {
	DPRINT(cout << ">randomize...N=" << n << endl;)
	srand((unsigned)time(NULL));

	for(int i=0;i<n;i++)
		swap(list[i],list[rand()%n]);

	//cout << "your code here\n";

	DPRINT(cout << "<randomize" << endl;)
}

// When we have a long list, we want to print some in the front
// part of the list and some in the rear part of the list.
//
// The max+print specifies the number of samples in either front
// or rear part of the list.  The per_line determines how many
// samples prints per line.
//
// If max_print is larger than or equal to the sample size N,
// prints max_print/2 samples only.
// For example:
// Case 1) N = 12, max_print = 100, per_line = 20
//		0	1	2	3	4	5
//		6	7	8	9  10  11
// Case 2) N = 12, max_print = 100, per_line = 4
//		0	1	2	3
//		4	5
//		6	7	8	9
//	   10  11
// Case 3) N = 12, max_print = 4, per_line = 6
//		0	1	2	3
//		8	9  10  11
// There should be a line feed between the front part and
// the rear part.
// Observe the sample runs using sortx.exe provided with you.

// Optionally, you may have this kind of a help function.
// void _printList(int *list, int start, int end, int per_line)

void printList(int *list, int N, int max_print, int per_line) {
	DPRINT(cout << ">printList...N=" << N << " max_print=" << max_print << endl;)
	if(max_print>=N){
		for(int i=0;i<N/2;i++){
				if(i%per_line==0) cout << endl;
				cout << "\t"<<list[i] <<" ";
		}
		for(int i=0;i<N/2;i++){
				if(i%per_line==0) cout << endl;
				cout << "\t"<<list[i+N/2] <<" ";
		}
	}
	else {
		for(int i=0;i<max_print;i++){
				if(i%per_line==0) cout << endl;
				cout << "\t"<<list[i] <<" ";
		}
		for(int i=0;i<max_print;i++){
				if(i%per_line==0) cout << endl;
				cout << "\t"<<list[i+N-max_print] <<" ";
		}
	}
		cout<<endl;
		// your code here
		// Optionally, you may create a help function such as _printList()/

		//cout << "your code here\n";

	DPRINT(cout << "<printList" << endl;)
}

// sortDriver to test sort functions or algorithms.
int main(int argc, char *argv[]) {
	int N = 0;						// default sample size
	int keyin;
	int *list = NULL;				// input and output buffer
	int max_print = 10;				// default max_print(=front_part+last_part)
	int per_line = max_print / 2;	// default samples per line to print
	clock_t start, end;
	char randomized = 'N';
	char option_char;
	char option_str[512];
	char algorithm_list[4][20] = {"Bubble", "Insertion", "Quicksort", "Selection"};
	enum algorithm_enum { BUBBLE, INSERTION, QUICKSORT, SELECTION };
	int  algorithm_chosen = SELECTION;  // default algorithm chosen
	void (*sortFn)(int *,int);
	sortFn = selectionSort;
	DPRINT(cout << ">main...N=" << N << endl;)

	// Use setvbuf() to prevent the output from buffered on console.
	setvbuf(stdout, NULL, _IONBF, 0);

	do {
		sprintf(option_str, "[sort=%s N=%d randomized=%c max_print=%d per_line=%d]",
			algorithm_list[algorithm_chosen], N, randomized, max_print, per_line);
		cout << "\n\tOPTIONS: " << option_str << "\n"
			"\tn - number of samples size and initialize\n"
			"\tr - randomize(shuffle) samples\n"
			"\ta - algorithm to run\n"
			"\tp - profiling\n"
			"\ts - sort()\n"
			"\tm - max samples to display at front or rear\n"
			"\td - max samples to display per line\n";

		option_char = GetChar("\tCommand(q to quit): ");
		DPRINT(cout << "option_char = " << option_char << endl;)

		switch (option_char) {
		case 'a': DPRINT(cout << "case = " << option_char << endl;)

			switch (GetChar("\tEnter b for bubble, i for insertion, s for selection, q for quick sort: ")) {

			// your code here
			case 'b': algorithm_chosen = BUBBLE; sortFn = bubbleSort; break;
			case 'i': algorithm_chosen = INSERTION; sortFn = insertionSort; break;
			case 's': algorithm_chosen = SELECTION; sortFn = selectionSort; break;
			case 'q': algorithm_chosen = QUICKSORT; sortFn = quickSort; break;

			default: { cout << "\tNo such an algorithm available. Try it again.\n"; break; }
			}

			//////////////
			break;

		case 'n': DPRINT(cout << "case = " << option_char;)

			keyin = GetInt("\tEnter input sample size: ");
			if (keyin < 1) {
				cout << "\tExpecting a number larger than 0";
				break;
			}

			// set N with the new keyin value
			N = keyin;
			// before allocating the new list, free the old list if not NULL
			if(list!=NULL) delete[] list;
			// allocate memory for new data samples
			list = new int[N];
			// Fill the list with numbers from 0 to n - 1.
			for(int i=0;i<N;i++)
				list[i]=i;

			printList(list,N,max_print,per_line);
			//cout << "your code here\n";

			break;

		case 'r': DPRINT(cout << "case = " << option_char << endl;)
			if (N <= 1) {
				cout << "\tSet sample size first or larger\n";
				break;
			}
			randomize(list,N);
			randomized = 'Y';
			printList(list,N,max_print,per_line);
			//cout << "your code here\n";

			break;
		
		case 'p': DPRINT(cout << "case = " << option_char << endl;)
			if (N<STARTING_SAMPLES) cout << "\tFor profiling, set sample size > " << STARTING_SAMPLES << endl;
			else sortProfiling(sortFn,list,N);
			break;

		case 's': DPRINT(cout << "case = " << option_char << endl;)
			if (N <= 0) {
				cout << "\tSet sample size first\n";
				break;
			}
			cout << "\tThe clock ticks and " << algorithm_list[algorithm_chosen] << " begins...\n";
			start = clock();
			sortFn(list,N);
			randomized = 'N';
			printList(list,N,max_print,per_line);
			//cout << "your code here\n";

			end = clock();
			cout << "\tDuration: " << (end - start) / (double)CLOCKS_PER_SEC << " seconds\n";
			break;

		case 'm': DPRINT(cout << "case = " << option_char << endl;)
			keyin = GetInt("\tEnter max sample size to display ");
			max_print = keyin;
			//cout << "your code here\n";
			printList(list,N,max_print,per_line);

			break;
		case 'd': DPRINT(cout << "case = " << option_char << endl;)
			keyin = GetInt("\tEnter max sample per line to display ");
			per_line = keyin;
			//cout << "your code here\n";
			printList(list,N,max_print,per_line);
			//cout << "your code here\n";

			break;
		default:
			break;
		}
	} while (option_char != 'q');

	if (list != NULL) delete[] list;
	// system("pause");
	DPRINT(cout << ">main" << endl;)
	return EXIT_SUCCESS;
}
