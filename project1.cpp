#include"header_project1.h"
#include<iostream>
#include<iomanip>

#define fastErrInfo std::cout << "Некорректный ввод. Введите информацию еще раз: "; 

Batch* batches;
int batchCount = 0;

void inputData(int& batchCount) {

    std::cout << "Введите количество поступивших партий (не более 10): ";
    while (!(std::cin >> batchCount) || batchCount < 1 || batchCount > 10 || std::cin.peek() != '\n') {
        fastErrInfo
            std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    batches = new Batch[batchCount];

    for (register int i = 0; i < batchCount; i++) {
        std::cout << "Партия #" << i + 1 << ":\n";

        std::cout << "Номер заказа: ";
        while (!(std::cin >> batches[i].orderNumber) || batches[i].orderNumber < 1 || std::cin.peek() != '\n') {
            fastErrInfo
                std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        std::cout << "Количество изделий: ";
        while (!(std::cin >> batches[i].totalItems) || batches[i].totalItems < 1 || std::cin.peek() != '\n') {
            fastErrInfo
                std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        std::cout << "Количество годных изделий: ";
        while (!(std::cin >> batches[i].goodItems) || batches[i].goodItems < 0 || batches[i].goodItems > batches[i].totalItems || std::cin.peek() != '\n') {
            fastErrInfo
                std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}

void outputData() {
    std::cout << "\n\nИтоговая информация:\n";
    std::cout << std::setw(15) << "Номер заказа" << std::setw(20) << "Количество изделий" << std::setw(30) << "Количество годных изделий" << std::setw(20) << "% годных изделий" << std::endl;
    std::cout << "----------------------------------------------------------------------------------------\n";

    for (register int i = 0; i < batchCount; ++i) {
        std::cout << std::setw(15) << batches[i].orderNumber << std::setw(20) << batches[i].totalItems << std::setw(30) << batches[i].goodItems;

        if (batches[i].totalItems != 0) {
            double percent = ((double)(batches[i].goodItems) / batches[i].totalItems) * 100;
            std::cout << std::setw(20) << std::fixed << std::setprecision(1) << percent << "%\n";
        }
        else {
            std::cout << std::setw(20) << "Ошибка: деление на ноль\n";
        }
    }
}