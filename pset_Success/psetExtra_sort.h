
#ifndef SORT_H
#define SORT_H

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

void printList(int *list, int n);

int up(int a,int b);
int dn(int a,int b);

void swap(int* a, int* b);

void bubbleSort(int *list, int n,int (*fn)(int,int)=up);
void selectionSort(int *list, int n,int (*fn)(int,int)=up);
void insertionSort(int *list, int n,int (*fn)(int,int)=up);

int partition(int list[], int lo, int hi,int (*fn)(int,int)=up);
void _quickSort(int *list, int lo, int hi, int N,int (*fn)(int,int)=up);
void quickSort(int *list, int n,int (*fn)(int,int)=up);

#endif
