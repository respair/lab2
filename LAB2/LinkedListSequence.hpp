#pragma once
#include "LinkedList.hpp"

template <class T>
class ListSequence : public Sequence<T>
{
private:
    LinkedList<T> list = LinkedList<T>();
public:
    ListSequence(const T* items, const int count) : Sequence<T>() {
        this->list = LinkedList<T>(items, count);
    }
    ListSequence() {};
    ListSequence(const Sequence<T>* list) : Sequence<T>() {
        int size_new = list->GetSize();
        T* array = new T[size_new];
        for (int i = 0; i < size_new; i++) array[i] = (*list)[i];
        this->list = LinkedList<T>(array, size_new);
        delete[] array;
    }
public:
    T GetFirst() const override {
        return  this->list.GetFirst();
    }

    T GetLast() const override {
        return this->list.GetLast();
    }

    T Get(const int index) const override {
        return this->list.Get(index);
    }
    T& operator [] (const int index) const override
    {
        return this->list[index];
    }
    ListSequence<T>* GetSubList(const int startIndex, const int endIndex) const override {
        ListSequence<T>* newSequence = new ListSequence<T>;
        LinkedList<T> newlist = *(this->list.GetSubList(startIndex, endIndex));
        newSequence->list = newlist;
        return newSequence;
    }
    int GetSize() const override {
        return  this->list.GetSize();
    }
public:
    void Append(const T item) override {
        this->list.Append(item);
    }
    void Prepend(const T item) override {
        this->list.Prepend(item);
    }
    void InsertAt(const T item, const int index) override {
        this->list.InsertAt(item, index);
    }
    ListSequence<T>* Concat(const Sequence<T>* list) override {
        int size = list->GetSize();
        T* array = new T[size];
        for (int i = 0; i < size; i++) array[i] = (*list)[i];
        ListSequence<T>* concat = new ListSequence<T>(array, size);
        concat->list = *(this->list.Concat(&(concat->list)));
        delete[] array;
        return concat;
    }
    ~ListSequence() override = default;
};

