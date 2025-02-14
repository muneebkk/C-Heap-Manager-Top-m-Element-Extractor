#pragma once
#include <stdexcept>
#include <algorithm>
#include <iostream>

using std::runtime_error;

template <typename T>
class HeapT {
public:
    explicit HeapT(int capacity);
    HeapT(const HeapT& other);
    ~HeapT();
    HeapT& operator=(const HeapT& other);
    void insert(T value);
    T remove();
    T peek() const;
    HeapT merge(const HeapT& other) const;
    int size() const;
    void print() const;

private:
    T* arr;
    int capacity;
    int count;
    void bubbleUp(int index);
    void bubbleDown(int index);
    void copyFrom(const HeapT& other);
};

// Constructor
template <typename T>
HeapT<T>::HeapT(int capacity) : capacity(capacity), count(0) {
    if (capacity <= 0) {
        throw runtime_error("Capacity must be positive");
    }
    arr = new T[capacity];
}

// Copy constructor
template <typename T>
HeapT<T>::HeapT(const HeapT& other) {
    copyFrom(other);
}

// Destructor
template <typename T>
HeapT<T>::~HeapT() {
    delete[] arr;
}

// Assignment operator
template <typename T>
HeapT<T>& HeapT<T>::operator=(const HeapT& other) {
    if (this != &other) {
        delete[] arr;
        copyFrom(other);
    }
    return *this;
}

// Insert method
template <typename T>
void HeapT<T>::insert(T value) {
    if (count >= capacity) {
        throw runtime_error("Heap is full");
    }
    arr[count++] = value;
    bubbleUp(count - 1);
}

// Remove method
template <typename T>
T HeapT<T>::remove() {
    if (count == 0) {
        throw runtime_error("Heap is empty");
    }
    T root = arr[0];
    arr[0] = arr[--count];
    bubbleDown(0);
    return root;
}

// Peek method
template <typename T>
T HeapT<T>::peek() const {
    if (count == 0) {
        throw runtime_error("Heap is empty");
    }
    return arr[0];
}

// Merge method
template <typename T>
HeapT<T> HeapT<T>::merge(const HeapT& other) const {
    HeapT<T> mergedHeap(capacity + other.capacity);
    for (int i = 0; i < count; ++i) {
        mergedHeap.insert(arr[i]);
    }
    for (int i = 0; i < other.count; ++i) {
        mergedHeap.insert(other.arr[i]);
    }
    return mergedHeap;
}

// Size method
template <typename T>
int HeapT<T>::size() const {
    return count;
}

// Print method for debugging
template <typename T>
void HeapT<T>::print() const {
    std::cout << "Heap elements: ";
    for (int i = 0; i < count; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// Helper methods
template <typename T>
void HeapT<T>::bubbleUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (arr[index] < arr[parent]) {
            std::swap(arr[index], arr[parent]);
            index = parent;
        } else {
            break;
        }
    }
}

template <typename T>
void HeapT<T>::bubbleDown(int index) {
    int leftChild;
    while ((leftChild = 2 * index + 1) < count) {
        int rightChild = leftChild + 1;
        int smallest = leftChild;
        if (rightChild < count && arr[rightChild] < arr[leftChild]) {
            smallest = rightChild;
        }
        if (arr[index] > arr[smallest]) {
            std::swap(arr[index], arr[smallest]);
            index = smallest;
        } else {
            break;
        }
    }
}

template <typename T>
void HeapT<T>::copyFrom(const HeapT& other) {
    capacity = other.capacity;
    count = other.count;
    arr = new T[capacity];
    for (int i = 0; i < count; ++i) {
        arr[i] = other.arr[i];
    }
}
