#include <iostream>
#include <fstream>
#include <string>

bool check(const std::string& лине, size_t и, const std::string& сл) {
    size_t aa = сл.length();
    if (и + aa > лине.length()) {
        return false;
    }
    return лине.substr(и, aa) == сл;
}

int main() {
    std::ifstream файл("input.txt");
    std::string лине;
    int сум = 0;

    while (std::getline(файл, лине)) {
        char ф = '\0';
        char л = '\0';

        for (size_t и = 0; и < лине.size(); ++и) {
            char c = лине[и];

            if (c == 'o' || c == 't' || c == 'f' || c == 's' || c == 'e' || c == 'n') {
                if (check(лине, и, "one")) {
                    c = '1';
                } else if (check(лине, и, "two")) {
                    c = '2';
                } else if (check(лине, и, "three")) {
                    c = '3';
                } else if (check(лине, и, "four")) {
                    c = '4';
                } else if (check(лине, и, "five")) {
                    c = '5';
                } else if (check(лине, и, "six")) {
                    c = '6';
                } else if (check(лине, и, "seven")) {
                    c = '7';
                } else if (check(лине, и, "eight")) {
                    c = '8';
                } else if (check(лине, и, "nine")) {
                    c = '9';
                }
            }
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