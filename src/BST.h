/**
 * @file BSTree.h
 * @author Marcin & Mateusz
 * @brief Binary Search Tree
 * @version 0.1
 * @date 2024-10-23
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef BST
#define BST

#include <iostream>
using namespace std;

class BSTree
{
private:

    /**
     * @brief Utworzenie Węzła
     * 
     */
    struct Node{
        int key;
        Node* left;
        Node* right;
        Node(int value){
            key = value;
            left = right = nullptr;
        }
    };

    Node* root;

    Node* addElement(Node* node,int value);
    Node* delElement(Node* node,int value);
    void delBST(Node* node);
    void searchPath(Node* node,int value);
    void preorderBST(Node* node);
    void inorderBST(Node* node);
    void postorderBST(Node* node);
    void saveBST(Node* node);
    
public:
    BSTree();
    ~BSTree();

    /**
     * @brief Dodanie elementu do drzewa
     *
     * @param value
     */
    void addElement(int value);

    /**
     * @brief Usunięcie elementu z drzewa
     *
     * @param value
     */
    void delElement(int value);

    /**
     * @brief Usunięcie całego drzewa
     *
     */
    void delBST();

    /**
     * @brief Szukanie drogi do podanego elementu w drzewie
     *
     * @param value
     */
    void searchPath(int value);

    /**
     * @brief Wyświetlenie w metodzie Preorder
     * 
     */
    void preorderBST();

    /**
     * @brief Wyświetlenie w metodzie Inorder
     * 
     */
    void inorderBST();

    /**
     * @brief Wyświetlenie w metodzie Postorder
     * 
     */
    void postorderBST();

    /**
     * @brief Zapisuje wygenerowane drzewo do pliku tekstowego
     *
     */
    void saveBST();

};

#endif