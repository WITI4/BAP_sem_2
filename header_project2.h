#pragma once
#include <string>
extern int* a_temp;
extern int* b_temp;
extern int* c_temp;
extern int* d_temp;
extern int* e_temp;
int sequentialSearch(int arr[], int n, int x);
int binarySearch(int arr[], int left, int right, int x);
void inputArray(int a[], int b[], int c[], int d[], int e[], int size);
void outputArray(int a[], int b[], int c[], int d[], int e[], int size);
void outputTempArray(int a_temp[], int b_temp[], int c_temp[], int d_temp[], int e_temp[], int size);
void writeInitializedArraysToFile(const std::string& filename, int a[], int b[], int c[], int d[], int e[], int size);
void writeSortedArraysToFile(const std::string& filename, int a[], int b[], int c[], int d[], int e[], int size, const std::string& sortType);
void writeSequentialSearchResultsToFile(const std::string& filename, int a[], int b[], int c[], int d[], int e[], int size, int searchValue, const int results[]);
void writeBinarySearchResultsToFile(const std::string& filename, int a[], int b[], int c[], int d[], int e[], int size, int searchValue, const bool results[]);