//
// Created by Pablo Ruiz on 4/9/25.
//

#ifndef CMAKESFMLPROJECT_AVL_H
#define CMAKESFMLPROJECT_AVL_H

#include "../TreeNode.h"
#include <initializer_list>
#include <iostream>
#include <queue>
#include <functional>

enum class Traversal {
    INORDER,
    PREORDER,
    POSTORDER
};

template<typename T>
class AVL {
private:
    TreeNode<T>* _root;
    Traversal _mode;

    // Internal utilities
    TreeNode<T>* copy(TreeNode<T>* node) const;
    void clear(TreeNode<T>*& node);
    int height(TreeNode<T>* node);
    void updateHeight(TreeNode<T>* node);
    int getBalance(TreeNode<T>* node);
    TreeNode<T>* rotateLeft(TreeNode<T>* node);
    TreeNode<T>* rotateRight(TreeNode<T>* node);

    TreeNode<T>* insert(TreeNode<T>* node, const T& data);
    TreeNode<T>* remove(TreeNode<T>* node, const T& data);

    void inorder(TreeNode<T>* node, std::function<void(T&)> f);
    void preorder(TreeNode<T>* node, std::function<void(T&)> f);
    void postorder(TreeNode<T>* node, std::function<void(T&)> f);

public:
    AVL();
    AVL(const AVL<T>& other);
    AVL& operator=(const AVL<T>& other);
    ~AVL();

    void push(const T& data);
    T remove(const T& data);
    void clear();

    void setTraversalOrder(Traversal mode);
    void print(void (*f)(T& data) = [](T& data) { std::cout << data << " "; });

    void printTree();
};

#include "AVL.cpp"
#endif //CMAKESFMLPROJECT_AVL_H
