#include <iostream>
#include <iomanip>

template<typename T>
class BinaryTree {
    class Node {
    public:
        T key;
        Node* left;
        Node* right;
        Node(T key = T(), Node* left = nullptr, Node* right = nullptr) {
            this->key = key;
            this->left = left;
            this->right = right;
        }
    };

    Node* root;

    void clear(Node* node) {
        if (node) {
            clear(node->left);
            clear(node->right);
            delete node;
        }
    }

    bool contains(Node* node, const T& key) const {
        if (!node) return false;
        if (key == node->key) return true;
        return (key < node->key) ? contains(node->left, key) : contains(node->right, key);
    }

    Node* insert(Node* node, const T& key) {
        if (!node) return new Node(key);
        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        return node;
    }

    void buildSpecial(Node*& node, const T* values, int& index, int N) {
        if (index >= N) return;
        node = new Node(values[index++]);

        if (index < N) {
            node->left = new Node(values[index++]);
        }
        if (index < N) {
            buildSpecial(node->right, values, index, N);
        }
    }

public:
    Node* GetRoot() const { return root; }

    BinaryTree() : root(nullptr) {}
    ~BinaryTree() { clear(root); }

    bool contains(const T& key) const {
        return contains(root, key);
    }

    void insert(const T& key) {
        root = insert(root, key);
    }

    void buildFromArray(const T* values, int N) {
        int index = 0;
        clear(root);
        buildSpecial(root, values, index, N);
    }

    void printTree() const {
        if (!root) return;
        std::cout << "      " << root->key << " (корень)\n";
        std::cout << "       /   \\\n";
        std::cout << "      " << root->left->key << "    " << root->right->key << " (узел)\n";
        std::cout << "   (лист) /   \\\n";
        std::cout << "         " << root->right->left->key << "    " << root->right->right->key << " (узел)\n";
        std::cout << "      (лист) /   \\\n";
        std::cout << "            " << root->right->right->left->key << "    ....\n";
        std::cout << "         (лист)\n";
    }

};