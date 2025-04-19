#include <iostream>
#include <string>
#include <vector>

class Hash {
private:
    static int receivingExistCodes(int x) {
        x += 256;
        while (!(((x <= 57) && (x >= 48)) || ((x <= 90) && (x >= 65)) || ((x <= 122) && (x >= 97)))) {
            if (x < 48) { x += 24; }
            else { x -= 47; }
        }
        return x;
    }

public:
    static int GetControlSum(const std::string& str) {
        unsigned sault = 0;
        for (size_t i = 0; i < str.size(); i++) {
            sault += (char)str[i];
        }
        return sault;
    }

    static std::string GetHash(std::string str, unsigned hashLength) {
        if (hashLength < 4) {
            return " ";
        }

        unsigned minLength = 2;
        const unsigned originalLengthStr = str.size();

        if (originalLengthStr == 0) {
            return " ";
        }

        while (minLength < originalLengthStr) {
            minLength *= 2;
        }
        if ((minLength - originalLengthStr) < minLength) {
            minLength *= 2;
        }

        const int addCount = minLength - originalLengthStr;
        for (int i = 0; i < addCount; i++) {
            const size_t idx1 = i % originalLengthStr;
            const size_t idx2 = (i + 1) % originalLengthStr;
            str += receivingExistCodes(str[idx1] + str[idx2]);
        }

        const unsigned originalSault = GetControlSum(str);
        const unsigned maxLengthStr = str.size();
        const int maxSault = GetControlSum(str);

        std::string tempHash;
        while (str.size() > hashLength) {
            tempHash.clear();
            const size_t center = str.size() / 2;

            for (size_t i = 0; i < center; i++) {
                const size_t left = center - i - 1;
                size_t right = center + i;
                if (right >= str.size()) {
                    right = str.size() - 1;
                }
                tempHash += receivingExistCodes(str[left] + str[right]);
            }
            str = tempHash;
        }

        std::string resultHash;
        for (size_t i = 0; resultHash.size() < hashLength - 4 && i < str.size(); i++) {
            resultHash += str[i];
        }

        resultHash += receivingExistCodes(originalSault);
        resultHash += receivingExistCodes(originalLengthStr);
        resultHash += receivingExistCodes(maxSault);
        resultHash += receivingExistCodes(maxLengthStr);

        if (resultHash.size() > hashLength) {
            resultHash.resize(hashLength);
        }

        return resultHash;
    }
};

class Node {
private:
    std::string key;
    Node* next;
public:
    Node() : key(""), next(nullptr) {}
    Node(const std::string& key) : key(key), next(nullptr) {}
    friend class HashTable;
};

class HashTable {
private:
    static const int SIZE = 100;
    Node* table[SIZE];
    std::vector<std::string> cities;

    int hashFunction(const std::string& key) {
        std::string hashStr = Hash::GetHash(key, 128);
        return Hash::GetControlSum(hashStr) % SIZE;
    }

    bool containsLetterO(const std::string& str) {
        for (char c : str) {
            if (c == 'o' || c == 'O') {
                return true;
            }
        }
        return false;
    }

public:
    HashTable() {
        for (int i = 0; i < SIZE; ++i) {
            table[i] = nullptr;
        }
    }

    ~HashTable() {
        for (int i = 0; i < SIZE; i++) {
            Node* current = table[i];
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
    }

    void insert(const std::string& key) {
        if (key == "end") return;

        cities.push_back(key);
        int hashValue = hashFunction(key);
        Node* newNode = new Node(key);

        if (table[hashValue] == nullptr) {
            table[hashValue] = newNode;
        }
        else {
            newNode->next = table[hashValue];
            table[hashValue] = newNode;
        }
    }

    void removeCitiesWithO() {
        std::vector<std::string> remainingCities;
        for (int i = 0; i < SIZE; i++) {
            Node* current = table[i];
            Node* prev = nullptr;

            while (current != nullptr) {
                if (containsLetterO(current->key)) {
                    Node* toDelete = current;

                    if (prev == nullptr) {
                        table[i] = current->next;
                        current = table[i];
                    }
                    else {
                        prev->next = current->next;
                        current = current->next;
                    }

                    delete toDelete;
                }
                else {
                    remainingCities.push_back(current->key);
                    prev = current;
                    current = current->next;
                }
            }
        }

        if (!remainingCities.empty()) {
            std::cout << "\nÃÎÐÎÄÀ ÏÎÑËÅ ÓÄÀËÅÍÈß ÁÓÊÂÛ 'O':\n";
            for (size_t i = 0; i < remainingCities.size(); ++i) {
                std::cout << i + 1 << ". " << remainingCities[i] << "\n";
            }
        }
    }

    void printCitiesList() {
        if (!cities.empty()) {
            std::cout << "\nÑÏÈÑÎÊ ÂÂÅÄ¨ÍÍÛÕ ÃÎÐÎÄÎÂ:\n";
            for (size_t i = 0; i < cities.size(); ++i) {
                std::cout << i + 1 << ". " << cities[i] << "\n";
            }
        }
    }

    void printHashes(unsigned hashLength) {
        if (!cities.empty()) {
            std::cout << "\nÕÅØÈ ÃÎÐÎÄÎÂ:\n";
            for (size_t i = 0; i < cities.size(); ++i) {
                std::string hashStr = Hash::GetHash(cities[i], hashLength);
                int hashValue = Hash::GetControlSum(hashStr) % SIZE;
                std::cout << i + 1 << ". " << cities[i] << " - ÕÅØ: " << hashStr << " - ÈÍÄÅÊÑ: " << hashValue << "\n";
            }
        }
    }

    int GetSize() {
        return cities.size();
    }
};