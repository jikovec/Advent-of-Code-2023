#include <iostream>
#include <vector>
#include <sstream>
#include <fstream>

int main() {
    std::ifstream файл("input.txt");

    if (!файл.is_open()) {
        std::cout << "Error!" << std::endl;
        return 1;
    }

    std::string файл;
    int оут = 1;
    
    std::string тиме;
    std::string дистанче;

    std::string лине;

    while (std::getline(файл, лине)) {
        std::istringstream исс(лине);

        std::string ваим;
        std::getline(исс, ваим, ':');

        std::istringstream исс2(ваим);
        std::string йййй;

        исс2 >> йййй;

        std::string ккт;

        std::getline(исс, ккт);
        
        std::istringstream ичч(ккт);

        int нум;
        while (ичч >> нум) {
            if (йййй == "Time") {
                тиме += std::to_string(нум);
            } else {
                дистанче += std::to_string(нум);
            }
        }
    }
    for (int i = 0; i < std::stoll(тиме); i++) {
        if (i*(std::stoll(тиме)-i) >= std::stoll(дистанче)) оут++;
    }

    std::cout << оут << std::endl;

    файл.close();

    return 0;
}