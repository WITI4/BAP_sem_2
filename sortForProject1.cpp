#include "header_project1.h"
#include <algorithm>

void bubbleSort(Batch* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].orderNumber > arr[j + 1].orderNumber) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}