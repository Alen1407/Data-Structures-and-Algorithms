#ifndef BENCHMAKER_VECTOR_H
#define BENCHMAKER_VECTOR_H
#include <iostream>
#include <stdexcept>

template<typename T>
class Vector {
private:
    T* elements;
    size_t capacity;
    size_t size;

public:
    Vector() : elements(nullptr), capacity(0), size(0) {}

    explicit Vector(size_t initialCapacity) : capacity(initialCapacity), size(0) {
        elements = new T[capacity];
    }

    ~Vector() {
        delete[] elements;
    }

    size_t getSize() const {
        return size;
    }

    bool isEmpty() const {
        return size == 0;
    }

    void pushBack(const T& value) {
        if (size == capacity) {
            expandCapacity();
        }
        elements[size++] = value;
    }

    T& operator[](size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return elements[index];
    }

    void deleteElement(size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        for (size_t i = index; i < size - 1; i++) {
            elements[i] = elements[i + 1];
        }
        size--;
    }

    int searchElement(const T& value){
        for(int i = 0; i < this->size; i++){
            if(elements[i] == value){
                return i;
            }
        }

        return -1;
    }

private:
    void expandCapacity() {
        size_t newCapacity = capacity == 0 ? 1 : capacity * 2;
        T* newElements = new T[newCapacity];
        for (size_t i = 0; i < size; i++) {
            newElements[i] = elements[i];
        }
        delete[] elements;
        elements = newElements;
        capacity = newCapacity;
    }
};


#endif //BENCHMAKER_VECTOR_H
