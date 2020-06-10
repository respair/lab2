#pragma once
#include <stdexcept>

const auto IndexOutOfRange = "Invalid range of index!";
const auto NegativeSizeOfArray = "Array size is negative!";


template <class T>
class DynamicArray
{
private:
	T* items;
	bool* itemsCheck;
	int size;
public:
	DynamicArray(T* items, int count)
	{
		if (count <= 0)
			throw std::length_error(NegativeSizeOfArray);
		this->items = new T[count];
		this->itemsCheck = new bool[count];
		for (int i = 0; i < count; i++) {
			this->itemsCheck[i] = true;
			this->items[i] = items[i];
		}
		this->size = count;
	}

	DynamicArray(const int size)
	{
		if (size <= 0)
			throw std::length_error(NegativeSizeOfArray);
		this->items = new T[size];
		this->itemsCheck = new bool[size];
		for (int i = 0; i < size; i++)
			this->itemsCheck[i] = false;
		this->size = size;
	}

	DynamicArray(const DynamicArray<T>& array)
	{
		if (array.size <= 0)
			throw std::length_error(NegativeSizeOfArray);
		this->size = array.size;
		this->items = new T[array.size];

		for (int i = 0; i < array.size; i++) {
			this->items[i] = array.items[i];
			this->itemsCheck[i] = true;
			if (array.itemsCheck[i] == false) this->itemsCheck[i] = false;
		}
	}
public:
	int GetSize() const { return this->size; }
	T Get(const int index) const
	{
		if (index < 0 || index >= this->size || this->itemsCheck[index] == false)
			throw std::out_of_range(IndexOutOfRange);
		return this->items[index];
	}
public:
	void Set(const int index, const T value)
	{
		if (index < 0 || index >= this->size)
			throw std::out_of_range(IndexOutOfRange);
		this->items[index] = value;
		this->itemsCheck[index] = true;
	}
	void Resize(int newSize)
	{
		if (this->size == 0 || newSize == 0)
			throw std::length_error(NegativeSizeOfArray);
		if (newSize > this->size) {
			T* time = new T[newSize];
			for (int i = 0; i < newSize; i++)
				time[i] = this->items[i];
			delete[] this->items;
			delete[] this->itemsCheck;
			this->items = new T[newSize];
			this->itemsCheck = new bool[newSize];
			for (int i = this->size; i < newSize; i++)
			{
				this->itemsCheck[i] = false;
				if (i < this->size) this->itemsCheck[i] = true;
				this->items[i] = time[i];
			}
			this->size = newSize;
			delete[] time;
		}
		if (newSize == this->size) {
			T* time = new T[newSize];
			for (int i = 0; i < newSize; i++)
				time[i] = this->items[i];
			delete[] this->items;
			delete[] this->itemsCheck;
			this->items = new T[newSize];
			this->itemsCheck = new bool[newSize];
			for (int i = 0; i < newSize; i++) {
				this->items[i] = time[i];
				this->itemsCheck[i] = true;
			}
			this->size = newSize;
			delete[] time;
		}
	}
	~DynamicArray()
	{
		this->size = 0;
		delete[] this->items;
		delete[] this->itemsCheck;
	}
};
