// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_
#include <string>
#include <iostream>

template<typename T, int size>
class TStack {
 private:
    T *arr;
    int tIndex;

 public:
    TStack() {
        arr = new T[size];
        tIndex = -1;
    }
    void push(T value) {
        if (isFull()) {
             std::cout << "Stack is Full!" << "\n";
        } else {
            arr[++tIndex] = value;
        }
    }
    T& pop() {
        if (isEmpty()) {
            std::cout << "Stack is Empty!" << "\n";
            return -1;
        } else {
            return arr[tIndex--];
        }
    }
    bool isEmpty() const {
        return tIndex == -1;
    }
    bool isFull() const {
        return tIndex == size;
    }
    T& get() const {
        if (isEmpty()) {
            std::cout << "Stack is Empty!" << "\n";
             return -1;
        } else {
            return arr[tIndex];
        }
    }
};

#endif  // INCLUDE_TSTACK_H_
