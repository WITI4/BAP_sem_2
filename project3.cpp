template<typename T>
class List {
	template<typename T>
	class Node {
	public:
		Node* pNext;
		T data;
		Node(T data=T(), Node* pNext = nullptr) {
			this->data = data;
			this->pNext = pNext;
		}
	};
	int Size;
	Node<T> *head;
public:
	List();
	~List();
	void push_back(T data);
	int GetSize() { return Size; }
	void bubbleSort();
	T& operator[](const int index);
	void pop_front();
	void clear();
	void push_front(T data);
	void insert(T data, int index);
	void removeAt(int index);
	void pop_back();
};

template<typename T>
List<T>::List() {
	Size = 0;
	head = nullptr;
}
template<typename T>
List<T>::~List() {
	clear();
}
template<typename T>
void List<T>::push_back(T data){
	if (head == nullptr) {
		head = new Node<T>(data);
	}
	else {
		Node<T>* current = this->head;
		while (current->pNext != nullptr) {
			current = current->pNext;
		}
		current->pNext= new Node<T>(data);
	}
	Size++;
}
template<typename T>
T& List<T>::operator[](const int index) {
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
void List<T>::bubbleSort() {
	if (head == nullptr || head->pNext == nullptr) {
		return;
	}

	bool swapped;
	Node<T>* current;
	Node<T>* lastSorted = nullptr;

	do {
		swapped = false;
		current = head;

		while (current->pNext != lastSorted) {
			if (current->data > current->pNext->data) {
				T temp = current->data;
				current->data = current->pNext->data;
				current->pNext->data = temp;
				swapped = true;
			}
			current = current->pNext;
		}
		lastSorted = current;
	} while (swapped);
}
template<typename T>
void List<T>::pop_front() {
	Node<T>* temp = head;
	head = head->pNext;

	delete temp;
	Size--;
}
template<typename T>
void List<T>::clear() {
	while (Size) {
		pop_front();
	}
}
template<typename T>
void List<T>::push_front(T data) {
	head = new Node<T>(data, head);
	Size++;

}
template<typename T>
void List<T>::insert(T data, int index) {
	if (index == 0) {
		pop_front();
	}
	else {
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++) {
			previous = previous->pNext;
		}

		previous->pNext = new Node<T>(data, previous->pNext);

		Size++;
	}
}
template<typename T>
void List<T>::removeAt(int index) {
	if (index == 0) {
		pop_front();
	}
	else {
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++) {
			previous = previous->pNext;
		}

		Node<T>* toDelete = previous->pNext;
		previous->pNext = toDelete->pNext;

		delete toDelete;
		Size--;
	}
}
template<typename T>
void List<T>::pop_back() {
	removeAt(Size - 1);
}