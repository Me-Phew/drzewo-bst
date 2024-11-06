/**
 * @file app.hpp
 * @brief Deklaracje funkcji i klasy aplikacji obsługującej drzewo przeszukiwań binarnych.
 * @details Plik nagłówkowy zawiera deklaracje klas i funkcji umożliwiających zarządzanie
 * drzewem binarnym poprzez interaktywne menu.
 * @date 2024-11-06
 * @authors
 * - Marcin Dudek
 * - Mateusz Basiaga
 *
 * @copyright Copyright (c) 2024
 */

#ifndef APP_HPP
#define APP_HPP

#include <iostream>
#include "../binary_search_tree/binary_search_tree.hpp"

 /// @brief Wyliczenie opcji dostępnych w menu.
 /// Definiuje różne operacje, które użytkownik może wybrać w aplikacji.
enum MenuOption {
  INSERT_ITEM = 1,            ///< Wstawienie elementu do drzewa.
  DELETE_ITEM,                ///< Usunięcie elementu z drzewa.
  FIND_PATH_TO_ITEM,          ///< Znalezienie ścieżki do wybranego elementu.

  DISPLAY_TREE,               ///< Wyświetlenie struktury drzewa.
  DELETE_TREE,                ///< Usunięcie całego drzewa.
  SAVE_TREE,                  ///< Zapisanie drzewa do pliku.
  LOAD_TREE,                  ///< Wczytanie drzewa z pliku binarnego.
  LOAD_TREE_TEXT,             ///< Wczytanie drzewa z pliku tekstowego (zastąpienie obecnego).
  LOAD_TREE_TEXT_APPEND,      ///< Wczytanie drzewa z pliku tekstowego (dodanie do obecnego).

  EXIT                        ///< Zakończenie działania aplikacji.
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

  /// @brief Obsługuje wstawianie nowego elementu do drzewa.
  static void handleInsertItem();

  /// @brief Obsługuje usuwanie wybranego elementu z drzewa.
  static void handleDeleteItem();

  /// @brief Obsługuje wyszukiwanie ścieżki do wybranego elementu w drzewie.
  static void handleFindPathToItem();

  /// @brief Wyświetla strukturę drzewa na standardowym wyjściu.
  static void handleDisplayTree();

  /// @brief Usuwa całe drzewo z pamięci.
  static void handleDeleteTree();

  /// @brief Zapisuje obecny stan drzewa do pliku binarnego.
  static void handleSaveBinaryTree();

  /// @brief Wczytuje stan drzewa z pliku binarnego.
  static void handleLoadBinaryTree();

  /// @brief Wczytuje stan drzewa z pliku tekstowego.
  /// @param clearExisting Flaga określająca, czy istniejące drzewo powinno zostać wyczyszczone przed wczytaniem nowego.
  static void handleLoadTextFile(bool clearExisting);

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
