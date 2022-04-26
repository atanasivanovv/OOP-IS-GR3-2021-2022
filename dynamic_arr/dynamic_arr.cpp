#include "dynamic_arr.h"

void DynamicArray::copy(const DynamicArray& other) {
    this->capacity = other.capacity;
    this->size = other.size;

    this->data = new int[this->capacity];   // deep copy

    for (int i = 0; i < this->size; i++) {
        this->data[i] = other.data[i];
    }
}

void DynamicArray::erase() {
    delete[] this->data;
}

void DynamicArray::resize() {
    if (this->size >= this->capacity) {
        this->capacity *= 2;
    }  

    // store data in bigger buffer
    int* bigger = new int[this->capacity];

    // copy all data from previous buffer
    for (int i = 0; i < this->size; i++) {
        bigger[i] = this->data[i];
    }

    // free alocated memory of this->data and set pointer to bigger
    this->erase();
    this->data = bigger;
}

DynamicArray::DynamicArray() {
    this->size = 0;
    this->capacity = 8;
    this->data = new int[this->capacity];
}

DynamicArray::DynamicArray(const DynamicArray& other) {
    this->copy(other);
}

DynamicArray& DynamicArray::operator=(const DynamicArray& other) {
    if (this != &other) {
        this->erase();
        this->copy(other);
    }

    return *this;
}

bool DynamicArray::operator==(const DynamicArray& other) {
    if (this->size != other.getSize()) {
        return false;
    }

    for (int i = 0; i < this->size; i++) {
        if (this->data[i] != other.data[i]) {
            return false;
        }
    }

    return true;
}

bool DynamicArray::operator!=(const DynamicArray& other) {
    return !(this == &other);
}

const int& DynamicArray::operator[](int i) const {
    return this->data[i];
} 

int& DynamicArray::operator[](int i) {
    return this->data[i];
} 

// [1,2,3] + [4,5,6] = [1,2,3,4,5,6] - this one
// [1,2,3] + [4,5,6] = [5,7,9]
// [1,2,3,4] + [4,5,6] 
DynamicArray DynamicArray::operator+(const DynamicArray& other) {
    DynamicArray result; // size 0, capacity = 8

    result.capacity = this->capacity + other.capacity; 
    result.data = new int[result.capacity]; // capacity = 15

    // [_, _, _, _, _, _, _, _]
    for (int i = 0; i < this->size; i++) {
        result[i] = this->data[i];   
    }

    // [1,2,3,4, _, _, _, _]
    for (int i = 0; i < other.size; i++) {
        result[this->size + i] = other[i];
    }

    result.size = this->size + other.size;
    return result;
}

DynamicArray::~DynamicArray() {
    this->erase();
}

int DynamicArray::getSize() const {
    return this->size;
}

int DynamicArray::getCapacity() const {
    return this->capacity;
}

int DynamicArray::getAtIndex(const int index) const {
    if (index < size) {
        return this->data[index];
    }

    return 0;
}

void DynamicArray::push_back(const int& element) {
    this->resize(); // resizes only if size is bigger than capacity 
    
    this->data[this->size] = element;
    this->size++;
}

void DynamicArray::push_front(const int& element) {
    this->resize();

    int* bigger = new int[this->size + 1];
    for (int i = 0; i < this->size; i++) {
        bigger[i+1] = this->data[i];
    }

    this->size++;
    bigger[0] = element;
    this->erase();
    this->data = bigger;
}

void DynamicArray::pop_front() {
    int* smaller = new int[this->size - 1];

    for (int i = 0; i < this->size - 1; i++) {
        smaller[i] = data[i+1];
    }

    this->size--;
    this->erase();
    this->data = smaller;
}

void DynamicArray::pop_back() {
    if (this->size > 0) 
        this->size--;

    // this->size--;
    // int* smaller = new int[this->size];

    // for (int i = 0; i < this->size; i++) {
    //     smaller[i] = this->data[i];
    // }

    // this->erase();
    // this->data = smaller;
}

void DynamicArray::print() const {
    for (int i = 0; i < this->size; i++) {
        std::cout << this->data[i] << " ";
    }
    std::cout << std::endl;
}
