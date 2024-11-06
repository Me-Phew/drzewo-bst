/**
 * @file binary_search_tree.cpp
 * @author Marcin Dudek & Mateusz Basiaga
 * @brief Binary Search Tree
 * @date 2024-10-23
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <fstream>
#include <string>

#include "binary_search_tree.hpp"
#include <vector>

std::istream& operator>>(std::istream& iStream, BinaryTreeTraversalMethod& traversalMethod) {
    int num;
    iStream >> num;
    traversalMethod = static_cast<BinaryTreeTraversalMethod>(num);

    return iStream;
}

BinarySearchTree::Node* BinarySearchTree::_addItem(Node* node, int value) {
    // Sprawdzenie czy węzeł nie jest pusty
    if (node == nullptr) {
        return new Node(value);
    }
    if (value < node->key) {
        node->left = _addItem(node->left, value);
    } else {
        node->right = _addItem(node->right, value);
    }

    return node;
}

BinarySearchTree::Node* BinarySearchTree::_removeItem(Node* node, int val) {
    if (node == nullptr)
        return nullptr;

    // Jeżeli dana wartość jest mniejsza niż wartość startowa to ląduje do lewej strony drzewa
    if (val < node->key) {
        node->left = _removeItem(node->left, val);
    } else if (val > node->key) {
        // Tak samo jak powyżej tylko ląduje do prawej strony bo jest większa
        node->right = _removeItem(node->right, val);
    } else {
        // Jeżeli dana wartość jest rowna wartości szukanej to usuwamy ten węzeł
        if (node->left == nullptr) {
            Node* temp = node->right;
            delete root;
            return temp;
        } else if (node->right == nullptr) {
            Node* temp = node->left;
            delete root;
            return temp;
        }
    }

    return node;
}

void BinarySearchTree::_removeAllNodes(Node* node) {
    if (node != nullptr) {
        _removeAllNodes(node->left);
        _removeAllNodes(node->right);
        delete node;
    }
}


void BinarySearchTree::_findPathToItem(const Node* node, int value, std::vector<int>& path) const {
    if (node == nullptr) {
        return;
    }
    path.push_back(node->key);
    if (value < node->key) {
        _findPathToItem(node->left, value, path);
    } else if (value > node->key) {
        _findPathToItem(node->right, value, path);
    }
}

void BinarySearchTree::_traversePreorder(Node* node) {
    if (node == nullptr) {
        return;
    }
    std::cout << node->key << " ";
    _traversePreorder(node->left);
    _traversePreorder(node->right);
}

void BinarySearchTree::_traverseInorder(Node* node) {
    if (node == nullptr)
        return;
    _traverseInorder(node->left);
    std::cout << node->key << " ";
    _traverseInorder(node->right);
}

void BinarySearchTree::_traversePostorder(Node* node) {
    if (node == nullptr)
        return;
    _traversePostorder(node->left);
    _traversePostorder(node->right);
    std::cout << node->key << " ";
}

void BinarySearchTree::_saveToTextFile(Node* node, std::ofstream& file) {
    if (node == nullptr) {
        return;
    }
    _saveToTextFile(node->left, file);
    file << node->key << " ";
    _saveToTextFile(node->right, file);
}

BinarySearchTree::BinarySearchTree() : root(nullptr) {}

BinarySearchTree::~BinarySearchTree() { destroy(); }

void BinarySearchTree::addItem(int value) {
    root = _addItem(root, value);
};


void BinarySearchTree::removeItem(int value) {
    root = _removeItem(root, value);
};

void BinarySearchTree::destroy() {
    _removeAllNodes(root);
    root = nullptr;
}

void BinarySearchTree::findPathToItem(int value) {
    std::vector<int> path;
    _findPathToItem(root, value, path);
    for (int key : path) {
        std::cout << key << " ";
    }
    std::cout << std::endl;
};

void BinarySearchTree::display(BinaryTreeTraversalMethod traversalMethod) {
    switch (traversalMethod) {
    case BinaryTreeTraversalMethod::PREORDER:
        _traversePreorder(root);
        break;
    case BinaryTreeTraversalMethod::INORDER:
        _traverseInorder(root);
        break;
    case BinaryTreeTraversalMethod::POSTORDER:
        _traversePostorder(root);
        break;

    }
    std::cout << std::endl;
}

void BinarySearchTree::saveToTextFile(const std::string& filename) {
    std::ofstream file(filename);
    if (file.is_open()) {
        _saveToTextFile(root, file);
        file.close();
    } else {
        std::cerr << "Nie można otworzyć pliku: " << filename << std::endl;
    }
}