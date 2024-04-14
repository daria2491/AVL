
#include <iostream>
#include <sstream>
#include "AVL.hpp"

int main(int argc, const char *argv[]){
    BT BinaryTree;
    BT BinaryTree2;
    int number;
    int operations;
    std::cin >> operations;
    for(int i=0; i<24; i++){
        std::cin >> number;
        BinaryTree.insert(number);
    }
    while(std::cin >> number){
        BinaryTree2.insert(number);
    }      

    std::cout << "DRZEWO 1:" << std::endl;
    BinaryTree.print2DUtil();
    std::cout << "DRZEWO 2:" << std::endl;
    BinaryTree2.print2DUtil();

    std::cout << "DZIELENIE DRZEWA 1:" << std::endl;
    BT tree;
    split(12, BinaryTree, tree);

    std::cout << "DRZEWO O KLUCZACH MNIEJSZYCH LUB RÓWNYCH OD X:" << std::endl;
    tree.print2DUtil();
    std::cout << "DRZEWO O KLUCZACH wIĘKSZYCH OD X:" << std::endl;
    BinaryTree.print2DUtil();

    std::cout << "DRZEWO POWSTAŁE PO POŁĄCZENIU DRZEWA O KLUCZACH wIĘKSZYCH OD X I DRZEWA 2:" << std::endl;
    join(BinaryTree, BinaryTree2);

    BinaryTree2.print2DUtil();

    std::cout << "KONIEC DZIAŁANIA PROGRAMU" << std::endl;
    return 0;
}