#include <iostream>
#include <string>

#define fastErrInfo std::cout << "Некорректный ввод. Введите информацию еще раз:\n"

template<typename T>
struct Node {
    static const int MAX_SIZE = INT_MAX;

    T data;
    Node* pNext;

    Node() : data(0), pNext(nullptr) {}
    Node(const T& val, Node* next = nullptr) : data(val), pNext(next) {} 

    Node* head = nullptr; 
    int size = 0;          

    void push_back(const T& data) {
        if (size >= MAX_SIZE) {
            std::cerr << "Список полон!\n";
            return;
        }

        Node* new_node = new Node(data);

        if (head == nullptr) {
            head = new_node;
        }
        else {
            Node* current = head;
            while (current->pNext) {
                current = current->pNext;
            }
            current->pNext = new_node;
        }
        size++;
    }

    void bubbleSort() {
        if (size < 2) return;

        bool swapped;
        do {
            swapped = false;
            Node* current = head;

            while (current->pNext) {
                if (current->data > current->pNext->data) {
                    std::swap(current->data, current->pNext->data);
                    swapped = true;
                }
                current = current->pNext;
            }
        } while (swapped);
    }

    void print() const {
        if (size == 0) {
            std::cout << "Список пуст!\n";
            return;
        }

        Node* current = head;
        while (current) {
            std::cout << current->data << std::endl;
            current = current->pNext;
        }
        std::cout << "\n";
    }
};

static bool operator!(const std::string& str) {
    return str.empty();
}