template<typename T>
class Stack {
	template<typename T>
	class Node {
	public:
		Node* pNext;
		T data;
		Node(T data = T(), Node* pNext = nullptr) {
			this->data = data;
			this->pNext = pNext;
		}
	};
	int Size;
	Node<T>* head;
public:
	Stack();
	~Stack();
	int GetSize() { return Size; }
	T& operator[](const int index);
	void pop_front();
	void clear();
	void push_front(T data);
};

template<typename T>
Stack<T>::Stack() {
	Size = 0;
	head = nullptr;
}
template<typename T>
Stack<T>::~Stack() {
	clear();
}
template<typename T>
T& Stack<T>::operator[](const int index) {
	int counter = 0;
	Node<T>* current = this->head;
	while (current != nullptr) {
		if (counter == index) {
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}
template<typename T>
void Stack<T>::pop_front() {
	Node<T>* temp = head;
	head = head->pNext;

	delete temp;
	Size--;
}
template<typename T>
void Stack<T>::clear() {
	while (Size) {
		pop_front();
	}
}
template<typename T>
void Stack<T>::push_front(T data) {
	head = new Node<T>(data, head);
	Size++;

}