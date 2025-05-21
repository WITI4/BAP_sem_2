#include <iostream>
#include <string>
#include <vector>
#include <ctime>

enum Method { Division = 1, Multiplication = 2, Universal = 3 };

class Node {
public:
    std::string key;
    Node* next;
    Node(const std::string& key) : key(key), next(nullptr) {}
};

class HashTable {
    static const int SIZE = 1000;
    Node* table[SIZE] = { nullptr };
    std::vector<std::string> cities;
    Method method;
    double A = 0.6180339887;
    int uni_a, uni_b;
    const int uni_p = 2147483647;

    bool hasLetterO(const std::string& s) const {
        for (int i = 0; i < (int)s.length(); i++) {
            if (s[i] == 'o' || s[i] == 'O') return true;
        }
        return false;
    }

    int stringToInt(const std::string& s) const {
        int h = 0;
        for (int i = 0; i < (int)s.length(); i++) {
            h = h * 31 + (int)s[i];//полиномиальное хеширование
        }
        return (h < 0) ? -h : h;
    }

    int hashDivision(const std::string& s) const {
        return stringToInt(s) % SIZE;
    }

    int hashMultiplication(const std::string& s) const {
        int k = stringToInt(s);
        double goldHesh = k * A;
        int intPart = (int)goldHesh;
        double frac = goldHesh - intPart;
        return (int)(frac * SIZE);
    }

    int simpleRandom(int min, int max) const {
        return min + (std::rand() % (max - min + 1));
    }
    int hashUniversal(const std::string& s) const {
        int k = stringToInt(s);
        return ((uni_a * k + uni_b) % uni_p) % SIZE;
    }
    int getIndex(const std::string& s) const {
        if (method == Division) return hashDivision(s);
        else if (method == Multiplication) return hashMultiplication(s);
        else return hashUniversal(s);
    }

public:
    HashTable(Method m) : method(m) {
        if (method == Universal) {
            srand(time(NULL));
            uni_a = simpleRandom(1, uni_p - 1);
            uni_b = simpleRandom(0, uni_p - 1);
        }
    }

    ~HashTable() {
        for (int i = 0; i < SIZE; ++i) {
            Node* node = table[i];
            while (node) {
                Node* temp = node;
                node = node->next;
                delete temp;
            }
        }
    }

    int GetSize() const {
        return (int)cities.size();
    }

    void insert(const std::string& key) {
        if (key == "end") return;
        int idx = getIndex(key);
        Node* newNode = new Node(key);
        if (!table[idx]) {
            table[idx] = newNode;
        }
        else {
            Node* curr = table[idx];
            while (curr->next) curr = curr->next;
            curr->next = newNode;
        }
        cities.push_back(key);
    }

    void printCitiesList() const {
        std::cout << "\nСПИСОК ГОРОДОВ:\n";
        for (int i = 0; i < (int)cities.size(); ++i)
            std::cout << i + 1 << ". " << cities[i] << "\n";
    }

    void printHashes() const {
        std::cout << "\nХЕШ-КОДЫ (метод ";
        if (method == Division) std::cout << "деления";
        else if (method == Multiplication) std::cout << "умножения";
        else std::cout << "универсальный";
        std::cout << "):\n";
        for (int i = 0; i < (int)cities.size(); ++i) {
            int hashValue = stringToInt(cities[i]);  // Вычисляем хеш
            int index = getIndex(cities[i]);         // Вычисляем индекс
            std::cout << i + 1 << ". " << cities[i]
                << " -> хеш: " << hashValue
                    << " -> индекс: " << index << "\n";
        }
    }

    void printHashTable(bool before) const {
        std::cout << "\nТАБЛИЦА " << (before ? "(до удаления):\n" : "(после удаления):\n");
        for (int i = 0; i < SIZE; ++i) {
            if (table[i]) {
                std::cout << i << ": ";
                Node* curr = table[i];
                while (curr) {
                    std::cout << curr->key;
                    if (curr->next) std::cout << " -> ";
                    curr = curr->next;
                }
                std::cout << "\n";
            }
        }
    }

    void removeCitiesWithO() {
        std::vector<std::string> remaining;
        for (int i = 0; i < SIZE; ++i) {
            Node* curr = table[i];
            Node* prev = nullptr;
            while (curr) {
                if (hasLetterO(curr->key)) {
                    Node* temp = curr;
                    curr = curr->next;
                    if (prev) prev->next = curr;
                    else table[i] = curr;
                    delete temp;
                }
                else {
                    remaining.push_back(curr->key);
                    prev = curr;
                    curr = curr->next;
                }
            }
        }
        cities = remaining;
    }
};