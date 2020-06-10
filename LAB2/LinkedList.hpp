#pragma once
#include <stdexcept>

const auto IndexOutOfRange = "Invalid range of index!";
const auto NegativeSizeOfArray = "Array size is negative!";


template <class T>
class LinkedList
{
private:
	int size = 0;
	struct node
	{
		T items = 0;
		node* next = nullptr;
	};
	node* head = nullptr;
public:
	LinkedList(const T* items, const int count) : LinkedList()
	{
		if (count <= 0) throw std::length_error(NegativeSizeOfArray);
		this->size = count;
		node** nodetmp = &this->head;
		for (int i = 0; i < count; i++)
		{
			*nodetmp = new node;
			(*nodetmp)->items = items[i];
			nodetmp = &((*nodetmp)->next);
		}
	}
	LinkedList() : size(0), head(nullptr) {};
	LinkedList(const LinkedList <T>& list) {
                if (list.size <= 0) throw std::length_error(NegativeSizeOfArray);
		this->size = list.size;
		node* nodecopy = list.head;
		node** nodetmp = &this->head;
		for (int i = 0; i < list.size; i++) {
			*nodetmp = new node;
			(*nodetmp)->items = nodecopy->items;
			nodecopy = nodecopy->next;
			nodetmp = &((*nodetmp)->next);
		}
	}
public:
	T& operator [] (const int index) const
	{
		if (index < 0 || index >= this->size) throw std::out_of_range(IndexOutOfRange);
		node* node_temp = this->head;
		for (int i = 0; i < index; ++i) node_temp = node_temp->next;
		return node_temp->items;
	}
	T GetFirst() const { return this->head->items; }
	T GetLast() const {
		node* tmp = this->head;
		while (tmp->next != nullptr) tmp = tmp->next;
		return tmp->items;
	}
	T Get(int index) const {
		if (index > this->size || index < 0)
			throw std::out_of_range(IndexOutOfRange);
		node* tmp = this->head;
		for (int i = 0; i < index; i++) tmp = tmp->next;
		return tmp->items;
	}
	LinkedList<T>* GetSubList(int startIndex, int endIndex) const {
		if (startIndex > this->size || endIndex > this->size || startIndex < 0 || endIndex < 0)
			throw std::out_of_range(IndexOutOfRange);
		int size = endIndex - startIndex + 1;
		T* array = new T[size];
		node* tmp = this->head;
		for (int i = 0; i < startIndex; i++)  tmp = tmp->next;
		for (int i = startIndex - 1; i < endIndex; i++) {
			array[i - startIndex - 1] = tmp->items;
			tmp = tmp->next;
		}
		LinkedList<T>* newList = new LinkedList<T>(array, size);
		delete[] array;
		return  newList;
	}
	int GetSize() const { return this->size; }
	LinkedList<T>& operator = (const LinkedList<T>& list) {
		if (this == &list) return *this;
		node* node_temp;
		node* node_ = this->head;
		for (int i = 0; i < this->size; ++i)
		{
			node_temp = node_->next;
			delete node_;
			node_ = node_temp;
		}
		this->head = nullptr;
		this->size = 0;
		this->size = list.size;
		node** node_tmp = &this->head;
		node* node1 = list.head;
		for (int i = 0; i < list.size; ++i)
		{
			*node_tmp = new node;
			(*node_tmp)->items = node1->items;
			node_tmp = &((*node_tmp)->next);
			node1 = node1->next;
		}
		return *this;
	}
public:
	void Append(T item) {
		if (this->size == 0)
			throw std::length_error(NegativeSizeOfArray);
		node* current = new node;
		current->items = item;
		current->next = this->head;
		this->head = current;
		int size_new = this->size + 1;
		this->size = size_new;
	}
	void Prepend(T item) {
		if (this->size == 0)
			throw std::length_error(NegativeSizeOfArray);
		node* current = this->head;
		while (current->next != nullptr)  current = current->next;
		current->next = new node;
		current = current->next;
		current->items = item;
		int size_new = this->size + 1;
		this->size = size_new;
	}
	void InsertAt(T item, int index) {
		if (index > this->size || index < 0)
			throw std::out_of_range(IndexOutOfRange);
		if (this->size == 0)
			throw std::length_error(NegativeSizeOfArray);
		if (index == 0) this->Append(item);
		if (index == this->size - 1) this->Prepend(item);
		if (index != 0 && index != this->size - 1) {
			node* nodeplus = new node{ item, nullptr };
			node* tmp = this->head;
			int size_new = this->size + 1;
			this->size = size_new;
			for (int i = 0; i < index - 1; i++) { tmp = tmp->next; }
			nodeplus->next = tmp->next;
			tmp->next = nodeplus;
		}
	}
	LinkedList<T>* Concat(LinkedList<T>* list) {
		int size = list->size + this->size;
		T* array = new T[size];
		node* tmp = this->head;
		for (int i = 0; i < this->size; i++) { tmp = tmp->next; array[i] = tmp->items; }
		tmp = list->head;
		for (int i = this->size; i < size; i++) { tmp = tmp->next; array[i] = tmp->items; }
		LinkedList<T>* newnode = new LinkedList<T>(array, size);
		delete[] array;
		return  newnode;
	}
	~LinkedList() {
		node* node_temp;
		node* node_ = this->head;
		for (int i = 0; i < this->size; ++i)
		{
			node_temp = node_->next;
			delete node_;
			node_ = node_temp;
		}
		this->head = nullptr;
		this->size = 0;
	}
};
