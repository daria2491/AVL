# AVL JOIN I SPLIT 
Biorąc pod uwagę dwa drzewa AVL T1 i T2, gdzie największy klucz w T1 jest mniejszy od najmniejszego klucza w T2, Join(T1, T2) zwraca drzewo AVL zawierające sumę elementów w T1 i T2.
Plik nagłówkowy AVL.hpp posiada operacje na drzewie AVL.
Operacja split dzieli drzewo AVL na dwa pochodne drzewa AVL, w oparciu o klucz. Jedno z pochodnych drzew powinno zawierać wszystkie wierzchołki, w których wszystkie klucze są mniejsze od klucza oryginalnego, a drugie resztę.
Plik BinaryTree zawiera metodę main() do uruchomienia operacji na drzewie.
Po skompiowaniu plików BinaryTree.cpp i test.cpp można testować drzewo na różnych zestawach danych.
Należy wpisać polecenie:
./test | ./BinaryTree


