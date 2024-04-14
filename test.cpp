#include <iostream>
#include <sstream>
#include <fstream>
#include <string>

int main(){
    std::string filename = "input102.txt";

    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "Nie można otworzyć pliku " << filename << std::endl;
        return 1; 
    }

    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << std::endl;
    }

    file.close();
    return 0;
}