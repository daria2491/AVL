# AVL Join i Split

## Opis zadania
Dane są dwa drzewa AVL:
- **T1**: Zawiera klucze, których wartości są mniejsze od pewnej wartości.
- **T2**: Zawiera klucze, których wartości są większe od pewnej wartości.

Operacje do wykonania:
1. **Join(T1, T2)**: Zwraca jedno drzewo AVL, które zawiera wszystkie elementy z T1 i T2, zachowując właściwości drzewa AVL.
2. **Split**: Dzieli drzewo AVL na dwa poddrzewa:
   - Jedno zawiera klucze mniejsze od zadanego klucza.
   - Drugie zawiera klucze równe lub większe od zadanego klucza.

### Struktura plików
- **AVL.hpp**: Plik nagłówkowy zawierający implementację operacji na drzewach AVL.
- **BinaryTree.cpp**: Zawiera funkcję `main()`, która umożliwia uruchamianie operacji na drzewach AVL.
- **test.cpp**: Plik zawierający zestawy danych do testowania operacji na drzewach AVL.

### Skompilowanie programu
Aby skompilować program, należy wykonać poniższe kroki:
1. Skompiluj pliki `BinaryTree.cpp` i `test.cpp`.
2. Uruchom program używając polecenia:
   ```bash
   ./test | ./BinaryTree


