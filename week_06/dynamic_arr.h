#ifndef DYNAMIC_ARR_H
#define DYNAMIC_ARR_H

#include <iostream>
// #include <cassert> - discuss assert next time

class DynamicArray {
    int* data;
    int size;
    int capacity;

    void copy(const DynamicArray& other);
    void erase();
    void resize();
public:
    DynamicArray();
    DynamicArray(const DynamicArray& other);
    DynamicArray& operator=(const DynamicArray& other);
    bool operator==(const DynamicArray& other);
    bool operator!=(const DynamicArray& other);
    const int& operator[](int index) const; 
    int& operator[](int index); 
    DynamicArray operator+(const DynamicArray& other);

    ~DynamicArray();

    int getSize() const;
    int getCapacity() const;
    int getAtIndex(const int index) const;
    // void setAtIndex(const int index, const int element);
    void print() const;

    void push_back(const int& element);
    void push_front(const int& element);
    void pop_front();
    void pop_back();
};

#endif