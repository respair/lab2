#pragma once
#include <iostream>
#include <stdexcept>
#include "Sequence.hpp"
#include "LinkedListSequence.hpp"


template <class T>
class Polynom
{
private:
    Sequence<T>* a = nullptr;   // a -  coefficient before X
    int size = 0;
public:
    Polynom(const int size)
    {
        T* tmp = new T[size];
        for (int i = 0; i < size; i++) tmp[i] = 0;
        this->a = new ListSequence<T>(tmp, size);
        this->size = size;
    }
    Polynom(const T* items, const int count)
    {
        this->a = new ListSequence<T>(items, count);
        this->size = count;
    }
    Polynom(const Polynom<T>& array)
    {
        this->a = array.a;
        this->size = array.GetSize();
    }
public:
    Polynom<T> AddPoly(const Polynom<T>& poly2)
    {
        if (this->GetSize() <= 0 || poly2.GetSize() <= 0)
            throw std::length_error(NegativeSizeOfArray);
        int sumsize;
        if (this->GetSize() > poly2.GetSize())
            sumsize = this->GetSize();
        else
            sumsize = poly2.GetSize();
        Polynom<T> array2(sumsize);
        if (sumsize == this->GetSize()) {

            for (int i = 0; i < poly2.GetSize(); i++) (*array2.a)[i] = (*this->a)[i] + (*poly2.a)[i];
            for (int i = poly2.GetSize(); i < sumsize; i++) (*array2.a)[i] = (*this->a)[i];
        }
        else {

            for (int i = 0; i < this->GetSize(); i++) (*array2.a)[i] = (*poly2.a)[i] + (*this->a)[i];
            for (int i = this->GetSize(); i < sumsize; i++) (*array2.a)[i] = (*poly2.a)[i];
        }
        return array2;
    }

    Polynom<T> SubPoly(const Polynom<T>& poly2) {
        if (this->GetSize() <= 0 || poly2.GetSize() <= 0)
            throw std::length_error(NegativeSizeOfArray);
        int sumsize;
        if (this->GetSize() > poly2.GetSize())
            sumsize = this->GetSize();
        else
            sumsize = poly2.GetSize();
        // std::cout << sumsize << std::endl;
        Polynom<T> array2(sumsize);
        if (sumsize == this->GetSize()) {

            for (int i = 0; i < poly2.GetSize(); i++) (*array2.a)[i] = (*this->a)[i] - (*poly2.a)[i];
            for (int i = poly2.GetSize(); i < sumsize; i++) (*array2.a)[i] = (*this->a)[i];
        }
        else {
            for (int i = 0; i < this->GetSize(); i++)  (*array2.a)[i] = (*this->a)[i] - (*poly2.a)[i];
            for (int i = this->GetSize(); i < sumsize; i++) (*array2.a)[i] = -(*poly2.a)[i];
        }
        return array2;
    }
    T GetRezult(T* array)
    {
        if (this->GetSize() <= 0)
            throw std::length_error(NegativeSizeOfArray);
        T rezult = (*this->a)[0];
        for (int i = 1; i < this->GetSize(); i++) rezult = rezult + (*this->a)[i] * array[i - 1];
        return rezult;
    }
    T Get(const int index) const
    {
        return (*this->a)[index];
    }
    bool operator == (const Polynom<T> poly1) {

        if (this->GetSize() == poly1.GetSize())
        {
            for (int i = 0; i < poly1.GetSize(); i++) {
                T tmp1 = poly1.Get(i);
                T tmp2 = this->Get(i);
                if (tmp1 != tmp2)
                    return false;
            }
            return true;
        }
        else return false;
    }
public:
    void ScalarPoly(T count)
    {
        if (this->GetSize() <= 0)
            throw std::length_error(NegativeSizeOfArray);
        for (int i = 0; i < this->size; i++) (*this->a)[i] = count * (*this->a)[i];
    }
    void Show()
    {
        if (this->GetSize() <= 0)
            throw std::length_error(NegativeSizeOfArray);
        //std::cout << this->GetSize() << std::endl;
        for (int i = 0; i < this->size; i++)
        {
            if (i == 0) {
                std::cout << std::endl;
                std::cout << (*this->a)[i];
            }
            else if ((*this->a)[i] != T(0)) std::cout << "+" << "(" << (*this->a)[i] << ")" << "*x" << i;
        }
        std::cout << std::endl;
    }
    int GetSize() const { return this->a->GetSize(); }
};
