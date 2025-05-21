#include "cursor_visibility.h"
#include "cursor_menu.h"
#include "console_inactivity_timer.h"
#include "input_check.h"
#include "sorts.h"
#include "header_project1.h"
#include "header_project2.h"
#include "project3.cpp"
#include "project4.cpp"
#include "project5.cpp"
#include "project6.cpp"
#include "project7.cpp"
#include "project8.cpp"
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

int main() { 
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
     
    HANDLE consoleColor = GetStdHandle(STD_OUTPUT_HANDLE);



    std::thread timer(inactivity_timer, 100);
    timer.detach();

    enum For_ladNumberSwitch{ lab_1_Scope_of_variable, lab_2_Sort, lab_3_List, lab_4_Deque, lab_5_Stack, lab_6_Binary_tree, lab_7_Hashmap, lab_8_Graph, endOfProgram };
    enum For_SecondaryMenu_Switch { lab_showTask, lab_showTaskAndCopmplete, lab_returnToMainMenu, lab_endOfProgram };
    enum For_mainProject2Menu_Switch { project2_arrInitialization, project2_bubbleSort_a, project2_selectionSort_b, project2_insertionSort_c, project2_shellSort_d, project2_quickSort_e, project2_sequentialSearch, project2_binarySearch, project2_returnToSecondaryMenu, project2_endOfProgram };


    const std::string mainMenu[]{ 
        "Лабораторная работа №1 - Scope of variable",
        "Лабораторная работа №2 - Sort",
        "Лабораторная работа №3 - List",
        "Лабораторная работа №4 - Deque",
        "Лабораторная работа №5 - Stack",
        "Лабораторная работа №6 - Binary Tree",
        "Лабораторная работа №7 - Hashtable",
        "Лабораторная работа №8 - Graph",
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
        int mainMenu_choice = showMenu(".../mainMenu/", mainMenu, mainMenuCount);
        switch (mainMenu_choice) {
        case lab_1_Scope_of_variable: {
            bool shouldReturnToMainMenu = false;

            while (!shouldReturnToMainMenu) {
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

                    break;
                }
                case lab_returnToMainMenu: {
                    shouldReturnToMainMenu = true;
                    break;
                }
                case lab_endOfProgram: {
                    std::cout << "\nВы выбрали: " << secondaryMenu[secondaryChoice] << std::endl;
                    return 0;
                }
                default:
                    break;
                }
            }
            break;
        }
        case lab_2_Sort: {
            bool shouldReturnToMainMenu = false;

            while (!shouldReturnToMainMenu) {
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
                    unsigned size = 0;
                    bool errFlag = false;
                    int* a = nullptr;
                    int* b = nullptr;
                    int* c = nullptr;
                    int* d = nullptr;
                    int* e = nullptr;

                    bool shouldReturnToSecondaryMenu = false;

                    while (!shouldReturnToSecondaryMenu) {
                        int project2Choice = showMenu(".../mainMenu/secondaryMenu/mainProject2Menu/", mainProject2Menu, mainProject2MenuCount, true);

                        switch (project2Choice) {
                        case project2_arrInitialization: {
                            std::cout << "\nВы выбрали: " << mainProject2Menu[project2Choice] << std::endl;

                            showCursor();

                            std::cout << "\n\nВведите количество элементов в массиве : ";
                            while (!errFlag) {
                                number_filteredInput<unsigned>(size);
                                size != 0 ? errFlag = true : fastErrInfo;
                            }
                            errFlag = false;

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
                            system("pause");
                            break;
                        }
                        case project2_bubbleSort_a: {
                            std::cout << "\nВы выбрали: " << mainProject2Menu[project2Choice] << std::endl;

                            if (!a) {
                                std::cout << "\nСначала выполните инициализацию!\n" << std::endl;
                                system("pause");
                                break;
                            }
                            if (size < 2) {
                                std::cout << "\nСлишком мало элементов для сортировки!\n" << std::endl;
                                open_binary_a = 0;
                                system("pause");
                                break;
                            }
                            else {
                                std::cout << "\nИсходный массив:\n";
                                outputTempArray(a, b, c, d, e, size);
                                bubbleSort(a_temp, size);
                                std::cout << "\nМассив a отсортирован методом пузырька:\n" << std::endl;
                                outputArray(a_temp, b_temp, c_temp, d_temp, e_temp, size);
                                open_binary_a = 1;
                                writeSortedArraysToFile("results.txt", a_temp, b_temp, c_temp, d_temp, e_temp, size, "Массив a отсортирован методом пузырька");
                                std::cout << "\n";
                                system("pause");
                                break;
                            }
                        }
                        case project2_selectionSort_b: {
                            std::cout << "\nВы выбрали: " << mainProject2Menu[project2Choice] << std::endl;

                            if (!b) {
                                std::cout << "\nСначала выполните инициализацию!\n" << std::endl;
                                system("pause");
                                break;
                            }
                            if (size < 2) {
                                std::cout << "\nСлишком мало элементов для сортировки!\n" << std::endl;
                                system("pause");
                                break;
                                open_binary_b = 0;
                            }
                            else {
                                std::cout << "\nИсходный массив:\n";
                                outputTempArray(a, b, c, d, e, size);
                                selectionSort(b_temp, size);
                                std::cout << "\nМассив b отсортирован методом выбора:\n" << std::endl;
                                outputArray(a_temp, b_temp, c_temp, d_temp, e_temp, size);
                                open_binary_b = 1;
                                writeSortedArraysToFile("results.txt", a_temp, b_temp, c_temp, d_temp, e_temp, size, "Массив b отсортирован методом выбора");
                                std::cout << "\n";
                                system("pause");
                                break;
                            }
                        }
                        case project2_insertionSort_c: {
                            std::cout << "\nВы выбрали: " << mainProject2Menu[project2Choice] << std::endl;

                            if (!c) {
                                std::cout << "\nСначала выполните инициализацию\n" << std::endl;
                                system("pause");
                                break;
                            }
                            if (size < 2) {
                                std::cout << "\nСлишком мало элементов для сортировки!\n" << std::endl;
                                system("pause");
                                open_binary_c = 0;
                                break;
                            }
                            else {
                                std::cout << "\nИсходный массив:\n";
                                outputTempArray(a, b, c, d, e, size);
                                insertionSort(c_temp, size);
                                std::cout << "\nМассив c отсортирован методом вставки:\n" << std::endl;
                                outputArray(a_temp, b_temp, c_temp, d_temp, e_temp, size);
                                open_binary_c = 1;
                                writeSortedArraysToFile("results.txt", a_temp, b_temp, c_temp, d_temp, e_temp, size, "Массив c отсортирован методом вставки");
                                std::cout << "\n";
                                system("pause");
                                break;
                            }
                        }
                        case project2_shellSort_d: {
                            std::cout << "\nВы выбрали: " << mainProject2Menu[project2Choice] << std::endl;

                            if (!d) {
                                std::cout << "\nСначала выполните инициализацию!\n" << std::endl;
                                system("pause");
                                break;
                            }
                            if (size < 2) {
                                std::cout << "\nСлишком мало элементов для сортировки!\n" << std::endl;
                                system("pause");
                                open_binary_d = 0;
                                break;
                            }
                            else {
                                std::cout << "\nИсходный массив:\n";
                                outputTempArray(a, b, c, d, e, size);
                                shellSort(d_temp, size);
                                std::cout << "\nМассив d отсортирован методом Шелла:\n" << std::endl;
                                outputArray(a_temp, b_temp, c_temp, d_temp, e_temp, size);
                                open_binary_d = 1;
                                writeSortedArraysToFile("results.txt", a_temp, b_temp, c_temp, d_temp, e_temp, size, "Массив d отсортирован методом Шелла");
                                std::cout << "\n";
                                system("pause");
                                break;
                            }
                        }
                        case project2_quickSort_e: {
                            std::cout << "\nВы выбрали: " << mainProject2Menu[project2Choice] << std::endl;

                            if (!e) {
                                std::cout << "\nСначала выполните инициализацию!\n" << std::endl;
                                system("pause");
                                break;
                            }
                            if (size < 2) {
                                std::cout << "\nСлишком мало элементов для сортировки!\n" << std::endl;
                                system("pause");
                                open_binary_e = 0;
                                break;
                            }
                            else {
                                std::cout << "\nИсходный массив: \n";
                                outputTempArray(a, b, c, d, e, size);
                                quickSort(e_temp, 0, size - 1);
                                std::cout << "\nМассив e отсортирован методом Хоара:\n" << std::endl;
                                outputArray(a_temp, b_temp, c_temp, d_temp, e_temp, size);
                                open_binary_e = 1;
                                writeSortedArraysToFile("results.txt", a_temp, b_temp, c_temp, d_temp, e_temp, size, "Массив e отсортирован методом Хоара");
                                std::cout << "\n";
                                system("pause");
                                break;
                            }
                        }
                        case project2_sequentialSearch: {
                            std::cout << "\nВы выбрали: " << mainProject2Menu[project2Choice] << std::endl;

                            if (!a && !b && !c && !d && !e) {
                                std::cout << "\nСначала выполните инициализацию!\n" << std::endl;
                                system("pause");
                                break;
                            }
                            int x;
                            std::cout << "Введите элемент для поиска: ";
                            number_filteredInput<int>(x);

                            int seqResults[5] = {
                                sequentialSearch(a, size, x),
                                sequentialSearch(b, size, x),
                                sequentialSearch(c, size, x),
                                sequentialSearch(d, size, x),
                                sequentialSearch(e, size, x)
                            };
                            std::cout << "\nРезультаты последовательного поиска:\n\n" << std::endl;
                            std::cout << "Массив a: " << seqResults[0] << " вхождений" << std::endl;
                            std::cout << "Массив b: " << seqResults[1] << " вхождений" << std::endl;
                            std::cout << "Массив c: " << seqResults[2] << " вхождений" << std::endl;
                            std::cout << "Массив d: " << seqResults[3] << " вхождений" << std::endl;
                            std::cout << "Массив e: " << seqResults[4] << " вхождений" << std::endl;

                            writeSequentialSearchResultsToFile("results.txt", a, b, c, d, e, size, x, seqResults);
                            std::cout << "\n";
                            system("pause");
                            break;
                        }
                        case project2_binarySearch: {
                            std::cout << "\nВы выбрали: " << mainProject2Menu[project2Choice] << std::endl;

                            if (!a && !b && !c && !d && !e || size < 2 || (open_binary_a == 0 && open_binary_b == 0 && open_binary_c == 0 && open_binary_d == 0 && open_binary_e == 0)) {
                                std::cout << "\nСначала выполните инициализацию и сортировку (минимум одного массива)!\n" << std::endl;
                                system("pause");
                                break;
                            }
                            int x;
                            std::cout << "Введите элемент для поиска: ";
                            number_filteredInput<int>(x);

                            bool binaryResults[5] = {
                                open_binary_a && binarySearch(a_temp, 0, size - 1, x) != -1,
                                open_binary_b && binarySearch(b_temp, 0, size - 1, x) != -1,
                                open_binary_c && binarySearch(c_temp, 0, size - 1, x) != -1,
                                open_binary_d && binarySearch(d_temp, 0, size - 1, x) != -1,
                                open_binary_e && binarySearch(e_temp, 0, size - 1, x) != -1
                            };
                            std::cout << "\nРезультаты бинарного поиска:\n\n" << std::endl;
                            if (open_binary_a == 1) std::cout << "Массив a: " << (binaryResults[0] ? "Найден" : "Не найден") << std::endl;
                            if (open_binary_b == 1) std::cout << "Массив b: " << (binaryResults[1] ? "Найден" : "Не найден") << std::endl;
                            if (open_binary_c == 1) std::cout << "Массив c: " << (binaryResults[2] ? "Найден" : "Не найден") << std::endl;
                            if (open_binary_d == 1) std::cout << "Массив d: " << (binaryResults[3] ? "Найден" : "Не найден") << std::endl;
                            if (open_binary_e == 1) std::cout << "Массив e: " << (binaryResults[4] ? "Найден" : "Не найден") << std::endl;

                            writeBinarySearchResultsToFile("results.txt", a_temp, b_temp, c_temp, d_temp, e_temp, size, x, binaryResults);
                            std::cout << "\n";
                            system("pause");
                            break;
                        }
                        case project2_returnToSecondaryMenu: {

                            shouldReturnToSecondaryMenu = true;
                            break;
                        }
                        case project2_endOfProgram: {
                            std::cout << "\nВы выбрали: " << mainProject2Menu[project2Choice] << std::endl;
                            return 0;
                        }
                        default:
                            break;
                        }
                    }
                }
                case lab_returnToMainMenu: {
                    shouldReturnToMainMenu = true;
                    break;
                }
                case lab_endOfProgram: {
                    std::cout << "\nВы выбрали: " << secondaryMenu[secondaryChoice] << std::endl;
                    return 0;
                }
                default:
                    break;
                }
            }
            break;
        }
        case lab_3_List: {
            bool shouldReturnToMainMenu = false;

            while (!shouldReturnToMainMenu) {
                int secondaryChoice = showMenu(".../mainMenu/secondaryMenu/", secondaryMenu, secondaryMenuCount);

                switch (secondaryChoice) {
                case lab_showTask: {
                    std::cout << "\nВы выбрали: " << secondaryMenu[secondaryChoice] << std::endl;
                    std::cout << "\nНЕОБХОДИМО:\n\n19. Создать односвязный строковый список с помощью массива структур. Отсортировать элементы списка по возрастанию. Результирующий список вывести на экран.\n" << std::endl; system("pause");
                    break;
                }
                case lab_showTaskAndCopmplete: {
                    std::cout << "\nВы выбрали: " << secondaryMenu[secondaryChoice] << std::endl;
                    std::cout << "\nНЕОБХОДИМО:\n\n19. Создать односвязный строковый список с помощью массива структур. Отсортировать элементы списка по возрастанию. Результирующий список вывести на экран.\n" << std::endl;  system("pause");

                    List<std::string> lst;
                    std::string str;
                    bool EndFlag = false;

                    std::cout << "Введите элементы списка (для завершения введите 'end'):\n";

                    while (!EndFlag) {
                        std::cout << "Элемент " << lst.GetSize() + 1 << "  : ";
                        letter_filteredInput<std::string>(str);
                        lst.push_back(str);
                        if (str == "end") {
                            EndFlag = true;
                        }
                    }

                    std::cout << "\nЭЛЕМЕНТЫ ВАШЕГО СПИСКА ДО СОРТИРОВКИ:\n";
                    for (int i = 0; i < lst.GetSize(); i++) {
                        std::cout << i + 1 << " - элемент списка: " << lst[i] << "\n";
                    }

                    lst.bubbleSort();

                    std::cout << "\nЭЛЕМЕНТЫ ВАШЕГО СПИСКА ПОСЛЕ СОРТИРОВКИ:\n";
                    for (int i = 0; i < lst.GetSize(); i++) {
                        std::cout << i + 1 << " - элемент списка: " << lst[i] << "\n";
                    }
                    system("pause");

                    break;
                }
                case lab_returnToMainMenu: {
                    shouldReturnToMainMenu = true;
                    break;
                }
                case lab_endOfProgram: {
                    std::cout << "\nВы выбрали: " << secondaryMenu[secondaryChoice] << std::endl;
                    return 0;
                }
                default:
                    break;
                }
            }
            break;
        }
        case lab_4_Deque: {
            bool shouldReturnToMainMenu = false;

            while (!shouldReturnToMainMenu) {
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
                    system("pause");

                    bool dequeSizeController = false;
                    unsigned dequeSize;
                    int num, dqElementCounter = 0;
                    Deque<int> dq;

                    while (!dequeSizeController) {
                        std::cout << "Введите максимальный размер дека: ";
                        number_filteredInput<unsigned>(dequeSize);
                        std::cout << "\n";
                        if (dequeSize == 0) {
                            fastErrInfo;
                        }
                        else dequeSizeController = true;
                    }

                    std::cout << "Вводите элементы дека (в количестве '" << dequeSize << "' штук):\n";
                    for (int i = 0; i < dequeSize; i++) {
                        std::cout << "Введите элемент " << dq.GetSize() + 1 << "  : ";
                        if (i < dq.GetSize() / 2) {
                            number_filteredInput<int>(num);
                            dq.push_front(num);
                            std::cout << "\n";
                        }
                        else {
                            number_filteredInput<int>(num);
                            dq.push_back(num);
                            std::cout << "\n";
                        }
                    }
                    std::cout << "\nДОБАВЛЯЕМ 3 ЭЛЕМЕНТА В ДЕК СЛЕВА:\n";
                    for (int i = 0; i < 3; i++) {
                        std::cout << "Введите элемент " << dq.GetSize() + 1 << "  : ";
                        number_filteredInput<int>(num);
                        dq.push_front(num);
                        std::cout << "\n";
                    }
                    std::cout << "\nДОБАВЛЯЕМ 3 ЭЛЕМЕНТА В ДЕК СПРАВА:\n";
                    for (int i = 0; i < 3; i++) {
                        std::cout << "Введите элемент " << dq.GetSize() + 1 << "  : ";
                        number_filteredInput<int>(num);
                        dq.push_back(num);
                        std::cout << "\n";
                    }
                    std::cout << "\nЭЛЕМЕНТЫ ДЕКА СПРАВА (до 1 отрицательного):\n";
                    bool negativeFound = false;
                    for (int i = dq.GetSize() - 1; i >= 0; i--) {
                        std::cout << dq[i] << " ";
                        dqElementCounter++;
                        if (dq[i] < 0) {
                            negativeFound = true;
                            break;
                        }
                    }
                    if (!negativeFound) {
                        std::cout << "\nОтрицательных элементов нет!\n";
                    }

                    std::cout << "\n\nРАЗМЕР ВСЕГО ДЕКА: " << dq.GetSize() << "\n";
                    std::cout << "\nРАЗМЕР ОСТАВШЕГОСЯ ДЕКА: " << dq.GetSize() - dqElementCounter << "\n\n";

                    system("pause");
                    break;
                }
                case lab_returnToMainMenu: {
                    shouldReturnToMainMenu = true;
                    break;
                }
                case lab_endOfProgram: {
                    std::cout << "\nВы выбрали: " << secondaryMenu[secondaryChoice] << std::endl;
                    return 0;
                }
                default:
                    break;
                }
            }
            break;
        }
        case lab_5_Stack: {
            bool shouldReturnToMainMenu = false;

            while (!shouldReturnToMainMenu) {
                int secondaryChoice = showMenu(".../mainMenu/secondaryMenu/", secondaryMenu, secondaryMenuCount);

                switch (secondaryChoice) {
                case lab_showTask: {
                    std::cout << "\nВы выбрали: " << secondaryMenu[secondaryChoice] << std::endl;
                    std::cout << "\nНЕОБХОДИМО:\n\n19. Создать стек для целых (положительных и отрицательных) чисел. Максимальный размер стека вводится с экрана. Создать функции для ввода, вывода и определения размера стека. Вводить с экрана числа, причем в стек должны добавляться поочередно положительные и отрицательные числа.\n" << std::endl;
                    system("pause");
                    break;
                }
                case lab_showTaskAndCopmplete: {
                    std::cout << "\nВы выбрали: " << secondaryMenu[secondaryChoice] << std::endl;
                    std::cout << "\nНЕОБХОДИМО:\n\n19. Создать стек для целых (положительных и отрицательных) чисел. Максимальный размер стека вводится с экрана. Создать функции для ввода, вывода и определения размера стека. Вводить с экрана числа, причем в стек должны добавляться поочередно положительные и отрицательные числа.\n" << std::endl;
                    system("pause");

                    bool stackSizeController = false;
                    unsigned stackSize;
                    int num;
                    Stack<int> stk;

                    while (!stackSizeController) {
                        std::cout << "Введите максимальный размер стека: ";
                        number_filteredInput<unsigned>(stackSize);
                        std::cout << "\n";
                        if (stackSize == 0) {
                            fastErrInfo;
                        }
                        else stackSizeController = true;
                    }

                    std::cout << "Вводите элементы стека (в количестве '" << stackSize << "' штук):\n";
                    std::cout << "Введите элемент " << stk.GetSize() + 1 << "  : ";
                    number_filteredInput<int>(num);
                    stk.push_front(num);
                    std::cout << "\n";
                    if (stackSize > 1) {
                        for (int i = 0; i < stackSize - 1; i++) {
                            if (num > 0) {
                                std::cout << "Введите отрицательный элемент " << stk.GetSize() + 1 << "  : ";
                                number_filteredInput<int>(num, true);
                                stk.push_front(num);
                                std::cout << "\n";
                            }
                            else {
                                std::cout << "Введите положительный элемент " << stk.GetSize() + 1 << "  : ";
                                number_filteredInput<int>(num, false, true);
                                stk.push_front(num);
                                std::cout << "\n";
                            }
                            num = stk[0];
                        }
                    }

                    std::cout << "\nЭЛЕМЕНТЫ ВАШЕГО СТЕКА (в порядке извлечения):\n";
                    for (int i = 0; i < stk.GetSize(); i++) {
                        std::cout << stk.GetSize() - i << " - элемент стека: " << stk[i] << "\n";
                    }
                    std::cout << "\nРАЗМЕР ВАШЕГО СТЕКА:\n";
                    std::cout << stk.GetSize() << std::endl;
                    system("pause");
                    break;
                }
                case lab_returnToMainMenu: {
                    shouldReturnToMainMenu = true;
                    break;
                }
                case lab_endOfProgram: {
                    std::cout << "\nВы выбрали: " << secondaryMenu[secondaryChoice] << std::endl;
                    return 0;
                }
                default:
                    break;
                }
            }
            break;
        }
        case lab_6_Binary_tree: {
            bool shouldReturnToMainMenu = false;

            while (!shouldReturnToMainMenu) {
                int secondaryChoice = showMenu(".../mainMenu/secondaryMenu/", secondaryMenu, secondaryMenuCount);

                switch (secondaryChoice) {
                case lab_showTask: {
                    std::cout << "\nВы выбрали: " << secondaryMenu[secondaryChoice] << std::endl;
                    std::cout << "\nНЕОБХОДИМО:\n\n19. Дано четное число N (> 0) и набор из N чисел. Создать дерево из N вершин, в котором каждая левая дочерняя вершина является листом, а правая дочерняя вершина является внутренней. Для каждой внутренней вершины в начале создавать левую дочернюю вершину, а затем правую (если 22 она существует); каждой создаваемой вершине присваивать очередное значение из исходного набора. Вывести указатель на корень созданного дерева.\n" << std::endl;
                    system("pause");
                    break;
                }
                case lab_showTaskAndCopmplete: {
                    std::cout << "\nВы выбрали: " << secondaryMenu[secondaryChoice] << std::endl;
                    std::cout << "\nНЕОБХОДИМО:\n\n19. Дано четное число N (> 0) и набор из N чисел. Создать дерево из N вершин, в котором каждая левая дочерняя вершина является листом, а правая дочерняя вершина является внутренней. Для каждой внутренней вершины в начале создавать левую дочернюю вершину, а затем правую (если 22 она существует); каждой создаваемой вершине присваивать очередное значение из исходного набора. Вывести указатель на корень созданного дерева.\n" << std::endl;
                    system("pause");

                    bool BinaryTreeSizeController = false;
                    unsigned N;
                    BinaryTree<int> bt;

                    while (!BinaryTreeSizeController) {
                        std::cout << "Введите количество вершин дерева: ";
                        number_filteredInput<unsigned>(N);
                        std::cout << "\n";
                        if (N < 6) {
                            fastErrInfo;
                        }
                        else BinaryTreeSizeController = true;
                    }

                    int* values = new int[N];
                    for (int i = 0; i < N; i++) {
                        std::cout << "Число " << i + 1 << ": ";
                        number_filteredInput<int>(values[i]);
                        std::cout << "\n";
                    }
                    bt.buildFromArray(values, N);

                    std::cout << "\nBinaryTree:\n";
                    bt.printTree();

                    std::cout << "\nRoot pointer: " << bt.GetRoot() << "\n";

                    delete[] values;

                    system("pause");
                    break;
                }
                case lab_returnToMainMenu: {
                    shouldReturnToMainMenu = true;
                    break;
                }
                case lab_endOfProgram: {
                    std::cout << "\nВы выбрали: " << secondaryMenu[secondaryChoice] << std::endl;
                    return 0;
                }
                default:
                    break;
                }
            }
            break;
        }
        case lab_7_Hashmap: {
            bool shouldReturnToMainMenu = false;

            while (!shouldReturnToMainMenu) {
                int secondaryChoice = showMenu(".../mainMenu/secondaryMenu/", secondaryMenu, secondaryMenuCount);

                switch (secondaryChoice) {
                case lab_showTask: {
                    std::cout << "\nВы выбрали: " << secondaryMenu[secondaryChoice] << std::endl;
                    std::cout << "\nНЕОБХОДИМО:\n\n19. Создать хеш-таблицу для хранения информации о городах с ключами (названиями) и удалить из нее все города, название которых содержит букву 'о'.\n" << std::endl;
                    system("pause");
                    break;
                }
                case lab_showTaskAndCopmplete: {
                    std::cout << "\nВы выбрали: " << secondaryMenu[secondaryChoice] << std::endl;
                    std::cout << "\nНЕОБХОДИМО:\n\n19. Создать хеш-таблицу для хранения информации о городах с ключами (названиями) и удалить из нее все города, название которых содержит букву 'о'.\n" << std::endl;
                    system("pause");
                    
                    unsigned methodInput;
                    Method methodChoice = Division;
                    bool ErrFlag = false;

                    std::cout << "Выберите метод хеширования:\n";
                    std::cout << "1. Деление\n2. Умножение\n3. Универсальный\n> ";

                    while (!ErrFlag) {
                        number_filteredInput<unsigned>(methodInput);
                        if (methodInput <= 3 && methodInput != 0) {
                            ErrFlag = true;
                        }
                        else {
                            fastErrInfo;
                        }
                    }

                    if (methodInput == 1) methodChoice = Division;
                    else if (methodInput == 2) methodChoice = Multiplication;
                    else if (methodInput == 3) methodChoice = Universal;

                    HashTable ht(methodChoice);
                    std::string str;
                    bool EndFlag = false;

                    std::cout << "\nВводите города (для завершения введите 'end'):\n";
                    while (!EndFlag) {
                        std::cout << "Город " << ht.GetSize() + 1 << ": ";
                        letter_filteredInput<std::string>(str);
                        ht.insert(str);
                        if (str == "end") EndFlag = true;
                    }

                    ht.printCitiesList();
                    ht.printHashes();
                    ht.printHashTable(true);

                    ht.removeCitiesWithO();
                    ht.printHashTable(false);

                    system("pause");
                    break;
                }
                case lab_returnToMainMenu: {
                    shouldReturnToMainMenu = true;
                    break;
                }
                case lab_endOfProgram: {
                    std::cout << "\nВы выбрали: " << secondaryMenu[secondaryChoice] << std::endl;
                    return 0;
                }
                default:
                    break;
                }
            }
            break;
        }
        case lab_8_Graph: {
            bool shouldReturnToMainMenu = false;

            while (!shouldReturnToMainMenu) {
                int secondaryChoice = showMenu(".../mainMenu/secondaryMenu/", secondaryMenu, secondaryMenuCount);

                switch (secondaryChoice) {
                case lab_showTask: {
                    std::cout << "\nВы выбрали: " << secondaryMenu[secondaryChoice] << std::endl;
                    std::cout << "\nНЕОБХОДИМО:\n\n19. Построить граф, согласно схеме. Построить матрицу смежности для данного графа. По запросу пользователя выполнить действия: удалить вершину; найти все вершины, лежащие на кратчайшем пути между заданными вершинами; вывести на экран результирующий граф.\nДополнительное задание : удалить вершину 1, найти вершины между вершинами 5 и 3.\n" << std::endl;
                    system("pause");
                    break;
                }
                case lab_showTaskAndCopmplete: {
                    std::cout << "\nВы выбрали: " << secondaryMenu[secondaryChoice] << std::endl;
                    std::cout << "\nНЕОБХОДИМО:\n\n19. Построить граф, согласно схеме. Построить матрицу смежности для данного графа. По запросу пользователя выполнить действия: удалить вершину; найти все вершины, лежащие на кратчайшем пути между заданными вершинами; вывести на экран результирующий граф.\nДополнительное задание : удалить вершину 1, найти вершины между вершинами 5 и 3.\n" << std::endl;
                    system("pause");

                        Graph g(5);

                        g.addEdge(0, 1);
                        g.addEdge(0, 2);
                        g.addEdge(0, 3);
                        g.addEdge(1, 4);
                        g.addEdge(3, 4);
                        g.addEdge(2, 3);

                        g.printAdjMatrix();
                        g.removeVertex(0);

                        std::cout << "\nМатрица смежности после удаления вершины 1:\n";
                        g.printAdjMatrix();

                        std::vector<int> path = g.shortestPath(3, 1);

                        std::cout << "\nКратчайший путь между вершинами 5 и 3 (с учетом удаления вершины 1):\n";
                        for (int v : path) {
                            std::cout << (v + 2) << " ";
                        }
                        std::cout << "\n";

                        std::cout << "\nРезультирующий граф после удаления вершины 1:\n";
                        g.printGraph();

                    system("pause");
                    break;
                }
                case lab_returnToMainMenu: {
                    shouldReturnToMainMenu = true;
                    break;
                }
                case lab_endOfProgram: {
                    std::cout << "\nВы выбрали: " << secondaryMenu[secondaryChoice] << std::endl;
                    return 0;
                }
                default:
                    break;
                }
            }
            break;
        }
        case endOfProgram: {
            std::cout << "\nВы выбрали: " << mainMenu[mainMenu_choice] << std::endl;
            return 0;
        }
        default:
            break;
        }
    }
    return 0;
}