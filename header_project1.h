#pragma once
static struct Batch {
    int orderNumber;
    int totalItems;
    int goodItems;
};

extern Batch* batches;
extern int batchCount;

void inputData(int& batchCount);
void outputData();
void bubbleSort(Batch* arr, int n);