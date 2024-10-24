/**
 * @file BSTree.cpp
 * @author Marcin & Mateusz
 * @brief Binary Search Tree
 * @version 0.1
 * @date 2024-10-23
 *
 * @copyright Copyright (c) 2024
 *
 */

#include <iostream>
#include <fstream>
#include <string>
#include "BST.h"

using namespace std;

int liczba;

BSTree::BSTree() : root(nullptr) {}
BSTree::~BSTree() { delBST(); }

void BSTree::addElement(int val)
{
    root = addElement(root, val);
};

BSTree::Node *BSTree::addElement(Node *node, int val)
{
    // Sprawdzenie czy węzeł nie jest pusty
    if (node == nullptr)
    {
        return new Node(val);
    }
    if (val < node->key)
    {
        node->left = addElement(node->left, val);
    }
    else
    {
        node->right = addElement(node->right, val);
    }
    return node;
}

void BSTree::delElement(int val)
{
    root = delElement(root, val);
};

BSTree::Node *BSTree::delElement(Node *node, int val)
{
    if (node == nullptr)
        return nullptr;
    // Jeżeli dana wartość jest mniejsza niż wartość startowa to ląduje do lewej strony drzewa
    if (val < node->key)
    {
        node->left = delElement(node->left, val);
    }
    // Tak samo jak powyżej tylko ląduje do prawej strony bo jest większa
    else if (val > node->key)
    {
        node->right = delElement(node->right, val);
    }
    // Jeżeli dana wartość jest rowna wartości szukanej to usuwamy ten węzeł
    else
    {
        if (node->left == nullptr)
        {
            Node *temp = node->right;
            delete root;
            return temp;
        }
        else if (node->right == nullptr)
        {
            Node *temp = node->left;
            delete root;
            return temp;
        }
    }
}

void BSTree::delBST()
{
    delBST(root);
    root = nullptr;
}

void BSTree::delBST(Node *node)
{
    if (node != nullptr)
    {
        delBST(node->left);
        delBST(node->right);
        delete node;
    }
}
void BSTree::searchPath(int val) {

};

void BSTree::preorderBST()
{
    preorderBST(root);
    cout << endl;
};

void BSTree::postorderBST(Node *node)
{
    if (node == nullptr)
        return;
    cout << node->key << " ";
    postorderBST(node->left);
    postorderBST(node->right);
}

void BSTree::inorderBST()
{
    inorderBST(root);
    cout << endl;
};

void BSTree::inorderBST(Node *node)
{
    if (node == nullptr)
        return;
    inorderBST(node->left);
    cout << node->key << " ";
    inorderBST(node->right);
}

void BSTree::postorderBST()
{
    postorderBST(root);
    cout << endl;
};

void BSTree::inorderBST(Node *node)
{
    if (node == nullptr)
        return;
    inorderBST(node->left);
    inorderBST(node->right);
    cout << node->key << " ";
}


void BST::saveBST(const string &filename)
{
    ofstream file(filename);
    if (file.is_open())
    {
        
    }
}
