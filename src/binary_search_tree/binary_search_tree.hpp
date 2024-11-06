/**
 * @file binary_search_tree.hpp
 * @author Marcin Dudek & Mateusz Basiaga
 * @brief Binary Search Tree
 * @date 2024-10-23
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

enum BinaryTreeTraversalMethod {
  PREORDER = 1,
  INORDER,
  POSTORDER
};

/// @brief Przeciążenie operatora >> do wyboru opcji.
/// @param iStream Strumień wejściowy.
/// @param traversalMethod Enum, który należy ustawić.
/// @return Referencja do strumienia wejściowego.
std::istream& operator>>(std::istream& iStream, BinaryTreeTraversalMethod& traversalMethod);


class BinarySearchTree {
private:

  /**
   * @brief Utworzenie Węzła
   *
   */
  struct Node {
    int key;
    Node* left;
    Node* right;

    explicit Node(int value) {
      key = value;
      left = right = nullptr;
    }
  };

  Node* root;

  Node* _addItem(Node* node, int value);
  Node* _removeItem(Node* node, int value);

  void _removeAllNodes(Node* node);
  void _findPathToItem(const Node* node, int value, std::vector<int>& path) const;
  void _traversePreorder(Node* node);
  void _traverseInorder(Node* node);
  void _traversePostorder(Node* node);
  void _saveToTextFile(Node* node, std::ofstream& file);
  void _loadFromTextFile(Node* node, std::ofstream& file);
  void _saveToBinaryFile(const Node* node, std::ofstream& file) const;
  void _loadFromBinaryFile(Node* node, std::ofstream& file);

public:
  BinarySearchTree();
  ~BinarySearchTree();

  /**
   * @brief Dodanie elementu do drzewa
   *
   * @param value
   */
  void addItem(int value);

  /**
   * @brief Usunięcie elementu z drzewa
   *
   * @param value
   */
  void removeItem(int value);

  /**
   * @brief Usunięcie całego drzewa
   *
   */
  void destroy();

  /**
   * @brief Szukanie drogi do podanego elementu w drzewie
   *
   * @param value
   */
  void findPathToItem(int value);

  /**
   * @brief Wyświetlenie drzewa
   * 
   * @param traversalMethod 
   */
  void display(BinaryTreeTraversalMethod traversalMethod);

  /**
   * @brief Zapisuje wygenerowane drzewo do pliku tekstowego
   *
   * @param filename
   */
  void saveToTextFile(const std::string& filename);

  /**
   * @brief Wczytanie drzewa z pliku tekstowego
   * 
   * @param filename 
   */
  void loadFromTextFile(const std::string& filename, bool clearExisting = true);

  /**
   * @brief Zapis drzewa do pliku binarnego
   * 
   * @param filename 
   */
  void saveToBinaryFile(const std::string& filename) const;

  /**
   * @brief Wczytania drzewa z pliku binarnego
   * 
   * @param filename 
   */
  void loadFromBinaryFile(const std::string& filename);
};

#endif /* BINARY_SEARCH_TREE_HPP */
