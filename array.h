#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

int* createArrKeyBoard(int n);
int* createArrRandom(int n, int k1, int k2);
void printArr(int* arr, int n);
int seachElement(int* arr, int n, int element);
int searchMin(int* arr, int n);
int searchMax(int* arr, int n);
int* searchEntry(int* arr, int num, int n, int* nn);
int* deleteElement(int* arr, int* n, int index);
int* addElement(int* arr, int* n, int index, int num);
int* deleteKElement(int* arr, int* n, int index, int k);
int* addKElement(int* arr, int* n, int index, int k);
int searchMaxElmentCond(int* arr, int n);
bool cond(int* arr, int i);
int searchMinElmentCond(int* arr, int n);
int* deleteKElementCond(int* arr, int* n);
#endif
