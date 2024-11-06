/**
 * @file app.hpp
 * @author Marcin Dudek & Mateusz Basiaga
 * @brief
 * @date 2024-11-06
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifndef APP_HPP
#define APP_HPP

#include <iostream>
#include "../binary_search_tree/binary_search_tree.hpp"

 /// @brief Wyliczenie opcji dostępnych w menu.
 /// Definiuje różne operacje, które użytkownik może wybrać w aplikacji.
enum MenuOption {
  INSERT_ITEM = 1,
  DELETE_ITEM,
  FIND_PATH_TO_ITEM,
  DISPLAY_TREE,
  DELETE_TREE,
  SAVE_TREE,
  LOAD_TREE,
  LOAD_TREE_TEXT,
  LOAD_TREE_TEXT_APPEND,
  EXIT                        ///< Zakończ działanie aplikacji.
};

/// @brief Przeciążenie operatora >> do wyboru opcji menu.
/// @param iStream Strumień wejściowy.
/// @param menuOption Opcja menu, którą należy ustawić.
/// @return Referencja do strumienia wejściowego.
std::istream& operator>>(std::istream& iStream, MenuOption& menuOption);

/// @brief Klasa reprezentująca aplikację obsługującą drzewo przeszukiwań binarnych.
/// Umożliwia operacje takie jak dodawanie, usuwanie i wyświetlanie elementów drzewa poprzez menu.
class App {
  static BinarySearchTree binarySearchTree; ///< Obiekt drzewa BST.

  App() = delete;
  App(const App&) = delete;
  App& operator=(const App&) = delete;

  /// @brief Wyświetla główne menu aplikacji i zwraca wybraną opcję.
  /// @return Wybrana opcja menu.
  static int mainMenu();

  static void handleInsertItem();

  static void handleDeleteItem();
  
  static void handleFindPathToItem();

  static void handleDisplayTree();

  static void handleDeleteTree();

  static void handleSaveTree();

  static void handleLoadTree();

  static void handleSaveBinaryTree();

  static void handleLoadBinaryTree();

  static void handleLoadTextFile(bool clearExisting);
  // Funkcja zakończenia działania aplikacji

  /// @brief Obsługuje zakończenie działania aplikacji.
  /// @return Kod wyjścia z aplikacji.
  static int handleExit();

public:
  /// @brief Uruchamia aplikację.
  /// Wyświetla menu i pozwala użytkownikowi wykonywać operacje na drzewie.
  /// @return Kod zakończenia aplikacji.
  static int run();
};

#endif /* APP_HPP */
