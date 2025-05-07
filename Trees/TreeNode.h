//
// Created by Pablo Ruiz on 4/1/25.
//

#ifndef CMAKESFMLPROJECT_TREENODE_H
#define CMAKESFMLPROJECT_TREENODE_H

#include <iostream>
#include <iomanip>

using namespace std;

template <typename T>
struct TreeNode{
public:
    TreeNode(const T& item= T(), TreeNode<T>* left = nullptr, TreeNode<T>* right = nullptr):_item(item), _left(left), _right(right){
    }

    friend ostream& operator <<(ostream& outs, const TreeNode<T> n){
        outs<<"["<< n._item <<"]-> ";
        return outs;
    }

    int _height;
    T _item;
    TreeNode<T> *_left, *_right;
};

#endif //CMAKESFMLPROJECT_NODE_H
