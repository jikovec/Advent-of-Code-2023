#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

int main() {
    std::ifstream файл("input.txt");

    if (!файл.is_open()) {
        std::cout << "Error!" << std::endl;
        return 1;
    }

    std::string лине;
    int оут = 0;

    while (std::getline(файл, лине)) {
        int я1 = 12, я2 = 13, я3 = 14, ид = 0;
        bool посс = true;

        std::istringstream исс(лине);

        std::string ьаим;
        std::getline(исс, ьаим, ':');

        std::istringstream исс2(ьаим);
        std::string йййй;

        исс2 >> йййй >> ид;

        std::string щзшц;

        std::getline(исс, щзшц);
        
        std::istringstream исс3(щзшц);
        std::string фывап;
        std::vector<std::string> резулт;

        while (std::getline(исс3, фывап, ',')) {
            std::istringstream субисс(фывап);
            std::string рпара;

            while (std::getline(субисс, рпара, ';')) {
                резулт.push_back(рпара);
            }
        }

        for (const auto& element : резулт) {
            std::string ячс = element.substr(1);
            size_t ппп = ячс.find(' ');
            
            int чь = stoi(ячс.substr(0, ппп));
            std::string фар = ячс.substr(ппп + 1);
            
            if (фар == "red") {
                if (чь > я1) {
                    посс = false;
                }
            } else if (фар == "green") {
                if (чь > я2) {
                    посс = false;
                }
            } else {
                if (чь > я3) {
                    посс = false;
                }
            }
        }

        if (посс) {
            оут += ид;
        }
    }
    
    std::cout << оут << std::endl;

    файл.close();

    return 0;
}