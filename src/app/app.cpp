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
    std::cout << "6. Zapisz drzewo do pliku binarnego\n";
    std::cout << "7. Wczytaj drzewo z pliku binarnego\n";
    std::cout << "8. Wczytaj drzewo z pliku tekstowego (czyści istniejące drzewo)\n";
    std::cout << "9. Wczytaj drzewo z pliku tekstowego (dodaje do istniejącego drzewa)\n\n";

    std::cout << "---OPCJE---\n";
    std::cout << "10. Wyjdź\n\n";

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
      break;
    case DELETE_ITEM:
      handleDeleteItem();
      break;
    case FIND_PATH_TO_ITEM:
      handleFindPathToItem();
      break;
    case DISPLAY_TREE:
      handleDisplayTree();
      break;
    case DELETE_TREE:
      handleDeleteTree();
      break;
    case SAVE_TREE:
      handleSaveBinaryTree();
      break;
    case LOAD_TREE:
      handleLoadBinaryTree();
      break;
    case LOAD_TREE_TEXT:
      handleLoadTextFile(true);  // czyści istniejące drzewo
      break;
    case LOAD_TREE_TEXT_APPEND:
      handleLoadTextFile(false);  // dodaje do istniejącego drzewa
      break;
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
  std::cout << "Podaj wartość: ";
  int value;
  std::cin >> value;

  binarySearchTree.addItem(value);
}

void App::handleDeleteItem() {
  std::cout << "Podaj wartość: ";
  int value;
  std::cin >> value;

  binarySearchTree.removeItem(value);
}

void App::handleFindPathToItem() {
  std::cout << "Podaj wartość: ";
  int value;
  std::cin >> value;

  binarySearchTree.findPathToItem(value);
}

void App::handleDisplayTree() {
  std::cout << "Wybierz metodę przejścia: \n";
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

int App::handleExit() {
  std::cout << "Dziękujemy za korzystanie z programu\n";
  return 0;
}

void App::handleSaveBinaryTree() {
  std::cout << "Podaj ścieżkę do pliku binarnego do zapisu: ";
  std::string filename;
  std::cin >> filename;

  binarySearchTree.saveToBinaryFile(filename);
  std::cout << "Drzewo zostało zapisane binarnie do pliku " << filename << ".\n";
}

void App::handleLoadBinaryTree() {
  std::cout << "Podaj ścieżkę do pliku binarnego do wczytania: ";
  std::string filename;
  std::cin >> filename;

  binarySearchTree.loadFromBinaryFile(filename);
  std::cout << "Drzewo zostało wczytane binarnie z pliku " << filename << ".\n";
}

void App::handleLoadTextFile(bool clearExisting) {
  std::cout << "Podaj ścieżkę do pliku tekstowego: ";
  std::string filename;
  std::cin >> filename;

  binarySearchTree.loadFromTextFile(filename, clearExisting);
  std::cout << "Drzewo zostało wczytane z pliku tekstowego " << filename << ".\n";
}
