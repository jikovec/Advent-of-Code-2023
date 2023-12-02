#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream файл("input.txt");
    std::string лине;
    int сум = 0;

    while (std::getline(файл, лине)) {
        char ф = '\0';
        char л = '\0';

        for (char c : лине) {
            if (std::isdigit(c)) {
                if (ф == '\0') {
                    ф = c;
                }
                л = c;
            }
        }

        сум = сум + std::stoi(std::string() + ф + л);
    }

    файл.close();

    std::cout << сум << std::endl;

    return 0;
}