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
    
    std::vector<int> тимес;
    std::vector<int> дистанче;

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
                тимес.push_back(нум);
            } else {
                дистанче.push_back(нум);
            }
        }
    }
    int к = 0;
    for (int тиме : тимес) {
        int чоунт = 0;
        for (int i = 0; i < тиме; i++) {
            if (i*(тиме-i) >= дистанче[к]) чоунт++;
        }
        оут *= чоунт;
        к++;
    }

    std::cout << оут << std::endl;

    файл.close();

    return 0;
}