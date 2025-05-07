//
// Created by Pablo Ruiz on 4/3/25.
//
#ifndef BST_CPP
#define BST_CPP
#include "BST.h"

template<typename T>
TreeNode<T>* BST<T>::copy(TreeNode<T>* node) const {
    if (node == nullptr) return nullptr;

    TreeNode<T>* new_root = new TreeNode<T>();
    new_root->_item = node->_item;
    new_root->_left = copy(node->_left);
    new_root->_right = copy(node->_right);
    return new_root;
}

template<typename T>
void BST<T>::push(TreeNode<T>*& node, const T& data) {
    if (node == nullptr) {
        node = new TreeNode<T>();
        node->_item = data;
    } else if (data <= node->_item) {
        push(node->_left, data);
    } else {
        push(node->_right, data);
    }
}

template<typename T>
void BST<T>::inorder(TreeNode<T>*& node, void(*f)(T&)) {
    if (node == nullptr) return;
    inorder(node->_left, f);
    f(node->_item);
    inorder(node->_right, f);
}

template<typename T>
void BST<T>::preorder(TreeNode<T>*& node, void(*f)(T&)) {
    if (node == nullptr) return;
    f(node->_item);
    preorder(node->_left, f);
    preorder(node->_right, f);
}

template<typename T>
void BST<T>::postorder(TreeNode<T>*& node, void(*f)(T&)) {
    if (node == nullptr) return;
    postorder(node->_left, f);
    postorder(node->_right, f);
    f(node->_item);
}

template<typename T>
void BST<T>::pop(TreeNode<T>*& node, const T& data) {
    if (node == nullptr) return;

    if (node->_item < data) {
        pop(node->_right, data);
    } else if (node->_item > data) {
        pop(node->_left, data);
    } else {
        if (node->_left != nullptr) {
            removeMax(node->_left, node->_item);
        } else {
            TreeNode<T>* temp = node;
            node = node->_right;
            delete temp;
        }
    }
}

template<typename T>
void BST<T>::print_tree(TreeNode<T>*& node, int level) {
    if (node != nullptr) {
        print_tree(node->_right, level + 1);
        for (int i = 0; i < level; i++) std::cout << "   ";
        std::cout << node->_item << std::endl;
        print_tree(node->_left, level + 1);
    }
}

template<typename T>
void BST<T>::removeMax(TreeNode<T>*& node, T& maxValue) {
    if (node != nullptr) {
        if (node->_right != nullptr) {
            removeMax(node->_right, maxValue);
        } else {
            TreeNode<T>* temp = node;
            node = node->_left;
            maxValue = temp->_item;
            delete temp;
        }
    }
}

template<typename T>
BST<T>::BST(std::initializer_list<T>& list) {
    root = nullptr;
    for (const T& item : list) {
        push(item);
    }
}

template<typename T>
BST<T>::BST() {
    root = nullptr;
}

template<typename T>
BST<T>::BST(const BST& tree) {
    root = copy(tree.root);
}

template<typename T>
BST<T>::~BST() {
    clear(root);
}

template<typename T>
BST<T>& BST<T>::operator=(const BST& tree) {
    if (this != &tree) {
        clear(root);
        root = copy(tree.root);
    }
    return *this;
}

template<typename T>
void BST<T>::push(const T& data) {
    push(root, data);
}

template<typename T>
void BST<T>::pop(const T& data) {
    pop(root, data);
}

template<typename T>
T BST<T>::remove(const T& data) {
    T removed = data;
    pop(root, data);
    return removed;
}

template<typename T>
void BST<T>::inorder(void(*f)(T&)) {
    inorder(root, f);
}

template<typename T>
template<typename U>
void BST<T>::inorder(void(U::*f)(T&), U& obj) {
    auto func = [&](T& data) { (obj.*f)(data); };
    inorder(func);
}

template<typename T>
void BST<T>::preorder(void(*f)(T&)) {
    preorder(root, f);
}

template<typename T>
template<typename U>
void BST<T>::preorder(void(U::*f)(T&), U& obj) {
    auto func = [&](T& data) { (obj.*f)(data); };
    preorder(func);
}

template<typename T>
void BST<T>::postorder(void(*f)(T&)) {
    postorder(root, f);
}

template<typename T>
template<typename U>
void BST<T>::postorder(void(U::*f)(T&), U& obj) {
    auto func = [&](T& data) { (obj.*f)(data); };
    postorder(func);
}

template<typename T>
void BST<T>::breadthorder(void(*f)(T&)) {
    std::queue<TreeNode<T>*> q;
    if (root) q.push(root);
    while (!q.empty()) {
        TreeNode<T>* node = q.front(); q.pop();
        if (node != nullptr) {
            f(node->_item);
            q.push(node->_left);
            q.push(node->_right);
        }
    }
}

template<typename T>
template<typename U>
void BST<T>::breadthorder(void(U::*f)(T&), U& obj) {
    std::queue<TreeNode<T>*> q;
    if (root) q.push(root);
    while (!q.empty()) {
        TreeNode<T>* node = q.front(); q.pop();
        if (node != nullptr) {
            (obj.*f)(node->_item);
            q.push(node->_left);
            q.push(node->_right);
        }
    }
}

template<typename T>
void BST<T>::clear(TreeNode<T>*& node) {
    if (node != nullptr) {
        clear(node->_left);
        clear(node->_right);
        delete node;
        node = nullptr;
    }
}

template<typename T>
void BST<T>::clear() {
    clear(root);
}

template<typename T>
void BST<T>::print_tree() {
    print_tree(root, 0);
}

#endif  //BST