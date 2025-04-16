template<typename T>
class Deque {
	template<typename T>
	class Node {
	public:
		Node* pNext;
		Node* pPrev;
		T data;
		Node(T data = T(), Node* pNext = nullptr, Node* pPrev = nullptr) {
			this->data = data;
			this->pNext = pNext;
			this->pPrev = pPrev;
		}
	};
	int Size;
	Node<T>* head;
	Node<T>* tail;
public:
	Deque();
	~Deque();
	void push_back(T data);
	int GetSize() { return Size; }
	T& operator[](const int index);
	void pop_front();
	void clear();
	void push_front(T data);
	void insert(T data, int index);
	void removeAt(int index);
	void pop_back();
};

template<typename T>
Deque<T>::Deque() {
	Size = 0;
	head = nullptr;
	tail = nullptr;
}
template<typename T>
Deque<T>::~Deque() {
	clear();
}
template<typename T>
void Deque<T>::push_back(T data) {
	if (tail == nullptr) {
		head = tail = new Node<T>(data);
	}
	else {
		tail->pNext = new Node<T>(data, nullptr, tail);
		tail = tail->pNext;
	}
	Size++;
}
template<typename T>
T& Deque<T>::operator[](const int index) {
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
void Deque<T>::pop_front() {
	if (head == nullptr) return;

	Node<T>* toDelete = head;
	head = head->pNext;

	if (head != nullptr) {
		head->pPrev = nullptr;
	}
	else {
		tail = nullptr;
	}

	delete toDelete;
	Size--;
}
template<typename T>
void Deque<T>::clear() {
	while (Size) {
		pop_front();
	}
}
template<typename T>
void Deque<T>::push_front(T data) {
	if (head == nullptr) {
		head = tail = new Node<T>(data);
	}
	else {
		head->pPrev = new Node<T>(data, head, nullptr);
		head = head->pPrev;
	}
	Size++;
}
template<typename T>
void Deque<T>::insert(T data, int index) {
	if (index < 0 || index > Size) return;

	if (index == 0) {
		push_front(data);
	}
	else if (index == Size) {
		push_back(data);
	}
	else {
		Node<T>* current = head;
		for (int i = 0; i < index; i++) {
			current = current->pNext;
		}

		Node<T>* newNode = new Node<T>(data, current, current->pPrev);
		current->pPrev->pNext = newNode;
		current->pPrev = newNode;

		Size++;
	}
}
template<typename T>
void Deque<T>::removeAt(int index) {
	if (index < 0 || index >= Size) return;

	if (index == 0) {
		pop_front();
	}
	else if (index == Size - 1) {
		pop_back();
	}
	else {
		Node<T>* current = head;
		for (int i = 0; i < index; i++) {
			current = current->pNext;
		}

		current->pPrev->pNext = current->pNext;
		current->pNext->pPrev = current->pPrev;

		delete current;
		Size--;
	}
}
template<typename T>
void Deque<T>::pop_back() {
	if (tail == nullptr) return;

	Node<T>* toDelete = tail;
	tail = tail->pPrev;

	if (tail != nullptr) {
		tail->pNext = nullptr;
	}
	else {
		head = nullptr;
	}

	delete toDelete;
	Size--;
}