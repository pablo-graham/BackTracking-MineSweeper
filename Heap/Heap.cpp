//
// Created by Pablo Ruiz on 4/23/25.
//

#include "Heap.h"
//

template<typename T>
void Heap<T>::reheapifyUp(int childIndex) {
    while (childIndex > 0) {
        int parentIndex = getParentIndex(childIndex);
        if (tree[childIndex] > tree[parentIndex]) {
            swap(tree[childIndex], tree[parentIndex]);
            childIndex = parentIndex;
        } else {
            break;
        }
    }
}

template<typename T>
void Heap<T>::reheapifyDown(int parentIndex) {
    while (true) {
        int maxChildIndex = getMaxChild(parentIndex);
        if (maxChildIndex != parentIndex && tree[maxChildIndex] > tree[parentIndex]) {
            swap(tree[parentIndex], tree[maxChildIndex]);
            parentIndex = maxChildIndex;
        } else {
            break;
        }
    }
}

template<typename T>
int Heap<T>::getParentIndex(int childIndex) {
    return (childIndex - 1) / 2;
}

template<typename T>
int Heap<T>::getLeftChild(int parentIndex) {
    return (2 * parentIndex) + 1;
}

template<typename T>
int Heap<T>::getRightChild(int parentIndex) {
    return (2 * parentIndex) + 2;
}

template<typename T>
int Heap<T>::getMaxChild(int parentIndex) {
    int left = getLeftChild(parentIndex);
    int right = getRightChild(parentIndex);

    if (left >= size) return parentIndex;   // no children
    if (right >= size) return left;         // only left child

    return (tree[left] > tree[right]) ? left : right;
}

template<typename T>
bool Heap<T>::empty() {
    return size == 0;
}

template<typename T>
int Heap<T>::getSize() {
    return size;
}

template<typename T>
void Heap<T>::push(T data) {
    tree.push_back(data);
    size++;
    reheapifyUp(size - 1);
}

template<typename T>
T Heap<T>::pop() {
    if (empty()) throw runtime_error("Heap is empty");
    T root = tree[0];
    tree[0] = tree[size - 1];
    tree.pop_back();
    size--;
    if (!empty()) reheapifyDown(0);
    return root;
}

template<typename T>
T Heap<T>::top() {
    if (empty()) throw runtime_error("Heap is empty");
    return tree[0];
}