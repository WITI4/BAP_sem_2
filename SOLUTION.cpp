#include "header_project1.h"
#include "header_project2.h"
#include "project3.cpp"
#include "sorts.h"
#include "cursor_visibility.h"
#include "cursor_menu.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <ctime>
#include <iomanip>
#include <cctype>

#undef max
#define fastErrInfo \
SetConsoleTextAttribute(consoleColor, 4);\
std::cout << "Некорректный ввод. Введите информацию еще раз:\n";\
SetConsoleTextAttribute(consoleColor, 7); 
//#define DEBUG

enum For_SecondaryMenu_Switch {
    lab_showTask = 0,
    lab_showTaskAndCopmplete = 1,
    lab_returnToMainMenu = 2,
    lab_endOfProgram = 3
};
enum For_mainProject2Menu_Switch {
    project2_arrInitialization = 0,
    project2_bubbleSort_a = 1,
    project2_selectionSort_b = 2,
    project2_insertionSort_c = 3,
    project2_shellSort_d = 4,
    project2_quickSort_e = 5,
    project2_sequentialSearch = 6,
    project2_binarySearch = 7,
    project2_returnToSecondaryMenu = 8,
    project2_endOfProgram = 9

};
enum For_mainProject3Menu_Switch {
    project3_int_list = 0,
    project3_string_list = 1,
    project3_returnToSecondaryMenu = 2,
    project3_endOfProgram = 3

};

int main() {
    setlocale(0, "ru");
    HANDLE consoleColor = GetStdHandle(STD_OUTPUT_HANDLE);

    const std::string mainMenu[]{
        "Лабораторная работа №1 - scope of variables",
        "Лабораторная работа №2 - sorts",
        "Лабораторная работа №3 - lists",
        "Лабораторная работа №4 - ...",
        "Выход из программы"
    };
    int mainMenuCount = sizeof(mainMenu) / sizeof(mainMenu[0]);

    const std::string secondaryMenu[]{
        "Посмотреть задание",
        "Посмотреть задание и выполнить работу",
        "Вернуться в выбор лабораторной работы",
        "Выход из программы"
    };
    int secondaryMenuCount = sizeof(secondaryMenu) / sizeof(secondaryMenu[0]);

    while (true) {
        hideCursor();
        int choice = showMenu(".../mainMenu/", mainMenu, mainMenuCount);
        switch (choice) {
        case 0: { // Лабораторная работа №1
            extern Batch* batches;
            extern int batchCount;

            while (true) {
                int secondaryChoice = showMenu(".../mainMenu/secondaryMenu/", secondaryMenu, secondaryMenuCount);

                switch (secondaryChoice) {
                case lab_showTask: {
                    std::cout << "\nВы выбрали: " << secondaryMenu[secondaryChoice] << std::endl;
                    std::cout << "\nНЕОБХОДИМО:\n\nВ каждом задании по возможности ввод, вывод, сортировку оформить как отдельные функции (применить к этим функциям классы хранения), функцию сортировки массива структур поместить в отдельный файл, структурную переменную объявить как статическую, счетчики циклов объявить как регистровые переменные, передачу значений осуществить через внешние переменные, осуществить динамическое распределение памяти под структуры.\n\n19. Разработать программу определения процента выхода годных изделий на основе актов приема ОТК. Данные о тестируемых партиях хранить в виде массива структур.Итоговая информация должна выводиться на экран в виде таблицы, отсортированной по номеру заказа.\n" << std::endl;
                    system("pause");
                    break;
                }
                case lab_showTaskAndCopmplete: {
                    int day, month, year, id, empPosition, empCount = 0;
                    float salary;

                    std::cout << "\nВы выбрали: " << secondaryMenu[secondaryChoice] << std::endl;
                    std::cout << "\nНЕОБХОДИМО:\n\nВ каждом задании по возможности ввод, вывод, сортировку оформить как отдельные функции (применить к этим функциям классы хранения), функцию сортировки массива структур поместить в отдельный файл, структурную переменную объявить как статическую, счетчики циклов объявить как регистровые переменные, передачу значений осуществить через внешние переменные, осуществить динамическое распределение памяти под структуры.\n\n19. Разработать программу определения процента выхода годных изделий на основе актов приема ОТК. Данные о тестируемых партиях хранить в виде массива структур.Итоговая информация должна выводиться на экран в виде таблицы, отсортированной по номеру заказа.\n" << std::endl;
                    showCursor();

                    inputData(batchCount);
                    outputData();
                    if (batchCount > 1) {
                        std::cout << "----------------------------------------------------------------------------------------\n";
                        std::cout << "\n\nОтсортированные данные: \n" << std::endl;
                        bubbleSort(batches, batchCount);
                        outputData();
                    }
                    delete[] batches;

                    hideCursor();

                    system("pause");
                    break;
                }
                case lab_returnToMainMenu: {
                    goto mainMenu;
                }
                case lab_endOfProgram: {
                    std::cout << "\nВы выбрали: " << secondaryMenu[secondaryChoice] << std::endl;
                    return 0;
                }
                }
            }
        }
        case 1: { // Лабораторная работа №2
            while (true) {
                int secondaryChoice = showMenu(".../mainMenu/secondaryMenu/", secondaryMenu, secondaryMenuCount);

                switch (secondaryChoice) {
                case lab_showTask: {
                    std::cout << "\nВы выбрали: " << secondaryMenu[secondaryChoice] << std::endl;
                    std::cout << "Разработать программу для создания пяти динамических массивов: a[ ], b[ ], c[ ], d[ ] и e[ ]. Эти массивы необходимо отсортировать соответственно методом обмена, методом выбора, методом вставки, методом Шелла и методом Хоора. Организовать последовательный поиск определенного элемента в каждом исходном массиве и подсчитать количество совпадений этого элемента в каждом массиве. Организовать бинарный поиск определенного элемента в каждом отсортированном массиве. Разработать в программе меню, структура которого следующая:\nMenu:\n1.Initilization arrays(инициализация массивов)\n2.Result of bubble sort\n3.Result of min sort\n4.Result of insert sort\n5.Result of Shell sort\n6.Result of Hoor sort\n7.Poisk\nPosledovatel’nyi poisk\nBinarnyi poik\nРезультаты всех сортировок и поиска записать в файл." << std::endl;
                    system("pause");
                    break;
                }
                case lab_showTaskAndCopmplete: {
                    std::cout << "\nВы выбрали: " << secondaryMenu[secondaryChoice] << std::endl;
                    std::cout << "Разработать программу для создания пяти динамических массивов: a[ ], b[ ], c[ ], d[ ] и e[ ]. Эти массивы необходимо отсортировать соответственно методом обмена, методом выбора, методом вставки, методом Шелла и методом Хоора. Организовать последовательный поиск определенного элемента в каждом исходном массиве и подсчитать количество совпадений этого элемента в каждом массиве. Организовать бинарный поиск определенного элемента в каждом отсортированном массиве. Разработать в программе меню, структура которого следующая:\nMenu:\n1.Initilization arrays(инициализация массивов)\n2.Result of bubble sort\n3.Result of min sort\n4.Result of insert sort\n5.Result of Shell sort\n6.Result of Hoor sort\n7.Poisk\nPosledovatel’nyi poisk\nBinarnyi poik\nРезультаты всех сортировок и поиска записать в файл.\n" << std::endl;
                    system("pause");

                    const std::string mainProject2Menu[] = {
                        "Инициализация массивов",
                        "bubbleSort - для массива a",
                        "selectionSort - для массива b",
                        "insertionSort - для массива c",
                        "shellSort - для массива d",
                        "quickSort - для массива e",
                        "Последовательный поиск",
                        "Бинарный поиск",
                        "Вернуться в меню",
                        "Выход из программы"
                    };
                    int mainProject2MenuCount = sizeof(mainProject2Menu) / sizeof(mainProject2Menu[0]);

                    bool open_binary_a = 0;
                    bool open_binary_b = 0;
                    bool open_binary_c = 0;
                    bool open_binary_d = 0;
                    bool open_binary_e = 0;
                    int size = 0;
                    int* a = nullptr;
                    int* b = nullptr;
                    int* c = nullptr;
                    int* d = nullptr;
                    int* e = nullptr;

                    while (true) {
                        int project2Choice = showMenu(".../mainMenu/secondaryMenu/mainProject2Menu/", mainProject2Menu, mainProject2MenuCount, true);

                        switch (project2Choice) {
                        case project2_arrInitialization: {
                            std::cout << "\nВы выбрали: " << mainProject2Menu[project2Choice] << std::endl;

                            showCursor();

                            std::cout << "\n\nВведите количество элементов в массиве : ";
                            while (!(std::cin >> size) || size < 1 || std::cin.peek() != '\n') {
                                fastErrInfo;
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            }

                            hideCursor();

                            if (a) delete[] a;
                            if (b) delete[] b;
                            if (c) delete[] c;
                            if (d) delete[] d;
                            if (e) delete[] e;

                            a = new int[size];
                            b = new int[size];
                            c = new int[size];
                            d = new int[size];
                            e = new int[size];

                            inputArray(a, b, c, d, e, size);
                            std::cout << "\nМассивы инициализированы случайными числами:\n" << std::endl;
                            outputArray(a, b, c, d, e, size);
                            writeInitializedArraysToFile("results.txt", a, b, c, d, e, size);
                            break;
                        }
                        case project2_bubbleSort_a: {
                            std::cout << "\nВы выбрали: " << mainProject2Menu[project2Choice] << std::endl; 

                            if (!a) {
                                std::cout << "\nСначала выполните инициализацию!\n" << std::endl;
                                break;
                            }
                            if (size <2) {
                                std::cout << "\nСлишком мало элементов для сортировки!\n" << std::endl;
                                open_binary_a = 0;
                                break;
                            }
                            else {
                                std::cout << "\nИсходный массив:\n";
                                outputTempArray(a_temp, b_temp, c_temp, d_temp, e_temp, size);
                                bubbleSort(a, size);
                                std::cout << "\nМассив a отсортирован методом пузырька:\n" << std::endl;
                                outputArray(a, b, c, d, e, size);
                                open_binary_a = 1;
                                writeSortedArraysToFile("results.txt", a, b, c, d, e, size, "Массив a отсортирован методом пузырька");
                                break;
                            }
                        }
                        case project2_selectionSort_b: {
                            std::cout << "\nВы выбрали: " << mainProject2Menu[project2Choice] << std::endl;

                            if (!b) {
                                std::cout << "\nСначала выполните инициализацию!\n" << std::endl;
                                break;
                            }
                            if (size < 2) {
                                std::cout << "\nСлишком мало элементов для сортировки!\n" << std::endl;
                                break;
                                open_binary_b = 0;
                            }
                            else {
                                std::cout << "\nИсходный массив:\n";
                                outputTempArray(a_temp, b_temp, c_temp, d_temp, e_temp, size);
                                selectionSort(b, size);
                                std::cout << "\nМассив b отсортирован методом выбора:\n" << std::endl;
                                outputArray(a, b, c, d, e, size);
                                open_binary_b = 1;
                                writeSortedArraysToFile("results.txt", a, b, c, d, e, size, "Массив b отсортирован методом выбора");
                                break;
                            }
                        }
                        case project2_insertionSort_c: {
                            std::cout << "\nВы выбрали: " << mainProject2Menu[project2Choice] << std::endl;

                            if (!c) {
                                std::cout << "\nСначала выполните инициализацию\n" << std::endl;
                                break;
                            }
                            if (size < 2) {
                                std::cout << "\nСлишком мало элементов для сортировки!\n" << std::endl;
                                open_binary_c = 0;
                                break;
                            }
                            else {
                                std::cout << "\nИсходный массив:\n";
                                outputTempArray(a_temp, b_temp, c_temp, d_temp, e_temp, size);
                                insertionSort(c, size);
                                std::cout << "\nМассив c отсортирован методом вставки:\n" << std::endl;
                                outputArray(a, b, c, d, e, size);
                                open_binary_c = 1;
                                writeSortedArraysToFile("results.txt", a, b, c, d, e, size, "Массив c отсортирован методом вставки");
                                break;
                            }                           
                        }
                        case project2_shellSort_d: {
                            std::cout << "\nВы выбрали: " << mainProject2Menu[project2Choice] << std::endl;

                            if (!d) {
                                std::cout << "\nСначала выполните инициализацию!\n" << std::endl;
                                break;
                            }
                            if (size < 2) {
                                std::cout << "\nСлишком мало элементов для сортировки!\n" << std::endl;
                                open_binary_d = 0;
                                break;
                            }
                            else {
                                std::cout << "\nИсходный массив:\n";
                                outputTempArray(a_temp, b_temp, c_temp, d_temp, e_temp, size);
                                shellSort(d, size);
                                std::cout << "\nМассив d отсортирован методом Шелла:\n" << std::endl;
                                outputArray(a, b, c, d, e, size);
                                open_binary_d = 1;
                                writeSortedArraysToFile("results.txt", a, b, c, d, e, size, "Массив d отсортирован методом Шелла");
                                break;
                            }
                        }
                        case project2_quickSort_e: {
                            std::cout << "\nВы выбрали: " << mainProject2Menu[project2Choice] << std::endl;

                            if (!e) {
                                std::cout << "\nСначала выполните инициализацию!\n" << std::endl;
                                break;
                            }
                            if (size < 2) {
                                std::cout << "\nСлишком мало элементов для сортировки!\n" << std::endl;
                                open_binary_e = 0;
                                break;
                            }
                            else {
                                std::cout << "\nИсходный массив: \n";
                                outputTempArray(a_temp, b_temp, c_temp, d_temp, e_temp, size);
                                quickSort(e, 0, size - 1);
                                std::cout << "\nМассив e отсортирован методом Хоара:\n" << std::endl;
                                outputArray(a, b, c, d, e, size);
                                open_binary_e = 1;
                                writeSortedArraysToFile("results.txt", a, b, c, d, e, size, "Массив e отсортирован методом Хоара");
                                break;
                            }
                        }
                        case project2_sequentialSearch: {
                            std::cout << "\nВы выбрали: " << mainProject2Menu[project2Choice] << std::endl;

                            if (!a && !b && !c && !d && !e) {
                                std::cout << "\nСначала выполните инициализацию!\n" << std::endl;
                                break;
                            }
                            int x;
                            std::cout << "Введите элемент для поиска: ";
                            while (!(std::cin >> x) || std::cin.peek() != '\n') {
                                fastErrInfo;
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            }
                            int seqResults[5] = {
                                sequentialSearch(a_temp, size, x),
                                sequentialSearch(b_temp, size, x),
                                sequentialSearch(c_temp, size, x),
                                sequentialSearch(d_temp, size, x),
                                sequentialSearch(e_temp, size, x)
                            };
                            std::cout << "\nРезультаты последовательного поиска:\n\n" << std::endl;
                            std::cout << "Массив a: " << seqResults[0] << " вхождений" << std::endl;
                            std::cout << "Массив b: " << seqResults[1] << " вхождений" << std::endl;
                            std::cout << "Массив c: " << seqResults[2] << " вхождений" << std::endl;
                            std::cout << "Массив d: " << seqResults[3] << " вхождений" << std::endl;
                            std::cout << "Массив e: " << seqResults[4] << " вхождений" << std::endl;

                            writeSequentialSearchResultsToFile("results.txt", a_temp, b_temp, c_temp, d_temp, e_temp, size, x, seqResults);
                            break;
                        }
                        case project2_binarySearch: {
                            std::cout << "\nВы выбрали: " << mainProject2Menu[project2Choice] << std::endl;

                            if (!a && !b && !c && !d && !e || size < 2 || (open_binary_a == 0 && open_binary_b == 0 && open_binary_c == 0 && open_binary_d == 0 && open_binary_e == 0)) {
                                std::cout << "\nСначала выполните инициализацию и сортировку (минимум одного массива)!\n" << std::endl;
                                break;
                            }
                            int x;
                            std::cout << "Введите элемент для поиска: ";
                            while (!(std::cin >> x) || std::cin.peek() != '\n') {
                                fastErrInfo;
                                std::cin.clear();
                                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            }
                            bool binaryResults[5] = {
                                open_binary_a && binarySearch(a, 0, size - 1, x) != -1,
                                open_binary_b && binarySearch(b, 0, size - 1, x) != -1,
                                open_binary_c && binarySearch(c, 0, size - 1, x) != -1,
                                open_binary_d && binarySearch(d, 0, size - 1, x) != -1,
                                open_binary_e && binarySearch(e, 0, size - 1, x) != -1
                            };
                            std::cout << "\nРезультаты бинарного поиска:\n\n" << std::endl;
                            if (open_binary_a == 1) std::cout << "Массив a: " << (binaryResults[0] ? "Найден" : "Не найден") << std::endl;
                            if (open_binary_b == 1) std::cout << "Массив b: " << (binaryResults[1] ? "Найден" : "Не найден") << std::endl;
                            if (open_binary_c == 1) std::cout << "Массив c: " << (binaryResults[2] ? "Найден" : "Не найден") << std::endl;
                            if (open_binary_d == 1) std::cout << "Массив d: " << (binaryResults[3] ? "Найден" : "Не найден") << std::endl;
                            if (open_binary_e == 1) std::cout << "Массив e: " << (binaryResults[4] ? "Найден" : "Не найден") << std::endl;
                            
                            writeBinarySearchResultsToFile("results.txt", a, b, c, d, e, size, x, binaryResults);
                            break;
                        }
                        case project2_returnToSecondaryMenu: {
                            goto project2MenuExit;
                        }
                        case project2_endOfProgram: {
                            std::cout << "\nВы выбрали: " << mainProject2Menu[project2Choice] << std::endl;
                            return 0;
                        }
                        }
                        system("pause");
                    }
                project2MenuExit:
                    if (a) delete[] a;
                    if (b) delete[] b;
                    if (c) delete[] c;
                    if (d) delete[] d;
                    if (e) delete[] e;
                    if (a_temp) delete[] a_temp;
                    if (b_temp) delete[] b_temp;
                    if (c_temp) delete[] c_temp;
                    if (d_temp) delete[] d_temp;
                    if (e_temp) delete[] e_temp;
                    break;
                }
                case lab_returnToMainMenu: {
                    goto mainMenu;
                }
                case lab_endOfProgram: {
                    std::cout << "\nВы выбрали: " << secondaryMenu[secondaryChoice] << std::endl;
                    return 0;
                }
                }
            }
            break;
        }
        case 2: { // Лабораторная работа №3
            while (true) {
                int secondaryChoice = showMenu(".../mainMenu/secondaryMenu/", secondaryMenu, secondaryMenuCount);

                switch (secondaryChoice) {
                case lab_showTask: {
                    std::cout << "\nВы выбрали: " << secondaryMenu[secondaryChoice] << std::endl;
                    std::cout << "\nНЕОБХОДИМО:\n\n19. Создать односвязный строковый список с помощью массива структур. Отсортировать элементы списка по возрастанию. Результирующий список вывести на экран.\n" << std::endl;
                    system("pause");
                    break;
                }
                case lab_showTaskAndCopmplete: {
                    std::cout << "\nВы выбрали: " << secondaryMenu[secondaryChoice] << std::endl;
                    std::cout << "\nНЕОБХОДИМО:\n\n19. Создать односвязный строковый список с помощью массива структур. Отсортировать элементы списка по возрастанию. Результирующий список вывести на экран.\n" << std::endl;
                    system("pause");

                    const std::string mainProject3Menu[] = {
                        "int list",
                        "string list",
                        "Вернуться в меню",
                        "Выход из программы"
                    };
                    int mainProject3MenuCount = sizeof(mainProject3Menu) / sizeof(mainProject3Menu[0]);

                    while (true) {
                        int project3Choice = showMenu(".../mainMenu/secondaryMenu/mainProject3Menu/", mainProject3Menu, mainProject3MenuCount, true);

                        switch (project3Choice) {
                        case project3_int_list: {
                            std::cout << "\nВы выбрали: " << mainProject3Menu[project3Choice] << std::endl;

                            showCursor();

                            Node<int> lst;
                            std::string inputStr;

                            std::cout << "Введите элементы списка (для завершения введите 'end'):\n";

                            while (true) {
                                std::cout << "Элемент " << lst.size + 1 << ": ";
                                getline(std::cin, inputStr);

                                if (inputStr.empty()) {
                                    fastErrInfo;
                                    continue;
                                }

                                bool isEnd = true;
                                if (inputStr == "end") {
                                    break;
                                }
                                else {
                                    isEnd = false;
                                }

                                if (isEnd) {
                                    break;
                                }

                                bool isValid = true;
                                for (size_t i = 0; i < inputStr.size(); ++i) {
                                    char c = inputStr[i];

                                    if (!(c >= '0' && c <= '9')) {
                                        if (c == '.') {
                                            fastErrInfo;
                                            isValid = false; 
                                            break;
                                        }

                                        else if (c == ' ' && i > 0 && (inputStr[i - 1] >= '0' && inputStr[i - 1] <= '9')) {
                                            fastErrInfo;
                                            isValid = false;
                                            break;
                                        }
                                        if (c == '-' && i == 0) {
                                            isValid = true;
                                            continue;
                                        }
                                        else if (c != ' ') {
                                            fastErrInfo;
                                            isValid = false;
                                            break;
                                        }
                                    }
                                }

                                if (!isValid) continue;

                                try {
                                    int num = stoi(inputStr);
                                    lst.push_back(num);
                                }
                                catch (...) {
                                    std::cout << "Ошибка: введено число, выходящее за допустимые пределы." << std::endl;
                                }
                            }

                            std::cout << "\nИсходный список:\n";
                            lst.print();

                            lst.bubbleSort();

                            std::cout << "\nОтсортированный список:\n";
                            lst.print();

                            hideCursor();

                            break;
                            }
                        case project3_returnToSecondaryMenu: {
                            goto project3MenuExit;
                        }
                        case project3_endOfProgram: {
                            std::cout << "\nВы выбрали: " << mainProject3Menu[project3Choice] << std::endl;
                            return 0;
                        }
                        }
                        system("pause");
                    }
                project3MenuExit:
                    break;
                }
                case lab_returnToMainMenu: {
                    goto mainMenu;
                }
                case lab_endOfProgram: {
                    std::cout << "\nВы выбрали: " << secondaryMenu[secondaryChoice] << std::endl;
                    return 0;
                }
                }
            }
            break;
        }
        case 3: { // Лабораторная работа №4
            while (true) {
                int secondaryChoice = showMenu(".../mainMenu/secondaryMenu/", secondaryMenu, secondaryMenuCount);

                switch (secondaryChoice) {
                case lab_showTask: {
                    std::cout << "\nВы выбрали: " << secondaryMenu[secondaryChoice] << std::endl;
                    std::cout << "\nНЕОБХОДИМО:\n\n19. Создать дек для целых (положительных и отрицательных) чисел. Максимальный размер дека вводится с экрана. Создать функции для ввода, вывода и определения размера дека. Ввести 3 элемента справа и 3 слева.  Вывести элементы дека справа до первого отрицательного (включительно). Вывести размер оставшегося дека.\n" << std::endl;
                    system("pause");
                    break;
                }
                case lab_showTaskAndCopmplete: {

                    std::cout << "\nВы выбрали: " << secondaryMenu[secondaryChoice] << std::endl;
                    std::cout << "\nНЕОБХОДИМО:\n\n19. Создать дек для целых (положительных и отрицательных) чисел. Максимальный размер дека вводится с экрана. Создать функции для ввода, вывода и определения размера дека. Ввести 3 элемента справа и 3 слева.  Вывести элементы дека справа до первого отрицательного (включительно). Вывести размер оставшегося дека.\n" << std::endl;
                    showCursor();



                    hideCursor();

                    system("pause");
                    break;
                }
                case lab_returnToMainMenu: {
                    goto mainMenu;
                }
                case lab_endOfProgram: {
                    std::cout << "\nВы выбрали: " << secondaryMenu[secondaryChoice] << std::endl;
                    return 0;
                }
                }
            }
        }
        case 4: {// Выход из программы
            std::cout << "\nВы выбрали: " << mainMenu[choice] << std::endl;
            return 0;
        }
          mainMenu:;
        }
    }
}