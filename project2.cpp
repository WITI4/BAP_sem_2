#include"header_project2.h"
#include <iostream>
#include <algorithm>
#include<ctime>
#include<fstream>
#include<iomanip>

int* a_temp = nullptr;
int* b_temp = nullptr;
int* c_temp = nullptr;
int* d_temp = nullptr;
int* e_temp = nullptr;

int sequentialSearch(int arr[], int n, int x) {
	int count = 0;
	for (int i = 0; i < n; i++) {
		if (arr[i] == x) count++;
	}
	return count;
}
int binarySearch(int arr[], int left, int right, int x) {
	while (left <= right) {
		int mid = left + (right - left) / 2;
		if (arr[mid] == x) return mid;
		if (arr[mid] < x) left = mid + 1;
		else right = mid - 1;
	}
	return -1;
}
void inputArray(int a[], int b[], int c[], int d[], int e[], int size) {
	srand(time(NULL));

    delete[] a_temp; delete[] b_temp; delete[] c_temp; delete[] d_temp; delete[] e_temp;

    a_temp = new int[size];
    b_temp = new int[size];
    c_temp = new int[size];
    d_temp = new int[size];
    e_temp = new int[size];

	for (int i = 0; i < size; i++) {
		a[i] = a_temp[i] = rand() % 41 - 20;
		b[i] = b_temp[i] = rand() % 41 - 20;
		c[i] = c_temp[i] = rand() % 41 - 20;
		d[i] = d_temp[i] = rand() % 41 - 20;
		e[i] = e_temp[i] = rand() % 41 - 20;
	}
}
void outputArray(int a[], int b[], int c[], int d[], int e[], int size) {
	for (int i = 0; i < size; i++) {
		std::cout << "a[" << i << "] = " << a[i] << "\t"
				  << "b[" << i << "] = " << b[i] << "\t"
				  << "c[" << i << "] = " << c[i] << "\t"
				  << "d[" << i << "] = " << d[i] << "\t"
				  << "e[" << i << "] = " << e[i] << std::endl;
	}
}
void outputTempArray(int a_temp[], int b_temp[], int c_temp[], int d_temp[], int e_temp[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << "a[" << i << "] = " << a_temp[i] << "\t"
                  << "b[" << i << "] = " << b_temp[i] << "\t"
                  << "c[" << i << "] = " << c_temp[i] << "\t"
                  << "d[" << i << "] = " << d_temp[i] << "\t"
                  << "e[" << i << "] = " << e_temp[i] << std::endl;
    }
}
void writeInitializedArraysToFile(const std::string& filename, int a[], int b[], int c[], int d[], int e[], int size) {
    std::ofstream outFile(filename, std::ios::app);
    if (!outFile) {
        std::cerr << "Ошибка открытия файла для записи!\n";
        return;
    }
    outFile << "Исходные массивы:\n";
    for (int i = 0; i < size; i++) {
        outFile << "a[" << i << "]=" << std::setw(4) << a[i] << " "
                << "b[" << i << "]=" << std::setw(4) << b[i] << " "
                << "c[" << i << "]=" << std::setw(4) << c[i] << " "
                << "d[" << i << "]=" << std::setw(4) << d[i] << " "
                << "e[" << i << "]=" << std::setw(4) << e[i] << "\n";
    }
    outFile << std::string(60, '=') << "\n";
    outFile.close();
}

void writeSortedArraysToFile(const std::string& filename, int a[], int b[], int c[], int d[], int e[], int size, const std::string& sortType) {
    std::ofstream outFile(filename, std::ios::app);
    if (!outFile) {
        std::cerr << "Ошибка открытия файла для записи!\n";
        return;
    }
    outFile << "Состояние массивов после сортировки:\n";
    for (int i = 0; i < size; i++) {
        outFile << "a[" << i << "]=" << std::setw(4) << a[i] << " "
                << "b[" << i << "]=" << std::setw(4) << b[i] << " "
                << "c[" << i << "]=" << std::setw(4) << c[i] << " "
                << "d[" << i << "]=" << std::setw(4) << d[i] << " "
                << "e[" << i << "]=" << std::setw(4) << e[i] << "\n";
    }
    outFile << std::string(60, '=') << "\n";
    outFile.close();
}

void writeSequentialSearchResultsToFile(const std::string& filename, int a[], int b[], int c[], int d[], int e[], int size, int searchValue, const int results[]) {
    std::ofstream outFile(filename, std::ios::app);
    if (!outFile) {
        std::cerr << "Ошибка открытия файла для записи!\n";
        return;
    }
    outFile << "Искомое значение: " << searchValue << "\n";
    outFile << "Количество совпадений:\n";
    outFile << "a: " << results[0] << "\n";
    outFile << "b: " << results[1] << "\n";
    outFile << "c: " << results[2] << "\n";
    outFile << "d: " << results[3] << "\n";
    outFile << "e: " << results[4] << "\n";

    outFile << "Состояние массивов на момент поиска:\n";
    for (int i = 0; i < size; i++) {
        outFile << "a[" << i << "]=" << std::setw(4) << a[i] << " "
            << "b[" << i << "]=" << std::setw(4) << b[i] << " "
            << "c[" << i << "]=" << std::setw(4) << c[i] << " "
            << "d[" << i << "]=" << std::setw(4) << d[i] << " "
            << "e[" << i << "]=" << std::setw(4) << e[i] << "\n";
    }
    outFile << std::string(60, '=') << "\n";
    outFile.close();
}

void writeBinarySearchResultsToFile(const std::string& filename, int a[], int b[], int c[], int d[], int e[], int size, int searchValue, const bool results[]) {
    std::ofstream outFile(filename, std::ios::app);
    if (!outFile) {
        std::cerr << "Ошибка открытия файла для записи!\n";
        return;
    }
    outFile << "Искомое значение: " << searchValue << "\n";
    outFile << "Результаты поиска:\n";
    outFile << "a: " << (results[0] ? "Найден" : "Не найден") << "\n";
    outFile << "b: " << (results[1] ? "Найден" : "Не найден") << "\n";
    outFile << "c: " << (results[2] ? "Найден" : "Не найден") << "\n";
    outFile << "d: " << (results[3] ? "Найден" : "Не найден") << "\n";
    outFile << "e: " << (results[4] ? "Найден" : "Не найден") << "\n";

    outFile << "Состояние массивов на момент поиска:\n";
    for (int i = 0; i < size; i++) {
        outFile << "a[" << i << "]=" << std::setw(4) << a[i] << " "
            << "b[" << i << "]=" << std::setw(4) << b[i] << " "
            << "c[" << i << "]=" << std::setw(4) << c[i] << " "
            << "d[" << i << "]=" << std::setw(4) << d[i] << " "
            << "e[" << i << "]=" << std::setw(4) << e[i] << "\n";
    }
    outFile << std::string(60, '=') << "\n";
    outFile.close();
}