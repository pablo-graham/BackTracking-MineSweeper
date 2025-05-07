//
// Created by Pablo Ruiz on 4/1/25.
//

#ifndef CMAKESFMLPROJECT_BST_H
#define CMAKESFMLPROJECT_BST_H

#include "../TreeNode.h"
#include <initializer_list>
#include <iostream>
#include <queue>
#include <stack>

template <typename T>
class BST {
    TreeNode<T>* root;

    TreeNode<T>* copy(TreeNode<T>* node) const;
    void push(TreeNode<T>*& node, const T& data);
    void pop(TreeNode<T>*& node, const T& data);
    void inorder(TreeNode<T>*& node, void (*f)(T&));
    void preorder(TreeNode<T>*& node, void (*f)(T&));
    void postorder(TreeNode<T>*& node, void (*f)(T&));
    void print_tree(TreeNode<T>*& node, int level);
    void removeMax(TreeNode<T>*& node, T& maxValue);
    void clear(TreeNode<T>*& node);

public:
    BST(std::initializer_list<T>& list);
    BST();
    BST(const BST& tree);
    ~BST();

    // Assignment
    BST& operator=(const BST& tree);

    // Public interface
    void push(const T& data);
    void pop(const T& data);
    T remove(const T& data); // Newly added for consistency
    void clear();
    void print_tree();

    // Traversals
    void inorder(void (*f)(T& data) = [](T& data){ std::cout << data << " "; });
    void preorder(void (*f)(T& data) = [](T& data){ std::cout << data << " "; });
    void postorder(void (*f)(T& data) = [](T& data){ std::cout << data << " "; });
    void breadthorder(void (*f)(T& data) = [](T& data){ std::cout << data << " "; });

    // Object-based function pointer versions
    template<typename U>
    void inorder(void (U::*f)(T& data), U& obj);

    template<typename U>
    void preorder(void (U::*f)(T& data), U& obj);

    template<typename U>
    void postorder(void (U::*f)(T& data), U& obj);

    template<typename U>
    void breadthorder(void (U::*f)(T& data), U& obj);
    
};

#include "BST.cpp"
#endif //CMAKESFMLPROJECT_BST_H
