//
// Created by Pablo Ruiz on 4/9/25.
//

#include "AVL.h"
#include <algorithm>

template<typename T>
AVL<T>::AVL() : _root(nullptr), _mode(Traversal::INORDER) {}

template<typename T>
AVL<T>::AVL(const AVL<T>& other) {
    _root = copy(other._root);
    _mode = other._mode;
}

template<typename T>
AVL<T>& AVL<T>::operator=(const AVL<T>& other) {
    if (this != &other) {
        clear(_root);
        _root = copy(other._root);
        _mode = other._mode;
    }
    return *this;
}

template<typename T>
AVL<T>::~AVL() {
    clear();
}

template<typename T>
TreeNode<T>* AVL<T>::copy(TreeNode<T>* node) const {
    if (!node) return nullptr;
    return new TreeNode<T>(
            node->_item,
            copy(node->_left),
            copy(node->_right)
    );
}

template<typename T>
void AVL<T>::clear(TreeNode<T>*& node) {
    if (!node) return;
    clear(node->_left);
    clear(node->_right);
    delete node;
    node = nullptr;
}

template<typename T>
void AVL<T>::clear() {
    clear(_root);
    _root = nullptr;
}

template<typename T>
int AVL<T>::height(TreeNode<T>* node) {
    if (!node) return 0;
    return 1 + std::max(height(node->_left), height(node->_right));
}

template<typename T>
void AVL<T>::updateHeight(TreeNode<T>* node) {
    if (!node) return;
    int leftH = node->_left ? height(node->_left) : 0;
    int rightH = node->_right ? height(node->_right) : 0;
    node->_height = 1 + std::max(leftH, rightH);
}

template<typename T>
int AVL<T>::getBalance(TreeNode<T>* node) {
    return node ? height(node->_left) - height(node->_right) : 0;
}

template<typename T>
TreeNode<T>* AVL<T>::rotateRight(TreeNode<T>* y) {
    TreeNode<T>* x = y->_left;
    TreeNode<T>* T2 = x->_right;

    x->_right = y;
    y->_left = T2;

    return x;
}

template<typename T>
TreeNode<T>* AVL<T>::rotateLeft(TreeNode<T>* x) {
    TreeNode<T>* y = x->_right;
    TreeNode<T>* T2 = y->_left;

    y->_left = x;
    x->_right = T2;

    return y;
}

template<typename T>
TreeNode<T>* AVL<T>::insert(TreeNode<T>* node, const T& data) {
    if (!node) return new TreeNode<T>(data);

    if (data < node->_item)
        node->_left = insert(node->_left, data);
    else if (data > node->_item)
        node->_right = insert(node->_right, data);
    else
        return node; // no duplicates

    updateHeight(node);
    int balance = getBalance(node);

    if (balance > 1 && data < node->_left->_item)
        return rotateRight(node);

    if (balance < -1 && data > node->_right->_item)
        return rotateLeft(node);

    if (balance > 1 && data > node->_left->_item) {
        node->_left = rotateLeft(node->_left);
        return rotateRight(node);
    }

    if (balance < -1 && data < node->_right->_item) {
        node->_right = rotateRight(node->_right);
        return rotateLeft(node);
    }

    return node;
}

template<typename T>
void AVL<T>::push(const T& data) {
    _root = insert(_root, data);
}

template<typename T>
TreeNode<T>* minValueNode(TreeNode<T>* node) {
    TreeNode<T>* current = node;
    while (current->_left)
        current = current->_left;
    return current;
}

template<typename T>
TreeNode<T>* AVL<T>::remove(TreeNode<T>* node, const T& data) {
    if (!node) return nullptr;

    if (data < node->_item)
        node->_left = remove(node->_left, data);
    else if (data > node->_item)
        node->_right = remove(node->_right, data);
    else {
        if (!node->_left || !node->_right) {
            TreeNode<T>* temp = node->_left ? node->_left : node->_right;
            delete node;
            return temp;
        } else {
            TreeNode<T>* temp = minValueNode(node->_right);
            node->_item = temp->_item;
            node->_right = remove(node->_right, temp->_item);
        }
    }

    updateHeight(node);
    int balance = getBalance(node);

    if (balance > 1 && getBalance(node->_left) >= 0)
        return rotateRight(node);

    if (balance > 1 && getBalance(node->_left) < 0) {
        node->_left = rotateLeft(node->_left);
        return rotateRight(node);
    }

    if (balance < -1 && getBalance(node->_right) <= 0)
        return rotateLeft(node);

    if (balance < -1 && getBalance(node->_right) > 0) {
        node->_right = rotateRight(node->_right);
        return rotateLeft(node);
    }

    return node;
}

template<typename T>
T AVL<T>::remove(const T& data) {
    T removed = data;
    _root = remove(_root, data);
    return removed;
}

template<typename T>
void AVL<T>::inorder(TreeNode<T>* node, std::function<void(T&)> f) {
    if (!node) return;
    inorder(node->_left, f);
    f(node->_item);
    inorder(node->_right, f);
}

template<typename T>
void AVL<T>::preorder(TreeNode<T>* node, std::function<void(T&)> f) {
    if (!node) return;
    f(node->_item);
    preorder(node->_left, f);
    preorder(node->_right, f);
}

template<typename T>
void AVL<T>::postorder(TreeNode<T>* node, std::function<void(T&)> f) {
    if (!node) return;
    postorder(node->_left, f);
    postorder(node->_right, f);
    f(node->_item);
}

template<typename T>
void AVL<T>::setTraversalOrder(Traversal mode) {
    _mode = mode;
}

template<typename T>
void AVL<T>::print(void (*f)(T&)) {
    std::function<void(T&)> func(f);

    switch (_mode) {
        case Traversal::INORDER:
            inorder(_root, func);
            break;
        case Traversal::PREORDER:
            preorder(_root, func);
            break;
        case Traversal::POSTORDER:
            postorder(_root, func);
            break;
    }

    std::cout << std::endl;
}

template<typename T>
void printTreeRecursive(TreeNode<T>* node, int depth = 0) {
    if (!node) return;

    printTreeRecursive(node->_right, depth + 1);

    for (int i = 0; i < depth; ++i)
        std::cout << "    ";
    std::cout << node->_item << std::endl;

    printTreeRecursive(node->_left, depth + 1);
}

template<typename T>
void AVL<T>::printTree() {
    std::cout << "\n=== Tree Structure ===\n";

    auto prnt = [&](auto&& prnt, TreeNode<T>* node, int depth){
        if (!node) return;

        prnt(prnt, node->_right, depth + 1);

        for (int i = 0; i < depth; ++i)
            std::cout << "    ";
        std::cout << node->_item << std::endl;

        prnt(prnt, node->_left, depth + 1);
    };

    //prnt(prnt, _root, 0);
    printTreeRecursive(_root);
}