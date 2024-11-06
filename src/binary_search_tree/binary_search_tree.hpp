/**
 * @file binary_search_tree.hpp
 * @brief Implementacja drzewa przeszukiwań binarnych (BST).
 * @details Plik nagłówkowy definiuje klasę BinarySearchTree, która umożliwia operacje na drzewie BST,
 * takie jak dodawanie, usuwanie, znajdowanie ścieżki, wyświetlanie oraz zapisywanie/wczytywanie drzewa z pliku.
 * @date 2024-10-23
 * @authors
 * - Marcin Dudek
 * - Mateusz Basiaga
 *
 * @copyright Copyright (c) 2024
 */

#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

 /// @brief Metody przeglądania drzewa BST.
 /// Definiuje kolejność odwiedzania węzłów w drzewie.
enum BinaryTreeTraversalMethod {
  PREORDER = 1,  ///< Preorder traversal.
  INORDER,       ///< Inorder traversal.
  POSTORDER      ///< Postorder traversal.
};

/// @brief Przeciążenie operatora >> do wyboru metody przeglądania drzewa.
/// @param iStream Strumień wejściowy.
/// @param traversalMethod Metoda przeglądania, którą należy ustawić.
/// @return Referencja do strumienia wejściowego.
std::istream& operator>>(std::istream& iStream, BinaryTreeTraversalMethod& traversalMethod);

/// @brief Klasa reprezentująca drzewo przeszukiwań binarnych (BST).
class BinarySearchTree {
private:

  /// @brief Struktura reprezentująca węzeł w drzewie.
  struct Node {
    int key;           ///< Wartość klucza węzła.
    Node* left;        ///< Wskaźnik na lewego potomka.
    Node* right;       ///< Wskaźnik na prawego potomka.

    /// @brief Konstruktor węzła.
    /// @param value Wartość klucza.
    explicit Node(int value) {
      key = value;
      left = right = nullptr;
    }
  };

  Node* root;  ///< Wskaźnik na korzeń drzewa.

  Node* _addItem(Node* node, int value);
  Node* _removeItem(Node* node, int value);

  void _removeAllNodes(Node* node);
  void _findPathToItem(const Node* node, int value, std::vector<int>& path) const;
  void _traversePreorder(Node* node);
  void _traverseInorder(Node* node);
  void _traversePostorder(Node* node);
  void _loadFromTextFile(Node* node, std::ofstream& file);
  void _saveToBinaryFile(const Node* node, std::ofstream& file) const;
  void _loadFromBinaryFile(Node* node, std::ofstream& file);

public:
  /// @brief Konstruktor domyślny klasy BinarySearchTree.
  BinarySearchTree();

  /// @brief Destruktor klasy BinarySearchTree.
  ~BinarySearchTree();

  /// @brief Dodaje element do drzewa.
  /// @param value Wartość elementu do dodania.
  void addItem(int value);

  /// @brief Usuwa element z drzewa.
  /// @param value Wartość elementu do usunięcia.
  void removeItem(int value);

  /// @brief Usuwa całe drzewo.
  void destroy();

  /// @brief Znajduje ścieżkę do podanego elementu w drzewie.
  /// @param value Wartość elementu, do którego ścieżka ma zostać znaleziona.
  void findPathToItem(int value);

  /// @brief Wyświetla drzewo za pomocą wybranej metody przeglądania.
  /// @param traversalMethod Metoda przeglądania drzewa.
  void display(BinaryTreeTraversalMethod traversalMethod);

  /// @brief Wczytuje drzewo z pliku tekstowego.
  /// @param filename Nazwa pliku tekstowego.
  /// @param clearExisting Flaga określająca, czy istniejące drzewo powinno zostać usunięte przed wczytaniem nowego.
  void loadFromTextFile(const std::string& filename, bool clearExisting = true);

  /// @brief Zapisuje drzewo do pliku binarnego.
  /// @param filename Nazwa pliku binarnego, do którego ma zostać zapisane drzewo.
  void saveToBinaryFile(const std::string& filename) const;

  /// @brief Wczytuje drzewo z pliku binarnego.
  /// @param filename Nazwa pliku binarnego, z którego ma zostać wczytane drzewo.
  void loadFromBinaryFile(const std::string& filename);
};

#endif /* BINARY_SEARCH_TREE_HPP */
