#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class List {
private:
	template<typename T>
	struct Node
	{
		Node* pNext;
		T data;

		Node(T data = T(), Node* pNext = nullptr) {
			this->data = data;
			this->pNext = pNext;
		}
	};

	int Size;
	Node<T> *head;

public:
	List();

	T& operator[](const size_t ind);

	int getSize();

	~List();

	void pop_front();
	void push_front(T data);
	void insertAt(T data, const size_t index);
	void removeAt(const size_t index);
	void clear();
	void pop_back();
	void push_back(T data);
};

template<typename T>
List<T>::List() {
	this->Size = 0;
	this->head = nullptr;
}

template<typename T>
T& List<T>::operator[](const size_t ind)
{
	Node<T>* current = this->head;
	int counter = 0;

	while (current != nullptr) {

		if (counter == ind) {
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}

template<typename T>
int List<T>::getSize() {
	return this->Size;
}

template<typename T>
List<T>::~List() {
	this->clear();
}

template<typename T>
void List<T>::pop_front()
{
	Node<T>* temp = this->head;
	this->head = head->pNext;

	delete temp;

	this->Size--;
}

template<typename T>
void List<T>::push_front(T data)
{

	if (this->head == nullptr)
	{
		this->head = new Node<T>(data);
	}
	else
	{
		Node<T>* next = this->head;
		Node<T>* newHead = new Node<T>(data, next);
		this->head = newHead;
		
	}

	this->Size++;
}

template<typename T>
void List<T>::insertAt(T data, const size_t index)
{
	if (index == 0) {
		this->push_front(data);
		return;
	}
	else
	{
		Node<T>* prev = this->head->pNext;
		for (auto i = 1; i < index - 1; i++)
			prev = prev->pNext;
		
		Node<T>* newNode = new Node<T>(data, prev->pNext);
		prev->pNext = newNode;
	}
		this->Size++;
}

template<typename T>
void List<T>::removeAt(const size_t index)
{
	if (index == 0) {
		this->pop_front();
		return;
	}
	else
	{
		Node<T>* prev = this->head->pNext;
		
		for (auto i = 1; i < index - 1; i++)
			prev = prev->pNext;

		Node<T>* toDelete = prev->pNext;
		prev->pNext = toDelete->pNext;

		delete toDelete;
	}
	this->Size--;
}

template<typename T>
void List<T>::clear()
{
	while (this->Size)
	{
		this->pop_front();
	}
}

template<typename T>
void List<T>::pop_back()
{
	this->removeAt(this->Size - 1);
}

template<typename T>
void List<T>::push_back(T data) {
	if (this->head == nullptr) 
	{
		this->head = new Node<T>(data);
	}
	else
	{
		Node<T>* current = this->head;
		while (current->pNext != nullptr) {
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
	}

	this->Size++;
}


int main() {

	vector<int> myArr {1,2,3,4,5,3,4,5,56,6};
	vector<int>::iterator i;
	//vector<int>::const_iterator ii;
	i = myArr.begin();
	
	advance(i, 4);
	myArr.insert(i, 999);
	for (vector<int>::iterator i = myArr.begin(); i != myArr.end(); i++)
	{
		cout << *i << endl;
	}
}

