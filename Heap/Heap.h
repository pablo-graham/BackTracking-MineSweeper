//
// Created by Pablo Ruiz on 4/23/25.
//

#ifndef MALENATEST_HEAP_H
#define MALENATEST_HEAP_H
#include <vector>
#include <iostream>
#include <cassert>

using namespace std;
template <typename T>
class Heap {
    struct TreeCompare{
        bool operator()(const T& lhs, const T& rhs){
            return lhs < rhs;
        }
    };

private:
    vector<T> tree;
    int size;


public:
    Heap() : size(0){}
    void reheapifyUp(int childIndex);    //comparing child with parent
    void reheapifyDown(int parentIndex); // if parent val is < child val, find index of child with greatest value and swap

    int getParentIndex(int childIndex);
    int getLeftChild(int parentIndex);
    int getRightChild(int parentIndex);
    int getMaxChild(int parentIndex);   //return the index of the child index value is the greatest if no child return parent index
    bool empty();
    int getSize();

    void push(T data); // add data to the back of the array, call reheapifyUp(size() - 1)
    T pop(); //swap root with the last index, reheapifyDown(root)
    T top(); // return value at root

};

#include "Heap.cpp"

#endif //MALENATEST_HEAP_H
