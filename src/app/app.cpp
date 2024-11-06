/**
 * @file app.cpp
 * @author Marcin Dudek & Mateusz Basiaga
 * @brief
 * @date 2024-11-06
 *
 * @copyright Copyright (c) 2024
 *
 */

#ifdef _WIN32
#include <windows.h>
#endif

#include "../binary_search_tree/binary_search_tree.hpp"
#include "app.hpp"

std::istream& operator>>(std::istream& iStream, MenuOption& menuOption) {
  int num;
  iStream >> num;
  menuOption = static_cast<MenuOption>(num);

  return iStream;
}

BinarySearchTree App::binarySearchTree;

int App::mainMenu() {
  while (true) {
    std::cout << "MENU:\n\n";

    std::cout << "---ZARZĄDZANIE ELEMENTAMI DRZEWA---\n";
    std::cout << "1. Dodaj element\n";
    std::cout << "2. Usuń element\n";
    std::cout << "3. Znajdź ścieżkę do elementu\n\n";

    std::cout << "---ZARZĄDZANIE DRZEWEM---\n";
    std::cout << "4. Wyświetl drzewo\n";
    std::cout << "5. Wyczyść drzewo\n";
    std::cout << "6. Zapisz drzewo\n";
    std::cout << "7. Wczytaj drzewo\n\n";

    std::cout << "---OPCJE---\n";
    std::cout << "8. Wyjdź\n\n";

    std::cout << "Wybierz działanie: ";

    MenuOption selectedOption;

    std::cin >> selectedOption;

    if (selectedOption > EXIT) {
      std::cout << "Nieprawidłowa opcja, spróbuj ponownie\n\n";
      continue;
    }

    std::cout << std::endl;

    switch (selectedOption) {
    case INSERT_ITEM:
      handleInsertItem();
    case DELETE_ITEM:
      handleDeleteItem();
    case FIND_PATH_TO_ITEM:
      handleFindPathToItem();
    case DISPLAY_TREE:
      handleDisplayTree();
    case SAVE_TREE:
      handleSaveTree();
    case LOAD_TREE:
      handleLoadTree();
    case EXIT: {
      return handleExit();
    }
    default:
      std::cout << "Nieprawidłowa opcja, spróbuj ponownie\n";
    }

    std::cout << "\n";
  }
}


int App::run() {
#ifdef _WIN32
  // enable utf-8 printing on windows
  SetConsoleOutputCP(CP_UTF8);
#endif

  BinarySearchTree binarySearchTree;

  int exitCode = mainMenu();
  return exitCode;
}

void App::handleInsertItem() {
  std::cout << "Podaj wartosc: ";
  int value;
  std::cin >> value;

  binarySearchTree.addItem(value);
}

void App::handleDeleteItem() {
  std::cout << "Podaj wartosc: ";
  int value;
  std::cin >> value;

  binarySearchTree.removeItem(value);
}

void App::handleFindPathToItem() {
  std::cout << "Podaj wartosc: ";
  int value;
  std::cin >> value;

  binarySearchTree.findPathToItem(value);
}

void App::handleDisplayTree() {
  std::cout << "Wybierz metodę przejścia: ";
  std::cout << "1. PREORDER\n";
  std::cout << "2. INORDER\n";
  std::cout << "3. POSTORDER\n\n";

  BinaryTreeTraversalMethod selectedTraversalMethod;

  std::cin >> selectedTraversalMethod;

  binarySearchTree.display(selectedTraversalMethod);
}

void App::handleDeleteTree() {
  binarySearchTree.destroy();
}

void App::handleSaveTree() {
  // TODO
  std::cout << "Podaj sciezke do pliku: ";
}

void App::handleLoadTree() {
  // TODO
  std::cout << "Podaj sciezke do pliku: ";
}

int App::handleExit() {
  std::cout << "Dziękujemy za korzystanie z programu\n";
  return 0;
}
